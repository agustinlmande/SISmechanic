#include "ConexionBD.h"
#include <iostream>
using namespace std;

ConexionBD::ConexionBD() : conector(nullptr) {}

ConexionBD::~ConexionBD() {
    cerrar_conexion();
}

void ConexionBD::abrir_conexion() {
    conector = mysql_init(nullptr);
    if (!conector) {
        cerr << "Error al inicializar MySQL: No se pudo asignar memoria para la conexion." << endl;
        return;
    }

    conector = mysql_real_connect(conector, "localhost", "root", "", "", 3306, nullptr, 0);
    if (!conector) {
        cerr << "Error al conectar a MySQL: " << mysql_error(conector) << endl;
        return;
    }

    // Crear la base de datos si no existe
    crearBaseDeDatos("mecanico");

    // Seleccionar la base de datos
    if (mysql_select_db(conector, "mecanico")) {
        cerr << "Error al seleccionar la base de datos: " << mysql_error(conector) << endl;
    }
    else {
        cout << "Base de datos seleccionada correctamente." << endl;
    }
}

void ConexionBD::crearBaseDeDatos(const string& nombreBD) {
    string consulta = "CREATE DATABASE IF NOT EXISTS " + nombreBD;
    if (mysql_query(conector, consulta.c_str())) {
        cerr << "Error al crear la base de datos: " << mysql_error(conector) << endl;
    }
    else {
        cout << "Base de datos creada o ya existe." << endl;
    }
}

MYSQL* ConexionBD::getConector() {
    return conector;
}

void ConexionBD::cerrar_conexion() {
    if (conector) {
        mysql_close(conector);
        conector = nullptr;  // Asegurarse de no usar el puntero después de cerrarlo.
        cout << "Conexion cerrada correctamente." << endl;
    }
}

void ConexionBD::ejecutarConsulta(const string& consulta) {
    if (!conector) {
        cerr << "Error: Conexion no establecida." << endl;
        return;
    }

    if (mysql_query(conector, consulta.c_str())) {
        cerr << "Error al ejecutar la consulta: " << mysql_error(conector) << endl;
    }
    else {
        cout << "Consulta ejecutada con exito." << endl;
    }
}

// Nuevo método para obtener resultados de una consulta SELECT
vector<vector<string>> ConexionBD::obtenerResultados(const string& consulta) {
    vector<vector<string>> resultados;

    if (mysql_query(conector, consulta.c_str())) {
        cerr << "Error al ejecutar la consulta: " << mysql_error(conector) << endl;
        return resultados;
    }

    MYSQL_RES* resultado = mysql_store_result(conector);
    if (!resultado) {
        cerr << "Error al obtener el resultado: " << mysql_error(conector) << endl;
        return resultados;
    }

    int num_campos = mysql_num_fields(resultado);
    MYSQL_ROW fila;

    while ((fila = mysql_fetch_row(resultado))) {
        vector<string> filaDatos;
        for (int i = 0; i < num_campos; ++i) {
            filaDatos.push_back(fila[i] ? fila[i] : "NULL");
        }
        resultados.push_back(filaDatos);
    }

    mysql_free_result(resultado);
    return resultados;
}
