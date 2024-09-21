#pragma once
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
#include <iostream>

using namespace std;

class Mecanico
{
private:
    ConexionBD* conexion;
    int idMecanico;
    string DniMecanico;
    string NombreMecanico;
    string ApellidoMecanico;
    string TelMecanico;
    string EmailMecanico;

public:
    // Constructores
    Mecanico(ConexionBD* con);
    Mecanico(ConexionBD* con, int id_m, const string& dni, const string& nom, const string& ape,
        const string& tel, const string& email);

    // Métodos get
    int getIdMecanico() const;
    string getDniMecanico() const;
    string getNombreMecanico() const;
    string getApellidoMecanico() const;
    string getTelMecanico() const;
    string getEmailMecanico() const;

    // Métodos set
    void setIdMecanico(int id_m);
    void setDniMecanico(const string& dni);
    void setNombreMecanico(const string& nombre);
    void setApellidoMecanico(const string& apellido);
    void setTelMecanico(const string& tel);
    void setEmailMecanico(const string& email);


    // Metodos CRUD
    void crearMecanico();
    void leerMecanico();
    void actualizarMecanico();
    void eliminarMecanico();
};


