#include "../Loader.h"

using namespace std;

class IO {

    public:
        static void pressKey() {
            cout << "Pressione enter para voltar ao menu principal..." << endl;
            cin.get();
        }

        static string getLineInput() {
            string buffer;
            getline(cin, buffer);
            return buffer;
        }

        static float getFloatInput() {
            float buffer;
            cin >> buffer;
            if (cin.fail()) {
                IO::clearScreen();
                cout << "Erro: valor inserido tem formato inválido." << endl;
                exit(1);
            }
            cin.ignore(256, '\n');
            return buffer;
        }

        static void clearScreen() {
            system("clear||cls");
        }
};