src/sistema/atividade.o: src/sistema/Atividade.cpp src/sistema/Atividade.h
	$(CPPC) -o build/sistema/atividade.o -c src/sistema/Atividade.cpp

src/sistema/curso.o: src/sistema/Curso.cpp src/sistema/Curso.h
	$(CPPC) -o build/sistema/curso.o -c src/sistema/Curso.cpp

src/sistema/discente.o: src/sistema/Discente.cpp src/sistema/Discente.h
	$(CPPC) -o build/sistema/discente.o -c src/sistema/Discente.cpp

src/sistema/disciplina.o: src/sistema/Disciplina.cpp src/sistema/Disciplina.h
	$(CPPC) -o build/sistema/disciplina.o -c src/sistema/Disciplina.cpp

src/sistema/docente.o: src/sistema/Docente.cpp src/sistema/Docente.h
	$(CPPC) -o build/sistema/docente.o -c src/sistema/Docente.cpp

src/sistema/orientacao.o: src/sistema/Orientacao.cpp src/sistema/Orientacao.h
	$(CPPC) -o build/sistema/orientacao.o -c src/sistema/Orientacao.cpp

src/sistema/orientagrad.o: src/sistema/OrientaGrad.cpp src/sistema/OrientaGrad.h
	$(CPPC) -o build/sistema/orientagrad.o -c src/sistema/OrientaGrad.cpp

src/sistema/orientapos.o: src/sistema/OrientaPos.cpp src/sistema/OrientaPos.h
	$(CPPC) -o build/sistema/orientapos.o -c src/sistema/OrientaPos.cpp

src/sistema/producao.o: src/sistema/Producao.cpp src/sistema/Producao.h
	$(CPPC) -o build/sistema/producao.o -c src/sistema/Producao.cpp

src/sistema/sistema.o: src/sistema/Sistema.cpp src/sistema/Sistema.h
	$(CPPC) -o build/sistema/sistema.o -c src/sistema/Sistema.cpp