#include "Cliente.h"
#include "Utilidades.h"
#include <iostream>

using namespace std;

int idCliente;
string dniCliente;
string nombreCliente;
string apellidoCliente;
string telCliente;
string emailCliente;

//Constructores
Cliente::Cliente(ConexionBD* con) : conexion(con), idCliente(0), dniCliente(""), nombreCliente(""), apellidoCliente(""),
telCliente(""), emailCliente("") {}

Cliente::Cliente(ConexionBD* con, int id_c, const string& dni, const string& nom, const string& ape,
    const string& tel, const string& email)
    : conexion(con), idCliente(id_c), dniCliente(dni), nombreCliente(nom), apellidoCliente(ape), telCliente(tel),
    emailCliente(email) {}

//Metodos setter
void Cliente::setIdCliente(int e) { idCliente = e; }
void Cliente::setdniCliente(const string& d) { dniCliente = d; }
void Cliente::setnombreCliente(const string& n) { nombreCliente = n; }
void Cliente::setapellidoCliente(const string& a) { apellidoCliente = a; }
void Cliente::settelCliente(const string& t) {telCliente = t; }
void Cliente::setemailCliente(const string& em) { emailCliente = em; }


//Metodos getter
int Cliente::getIdCliente() const { return idCliente; }
string Cliente::getdniCliente() const { return dniCliente; }
string Cliente::getnombreCliente() const { return nombreCliente; }
string Cliente::getapellidoCliente() const { return apellidoCliente; }
string Cliente::gettelCliente() const { return telCliente; }
string Cliente::getemailCliente() const { return emailCliente; }

//METODOS CRUD
void Cliente::crearCliente() {
    string consulta = "INSERT INTO cliente (dniCliente, nombreCliente, apellidoCliente, telCliente, emailCliente) VALUES ('" +
        dniCliente + "', '" + nombreCliente + "', '" + apellidoCliente + "', '" + telCliente + "', '" + emailCliente + "')";
    conexion->ejecutarConsulta(consulta);
}

void Cliente::leerClientes() {
    const char* consulta = "SELECT * FROM cliente";
    if (mysql_query(conexion->getConector(), consulta)) {
        cerr << "Error al leer los clientes: " << mysql_error(conexion->getConector()) << endl;
        return;
    }

    MYSQL_RES* resultado = mysql_store_result(conexion->getConector());
    if (!resultado) {
        cerr << "Error al almacenar el resultado: " << mysql_error(conexion->getConector()) << endl;
        return;
    }

    int numCampos = mysql_num_fields(resultado);
    MYSQL_ROW fila;
    while ((fila = mysql_fetch_row(resultado))) {
        for (int i = 0; i < numCampos; i++) {
            cout << fila[i] << " ";
        }
        cout << endl;
    }

    mysql_free_result(resultado);
}



void Cliente::actualizarCliente() {
    // Mostrar clientes disponibles (si tienes una función para esto)
    // verClientes(); // Si tienes una función similar a verVehiculos()

    // Solicitar DNI y verificar si existe
    string dni;
    bool dniValido = false;

    while (!dniValido) {
        dni = capturarDni("Ingrese el DNI del cliente que desea actualizar: ");
        setdniCliente(dni);

        if (existeCliente()) {  // Verificar si el cliente existe en la base de datos
            dniValido = true;
        }
        else {
            cout << "El DNI ingresado no existe. Por favor, intente de nuevo." << endl;
        }
    }

    // Confirmar actualización
    cout << "Confirma la actualizacion del cliente: ";
    char confirmacion = capturarConfirmacion();

    if (confirmacion != 's') {
        cout << "Operacion cancelada." << endl;
        pausa();
        limpiarPantalla();
        return;
    }

    // Variables para almacenar los nuevos valores
    bool actualizarDni = false, actualizarNombre = false, actualizarApellido = false, actualizarTelefono = false, actualizarEmail = false;

    string nuevoDni, nuevoNombre, nuevoApellido, nuevoTelefono, nuevoEmail;
    bool continuar = true;

    while (continuar) {
        limpiarPantalla();
        cout << "Seleccione el campo que desea actualizar: " << endl;
        cout << "1. DNI" << endl;
        cout << "2. Nombre" << endl;
        cout << "3. Apellido" << endl;
        cout << "4. Telefono" << endl;
        cout << "5. Email" << endl;
        cout << "6. Guardar cambios y salir" << endl;
        cout << "7. Cancelar" << endl;

        int opcion = capturarId("Ingrese el numero de la opcion: ");
        switch (opcion) {
        case 1: {
            nuevoDni = capturarDni("Ingrese el nuevo DNI: ");
            actualizarDni = true;
            break;
        }
        case 2: {
            cout << "Ingrese el nuevo nombre: ";
            cin >> nuevoNombre;
            actualizarNombre = true;
            break;
        }
        case 3: {
            cout << "Ingrese el nuevo apellido: ";
            cin >> nuevoApellido;
            actualizarApellido = true;
            break;
        }
        case 4: {
            cout << "Ingrese el nuevo telefono: ";
            cin >> nuevoTelefono;
            actualizarTelefono = true;
            break;
        }
        case 5: {
            cout << "Ingrese el nuevo email: ";
            cin >> nuevoEmail;
            actualizarEmail = true;
            break;
        }
        case 6: {
            continuar = false;  // Salir y guardar cambios
            break;
        }
        case 7: {
            cout << "Operacion cancelada." << endl;
            pausa();
            limpiarPantalla();
            return;
        }
        default:
            cout << "Opcion no valida, intente de nuevo." << endl;
            pausa();
            continue;
        }
    }

    // Crear la consulta de actualización solo con los campos seleccionados
    string consulta = "UPDATE cliente SET ";
    bool primeraCondicion = true;

    if (actualizarDni) {
        consulta += "dniCliente='" + nuevoDni + "'";
        primeraCondicion = false;
    }
    if (actualizarNombre) {
        if (!primeraCondicion) consulta += ", ";
        consulta += "nombreCliente='" + nuevoNombre + "'";
        primeraCondicion = false;
    }
    if (actualizarApellido) {
        if (!primeraCondicion) consulta += ", ";
        consulta += "apellidoCliente='" + nuevoApellido + "'";
        primeraCondicion = false;
    }
    if (actualizarTelefono) {
        if (!primeraCondicion) consulta += ", ";
        consulta += "telCliente='" + nuevoTelefono + "'";
        primeraCondicion = false;
    }
    if (actualizarEmail) {
        if (!primeraCondicion) consulta += ", ";
        consulta += "emailCliente='" + nuevoEmail + "'";
    }

    consulta += " WHERE dniCliente='" + dni + "'";

    // Ejecutar la consulta
    conexion->ejecutarConsulta(consulta);

    cout << "Cliente actualizado exitosamente." << endl;

    pausa();
    limpiarPantalla();
}



void Cliente::eliminarCliente() {
    string consulta = "DELETE FROM cliente WHERE idCliente=" + to_string(idCliente);
    conexion->ejecutarConsulta(consulta);
}

// Método para verificar si el cliente existe en la base de datos
bool Cliente::existeCliente() {
    string consulta = "SELECT COUNT(*) FROM Cliente WHERE dniCliente = '" + dniCliente + "'";
    if (mysql_query(conexion->getConector(), consulta.c_str())) {
        cerr << "Error al verificar el cliente: " << mysql_error(conexion->getConector()) << endl;
        return false;
    }

    MYSQL_RES* res = mysql_store_result(conexion->getConector());
    MYSQL_ROW row = mysql_fetch_row(res);
    int count = atoi(row[0]);
    mysql_free_result(res);

    return count > 0;  // Devuelve true si el cliente existe
}