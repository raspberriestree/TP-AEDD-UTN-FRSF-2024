#ifndef LOGICAMENUESTADISTICAS_H
#define LOGICAMENUESTADISTICAS_H
#include <string>
#include "paises.h"
#include "deportes.h"

using namespace std;

//Pa�s con m�s medallas
void pais_mas_medallas_1(int deporte_medallas[87][3]);

//Medallas del pa�s
void medallas_obtenidas_2(int deporte_medallas[87][3]);
bool entradaValidaMedallasObtenidas(string idPais,bool &sePresionaX);

//Pais con m�s deportes individuales
void estadistica3(int deporte_medallas[87][3]);

//Paises premiados del deporte X
void estadistica4(int deporte_medallas[87][3]);





#endif
