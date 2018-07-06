# Compilador
CPPC := g++ -std=c++11

OUTPUT_DIR_B = build
OUTPUT_DIR_E = build/exceptions
OUTPUT_DIR_S = build/sistema
OUTPUT_DIR_U = build/utils

OUTPUT_DIR_BIN = bin

all: dirs trabalho

dirs:
	mkdir -p $(OUTPUT_DIR_B) $(OUTPUT_DIR_U) $(OUTPUT_DIR_S) $(OUTPUT_DIR_E) $(OUTPUT_DIR_BIN)

trabalho: exceptions utils sistema
	$(CPPC) -o trabalho src/main.cpp exceptions.o utils.o sistema.o

trabalho_new: src/exceptions/classinconsistencyexception.o src/exceptions/invalidcodeexception.o src/exceptions/invaliddateexception.o src/exceptions/repeatedcodeexception.o src/utils/argparse.o src/utils/icstream.o src/utils/ocstream.o src/utils/cpp_utils/dateutils.o src/utils/cpp_utils/numberutils.o src/utils/cpp_utils/numpunctptbr.o src/utils/cpp_utils/stringutils.o src/utils/cpp_utils/tokenizer.o src/sistema/atividade.o src/sistema/curso.o src/sistema/discente.o src/sistema/disciplina.o src/sistema/docente.o src/sistema/orientacao.o src/sistema/orientagrad.o src/sistema/orientapos.o src/sistema/producao.o src/sistema/sistema.o
	$(CPPC) -o trabalho src/main.cpp src/exceptions/classinconsistencyexception.o src/exceptions/invalidcodeexception.o src/exceptions/invaliddateexception.o src/exceptions/repeatedcodeexception.o src/utils/argparse.o src/utils/icstream.o src/utils/ocstream.o src/utils/cpp_utils/dateutils.o src/utils/cpp_utils/numberutils.o src/utils/cpp_utils/numpunctptbr.o src/utils/cpp_utils/stringutils.o src/utils/cpp_utils/tokenizer.o src/sistema/atividade.o src/sistema/curso.o src/sistema/discente.o src/sistema/disciplina.o src/sistema/docente.o src/sistema/orientacao.o src/sistema/orientagrad.o src/sistema/orientapos.o src/sistema/producao.o src/sistema/sistema.o

exceptions: src/exceptions/classinconsistencyexception.o src/exceptions/invalidcodeexception.o src/exceptions/invaliddateexception.o src/exceptions/repeatedcodeexception.o
	ld -r src/exceptions/classinconsistencyexception.o src/exceptions/invalidcodeexception.o src/exceptions/invaliddateexception.o src/exceptions/repeatedcodeexception.o -o exceptions.o


utils: src/utils/argparse.o src/utils/icstream.o src/utils/ocstream.o src/utils/cpp_utils/dateutils.o src/utils/cpp_utils/numberutils.o src/utils/cpp_utils/numpunctptbr.o src/utils/cpp_utils/stringutils.o src/utils/cpp_utils/tokenizer.o
	ld -r -o utils.o src/utils/argparse.o src/utils/icstream.o src/utils/ocstream.o src/utils/cpp_utils/dateutils.o src/utils/cpp_utils/numberutils.o src/utils/cpp_utils/numpunctptbr.o src/utils/cpp_utils/stringutils.o src/utils/cpp_utils/tokenizer.o

sistema: src/sistema/atividade.o src/sistema/curso.o src/sistema/discente.o src/sistema/disciplina.o src/sistema/docente.o src/sistema/orientacao.o src/sistema/orientagrad.o src/sistema/orientapos.o src/sistema/producao.o src/sistema/sistema.o
	ld -r -o sistema.o src/sistema/atividade.o src/sistema/curso.o src/sistema/discente.o src/sistema/disciplina.o src/sistema/docente.o src/sistema/orientacao.o src/sistema/orientagrad.o src/sistema/orientapos.o src/sistema/producao.o src/sistema/sistema.o

-include src/exceptions/subdir.mk
-include src/sistema/subdir.mk
-include src/utils/subdir.mk