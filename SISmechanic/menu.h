#pragma once
#include "Cliente.h"
#include "Mecanico.h"
#include "Utilidades.h"

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

    // Utilidad para capturar una opci�n v�lida
    //int capturarOpcion(int min, int max);
};
