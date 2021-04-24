#include "../Loader.h"

using namespace std;

class Aluno: public Pessoa {

    public:
        Aluno(): Pessoa("", "") {}
        Aluno(string codigo, string nome, string email, Desempenho desempenho): Pessoa(codigo, nome) {
            this->setEmail(email);
            this->setDesempenho(desempenho);
        }
        Aluno(string codigo, string nome, string email, Desempenho desempenho, string curso): Pessoa(codigo, nome) {
            this->setEmail(email);
            this->setDesempenho(desempenho);
            this->setCurso(curso);
        }

        void setEmail(string email) {
            this->email = email;
        }

        string getEmail() {
            return this->email;
        }

        void setDesempenho(Desempenho desempenho) {
            this->desempenho = desempenho;
        }

        Desempenho getDesempenho() {
            return this->desempenho;
        }

        void setCurso(string curso) {
            if (
                curso != Curso::CIENCIA_COMPUTACAO &&
                curso != Curso::SISTEMAS_INFORMACAO &&
                curso != Curso::ENGENHARIA_COMPUTACAO &&
                curso != Curso::ANALISE_DESENVOLVIMENTO_SISTEMAS
            ) {
                throw -1;
            }
            this->curso = curso;
        }

        string getCurso() {
            return this->curso;
        }

    private:
        string email;
        Desempenho desempenho;
        string curso;
};