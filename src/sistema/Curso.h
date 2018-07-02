//
// Created by gabriel on 18/06/18.
//

#ifndef TRABALHO_PROG3_CURSO_H
#define TRABALHO_PROG3_CURSO_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

namespace prog3 {

    //Forward declaration
    class Discente;
    class Disciplina;
    class OrientaGrad;
    class Docente;
    
     /**
     *****************************************************************************************
     *  @brief      Classe de domínio Curso
     *
     *  @usage       Utilizada na classe de domínio sistema
     *
     *  @param      string Nome do curso
     *  @param      int Código do curso
     *  @param      bool É curso de graduação?
     *
     ****************************************************************************************/
    class Curso {
    private:
        int codigo;
        string nome;
        bool grad;
        vector<Discente*> discentes;
        vector<Disciplina*> disciplinas;
        vector<OrientaGrad*> orientacoesGrad;
        map<Docente*, int> horasDocente;
    public:
        Curso(string = "", int = 0, bool = false);
        ~Curso();
        int getCodigo();
        string getNome() {return this->nome; }
        void adicionaDiscente(Discente &d);
        void adicionaDisciplina(Disciplina& d);
        void adicionaOrientaGrad(OrientaGrad& o);
        void adicionaHorasADocente(Docente& doc, int val);
        map<Docente*, int>* getMap() { return &(this->horasDocente); }
    };

}
#endif //TRABALHO_PROG3_CURSO_H
