#include "menu.h"
#include <iostream>
#include <limits>
#include "Utilidades.h"
#include "Vehiculo.h"
#include <chrono>
#include <thread>
#include <iomanip>
#include <string>

using namespace std;

Menu::Menu(ConexionBD* conexion) : conexion(conexion) {}

void Menu::mostrarMenuPrincipal() {
    int opcion;
    do {
        limpiarPantalla();

        cout << setfill('=') << setw(30) << "=" << endl;
        cout << setfill(' ') << setw(4) << " " << "#---------------------#" << endl;
        cout << setfill(' ') << setw(4) << " " << "|     SISmechanic     |" << endl;
        cout << setfill(' ') << setw(4) << " " << "#---------------------#" << endl;
        cout << setfill('=') << setw(30) << "=" << endl;
        cout << setfill(' ') << setw(29) << "Sistema de Gestion de Taller" << endl;
        cout << setfill('=') << setw(30) << "=" << endl;
        cout << setfill(' ') << setw(23) << "MENU PRINCIPAL" << endl;
        cout << setfill('=') << setw(30) << "=" << endl;
        cout << "1. Gestionar Clientes" << endl;
        cout << "2. Gestionar Mecanicos" << endl;
        cout << "3. Gestionar Vehiculos" << endl;
        cout << "4. Salir" << endl;
        cout << setfill('=') << setw(30) << "=" << endl;
        opcion = capturarOpcion(1, 4);

        switch (opcion) {
        case 1:
            menuClientes();
            break;
        case 2:
            menuMecanicos();
            break;
        case 3:
            menuVehiculos();
            break;
        case 4:
            cout << "Saliendo del programa..." << endl;
            this_thread::sleep_for(chrono::milliseconds(500));  // Pausa breve
            limpiarPantalla();
            break;
        }
    } while (opcion != 4);
}

void Menu::menuClientes() {
    int opcion;
    do {
        limpiarPantalla();
        encabezado("Clientes");
        cout << "1. Crear Cliente" << endl;
        cout << "2. Ver Clientes" << endl;
        cout << "3. Actualizar Cliente" << endl;
        cout << "4. Eliminar Cliente" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << setfill('=') << setw(30) << "=" << endl;
        opcion = capturarOpcion(1, 5);

        switch (opcion) {
        case 1:
            crearCliente();
            break;
        case 2:
            verClientes();
            break;
        case 3:
            actualizarCliente();
            break;
        case 4:
            eliminarCliente();
            break;
        case 5:
            return;
        }
    } while (opcion != 5);
}

void Menu::menuMecanicos() {
    int opcion;
    do {
        limpiarPantalla();
        encabezado("Mecanicos");
        cout << "1. Crear Mecanico" << endl;
        cout << "2. Ver Mecanicos" << endl;
        cout << "3. Eliminar Mecanico" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << setfill('=') << setw(30) << "=" << endl;
        opcion = capturarOpcion(1, 4);

        switch (opcion) {
        case 1:
            crearMecanico();
            break;
        case 2:
            verMecanicos();
            break;
        case 3:
            eliminarMecanico();
            break;
        case 4:
            return;
        }
    } while (opcion != 4);
}

void Menu::menuVehiculos() {
    int opcion;
    do {
        limpiarPantalla();
        encabezado("Vehiculos");
        cout << "1. Crear vehiculo" << endl;
        cout << "2. Ver vehiculos" << endl;
        cout << "3. Eliminar vehiculo" << endl;
        cout << "3. Actualizar vehiculo" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << setfill('=') << setw(30) << "=" << endl;
        opcion = capturarOpcion(1, 5);

        switch (opcion) {
        case 1:
            crearVehiculo();
            break;
        case 2:
            verVehiculos();
            break;
        case 3:
            actualizarVehiculo();
            break;
        case 4:
            eliminarVehiculo();
            break;
        case 5:
            return;
        }
    } while (opcion != 4);
}

void Menu::crearCliente() {
    limpiarPantalla();
    string dni, nombre, apellido, tel, email;

    dni = capturarStringNumerico("Ingrese el DNI del cliente: ");
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout << "Ingrese el apellido del cliente: ";
    cin >> apellido;
    tel = capturarStringNumerico("Ingrese el telefono del cliente: ");
    cout << "Ingrese el email del cliente: ";
    cin >> email;

    Cliente cliente(conexion, 0, dni, nombre, apellido, tel, email);
    cliente.crearCliente();
    cout << "Cliente creado exitosamente!" << endl;

    pausa();
    limpiarPantalla();
}

void Menu::verClientes() {
    limpiarPantalla();
    Cliente cliente(conexion);
    cliente.leerClientes();

    pausa();
    limpiarPantalla();
}

void Menu::actualizarCliente() {
    limpiarPantalla();
    int id = capturarId("Ingrese el ID del cliente que desea actualizar: ");

    Cliente cliente(conexion);
    cliente.setIdCliente(id);
    cliente.actualizarCliente();
    cout << "Cliente actualizado exitosamente!" << endl;

    pausa();
    limpiarPantalla();
}

void Menu::eliminarCliente() {
    limpiarPantalla();
    int id = capturarId("Ingrese el ID del cliente que desea eliminar: ");

    Cliente cliente(conexion);
    cliente.setIdCliente(id);
    cliente.eliminarCliente();
    cout << "Cliente eliminado exitosamente!" << endl;

    pausa();
    limpiarPantalla();
}

void Menu::crearMecanico() {
    limpiarPantalla();
    string dni, nombre, apellido, tel, email;

    dni = capturarStringNumerico("Ingrese el DNI del mecanico: ");
    cout << "Ingrese el nombre del mecanico: ";
    cin >> nombre;
    cout << "Ingrese el apellido del mecanico: ";
    cin >> apellido;
    tel = capturarStringNumerico("Ingrese el telefono del mecanico: ");
    cout << "Ingrese el email del mecanico: ";
    cin >> email;

    Mecanico mecanico(conexion, 0, dni, nombre, apellido, tel, email);
    mecanico.crearMecanico();
    cout << "Mecanico creado exitosamente!" << endl;

    pausa();
    limpiarPantalla();
}

void Menu::verMecanicos() {
    limpiarPantalla();
    Mecanico mecanico(conexion);
    mecanico.leerMecanico();

    pausa();
    limpiarPantalla();
}

void Menu::eliminarMecanico() {
    limpiarPantalla();
    int id = capturarId("Ingrese el ID del mecanico que desea eliminar: ");

    Mecanico mecanico(conexion);
    mecanico.setIdMecanico(id);
    mecanico.eliminarMecanico();
    cout << "Mecanico eliminado exitosamente!" << endl;

    pausa();
    limpiarPantalla();
}

void Menu::crearVehiculo() {
    limpiarPantalla();
    string marca, modelo;
    int anio, idCliente;

    cout << "Ingrese la marca del veh�culo: ";
    cin >> marca;
    cout << "Ingrese el modelo del veh�culo: ";
    cin >> modelo;
    cout << "Ingrese a�o del veh�culo: ";
    cin >> anio;
    idCliente = capturarId("Ingrese el ID del cliente asociado: ");

    Vehiculo vehiculo(conexion, 0, marca, modelo, anio, idCliente); 
    vehiculo.crearVehiculo();
    cout << "Veh�culo creado exitosamente!" << endl;

    pausa();
    limpiarPantalla();
}

void Menu::verVehiculos() {
    limpiarPantalla();
    Vehiculo vehiculo(conexion);
    vehiculo.leerVehiculo(); 

    pausa();
    limpiarPantalla();
}

void Menu::actualizarVehiculo() {
    limpiarPantalla();
    int id = capturarId("Ingrese el ID del vehiculo que desea actualizar: ");

    Vehiculo vehiculo(conexion);
    vehiculo.setIdVehiculo(id);
    vehiculo.actualizarVehiculo();
    cout << "Vehiculo actualizado exitosamente!" << endl;

    pausa();
    limpiarPantalla();
}

void Menu::eliminarVehiculo() {
    limpiarPantalla();
    int id = capturarId("Ingrese el ID del veh�culo que desea eliminar: ");

    Vehiculo vehiculo(conexion);
    vehiculo.setIdVehiculo(id);
    vehiculo.eliminarVehiculo();
    cout << "Veh�culo eliminado exitosamente!" << endl;

    pausa();
    limpiarPantalla();
}