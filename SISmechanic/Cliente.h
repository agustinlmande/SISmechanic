#pragma once
#include "ConexionBD.h"
#include <string>
#include <vector>

using namespace std;

class Cliente {
private:
    ConexionBD* conexion;
    int idCliente;
    string dniCliente;
    string nombreCliente;
    string apellidoCliente;
    string telCliente;
    string emailCliente;
   

public:
    Cliente(ConexionBD* con);
    Cliente(ConexionBD* con, int id_c, const string& dni, const string& nom, const string& ape,
        const string& tel, const string& email);

    // Métodos set (modificar)
    void setIdCliente(int e);
    void setdniCliente(const string& d);
    void setnombreCliente(const string& n);
    void setapellidoCliente(const string& a);
    void settelCliente(const string& t);
    void setemailCliente(const string& em);


    // Métodos get (mostrar)
    int getIdCliente() const;
    string getdniCliente() const;
    string getnombreCliente() const;
    string getapellidoCliente() const;
    string gettelCliente() const;
    string getemailCliente() const;
   

    // Métodos CRUD
    void crearCliente();
    void leerClientes();
    void actualizarCliente();
    void eliminarCliente();
};