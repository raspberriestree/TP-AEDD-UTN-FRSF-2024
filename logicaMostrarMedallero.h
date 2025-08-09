#ifndef LOGICAMOSTRARMEDALLERO_H
#define LOGICAMOSTRARMEDALLERO_H
#include "logicaMenus.h"
#include <string>
using namespace std;

void medalleroPorPais(int deporte_medallas[87][3]);
void medalleroPorDeporte(int deporte_medallas[87][3]);
void topMedallero(int deporte_medallas[87][3]);

void convertirMatriz(int deporte_medallas[87][3],int paises[197][3]);
void generarID(int id[197]);
void generarIDFuncion3(int arreglo_ID[197]);
bool entradaValidaTopMedallero(string, int &, bool &);
int contarPaisesCargados(int paises[197][3]);


void mergesortFuncion1(int paises[197][3],int id[197],int inicio,int fin);
void mergeFuncion1(int paises[197][3],int id[197], int inicio, int mitad, int fin);


void mergesortFuncion3(int paises[197][3],int arreglo_ID[197],int inicio,int fin);
void mergeFuncion3(int paises[197][3],int arreglo_ID[197], int inicio, int mitad, int fin);


void imprimirTopMedallero(int paises[197][3],int arreglo_ID[197], int top);
void imprimirMedalleroPorPais (int paises[197][3],int arreglo_ID[197]);

#endif
