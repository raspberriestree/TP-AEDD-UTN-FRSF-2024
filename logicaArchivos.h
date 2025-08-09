#ifndef LOGICAARCHIVOS_H
#define LOGICAARCHIVOS_H
#include "logicaMenus.h"
#include <string>
#include <time.h>

using namespace std;

//Logica para crear un archivo
void generarArchivoCompetencia(competidores competencia[],int deporte_medallas[87][3],int legajoIngresa,bool &competenciaGenerada,string &fileName);
string obtenerFecha(const tm& fecha);

//Logica para cargar un archivo
void cargarArchivoCompetencia(competidores competencia[],int deporte_medallas[87][3],int legajoIngresa,bool &competenciaGenerada,string &fileName);

//Logica para guardar cambios en el archivo
void guardarArchivoCompetencia(string nombreArchivo,competidores competencia[],int deporte_medallas[87][3],int legajoIngresado);

void mostrarFechaDesdeNombre(string);

#endif
