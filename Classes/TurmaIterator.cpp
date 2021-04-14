#include "../Loader.h"

using namespace std;

class TurmaIterator {

    public:
        vector<Turma> turmas;
        vector<Turma>::iterator it;

        TurmaIterator(vector<Turma> turmas) {
            this->turmas = turmas;
        }

        void itarate() {
            for (this->it = this->first(); it != this->last(); this->next()) {
                cout << "Cod. turma: " << it->getCodigo() << endl;
                cout << "Disciplina: " << it->getDisciplina() << endl;
                cout << "Professor: " << it->getProfessor().getNome() << endl;
                cout << "Alunos matriculados: " << it->getAlunos().size() << endl;
                cout << endl;
            }
            cout << endl;
        }

        void itarateDetails() {
            for (this->it = this->first(); it != this->last(); this->next()) {
                cout << "Cod. turma: " << it->getCodigo() << endl;
                cout << "Disciplina: " << it->getDisciplina() << endl;
                cout << "Professor: " << it->getProfessor().getNome() << endl;
                cout << endl;
                AlunoIterator aIterator = AlunoIterator(it->getAlunos());
                aIterator.itarate();
            }
            cout << endl;
        }

        void iterateStatistics() {
            int qtdAlunosInstituicao = 0;
            int qtdAprovadosInstituicao = 0;

            for (this->it = this->first(); it != this->last(); this->next()) {
                int qtdAprovados = (int) it->getQtdAlunosAprovados();
                qtdAlunosInstituicao += it->getAlunos().size();
                qtdAprovadosInstituicao += qtdAprovados;

                cout << "Cod. turma: " << it->getCodigo() << endl;
                cout << "Disciplina: " << it->getDisciplina() << endl;
                cout << "Professor: " << it->getProfessor().getNome() << endl;
                cout << "Alunos matriculados: " << it->getAlunos().size() << endl;
                cout << "Número de aprovados: " << qtdAprovados << endl;
                cout << "Percentual de aprovados: " << it->getPctAlunosAprovados() << "%" << endl;
                cout << endl;
            }

            cout << "Total de alunos matriculados na instituição: " << qtdAlunosInstituicao << endl;
            cout << "Percentual de aprovados na instituição: " << ((float) qtdAprovadosInstituicao / (float) qtdAlunosInstituicao) * 100 << "%" << endl;
            cout << endl;
        }

        vector<Turma>::iterator first() {
            return this->turmas.begin();
        }

        vector<Turma>::iterator last() {
            return this->turmas.end();
        }

        void next() {
            ++this->it;
        }
};