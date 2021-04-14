#include "../Loader.h"

using namespace std;

class IMain {
    public:
        static const string OPCAO_LISTAR_TODAS;
        static const string OPCAO_INFORMAR_DADOS;
        static const string OPCAO_CONSULTAR_DADOS;
        static const string OPCAO_CONSULTAR_ESTATISTICAS;
        static const string OPCAO_SAIR_SISTEMA;
        static const string OPCAO_EXTRA;

        static const int MILLISECONDS_SLEEP;

        virtual void inicializar() = 0;
        virtual void getMenu() = 0;
        virtual void opcaoListarTodas() = 0;
        virtual void opcaoInformarDados() = 0;
        virtual void opcaoConsultarDados() = 0;
        virtual void opcaoConsultarEstatisticas() = 0;
        virtual void opcaoSairSistema() = 0;
        virtual void opcaoInicializarTurmaTeste() = 0;
        virtual void setOpcao(string opcao) = 0;
        virtual string getOpcao() = 0;
};
const string IMain::OPCAO_LISTAR_TODAS = "OP1";
const string IMain::OPCAO_INFORMAR_DADOS = "OP2";
const string IMain::OPCAO_CONSULTAR_DADOS = "OP3";
const string IMain::OPCAO_CONSULTAR_ESTATISTICAS = "OP4";
const string IMain::OPCAO_SAIR_SISTEMA = "OP5";
const string IMain::OPCAO_EXTRA = "OP6";

const int IMain::MILLISECONDS_SLEEP = 500;