#ifndef Utilidades_h
#define Utilidades_h

#include <string>

using namespace std;

void limpiarPantalla();
void pausa();
int capturarOpcion(int min, int max);
string capturarStringNumerico(const string& mensaje);
int capturarId(const string& mensaje);
string capturarDni(const string& mensaje);
string capturarPatente(const string& mensaje);
void encabezado(const string& nombreGestion);
char capturarConfirmacion();
#endif // Utilidades_h

