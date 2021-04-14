#include "../Loader.h"

using namespace std;

class IDesempenho {
    public:
        static const string SITUACAO_APROVADO;
        static const string SITUACAO_REPROVADO;
};
const string IDesempenho::SITUACAO_APROVADO = "Aprovado";
const string IDesempenho::SITUACAO_REPROVADO = "Reprovado";