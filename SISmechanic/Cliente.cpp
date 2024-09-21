#include "Cliente.h"
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
    string consulta = "UPDATE cliente SET dniCliente='" + dniCliente + "', nombreCliente='" + nombreCliente + "', apellidoCliente='" + apellidoCliente +
        "', telCliente='" + telCliente + "', emailCliente='" + emailCliente + "' WHERE idCliente=" + to_string(idCliente);
    conexion->ejecutarConsulta(consulta);
}

void Cliente::eliminarCliente() {
    string consulta = "DELETE FROM cliente WHERE id_Cliente=" + to_string(idCliente);
    conexion->ejecutarConsulta(consulta);
}
