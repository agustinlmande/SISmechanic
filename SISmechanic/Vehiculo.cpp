#include "Vehiculo.h"
#include <iostream>
#include <mysql.h>
#include "Utilidades.h"

using namespace std;

// Constructores
Vehiculo::Vehiculo(ConexionBD* con) : conexion(con), idVehiculo(0), patente(""), marca(""), modelo(""), anio(0), idCliente(0) {}

Vehiculo::Vehiculo(ConexionBD* con, int id_v, const string& p, const string& m, const string& mo, int a, int id_c)
    : conexion(con), idVehiculo(id_v), patente(p), marca(m), modelo(mo), anio(a), idCliente(id_c) {}

// Métodos setter
void Vehiculo::setIdVehiculo(int id_v) { idVehiculo = id_v; }
void Vehiculo::setPatente(const string& p) { patente = p; }
void Vehiculo::setMarca(const string& m) { marca = m; }
void Vehiculo::setModelo(const string& mo) { modelo = mo; }
void Vehiculo::setAnio(int a) { anio = a; }
void Vehiculo::setIdCliente(int id_c) { idCliente = id_c; }

// Métodos getter
int Vehiculo::getIdVehiculo() const { return idVehiculo; }
string Vehiculo::getPatente() const { return patente; }
string Vehiculo::getMarca() const { return marca; }
string Vehiculo::getModelo() const { return modelo; }
int Vehiculo::getAnio() const { return anio; }
int Vehiculo::getIdCliente() const { return idCliente; }

// Métodos CRUD
void Vehiculo::crearVehiculo() {
    string consulta = "INSERT INTO Vehiculo (patente, marca, modelo, anio, idCliente) VALUES ('" +
        patente + "', '" + marca + "', '" + modelo + "', " + to_string(anio) + ", " + to_string(idCliente) + ")";
    conexion->ejecutarConsulta(consulta);
}

void Vehiculo::leerVehiculo() {
    const char* consulta = "SELECT * FROM Vehiculo";
    if (mysql_query(conexion->getConector(), consulta)) {
        cerr << "Error al leer el vehiculo: " << mysql_error(conexion->getConector()) << endl;
        return;
    }

    MYSQL_RES* resultado = mysql_store_result(conexion->getConector());
    if (!resultado) {
        cerr << "Error al almacenar el resultado: " << mysql_error(conexion->getConector()) << endl;
        return;
    }

    MYSQL_ROW fila;
    while ((fila = mysql_fetch_row(resultado))) {
        cout << "ID: " << fila[0] << ", Patente: " << fila[1] << ", Marca: " << fila[2] << ", Modelo: " << fila[3]
            << ", Año: " << fila[4] << ", ID Cliente: " << fila[5] << endl;
    }

    mysql_free_result(resultado);
}


void Vehiculo::eliminarVehiculo() {
    string consulta = "DELETE FROM Vehiculo WHERE idVehiculo=" + to_string(idVehiculo);
    conexion->ejecutarConsulta(consulta);
}

bool Vehiculo::existeVehiculo() {
    // Crea una consulta SQL para buscar el vehículo por su patente
    string consulta = "SELECT COUNT(*) FROM Vehiculo WHERE patente = '" + patente + "'";

    // Ejecuta la consulta
    if (mysql_query(conexion->getConector(), consulta.c_str())) {
        cerr << "Error al verificar el vehiculo: " << mysql_error(conexion->getConector()) << endl;
        return false;
    }

    // Obtiene el resultado de la consulta
    MYSQL_RES* res = mysql_store_result(conexion->getConector());
    MYSQL_ROW row = mysql_fetch_row(res);

    // Convierte el resultado a entero
    int count = atoi(row[0]);
    mysql_free_result(res);

    // Devuelve true si la patente existe en la base de datos
    return count > 0;
}
