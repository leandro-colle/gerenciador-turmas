#include "../Loader.h"

using namespace std;

class AlunoIterator {

    public:
        vector<Aluno> alunos;
        vector<Aluno>::iterator it;

        AlunoIterator(vector<Aluno> alunos) {
            this->alunos = alunos;
        }

        void itarate() {
            for (this->it = this->first(); it != this->last(); this->next()) {
                cout << "Aluno: " << it->getNome() << endl;
                cout << "Nota 1: " << it->getDesempenho().getNota(1) << endl;
                cout << "Nota 2: " << it->getDesempenho().getNota(2) << endl;
                cout << "Nota 3: " << it->getDesempenho().getNota(3) << endl;
                cout << "Nota final: " << it->getDesempenho().getMedia() << endl;
                cout << "Situação: " << it->getDesempenho().getSituacao() << endl;
                cout << endl;
            }
        }

        vector<Aluno>::iterator first() {
            return this->alunos.begin();
        }

        vector<Aluno>::iterator last() {
            return this->alunos.end();
        }

        void next() {
            ++this->it;
        }
};