#pragma once
#include "Cliente.h"
#include "Mecanico.h"

class Menu {
public:
    // Constructor que recibe la conexión a la base de datos
    Menu(ConexionBD* conexion);

    // Mostrar el menú principal
    void mostrarMenuPrincipal();

private:
    ConexionBD* conexion;  // La conexión a la base de datos

    // Métodos privados para las operaciones CRUD de Cliente y Mecanico
    void menuClientes();
    void menuMecanicos();

    void crearCliente();
    void verClientes();
    void actualizarCliente();
    void eliminarCliente();

    void crearMecanico();
    void verMecanicos();
    
    void eliminarMecanico();

    // Utilidad para capturar una opción válida
    //int capturarOpcion(int min, int max);
};
