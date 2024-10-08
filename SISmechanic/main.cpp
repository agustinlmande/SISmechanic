#include <iostream>
#include "Login.h"
#include "menu.h"
#include "ConexionBD.h"

using namespace std;

int main() {
    ConexionBD conexion;
    conexion.abrir_conexion();
    
    mostrarPantallaLogin();
    Menu menu(&conexion);
    menu.mostrarMenuPrincipal();

    conexion.cerrar_conexion();
    return 0;
}
