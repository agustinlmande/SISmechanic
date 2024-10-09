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
        cerr << "Error al inicializar MySQL: No se pudo asignar memoria para la conexión." << endl;
        return;
    }

    // Ajustar el puerto según corresponda, cambiando 3306 si usas otro puerto
    conector = mysql_real_connect(conector, "localhost", "root", "", "", 3307, nullptr, 0);
    if (!conector) {
        cerr << "Error al conectar a MySQL: " << mysql_error(conector) << endl;
        return;
    }

    // Crear la base de datos si no existe
    crearBaseDeDatos("TallerMecanico");

    // Seleccionar la base de datos
    if (mysql_select_db(conector, "TallerMecanico")) {
        cerr << "Error al seleccionar la base de datos: " << mysql_error(conector) << endl;
    }
    else {
        cout << "Base de datos seleccionada correctamente." << endl;
    }

    // Crear las tablas
    crearTablas();
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

void ConexionBD::crearTablas() {
    // Crear la tabla Mecanico
    ejecutarConsulta(R"(
        CREATE TABLE IF NOT EXISTS Mecanico (
            idMecanico INT AUTO_INCREMENT PRIMARY KEY,
            DniMecanico VARCHAR(50) NOT NULL,
            NombreMecanico VARCHAR(50) NOT NULL,
            ApellidoMecanico VARCHAR(50) NOT NULL,
            TelMecanico VARCHAR(20),
            EmailMecanico VARCHAR(50)
        ) ENGINE = InnoDB;
    )");

    // Crear la tabla Cliente
    ejecutarConsulta(R"(
        CREATE TABLE IF NOT EXISTS Cliente (
            IdCliente INT AUTO_INCREMENT PRIMARY KEY,
            dniCliente varchar(30) NOT NULL,
            nombreCliente VARCHAR(50) NOT NULL,
            apellidoCliente varchar(50) NOT NULL,
            telCliente VARCHAR(20),
            emailCliente VARCHAR(50)
            
        ) ENGINE = InnoDB;
    )");

    // Crear la tabla Vehiculo
    ejecutarConsulta(R"(
        CREATE TABLE IF NOT EXISTS Vehiculo (
            idVehiculo INT AUTO_INCREMENT PRIMARY KEY,
            marca VARCHAR(50) NOT NULL,
            modelo VARCHAR(50) NOT NULL,
            anio INT,
            idCliente INT,
            FOREIGN KEY (idCliente) REFERENCES Cliente(IdCliente) ON DELETE CASCADE ON UPDATE CASCADE
        ) ENGINE = InnoDB;
    )");

    // Crear la tabla Estado
    ejecutarConsulta(R"(
        CREATE TABLE IF NOT EXISTS Estado (
            idEstado INT AUTO_INCREMENT PRIMARY KEY,
            descripcion VARCHAR(50) NOT NULL
        ) ENGINE = InnoDB;
    )");

    // Crear la tabla Service
    ejecutarConsulta(R"(
        CREATE TABLE IF NOT EXISTS Service (
            idService INT AUTO_INCREMENT PRIMARY KEY,
            descripcion VARCHAR(100) NOT NULL,
            fecha DATE,
            costo DECIMAL(10, 2),
            idMecanico INT,
            idVehiculo INT,
            idEstado INT,
            FOREIGN KEY (idMecanico) REFERENCES Mecanico(idMecanico) ON DELETE SET NULL ON UPDATE CASCADE,
            FOREIGN KEY (idVehiculo) REFERENCES Vehiculo(idVehiculo) ON DELETE CASCADE ON UPDATE CASCADE,
            FOREIGN KEY (idEstado) REFERENCES Estado(idEstado) ON DELETE CASCADE ON UPDATE CASCADE
        ) ENGINE = InnoDB;
    )");

    // Crear la tabla Vehiculo_has_Service (relación muchos a muchos)
    ejecutarConsulta(R"(
        CREATE TABLE IF NOT EXISTS Vehiculo_has_Service (
            Vehiculo_idVehiculo INT NOT NULL,
            Service_idService INT NOT NULL,
            PRIMARY KEY (Vehiculo_idVehiculo, Service_idService),
            FOREIGN KEY (Vehiculo_idVehiculo) REFERENCES Vehiculo(idVehiculo) ON DELETE CASCADE ON UPDATE CASCADE,
            FOREIGN KEY (Service_idService) REFERENCES Service(idService) ON DELETE CASCADE ON UPDATE CASCADE
        ) ENGINE = InnoDB;
    )");

    // Precargar datos después de crear las tablas
    precargarDatos();
}

void ConexionBD::precargarDatos() {
    // Verificar si la tabla Estado ya tiene datos
    if (mysql_query(conector, "SELECT COUNT(*) FROM Estado")) {
        cerr << "Error al contar registros en la tabla Estado: " << mysql_error(conector) << endl;
        return;
    }

    MYSQL_RES* resEstado = mysql_store_result(conector);
    MYSQL_ROW rowEstado = mysql_fetch_row(resEstado);
    int countEstado = atoi(rowEstado[0]);

    if (countEstado == 0) {
        // Precargar datos en la tabla Estado
        ejecutarConsulta(R"(
            INSERT INTO Estado (descripcion) VALUES
            ('Pendiente'),
            ('En Proceso'),
            ('Finalizado');
        )");
    }
    else {
        cout << "La tabla Estado ya tiene datos." << endl;
    }

    // Verificar si la tabla Cliente ya tiene datos
    if (mysql_query(conector, "SELECT COUNT(*) FROM Cliente")) {
        cerr << "Error al contar registros en la tabla Cliente: " << mysql_error(conector) << endl;
        return;
    }

    MYSQL_RES* resCliente = mysql_store_result(conector);
    MYSQL_ROW rowCliente = mysql_fetch_row(resCliente);
    int countCliente = atoi(rowCliente[0]);

    if (countCliente == 0) {
        // Precargar datos en la tabla Cliente
        ejecutarConsulta(R"(
           INSERT INTO Cliente (dniCliente, nombreCliente, apellidoCliente, telCliente, emailCliente) VALUES
          ('45678912', 'Lucia', 'Fernandez', '1122334455', 'lucia.fernandez@example.com'),
          ('78912345', 'Miguel', 'Ramirez', '5566778899', 'miguel.ramirez@example.com');
        )");
    }
    else {
        cout << "La tabla Cliente ya tiene datos." << endl;
    }

    // Verificar si la tabla Mecanico ya tiene datos
    if (mysql_query(conector, "SELECT COUNT(*) FROM Mecanico")) {
        cerr << "Error al contar registros en la tabla Mecanico: " << mysql_error(conector) << endl;
        return;
    }

    MYSQL_RES* resMecanico = mysql_store_result(conector);
    MYSQL_ROW rowMecanico = mysql_fetch_row(resMecanico);
    int countMecanico = atoi(rowMecanico[0]);

    if (countMecanico == 0) {
        // Precargar datos en la tabla Mecanico
        ejecutarConsulta(R"(
            INSERT INTO Mecanico (DniMecanico, NombreMecanico, ApellidoMecanico, TelMecanico, EmailMecanico) VALUES
          ('12345678', 'Pedro', 'Gonzalez', '111222333', 'pedro.gonzalez@example.com'),
          ('87654321', 'Laura', 'Martinez', '444555666', 'laura.martinez@example.com');
        )");
    }
    else {
        cout << "La tabla Mecanico ya tiene datos." << endl;
    }

    // Verificar si la tabla Vehiculo ya tiene datos
    if (mysql_query(conector, "SELECT COUNT(*) FROM Vehiculo")) {
        cerr << "Error al contar registros en la tabla Vehiculo: " << mysql_error(conector) << endl;
        return;
    }

    MYSQL_RES* resVehiculo = mysql_store_result(conector);
    MYSQL_ROW rowVehiculo = mysql_fetch_row(resVehiculo);
    int countVehiculo = atoi(rowVehiculo[0]);

    if (countVehiculo == 0) {
        // Precargar datos en la tabla Vehiculo
        ejecutarConsulta(R"(
            INSERT INTO Vehiculo (marca, modelo, anio, idCliente) VALUES
            ('Toyota', 'Corolla', 2018, 1),
            ('Ford', 'Fiesta', 2020, 2);
        )");
    }
    else {
        cout << "La tabla Vehiculo ya tiene datos." << endl;
    }

    // Verificar si la tabla Service ya tiene datos
    if (mysql_query(conector, "SELECT COUNT(*) FROM Service")) {
        cerr << "Error al contar registros en la tabla Service: " << mysql_error(conector) << endl;
        return;
    }

    MYSQL_RES* resService = mysql_store_result(conector);
    MYSQL_ROW rowService = mysql_fetch_row(resService);
    int countService = atoi(rowService[0]);

    if (countService == 0) {
        // Precargar datos en la tabla Service
        ejecutarConsulta(R"(
            INSERT INTO Service (descripcion, fecha, costo, idMecanico, idVehiculo, idEstado) VALUES
            ('Cambio de aceite', '2023-07-15', 1500.00, 1, 1, 1),
            ('Revision general', '2023-08-05', 3000.00, 2, 2, 2);
        )");
    }
    else {
        cout << "La tabla Service ya tiene datos." << endl;
    }

    // Liberar resultados
    mysql_free_result(resEstado);
    mysql_free_result(resCliente);
    mysql_free_result(resMecanico);
    mysql_free_result(resVehiculo);
    mysql_free_result(resService);
}


MYSQL* ConexionBD::getConector() {
    return conector;
}

void ConexionBD::cerrar_conexion() {
    if (conector) {
        mysql_close(conector);
        conector = nullptr;  // Asegurarse de no usar el puntero después de cerrarlo.
        cout << "Conexión cerrada correctamente." << endl;
    }
}

void ConexionBD::ejecutarConsulta(const string& consulta) {
    if (!conector) {
        cerr << "Error: Conexión no establecida." << endl;
        return;
    }

    if (mysql_query(conector, consulta.c_str())) {
        cerr << "Error al ejecutar la consulta: " << mysql_error(conector) << endl;
    }
    else {
        cout << "Consulta ejecutada con Exito." << endl;
    }
}

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

