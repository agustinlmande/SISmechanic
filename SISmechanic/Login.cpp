#include "Login.h"
#include "Utilidades.h"
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

// Función para mostrar la barra de progreso
void mostrarBarraProgreso() {
    cout << setfill('=') << setw(30) << "=" << endl;
    cout << "\nVerificando credenciales";
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::milliseconds(500));  // Pausa de 500ms
        cout << "." << flush;
    }
    cout << endl;
}

void mostrarPantallaLogin() {
    limpiarPantalla();

    string username = "admin";
    string password = "********";

    cout << setfill('=') << setw(30) << "=" << endl;
    cout << setfill(' ') << setw(4) << " " << "#---------------------#" << endl;
    cout << setfill(' ') << setw(4) << " " << "|     SISmechanic     |" << endl;
    cout << setfill(' ') << setw(4) << " " << "#---------------------#" << endl;
    cout << setfill('=') << setw(30) << "=" << endl;
    cout << setfill(' ') << setw(29) << "Sistema de Gestion de Taller" << endl;
    cout << setfill('=') << setw(30) << "=" << endl;
    cout << "Usuario: " << username << endl;
    cout << "Contrasena: " ;
    

    for (char c : password) {
        this_thread::sleep_for(chrono::milliseconds(300));  // Pausa más rápida para dar fluidez
        cout << c << flush;
    }

    this_thread::sleep_for(chrono::milliseconds(500));  // Simula el "Enter"
    cout << endl;

    // Mostrar barra de progreso
    mostrarBarraProgreso();

    // Limpiar la pantalla antes de mostrar el menú (usando tu función limpiarpantalla)
    this_thread::sleep_for(chrono::milliseconds(500));  // Pausa breve
    limpiarPantalla();  
}
