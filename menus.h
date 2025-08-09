#ifndef MENUS_H
#define MENUS_H
#include "logicaMenus.h"

void menuPrincipal(int legajoIngresado);

void menuCargarMedallas(competidores competencia[],int deporte_medallas[87][3]);

void menuMostrarMedallero(int deporte_medallas[87][3]);

void menuGenerarCompetencia(competidores competencia[],int deporte_medallas[87][3],bool &competenciaGenerada,int legajoIngresado,string &nombreArchivo);

void menuEstadisticas(int deporte_medallas[87][3]);

#endif
