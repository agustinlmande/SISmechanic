#include "Mecanico.h"
#include <iostream>
#include <mysql.h>

using namespace std;

// Constructores
Mecanico::Mecanico(ConexionBD* con) : conexion(con), idMecanico(0), DniMecanico(""), NombreMecanico(""),
ApellidoMecanico(""), TelMecanico(""), EmailMecanico("") {}

Mecanico::Mecanico(ConexionBD* con, int id_m, const string& dni, const string& nom,
    const string& ape, const string& tel, const string& email)
    : conexion(con), idMecanico(id_m), DniMecanico(dni), NombreMecanico(nom),
    ApellidoMecanico(ape), TelMecanico(tel), EmailMecanico(email) {}

// Métodos setter
void Mecanico::setIdMecanico(int id_m) { idMecanico = id_m; }
void Mecanico::setDniMecanico(const string& dni) { DniMecanico = dni; }
void Mecanico::setNombreMecanico(const string& nombre) { NombreMecanico = nombre; }
void Mecanico::setApellidoMecanico(const string& apellido) { ApellidoMecanico = apellido; }
void Mecanico::setTelMecanico(const string& tel) { TelMecanico = tel; }
void Mecanico::setEmailMecanico(const string& email) { EmailMecanico = email; }

// Métodos getter
int Mecanico::getIdMecanico() const { return idMecanico; }
string Mecanico::getDniMecanico() const { return DniMecanico; }
string Mecanico::getNombreMecanico() const { return NombreMecanico; }
string Mecanico::getApellidoMecanico() const { return ApellidoMecanico; }
string Mecanico::getTelMecanico() const { return TelMecanico; }
string Mecanico::getEmailMecanico() const { return EmailMecanico; }

// Métodos CRUD
void Mecanico::crearMecanico() {
    string consulta = "INSERT INTO Mecanico (DniMecanico, NombreMecanico, ApellidoMecanico, TelMecanico, EmailMecanico) VALUES ('" +
        DniMecanico + "', '" + NombreMecanico + "', '" + ApellidoMecanico + "', '" + TelMecanico + "', '" + EmailMecanico + "')";
    conexion->ejecutarConsulta(consulta);
}

void Mecanico::leerMecanico() {
    const char* consulta = "SELECT * FROM mecanico";
    if (mysql_query(conexion->getConector(), consulta)) {
        cerr << "Error al leer el mecanico: " << mysql_error(conexion->getConector()) << endl;
        return;
    }

    MYSQL_RES* resultado = mysql_store_result(conexion->getConector());
    if (!resultado) {
        cerr << "Error al almacenar el resultado: " << mysql_error(conexion->getConector()) << endl;
        return;
    }

    MYSQL_ROW fila;
    while ((fila = mysql_fetch_row(resultado))) {
        cout << "ID: " << fila[0] << ", DNI: " << fila[1] << ", Nombre: " << fila[2] << ", Apellido: " << fila[3]
            << ", Teléfono: " << fila[4] << ", Email: " << fila[5] << endl;
    }

    mysql_free_result(resultado);
}

void Mecanico::actualizarMecanico() {
    // Solicitar los nuevos valores para actualizar el mecánico
    cout << "Ingrese el nuevo DNI del mecánico  " << DniMecanico << ": ";
    cin >> DniMecanico;

    cout << "Ingrese el nuevo nombre del mecánico  " << NombreMecanico << ": ";
    cin >> NombreMecanico;

    cout << "Ingrese el nuevo apellido del mecánico  " << ApellidoMecanico << ": ";
    cin >> ApellidoMecanico;

    cout << "Ingrese el nuevo teléfono del mecánico  " << TelMecanico << ": ";
    cin >> TelMecanico;

    cout << "Ingrese el nuevo email del mecánico  " << EmailMecanico << ": ";
    cin >> EmailMecanico;

    // Crear la consulta de actualización
    string consulta = "UPDATE Mecanico SET DniMecanico='" + DniMecanico +
        "', NombreMecanico='" + NombreMecanico +
        "', ApellidoMecanico='" + ApellidoMecanico +
        "', TelMecanico='" + TelMecanico +
        "', EmailMecanico='" + EmailMecanico +
        "' WHERE idMecanico=" + to_string(idMecanico);

    // Ejecutar la consulta
    conexion->ejecutarConsulta(consulta);

    cout << "Mecánico actualizado exitosamente." << endl;
}


void Mecanico::eliminarMecanico() {
    string consulta = "DELETE FROM cliente WHERE id_Cliente=" + to_string(idMecanico);
    conexion->ejecutarConsulta(consulta);
}