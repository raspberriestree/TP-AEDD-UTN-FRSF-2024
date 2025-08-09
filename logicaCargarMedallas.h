#ifndef LOGICACARGARMEDALLAS_H
#define LOGICACARGARMEDALLAS_H
#include "logicaMenus.h"
#include "menus.h"
#include <string>
using namespace std;

void cargarMedallasIndividual(competidores competencia[87],int deporte_medallas[87][3]);
void cargarMedallasColectivo(competidores competencia[87],int deporte_medallas[87][3]);

bool entradaValidaCargaMedallaDeporte(string,int &,bool &);
bool entradaValidaCargaMedallaPais(string ,int & ,bool &);
bool equipoCompite(int,int,competidores competencia[87]);

void cargarMedallas(int,competidores competencia[87],int deporte_medallas[87][3]);
void cargarMatrizDeporteMedallas(int &,int,int,bool,int deporte_medallas[87][3]);
bool filaLlena(int,int deporte_medallas[87][3]);

#endif
