#pragma once
#include "Cliente.h"
#include "Mecanico.h"
#include "Utilidades.h"

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
    void menuVehiculos();

    void crearCliente();
    void verClientes();
    void actualizarCliente();
    void eliminarCliente();

    void crearMecanico();
    void verMecanicos();
    
    void eliminarMecanico();

    void crearVehiculo();
    void verVehiculos();
    void actualizarVehiculo();
    void eliminarVehiculo();

    // Utilidad para capturar una opción válida
    //int capturarOpcion(int min, int max);
};
