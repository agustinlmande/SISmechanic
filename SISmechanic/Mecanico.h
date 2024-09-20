#include <mysql.h>
#include "ConexionBD.h"
#include <iostream>

using namespace std;

class Mecanico
{
private:
    int idMecanico;
    int DniMecanico;
    string NombreMecanico;
    string ApellidoMecanico;
    int TelMecanico;
    string EmailMecanico;

public:
    // Constructores
    Mecanico(ConexionBD* con);
    Mecanico(ConexionBD* con, int id_m, const string& dni, const string& nom, const string& ape,
        const string& tel, const string& email);

    // Metodos get y set
    // idMecanico
    int getIdMecanico() const; //get = mostrar
    void setIdMecanico(int id_m); //set = modificar

    // DniMecanico
    int getDniMecanico() const;
    void setDniMecanico(int dni);

    // NombreMecanico
    string getNombreMecanico() const;
    void setNombreMecanico(const string& nombre);

    // ApellidoMecanico
    string getApellidoMecanico() const;
    void setApellidoMecanico(const string& apellido);

    // TelMecanico
    int getTelMecanico() const;
    void setTelMecanico(int tel);

    // EmailMecanico
    string getEmailMecanico() const;
    void setEmailMecanico(const string& email);

    // Métodos CRUD
    void crearMecanico();
    void leerMecanico();
    void actualizarMecanico();
    void eliminarMecanico();

};


