#include "../Loader.h"

using namespace std;

class MediaAritmetica {

    public:
        float getMediaAritmetica(vector<float> notas) {
            float soma = 0.0;
            for (float nota: notas) {
                soma += nota;
            }
            return soma / notas.size();
        }

};