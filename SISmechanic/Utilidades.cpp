#include "Utilidades.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib> // Para system("CLS")
#include <string>

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
        cout << "Selecciona una opción (" << min << " - " << max << "): ";
        cin >> opcion;

        // Verifica si la entrada es un número válido y dentro del rango
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora hasta el final de la línea
            cout << "Opción inválida. Intenta nuevamente." << endl;
        }
        else if (opcion < min || opcion > max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
            cout << "Opción fuera de rango. Intenta nuevamente." << endl;
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
            return opcion; // Retorna la opción válida
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

void encabezado(const std::string& nombreGestion) {
    cout << setfill('=') << setw(30) << "=" << endl;
    cout << setfill(' ') << setw(4) << " " << "#---------------------#" << endl;
    cout << setfill(' ') << setw(4) << " " << "|     SISmechanic     |" << endl;
    cout << setfill(' ') << setw(4) << " " << "#---------------------#" << endl;
    cout << setfill('=') << setw(30) << "=" << endl;
    cout << setfill(' ') << setw(11) << "Gestion de " << nombreGestion << endl;
    cout << setfill('=') << setw(30) << "=" << endl;
}