#include "Utilidades.h"
#include <iostream>
#include <limits>
#include <cstdlib> // Para system("CLS")

using namespace std;

void limpiarPantalla() {
    system("CLS"); // Solo en Windows
}

void pausa() {
    cout << "Presione Enter para continuar...";
    cin.ignore();
    cin.get();
}

int capturarOpcion(int min, int max) {
    int opcion;
    while (true) {
        cin >> opcion;
        if (cin.fail() || opcion < min || opcion > max) {
            cin.clear(); // Limpia el estado del flujo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora la entrada
            cout << "Opcion no valida. Intente nuevamente: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer
            return opcion;
        }
    }
}

string capturarStringNumerico(const string& mensaje) {
    string entrada;
    bool esNumerico;
    do {
        cout << mensaje;
        cin >> entrada;
        esNumerico = true;
        for (char c : entrada) {
            if (!isdigit(c)) {
                esNumerico = false;
                cout << "Entrada no valida. Intente nuevamente." << endl;
                break;
            }
        }
    } while (!esNumerico);
    return entrada;
}

int capturarId(const string& mensaje) {
    int id;
    while (true) {
        cout << mensaje;
        cin >> id;
        if (cin.fail() || id <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "ID no valido. Intente nuevamente: ";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return id;
        }
    }
}
