import pandas as pd 
import os 
import subprocess
from glob import glob
from decimal import Decimal, InvalidOperation

def run(algoritmo: str, entradas: str):
    with open(entradas, 'r') as f:
        processo = subprocess.run([f"./{algoritmo.split('.')[0]}"], stdin=f, capture_output=True, text=True)

    if processo.returncode != 0:
        print(f"Erro ao executar o processo:\n{processo.stderr.strip()}")
        raise Exception("Deu ruim na execução!!")

    try:
        # Usando Decimal para maior precisão
        return Decimal(processo.stdout.strip())
    except InvalidOperation as e:
        print(e)
        raise Exception("Falha ao receber o tempo de execução")


algortimos = glob("*.c")
testes = glob("testes/*.txt")

df = pd.DataFrame(columns=["algoritmo", "caso", "tamanho", "tempo"])

for alg in algortimos:
    for teste in testes:
        try:
            tempo = run(alg, teste)

            #debug (pra saber se ele nao morreu no processo)
            print(f"- {alg} caso {teste} em {tempo}")

            caso_teste = teste.split("_")

            df.loc[len(df)] = {
                'algoritmo': alg,
                'caso': caso_teste[0].split("/")[1],
                'tamanho': caso_teste[1].replace(".txt", ""),
                'tempo': tempo
            }
        except Exception as e:
            print(e)

#exportar o arquivo pra usar no jupyter
df.to_csv("resultados.csv", index=False)