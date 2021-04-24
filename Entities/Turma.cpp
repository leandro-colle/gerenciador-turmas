#include "../Loader.h"

using namespace std;

class Turma: public ITurma {

    public:
        Turma() {}
        Turma(string codigo, string disciplina, Professor professor) {
            this->setCodigo(codigo);
            this->setDisciplina(disciplina);
            this->setProfessor(professor);
        }

        void setCodigo(string codigo) {
            this->codigo = codigo;
        }

        string getCodigo() {
            return this->codigo;
        }

        void setDisciplina(string disciplina) {
            this->disciplina = disciplina;
        }

        string getDisciplina() {
            return this->disciplina;
        }

        void setProfessor(Professor professor) {
            this->professor = professor;
        }

        Professor getProfessor() {
            return this->professor;
        }

        bool setAluno(Aluno aluno) {
            if (this->alunos.size() < this->QUANTIDADE_MAXIMA_ALUNOS) {
                this->alunos.push_back(aluno);
                return true;
            }
            return false;
        }

        Aluno getAluno(string codigo) {
            for (vector<Aluno>::iterator it = this->alunos.begin(); it != this->alunos.end(); ++it) {
                if (it->getCodigo().compare(codigo) == 0) {
                    return (Aluno) *it;
                }
            }
            return Aluno();
        }

        vector<Aluno> getAlunos() {
            return this->alunos;
        }

        int getQtdAlunosAprovados() {
            int qtdAprovados = 0;
            for (Aluno aluno: this->alunos) {
                if (aluno.getDesempenho().getSituacao() == Desempenho::SITUACAO_APROVADO) {
                    qtdAprovados++;
                }
            }
            return qtdAprovados;
        }

        float getPctAlunosAprovados() {
            int qtdAprovados = 0;
            for (Aluno aluno: this->alunos) {
                if (aluno.getDesempenho().getSituacao() == Desempenho::SITUACAO_APROVADO) {
                    qtdAprovados++;
                }
            }
            return ((float) qtdAprovados / this->alunos.size()) * 100;
        }

    private:
        string codigo;
        string disciplina;
        Professor professor;
        vector<Aluno> alunos;

};