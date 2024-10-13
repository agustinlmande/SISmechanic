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
            pausa();

            limpiarPantalla();
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
        cout << "4. Actualizar Mecanico" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << setfill('=') << setw(30) << "=" << endl;
        opcion = capturarOpcion(1, 5);

        switch (opcion) {
        case 1:
            crearMecanico();
            break;
        case 2:
            verMecanicos();
            pausa();
            limpiarPantalla();
            break;
        case 3:
            eliminarMecanico();
            break;
        case 4:
            actualizarMecanico();
            break;
        case 5:
            return;
        }
    } while (opcion != 5);
}

void Menu::menuVehiculos() {
    int opcion;
    do {
        limpiarPantalla();
        encabezado("Vehiculos");
        cout << "1. Crear vehiculo" << endl;
        cout << "2. Ver vehiculos" << endl;
        cout << "3. Eliminar vehiculo" << endl;
        cout << "4. Actualizar vehiculo" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << setfill('=') << setw(30) << "=" << endl;
        opcion = capturarOpcion(1, 5);

        switch (opcion) {
        case 1:
            crearVehiculo();
            break;
        case 2:
            verVehiculos();
            pausa();
            limpiarPantalla();
            break;
        case 3:
            eliminarVehiculo();
            break;
        case 4:
            actualizarVehiculo();
            break;
        case 5:
            return;
        }
    } while (opcion != 5);
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

    cout << "Confirma la creacion del cliente ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion == 's') {
        Cliente cliente(conexion, 0, dni, nombre, apellido, tel, email);
        cliente.crearCliente();
        cout << "Cliente creado exitosamente!" << endl;
    }
    else {
        cout << "Operacion cancelada." << endl;
    }

    pausa();
    limpiarPantalla();
}

void Menu::verClientes() {
    limpiarPantalla();
    Cliente cliente(conexion);
    cliente.leerClientes();

    //pausa();

    //limpiarPantalla();
    
}

void Menu::actualizarCliente() {
    limpiarPantalla();
    
    verClientes();

    string dni = capturarDni("Ingrese el DNI del cliente que desea actualizar: ");

    Cliente cliente(conexion);
    cliente.setdniCliente(dni);

    cout << "Confirma la actualizacion del cliente ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion == 's') {
        cliente.actualizarCliente();
        cout << "Cliente actualizado exitosamente!" << endl;
    }
    else {
        cout << "Operacion cancelada." << endl;
    }

    pausa();
    limpiarPantalla();
}


void Menu::eliminarCliente() {
    limpiarPantalla();

    verClientes();

    string dni = capturarDni("Ingrese el DNI del cliente que desea eliminar: ");

    Cliente cliente(conexion);
    cliente.setdniCliente(dni);

    cout << "Confirma la eliminacion del cliente ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion == 's') {
        cliente.eliminarCliente();
        cout << "Cliente eliminado exitosamente!" << endl;
    }
    else {
        cout << "Operacion cancelada." << endl;
    }

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

    cout << "Confirma la creacion del mecanico ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion == 's') {
        Mecanico mecanico(conexion, 0, dni, nombre, apellido, tel, email);
        mecanico.crearMecanico();
        cout << "Mecanico creado exitosamente!" << endl;
    }
    else {
        cout << "Operacion cancelada." << endl;
    }

    pausa();
    limpiarPantalla();
}

void Menu::verMecanicos() {
    limpiarPantalla();
    Mecanico mecanico(conexion);
    mecanico.leerMecanico();

    
}

void Menu::actualizarMecanico() {
    limpiarPantalla();

    verMecanicos();

    int id = capturarId("Ingrese el ID del mecanico que desea actualizar: ");

    Mecanico mecanico(conexion);
    mecanico.setIdMecanico(id);

    cout << "Confirma la actualizacion del mecanico ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion == 's') {
        mecanico.actualizarMecanico();
        cout << "Mecanico actualizado exitosamente!" << endl;
    }
    else {
        cout << "Operacion cancelada." << endl;
    }

    pausa();
    limpiarPantalla();
}


void Menu::eliminarMecanico() {
    limpiarPantalla();

    verMecanicos();

    string dni = capturarDni("Ingrese el ID del mecanico que desea eliminar: ");

    Mecanico mecanico(conexion);
    mecanico.setDniMecanico(dni);

    cout << "Confirma la eliminacion del mecanico ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion == 's') {
        mecanico.eliminarMecanico();
        cout << "Mecanico eliminado exitosamente!" << endl;
    }
    else {
        cout << "Operacion cancelada." << endl;
    }

    pausa();
    limpiarPantalla();
}


void Menu::crearVehiculo() {
    limpiarPantalla();
    string patente, marca, modelo;
    int anio, idCliente;

    cout << "Ingrese la patente del vehiculo: ";
    cin >> patente;
    cout << "Ingrese la marca del vehiculo: ";
    cin >> marca;
    cout << "Ingrese el modelo del vehiculo: ";
    cin >> modelo;
    cout << "Ingrese a�o del vehiculo: ";
    cin >> anio;
    idCliente = capturarId("Ingrese el ID del cliente asociado: ");

    cout << "Confirma la creacion del vehiculo ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion == 's') {
        Vehiculo vehiculo(conexion, 0,patente, marca, modelo, anio, idCliente);
        vehiculo.crearVehiculo();
        cout << "Vehiculo creado exitosamente!" << endl;
    }
    else {
        cout << "Operacion cancelada." << endl;
    }

    pausa();
    limpiarPantalla();
}



void Menu::verVehiculos() {
    limpiarPantalla();
    Vehiculo vehiculo(conexion);
    vehiculo.leerVehiculo(); 

    
}

void Menu::actualizarVehiculo() {
    limpiarPantalla();

    verVehiculos();  // Muestra los veh�culos disponibles

    Vehiculo vehiculo(conexion);  // Crea un objeto Vehiculo

    int id;
    bool idValido = false;

    // Bucle para seguir solicitando un ID v�lido
    while (!idValido) {
        id = capturarId("Ingrese el ID del vehiculo que desea actualizar: ");
        vehiculo.setIdVehiculo(id);

        // Verifica si el veh�culo existe
        if (vehiculo.existeVehiculo()) {
            idValido = true;  // Si existe, rompe el bucle
        }
        else {
            cout << "El ID del vehiculo ingresado no existe. Por favor, intente de nuevo." << endl;
        }
    }

    // Confirmar actualizaci�n
    cout << "Confirma la actualizacion del vehiculo. ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion == 's') {
        vehiculo.actualizarVehiculo();  // Llama al m�todo para actualizar el veh�culo
        cout << "Vehiculo actualizado exitosamente!" << endl;
    }
    else {
        cout << "Operacion cancelada." << endl;
    }

    pausa();
    limpiarPantalla();
}


void Menu::eliminarVehiculo() {
    limpiarPantalla();

    verVehiculos();  // Muestra los veh�culos disponibles

    Vehiculo vehiculo(conexion);  // Crea un objeto Vehiculo
    string patente;

    // Bucle para seguir solicitando una patente v�lida y existente
    while (true) {
        patente = capturarPatente("Ingrese la Patente del vehiculo que desea eliminar: ");
        vehiculo.setPatente(patente);

        // Verifica si el veh�culo con esa patente existe
        if (vehiculo.existeVehiculo()) {
            break;  // Si existe, sale del bucle
        }
        else {
            cout << "La patente ingresada no corresponde a ning�n veh�culo. Por favor, intente de nuevo." << endl;
        }
    }

    // Confirmar eliminaci�n
    cout << "Confirma la eliminacion del vehiculo.  ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion == 's') {
        vehiculo.eliminarVehiculo();  // Llama al m�todo para eliminar el veh�culo
        cout << "Vehiculo eliminado exitosamente!" << endl;
    }
    else {
        cout << "Operacion cancelada." << endl;
    }

    pausa();
    limpiarPantalla();
}


