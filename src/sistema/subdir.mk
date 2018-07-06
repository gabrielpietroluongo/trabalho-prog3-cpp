atividade: src/sistema/Atividade.cpp src/sistema/Atividade.h
	$(CPPC) -o build/sistema/atividade.o -c src/sistema/Atividade.cpp

curso: src/sistema/Curso.cpp src/sistema/Curso.h
	$(CPPC) -o build/sistema/curso.o -c src/sistema/Curso.cpp

discente: src/sistema/Discente.cpp src/sistema/Discente.h
	$(CPPC) -o build/sistema/discente.o -c src/sistema/Discente.cpp

disciplina: src/sistema/Disciplina.cpp src/sistema/Disciplina.h
	$(CPPC) -o build/sistema/disciplina.o -c src/sistema/Disciplina.cpp

docente: src/sistema/Docente.cpp src/sistema/Docente.h
	$(CPPC) -o build/sistema/docente.o -c src/sistema/Docente.cpp

orientacao: src/sistema/Orientacao.cpp src/sistema/Orientacao.h
	$(CPPC) -o build/sistema/orientacao.o -c src/sistema/Orientacao.cpp

orientagrad: src/sistema/OrientaGrad.cpp src/sistema/OrientaGrad.h
	$(CPPC) -o build/sistema/orientagrad.o -c src/sistema/OrientaGrad.cpp

orientapos: src/sistema/OrientaPos.cpp src/sistema/OrientaPos.h
	$(CPPC) -o build/sistema/orientapos.o -c src/sistema/OrientaPos.cpp

producao: src/sistema/Producao.cpp src/sistema/Producao.h
	$(CPPC) -o build/sistema/producao.o -c src/sistema/Producao.cpp

sistema_o: src/sistema/Sistema.cpp src/sistema/Sistema.h
	$(CPPC) -o build/sistema/sistema.o -c src/sistema/Sistema.cpp