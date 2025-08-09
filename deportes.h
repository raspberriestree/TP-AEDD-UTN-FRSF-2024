#ifndef DEPORTES_H
#include <string>

using namespace std;

void imprimirDeporte(int indice);
void mostrarDeportes();
void mostrarDeportesIndividuales();
void listarDeportesPorCategoria(const char* categoria, const int* indices, int numIndices);
void mostrarDeportesColectivos();


//Agregadas
bool estaEnListaIndividual(int);
bool estaEnListaColectivo(int);

bool letraigual(int indice,string letra,int &coincidencias);
int obtenerindiceindividual(int i);

#endif
