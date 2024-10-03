#include "menu.h"
#include <iostream>
#include <limits>
using namespace std;

Menu::Menu(ConexionBD* conexion) : conexion(conexion) {}

void Menu::mostrarMenuPrincipal() {
    int opcion;
    do {
        cout << "==========================" << endl;
        cout << "       MENU PRINCIPAL     " << endl;
        cout << "==========================" << endl;
        cout << "1. Gestionar Clientes" << endl;
        cout << "2. Gestionar Mecanicos" << endl;
        cout << "3. Salir" << endl;
        cout << "==========================" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion; // = capturarOpcion(1, 3);

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
        cout << "==========================" << endl;
        cout << "     GESTION DE CLIENTES  " << endl;
        cout << "==========================" << endl;
        cout << "1. Crear Cliente" << endl;
        cout << "2. Ver Clientes" << endl;
        cout << "3. Actualizar Cliente" << endl; // Nueva opción para actualizar
        cout << "4. Eliminar Cliente" << endl;
        cout << "5. Volver al menu principal" << endl; // Cambia el número de opción
        cout << "==========================" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            crearCliente();
            break;
        case 2:
            verClientes();
            break;
        case 3:
            actualizarCliente(); // Llamar al nuevo método
            break;
        case 4:
            eliminarCliente();
            break;
        case 5: // Cambia el número de opción
            return;
        }
    } while (opcion != 5); // Cambia el número de opción
}

void Menu::menuMecanicos() {
    int opcion;
    do {
        cout << "==========================" << endl;
        cout << "    GESTION DE MECANICOS  " << endl;
        cout << "==========================" << endl;
        cout << "1. Crear Mecanico" << endl;
        cout << "2. Ver Mecanicos" << endl;
        cout << "3. Eliminar Mecanico" << endl;
        cout << "4. Volver al menu principal" << endl;
        cout << "==========================" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;// = capturarOpcion(1, 4);

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
    string dni, nombre, apellido, tel, email;
    cout << "Ingrese el DNI del cliente: ";
    cin >> dni;
    cout << "Ingrese el nombre del cliente: ";
    cin >> nombre;
    cout << "Ingrese el apellido del cliente: ";
    cin >> apellido;
    cout << "Ingrese el telefono del cliente: ";
    cin >> tel;
    cout << "Ingrese el email del cliente: ";
    cin >> email;

    Cliente cliente(conexion, 0, dni, nombre, apellido, tel, email);
    cliente.crearCliente();
    cout << "Cliente creado exitosamente!" << endl;
}

void Menu::verClientes() {
    Cliente cliente(conexion);
    cliente.leerClientes();
}

void Menu::actualizarCliente() {
    int id;
    cout << "Ingrese el ID del cliente que desea actualizar: ";
    cin >> id;

    Cliente cliente(conexion);
    cliente.setIdCliente(id); // Asigna el ID al objeto cliente
    cliente.actualizarCliente(); // Llama al método de actualización en la clase Cliente
}

void Menu::eliminarCliente() {
    int id;
    cout << "Ingrese el ID del cliente que desea eliminar: ";
    cin >> id;

    Cliente cliente(conexion);
    cliente.setIdCliente(id);
    cliente.eliminarCliente();
    cout << "Cliente eliminado exitosamente!" << endl;
}

void Menu::crearMecanico() {
    string dni, nombre, apellido, tel, email;
    cout << "Ingrese el DNI del mecanico: ";
    cin >> dni;
    cout << "Ingrese el nombre del mecanico: ";
    cin >> nombre;
    cout << "Ingrese el apellido del mecanico: ";
    cin >> apellido;
    cout << "Ingrese el telefono del mecanico: ";
    cin >> tel;
    cout << "Ingrese el email del mecanico: ";
    cin >> email;

    Mecanico mecanico(conexion, 0, dni, nombre, apellido, tel, email);
    mecanico.crearMecanico();
    cout << "Mecanico creado exitosamente!" << endl;
}

void Menu::verMecanicos() {
    Mecanico mecanico(conexion);
    mecanico.leerMecanico();
}

void Menu::eliminarMecanico() {
    int id;
    cout << "Ingrese el ID del mecanico que desea eliminar: ";
    cin >> id;

    Mecanico mecanico(conexion);
    mecanico.setIdMecanico(id);
    mecanico.eliminarMecanico();
    cout << "Mecanico eliminado exitosamente!" << endl;
}


