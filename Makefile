# Compilador
CPPC := g++ -std=c++11

OUTPUT_DIR_B = build
OUTPUT_DIR_E = build/exceptions
OUTPUT_DIR_S = build/sistema
OUTPUT_DIR_U = build/utils

OUTPUT_DIR_BIN = bin

all: dirs trabalho

# Cria os diretórios de saída
dirs:
	mkdir -p $(OUTPUT_DIR_B) $(OUTPUT_DIR_U) $(OUTPUT_DIR_S) $(OUTPUT_DIR_E) $(OUTPUT_DIR_BIN)

trabalho: exceptions utils sistema
	$(CPPC) -o bin/trabalho src/main.cpp build/exceptions.o build/utils.o build/sistema.o

exceptions: classinconsistencyexception invalidcodeexception invaliddateexception repeatedcodeexception
	ld -r -o build/exceptions.o build/exceptions/classinconsistencyexception.o build/exceptions/invalidcodeexception.o build/exceptions/invaliddateexception.o build/exceptions/repeatedcodeexception.o

utils: argparse icstream ocstream cpp_utils/dateutils cpp_utils/numberutils cpp_utils/numpunctptbr cpp_utils/stringutils cpp_utils/tokenizer
	ld -r -o build/utils.o build/utils/argparse.o build/utils/icstream.o build/utils/ocstream.o build/utils/dateutils.o build/utils/numberutils.o build/utils/numpunctptbr.o build/utils/stringutils.o build/utils/tokenizer.o

sistema: atividade curso discente disciplina docente orientacao orientagrad orientapos producao sistema_o
	ld -r -o build/sistema.o build/sistema/atividade.o build/sistema/curso.o build/sistema/discente.o build/sistema/disciplina.o build/sistema/docente.o build/sistema/orientacao.o build/sistema/orientagrad.o build/sistema/orientapos.o build/sistema/producao.o build/sistema/sistema.o

-include src/exceptions/subdir.mk
-include src/sistema/subdir.mk
-include src/utils/subdir.mk

clean:
	@rm -f -r build bin

run:
	bin/trabalho