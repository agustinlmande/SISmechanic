#ifndef CONEXIONBD_H
#define CONEXIONBD_H

#include <mysql.h>
#include <iostream>
#include <vector>
#include <string>

class ConexionBD {
private:
    MYSQL* conector;

public:
    ConexionBD();
    ~ConexionBD();

    // Declaración de las funciones
    void abrir_conexion();
    void crearBaseDeDatos(const std::string& nombreBD); // Declarada solo una vez
    void crearTablas();
    void cerrar_conexion();
    void ejecutarConsulta(const std::string& consulta);
    std::vector<std::vector<std::string>> obtenerResultados(const std::string& consulta); // Declarada solo una vez
    MYSQL* getConector();
};

#endif // CONEXIONBD_H



