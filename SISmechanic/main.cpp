#include <iostream>
#include "ConexionBD.h"

using namespace std;

int main() {
    // Crear la conexi�n a la base de datos
    ConexionBD conexion;
    conexion.abrir_conexion();
    

    conexion.cerrar_conexion();

    return 0;
}