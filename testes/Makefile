TAMANHOS = 100 1000 10000 100000
INDICES = 1 2 3 4 5

all: gerador normal reverse random
	

gerador:
	gcc gerador.c -Wall -std=c99 -o gerador

normal:
	$(foreach tamanho, $(TAMANHOS), \
		./gerador $(tamanho) normal; \
	)


reverse:
	$(foreach tamanho, $(TAMANHOS), \
		./gerador $(tamanho) reverse; \
	)

random:
	$(foreach tamanho, $(TAMANHOS), \
		$(foreach i, $(INDICES), \
			./gerador $(tamanho) random random_$(tamanho)_$(i).txt; \
		) \
	)

clear: 
	rm gerador *.txt

