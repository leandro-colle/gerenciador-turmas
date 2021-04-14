#include "../Loader.h"

using namespace std;

class Pessoa: private IPessoa {

    public:
        Pessoa(string codigo, string nome) {
            this->setCodigo(codigo);
            this->setNome(nome);
        }

        void setCodigo(string codigo) {
            this->codigo = codigo;
        }

        string getCodigo() {
            return this->codigo;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        string getNome() {
            return this->nome;
        }

    private:
        string codigo;
        string nome;

};