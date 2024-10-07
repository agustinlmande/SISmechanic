#include "Vehiculo.h"
#include <iostream>
#include <mysql.h>

using namespace std;

// Constructores
Vehiculo::Vehiculo(ConexionBD* con) : conexion(con), idVehiculo(0), marca(""), modelo(""), anio(0), idCliente(0) {}

Vehiculo::Vehiculo(ConexionBD* con, int id_v, const string& m, const string& mo, int a, int id_c)
    : conexion(con), idVehiculo(id_v), marca(m), modelo(mo), anio(a), idCliente(id_c) {}

// Métodos setter
void Vehiculo::setIdVehiculo(int id_v) { idVehiculo = id_v; }
void Vehiculo::setMarca(const string& m) { marca = m; }
void Vehiculo::setModelo(const string& mo) { modelo = mo; }
void Vehiculo::setAnio(int a) { anio = a; }
void Vehiculo::setIdCliente(int id_c) { idCliente = id_c; }

// Métodos getter
int Vehiculo::getIdVehiculo() const { return idVehiculo; }
string Vehiculo::getMarca() const { return marca; }
string Vehiculo::getModelo() const { return modelo; }
int Vehiculo::getAnio() const { return anio; }
int Vehiculo::getIdCliente() const { return idCliente; }

// Métodos CRUD
void Vehiculo::crearVehiculo() {
    string consulta = "INSERT INTO Vehiculo (marca, modelo, anio, idCliente) VALUES ('" +
        marca + "', '" + modelo + "', " + to_string(anio) + ", " + to_string(idCliente) + ")";
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
        cout << "ID: " << fila[0] << ", Marca: " << fila[1] << ", Modelo: " << fila[2]
            << ", Año: " << fila[3] << ", ID Cliente: " << fila[4] << endl;
    }

    mysql_free_result(resultado);
}

void Vehiculo::actualizarVehiculo() {
    // Solicitar los nuevos valores para actualizar el vehículo
    cout << "Ingrese la nueva marca del vehículo " << marca << ": ";
    cin >> marca;

    cout << "Ingrese el nuevo modelo del vehículo " << modelo << ": ";
    cin >> modelo;

    cout << "Ingrese el nuevo año del vehículo " << anio << ": ";
    cin >> anio;

    cout << "Ingrese el nuevo ID del cliente del vehículo " << idCliente << ": ";
    cin >> idCliente;

    // Crear la consulta de actualización
    string consulta = "UPDATE Vehiculo SET marca='" + marca +
        "', modelo='" + modelo +
        "', anio=" + to_string(anio) +
        ", idCliente=" + to_string(idCliente) +
        " WHERE idVehiculo=" + to_string(idVehiculo);

    // Ejecutar la consulta
    conexion->ejecutarConsulta(consulta);

    cout << "Vehículo actualizado exitosamente." << endl;
}

void Vehiculo::eliminarVehiculo() {
    string consulta = "DELETE FROM Vehiculo WHERE idVehiculo=" + to_string(idVehiculo);
    conexion->ejecutarConsulta(consulta);
}
