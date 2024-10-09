#ifndef Utilidades_h
#define Utilidades_h

#include <string>

void limpiarPantalla();
void pausa();
int capturarOpcion(int min, int max);
std::string capturarStringNumerico(const std::string& mensaje);
int capturarId(const std::string& mensaje);
void encabezado(const std::string& nombreGestion);
char capturarConfirmacion();
#endif // Utilidades_h

