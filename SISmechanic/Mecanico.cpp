#include "Mecanico.h"

// Constructor sin parámetros para inicializar solo la conexión
Mecanico::Mecanico(ConexionBD* con) {
    
}

// Constructor con parámetros para inicializar todos los atributos del mecanico
Mecanico::Mecanico(ConexionBD* con, int id_m, const string& dni, const string& nom, const string& ape,
    const string& tel, const string& email) : idMecanico(id_m), DniMecanico(stoi(dni)),
    NombreMecanico(nom), ApellidoMecanico(ape), TelMecanico(stoi(tel)), EmailMecanico(email) {
    
}

// Metodos GET y SET

// idMecanico
int Mecanico::getIdMecanico() const {
    return idMecanico;
}

void Mecanico::setIdMecanico(int id_m) {
    idMecanico = id_m;
}

// DniMecanico
int Mecanico::getDniMecanico() const {
    return DniMecanico;
}

void Mecanico::setDniMecanico(int dni) {
    DniMecanico = dni;
}

// NombreMecanico
string Mecanico::getNombreMecanico() const {
    return NombreMecanico;
}

void Mecanico::setNombreMecanico(const string& nombre) {
    NombreMecanico = nombre;
}

// ApellidoMecanico
string Mecanico::getApellidoMecanico() const {
    return ApellidoMecanico;
}

void Mecanico::setApellidoMecanico(const string& apellido) {
    ApellidoMecanico = apellido;
}

// TelMecanico
int Mecanico::getTelMecanico() const {
    return TelMecanico;
}

void Mecanico::setTelMecanico(int tel) {
    TelMecanico = tel;
}

// EmailMecanico
string Mecanico::getEmailMecanico() const {
    return EmailMecanico;
}

void Mecanico::setEmailMecanico(const string& email) {
    EmailMecanico = email;
}

// Metodos CRUD

// Crear un nuevo mecánico en la base de datos
void Mecanico::crearMecanico() {
    string query = "INSERT INTO Mecanico (DniMecanico, NombreMecanico, ApellidoMecanico, TelMecanico, EmailMecanico) VALUES ('" +
        to_string(DniMecanico) + "', '" + NombreMecanico + "', '" + ApellidoMecanico + "', '" +
        to_string(TelMecanico) + "', '" + EmailMecanico + "')";

    // Ejecutar el query usando la conexión
    // con->ejecutar(query); // Usar el método adecuado de la clase ConexionBD para ejecutar el query
}

// Leer los datos de un mecánico de la base de datos
void Mecanico::leerMecanico() {
    string query = "SELECT * FROM Mecanico WHERE idMecanico = " + to_string(idMecanico);

    // Ejecutar el query y obtener el resultado
    // con->ejecutar(query); // Usar el metodo adecuado de la clase ConexionBD para ejecutar el query y manejar resultados
}

// Actualizar los datos de un mecanico en la base de datos
void Mecanico::actualizarMecanico() {
    string query = "UPDATE Mecanico SET DniMecanico = '" + to_string(DniMecanico) +
        "', NombreMecanico = '" + NombreMecanico + "', ApellidoMecanico = '" + ApellidoMecanico +
        "', TelMecanico = '" + to_string(TelMecanico) + "', EmailMecanico = '" + EmailMecanico +
        "' WHERE idMecanico = " + to_string(idMecanico);

    // Ejecutar el query usando la conexión
    // con->ejecutar(query); // Usar el método adecuado de la clase ConexionBD para ejecutar el query
}

// Eliminar un mecanico de la base de datos
void Mecanico::eliminarMecanico() {
    string query = "DELETE FROM Mecanico WHERE idMecanico = " + to_string(idMecanico);

    // Ejecutar el query usando la conexion
    // con->ejecutar(query); // Usar el método adecuado de la clase ConexionBD para ejecutar el query
}
