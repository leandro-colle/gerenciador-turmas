#include "../Loader.h"

using namespace std;

class Desempenho: public IDesempenho, public MediaAritmetica {

    public:
        Desempenho() {}
        Desempenho(map<int, float> notas) {
            this->setNota(1, notas.at(1));
            this->setNota(2, notas.at(2));
            this->setNota(3, notas.at(3));
        }

        float getNota(int nota) {
            switch (nota) {
                case 1: return this->n1; break;
                case 2: return this->n2; break;
                case 3: return this->n3; break;
                default: return 0.0;
            }
        }

        void setNota(int nota, float valor) {
            if (valor < 0 || valor > 10) {
                throw -1;
            }
            switch (nota) {
                case 1: this->n1 = valor; break;
                case 2: this->n2 = valor; break;
                case 3: this->n3 = valor; break;
            }
        }

        float getMedia() {
            return this->getMediaAritmetica(this->getNotas());
        }

        string getSituacao() {
            float media = this->getMedia();
            if (media >= 7) {
                return this->SITUACAO_APROVADO;
            } else {
                return this->SITUACAO_REPROVADO;
            }
        }

        vector<float> getNotas() {
            return vector<float> {
                this->getNota(1),
                this->getNota(2),
                this->getNota(3)
            };
        }

    private:
        float n1;
        float n2;
        float n3;

};