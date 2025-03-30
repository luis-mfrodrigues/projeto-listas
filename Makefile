#compilar programa
#-p cria pasta build e se já existir nao gera erro
all:
	mkdir -p build
	gcc src/main.c src/funcoes.c -Iinclude -g -o build/projeto-listas

#compilar e abrir programa
run: all
	./build/projeto-listas

#apagar pasta build
clean:
	rm -rf build