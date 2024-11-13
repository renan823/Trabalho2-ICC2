import pandas as pd 
import os 
import subprocess
from glob import glob

def run(algoritmo: str, entradas: str):
    processo = subprocess.run([f"./{algoritmo}", entradas], capture_output=True, text=True)

    if processo.return_code != 0:
        raise Exception("Deu ruim na execução!!")

    try:
        return float(processo.stdout.strip())
    except ValueError:
        raise Exception("Falha ao receber o tempo de execução")


algortimos = glob("./*.c")
testes = glob("testes/*.txt")

df = pd.DataFrame(columns=["algoritmo", "caso", "tamanho", "tempo"])