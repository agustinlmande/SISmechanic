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
    cout << "Presione dos veces Enter para continuar...";
    cin.ignore();
    cin.get();
}

int capturarOpcion(int min, int max) {
    int opcion;

    while (true) {
        cout << "Selecciona una opcion (" << min << " - " << max << "): ";
        cin >> opcion;

        // Verifica si la entrada es un número válido y dentro del rango
        if (cin.fail()) {
            cin.clear(); // Limpia el estado de error
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora hasta el final de la línea
            cout << "Opcion invalida. Intenta nuevamente." << endl;
        }
        else if (opcion < min || opcion > max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora el resto de la línea
            cout << "Opcion fuera de rango. Intenta nuevamente." << endl;
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

string capturarDni(const string& mensaje) {
    string dni;
    while (true) {
        cout << mensaje;
        getline(cin, dni);

        // Verifica que el DNI no esté vacío
        if (dni.empty()) {
            cout << "DNI no valido. Intente nuevamente: ";
            continue;
        }

        // Verifica que el DNI solo contenga letras o números
        bool valido = true;
        for (char c : dni) {
            if (!isalnum(c)) {
                valido = false;
                break;
            }
        }

        if (!valido) {
            cout << "DNI no valido. Intente nuevamente: ";
        }
        else {
            return dni;
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

// Verifica si la entrada es válida y dentro del rango por s o n para confirmar diferentes funciones del CRUD
char capturarConfirmacion() {
    char respuesta;
    do {
        cout << "Desea continuar? (S/N): ";
        cin >> respuesta;
        respuesta = tolower(respuesta);  // Convierte a minúscula para comparar fácilmente
        if (respuesta != 's' && respuesta != 'n') {
            cout << "Entrada invalida. Por favor, ingrese 'S' o 'N'." << endl;
        }
    } while (respuesta != 's' && respuesta != 'n');

    return respuesta;
}
