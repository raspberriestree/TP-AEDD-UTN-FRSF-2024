#ifndef LOGICAMENUS_H
#define LOGICAMENUS_H
#include <string>
using namespace std;

struct competidores{
	int paises [16];
	int TL;
};

//Menu Principal
	//Generacion de competencia
	void generarCompetencia(competidores competencia[87]);
	int asignarIDPais(bool paisAsignado[196]);
	
	//Manejo menu
	void confirmarOpcionMenuPrincipal(char &,bool &,competidores competencia[],bool &,int deporte_medallas[87][3],
										int legajoIngresado,string &nombreArchivo);
	
	bool confirmarSalidaPrincipal();

//Menu Generar competencia
	void confirmarOpcionMenuGenerarCompetencia(char &seleccionarOpcion,bool &salirSubMenu,bool& competenciaGenerada,
											   competidores competencia[],int deporte_medallas[87][3],int legajoIngresado,string &nombreArchivo);

//Menu Cargar Medallas
	//Manejo del Menu
	void confirmarOpcionMenuCargarMedallas(char &,bool &,competidores competencia[],int deporte_medallas[87][3]);
	
//Menu Mostrar medallero
	//Manejo del Menu
	void confirmarOpcionMenuMostrarMedallero(char &,bool &, int[87][3]);
	
//Menu estadistica
	//Manejo del Menu
	void confirmarOpcionMenuEstadisticas(char &seleccionarOpcion,bool &salir,int deporte_medallas[87][3]);
	
//Validacion
	bool seCargaronMedallas (int deporte_medallas[87][3]);
#endif
