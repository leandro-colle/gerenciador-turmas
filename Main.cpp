#include "Loader.h"

using namespace std;

class Main: public IMain {

    public:
        void inicializar() {
            this->getMenu();
        }

        void getMenu() {
            string opcao = "";
            do {
                std::this_thread::sleep_for(std::chrono::milliseconds(this->MILLISECONDS_SLEEP));
                IO::clearScreen();
                cout << "Escolha uma das opções a seguir:" << endl;
                cout << "1) Listar todas as turmas" << endl;
                cout << "2) Informar dados de uma turma" << endl;
                cout << "3) Consultar os dados de uma turma" << endl;
                cout << "4) Consultar estatísticas gerais" << endl;
                cout << "5) Sair do sistema" << endl;
                cout << "6) EXTRA: Inicializar turma teste" << endl;

                this->setOpcao(IO::getLineInput());
                opcao = this->getOpcao();

                if (opcao == this->OPCAO_LISTAR_TODAS) {
                    this->opcaoListarTodas();
                } else if (opcao == this->OPCAO_INFORMAR_DADOS) {
                    this->opcaoInformarDados();
                } else if (opcao == this->OPCAO_CONSULTAR_DADOS) {
                    this->opcaoConsultarDados();
                } else if (opcao == this->OPCAO_CONSULTAR_ESTATISTICAS) {
                    this->opcaoConsultarEstatisticas();
                } else if (opcao == this->OPCAO_SAIR_SISTEMA) {
                    this->opcaoSairSistema();
                } else if (opcao == this->OPCAO_EXTRA) {
                    this->opcaoInicializarTurmaTeste();
                }
            } while (opcao != this->OPCAO_SAIR_SISTEMA);
        }

        void opcaoListarTodas() {
            IO::clearScreen();

            vector<Turma> ts = this->getTurmas();

            if (ts.size() == 0) {
                cout << "Turmas não encontradas" << endl << endl;
            } else {
                TurmaIterator tIterator = TurmaIterator(ts);
                tIterator.itarate();
            }

            IO::pressKey();
        }

        void opcaoInformarDados() {
            IO::clearScreen();

            Turma turma = Turma();
            Professor professor = Professor();
            bool repeatBuffer;

            cout << "Digite o código da turma" << endl;
            turma.setCodigo(IO::getLineInput());
            cout << endl;
            cout << "Digite o nome da disciplina" << endl;
            turma.setDisciplina(IO::getLineInput());
            cout << endl;
            cout << "Digite o código do professor" << endl;
            professor.setCodigo(IO::getLineInput());
            cout << endl;
            cout << "Digite o nome do professor" << endl;
            professor.setNome(IO::getLineInput());
            cout << endl;
            turma.setProfessor(professor);

            string novoAluno;
            do {
                Aluno aluno = Aluno();
                Desempenho desempenho = Desempenho();

                cout << "Digite o código do aluno" << endl;
                aluno.setCodigo(IO::getLineInput());
                cout << endl;
                cout << "Digite o nome do aluno" << endl;
                aluno.setNome(IO::getLineInput());
                cout << endl;
                cout << "Digite o e-mail do aluno" << endl;
                aluno.setEmail(IO::getLineInput());
                cout << endl;
                desempenho = this->setNotaDesempenho(1, desempenho);
                cout << endl;
                desempenho = this->setNotaDesempenho(2, desempenho);
                cout << endl;
                desempenho = this->setNotaDesempenho(3, desempenho);
                cout << endl;
                aluno.setDesempenho(desempenho);
                turma.setAluno(aluno);

                if (turma.getAlunos().size() == turma.QUANTIDADE_MAXIMA_ALUNOS) {
                    IO::clearScreen();
                    novoAluno = 'n';
                    cout << "A sala lotou." << endl << endl;
                    IO::pressKey();
                } else {
                    cout << "Deseja adicionar mais alunos a turma? S/n" << endl << endl;
                    novoAluno = IO::getLineInput();
                    if (novoAluno == "s" || novoAluno == "S") {
                        IO::clearScreen();
                    }
                }
            } while (novoAluno == "s" || novoAluno == "S");
            this->setTurma(turma);
        }

        void opcaoConsultarDados() {
            IO::clearScreen();

            cout << "Digite o código da turma" << endl;
            string codigo = IO::getLineInput();
            Turma turma = this->getTurma(codigo);

            IO::clearScreen();

            if (turma.getCodigo() == "") {
                cout << "Turma não encontrada" << endl << endl;
            } else {
                vector<Turma> ts = {turma};
                TurmaIterator tIterator = TurmaIterator(ts);
                tIterator.itarateDetails();
            }

            IO::pressKey();
        }

        void opcaoConsultarEstatisticas() {
            IO::clearScreen();

            vector<Turma> ts = this->getTurmas();

            if (ts.size() == 0) {
                cout << "Turmas não encontradas" << endl << endl;
            } else {
                TurmaIterator tIterator = TurmaIterator(ts);
                tIterator.iterateStatistics();
            }

            IO::pressKey();
        }

        void opcaoSairSistema() {
            cout << "Deseja realmente sair? S/n" << endl;
            string sair = IO::getLineInput();
            if (sair == "n" || sair == "N") {
                this->getMenu();
            }
        }

        void opcaoInicializarTurmaTeste() {
            this->inicializarTurmaTeste();
            cout << "Turma teste inicializada." << endl;
        }

        void inicializarTurmaTeste() {
            Professor professor = Professor("P01", "Alexandre");
            Turma turma = Turma("T01", "Projeto e Arquitetura de Software", professor);

            turma.setAluno(Aluno("A01", "André", "andre@ucs.br", Desempenho({{1, 10.0}, {2, 10.0}, {3, 10.0}})));
            turma.setAluno(Aluno("A02", "Jean", "jean@ucs.br", Desempenho({{1, 6.0}, {2, 8.9}, {3, 6.0}})));
            turma.setAluno(Aluno("A03", "Jonas", "jonas@ucs.br", Desempenho({{1, 10.0}, {2, 10.0}, {3, 10.0}})));
            turma.setAluno(Aluno("A04", "Laura", "laura@ucs.br", Desempenho({{1, 10.0}, {2, 10.0}, {3, 10.0}})));
            turma.setAluno(Aluno("A05", "Leandro", "leandro@ucs.br", Desempenho({{1, 10.0}, {2, 10.0}, {3, 10.0}})));
            turma.setAluno(Aluno("A06", "Maria", "maria@ucs.br", Desempenho({{1, 10.0}, {2, 10.0}, {3, 10.0}})));
            turma.setAluno(Aluno("A07", "Nataniel", "nataniel@ucs.br", Desempenho({{1, 10.0}, {2, 10.0}, {3, 10.0}})));
            turma.setAluno(Aluno("A08", "Paulo", "paulo@ucs.br", Desempenho({{1, 10.0}, {2, 10.0}, {3, 10.0}})));

            this->setTurma(turma);
        }

        void setOpcao(string opcao) {
            opcao = "OP" + opcao;
            if (
                opcao != this->OPCAO_LISTAR_TODAS &&
                opcao != this->OPCAO_INFORMAR_DADOS &&
                opcao != this->OPCAO_CONSULTAR_DADOS &&
                opcao != this->OPCAO_CONSULTAR_ESTATISTICAS &&
                opcao != this->OPCAO_SAIR_SISTEMA &&
                opcao != this->OPCAO_EXTRA
            ) {
                cout << "Opção inválida!" << endl;
                this->opcao = "";
            } else {
                this->opcao = opcao;
            }
        }

        string getOpcao() {
            return this->opcao;
        }

        void setTurma(Turma turma) {
            this->turmas.push_back(turma);
        }

        Turma getTurma(string codigo) {
            for (Turma turma: this->turmas) {
                if (turma.getCodigo().compare(codigo) == 0) {
                    return turma;
                }
            }
            return Turma();
        }

        vector<Turma> getTurmas() {
            return this->turmas;
        }

        Desempenho setNotaDesempenho(int nota, Desempenho desempenho) {
            bool repeatBuffer;
            do {
                repeatBuffer = false;
                try {
                    cout << "Digite a nota " << nota << " do aluno" << endl;
                    desempenho.setNota(nota, IO::getFloatInput());
                } catch (int) {
                    repeatBuffer = true;
                    cout << "Nota inválida" << endl;
                    std::this_thread::sleep_for(std::chrono::milliseconds(this->MILLISECONDS_SLEEP));
                    IO::clearScreen();
                }
            } while (repeatBuffer);
            return desempenho;
        }

    private:
        string opcao = "";
        vector<Turma> turmas;

};