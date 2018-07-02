#include "Docente.h"
#include "Producao.h"

namespace prog3 {
    /**
    *****************************************************************************************
    *  @brief      Construtor da classe
    *
    *  @param      int Codigo do docente
    *  @param      string Nome do docente
    *  @param      string Departamento do docente
    *
    ****************************************************************************************/
    Docente::Docente(int c, string n, string d) {
        this->codigo = c;
        this->nome = n;
        this->departamento = d;
        this->horasAulaSemanais = 0;
        this->horasAulaSemestrais = 0;
    }

    Docente::~Docente() {

    }
    
    /**
    *****************************************************************************************
    *  @brief      Adiciona produçao ao docente
    *
    *  @param      Producao& produçao a adicionar
    *
    ****************************************************************************************/
    void Docente::adicionaProducao(Producao& p) {
        this->producoes.push_back(&p);
    }

    /**
    *****************************************************************************************
    *  @brief      Adiciona atividade ao docente
    *
    *  @param      Atividade& atividade a adicionar
    *
    ****************************************************************************************/
    void Docente::adicionaAtividade(Atividade& a) {
        this->atividades.push_back(&a);
    }
    /**
    *****************************************************************************************
    *  @brief      Adiciona horas aula semanais ao docente
    *
    *  @param      int quantidade de horas a adicionar
    *
    ****************************************************************************************/
    void Docente::adicionaHorasAulaSemanais(int val) {
        this->horasAulaSemanais += val;
    }

    /**
    *****************************************************************************************
    *  @brief      Adiciona horas aula semestrais ao docente
    *
    *  @param      int quantidade de horas a adicionar
    *
    ****************************************************************************************/
    void Docente::adicionaHorasAulaSemestrais(int val) {
        this->horasAulaSemestrais += val;
    }

    /**
    *****************************************************************************************
    *  @brief      Adiciona horas de orientaçao ao docente
    *
    *  @param      int quantidade de horas a adicionar
    *
    ****************************************************************************************/
    void Docente::adicionaHorasOrientacao(int val) {
        this->horasOrientacaoSemanais += val;
    }

    /**
    *****************************************************************************************
    *  @brief      Retorna os dados formatados em CSV para escrita na saida
    *
    *  @returns    vector<string> lista de strings para escrita
    *
    ****************************************************************************************/
    vector<string> Docente::getCSVData() {
        unsigned long prodQual = 0;
        unsigned long prodUnqual = 0;
        for(Producao* p : this->producoes) {
            if(p->isQualificada()) {
                prodQual++;
            }
        }
        prodUnqual = this->producoes.size() - prodQual;

        vector<string> vec = {
                this->nome,
                this->departamento,
                std::to_string(this->horasAulaSemanais),
                std::to_string(this->horasAulaSemestrais),
                std::to_string(this->horasOrientacaoSemanais),
                std::to_string(prodQual),
                std::to_string(prodUnqual)
                };
        return vec;
    }

    ostream &operator<<(ostream &os, const Docente &doc) {
        os << "Nome: " << doc.nome << "\nCodigo: " << doc.codigo << "\nDepartamento: " << doc.departamento;
        return os;
    }

    ostream &operator<<(ostream &os, const Docente* doc) {
        os << "Nome: " << doc->nome << "\nCodigo: " << doc->codigo << "\nDepartamento: " << doc->departamento;
        return os;
    }

    bool operator<(Docente const& a, Docente const& b) {
        return cpp_util::stringCompare(a.nome, b.nome);
    }

}

