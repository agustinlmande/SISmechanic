#include "menu.h"
#include <iostream>
#include <limits>
#include "Utilidades.h"

using namespace std;

Menu::Menu(ConexionBD* conexion) : conexion(conexion) {}

void Menu::mostrarMenuPrincipal() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "============================" << endl;
        cout << "  #####################" << endl;
        cout << "  #   SISmechanic     #" << endl;
        cout << "  #####################" << endl;
        cout << "============================" << endl;
        cout << "Sistema de Gestion de Taller" << endl;
        cout << "============================" << endl;
        cout << "       MENU PRINCIPAL     " << endl;
        cout << "============================" << endl;
        cout << "1. Gestionar Clientes" << endl;
        cout << "2. Gestionar Mecanicos" << endl;
        cout << "3. Salir" << endl;
        cout << "============================" << endl;
        opcion = capturarOpcion(1, 3);

        switch (opcion) {
        case 1:
            menuClientes();
            break;
        case 2:
            menuMecanicos();
            break;
        case 3:
            cout << "Saliendo del programa..." << endl;
            break;
        }
    } while (opcion != 3);
}

void Menu::menuClientes() {
    int opcion;
    do {
        limpiarPantalla();
        cout << "==========================" << endl;
        cout << "     GESTION DE CLIENTES  " << endl;
        cout << "==========================" << endl;
        cout << "1. Crear Cliente" << endl;
        cout << "2. Ver Clientes" << endl;
        cout << "3. Actualizar Cliente" << endl;
        cout << "4. Eliminar Cliente" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "==========================" << endl;
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
        cout << "==========================" << endl;
        cout << "    GESTION DE MECANICOS  " << endl;
        cout << "==========================" << endl;
        cout << "1. Crear Mecanico" << endl;
        cout << "2. Ver Mecanicos" << endl;
        cout << "3. Eliminar Mecanico" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << "==========================" << endl;
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