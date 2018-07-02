#include "Curso.h"

namespace prog3 {
    /**
     *****************************************************************************************
     *  @brief      Classe de domínio Curso
     *
     *  @param      string Nome do curso
     *  @param      int Código do curso
     *  @param      bool É curso de graduação?
     *
     ****************************************************************************************/
    Curso::Curso(string n, int c, bool g) {
        this->nome = n;
        this->codigo = c;
        this->grad = g;
    }

    Curso::~Curso() {

    }

    int Curso::getCodigo() {
        return this->codigo;
    }
    /**
     *****************************************************************************************
     *  @brief      Adiciona Discente a lista de Discentes do curso
     *
     *  @param      Discente&       Discente a ser adicionado
     *
     ****************************************************************************************/
    void Curso::adicionaDiscente(Discente& d) {
        this->discentes.push_back(&d);
    }
     /**
     *****************************************************************************************
     *  @brief      Adiciona Disciplina a lista de Disciplinas do curso
     *
     *  @param      Disciplina&       Disciplina a ser adicionada
     *
     ****************************************************************************************/
    void Curso::adicionaDisciplina(Disciplina& d) {
        this->disciplinas.push_back(&d);
    }

    /**
    *****************************************************************************************
    *  @brief      Adiciona Orientaçao de Graduaçao a lista de Orientaçoes de Graduaçao do curso
    *
    *  @param      OrientaGrad&       Orientacao a ser adicionada
    *
    ****************************************************************************************/
    void Curso::adicionaOrientaGrad(OrientaGrad& o) {
        this->orientacoesGrad.push_back(&o);
    }
/**
    *****************************************************************************************
    *  @brief      Adiciona Horas aula a um docente
    *
    *  @param      Docente&       Docente que recebera horas-aula
    *  @param      int            Quantidade de horas-aula a adicionar
    *
    ****************************************************************************************/
    void Curso::adicionaHorasADocente(Docente& doc, int val) {
        this->horasDocente[&doc] += val;
    }

}