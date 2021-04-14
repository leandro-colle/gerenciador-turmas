#include "../Loader.h"

using namespace std;

class Professor: public Pessoa {

    public:
        Professor(): Pessoa("", "") {}
        Professor(string codigo, string nome): Pessoa(codigo, nome) {}
        Professor(string codigo, string nome, string localFormacao): Pessoa(codigo, nome) {
            this->setLocalFormacao(localFormacao);
        }

        void setLocalFormacao(string localFormacao) {
            this->localFormacao = localFormacao;
        }

        string getLocalFormacao() {
            return this->localFormacao;
        }

    private:
        string localFormacao;
};