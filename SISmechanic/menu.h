#pragma once
#include "Cliente.h"
#include "Mecanico.h"

class Menu {
public:
    // Constructor que recibe la conexi�n a la base de datos
    Menu(ConexionBD* conexion);

    // Mostrar el men� principal
    void mostrarMenuPrincipal();

private:
    ConexionBD* conexion;  // La conexi�n a la base de datos

    // M�todos privados para las operaciones CRUD de Cliente y Mecanico
    void menuClientes();
    void menuMecanicos();

    void crearCliente();
    void verClientes();
    void actualizarCliente();
    void eliminarCliente();

    void crearMecanico();
    void verMecanicos();
    
    void eliminarMecanico();

    // Utilidad para capturar una opci�n v�lida
    //int capturarOpcion(int min, int max);
};
