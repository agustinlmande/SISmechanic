#pragma once
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include <iostream>

using namespace std;

class Vehiculo {
private:
    ConexionBD* conexion;
    int idVehiculo;
    string patente;
    string marca;
    string modelo;
    int anio;
    int idCliente;

public:
    // Constructores
    Vehiculo(ConexionBD* con);
    Vehiculo(ConexionBD* con, int id_v, const string& p, const string& m, const string& mo, int a, int id_c);

    // Métodos get
    int getIdVehiculo() const;
    string getPatente() const;
    string getMarca() const;
    string getModelo() const;
    int getAnio() const;
    int getIdCliente() const;

    // Métodos set
    void setIdVehiculo(int id_v);
    void setPatente(const string& p);
    void setMarca(const string& m);
    void setModelo(const string& mo);
    void setAnio(int a);
    void setIdCliente(int id_c);

    // Métodos CRUD
    void crearVehiculo();
    void leerVehiculo();
    void actualizarVehiculo();
    void eliminarVehiculo();
};
