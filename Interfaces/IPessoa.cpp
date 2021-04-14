#include "../Loader.h"

using namespace std;

class IPessoa {
    virtual void setCodigo(string codigo) = 0;
    virtual string getCodigo() = 0;
    virtual void setNome(string nome) = 0;
    virtual string getNome() = 0;
};