#ifndef Utilidades_h
#define Utilidades_h

#include <string>

void limpiarPantalla();
void pausa();
int capturarOpcion(int min, int max);
std::string capturarStringNumerico(const std::string& mensaje);
int capturarId(const std::string& mensaje);

#endif // Utilidades_h

