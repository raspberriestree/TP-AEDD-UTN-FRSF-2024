#include "menus.h"
#include "logicaVisual.h"
#include "logicaMenus.h"
#include "logicaArchivos.h"
#include <string>
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

void menuPrincipal(int legajoIngresado){
	bool salir = false;
	bool competenciaGenerada = false;
	char seleccionarOpcion = '0';
	string nombreArchivo;
	
	competidores competencia[87];
	int deporte_medallas[87][3] = {0};
	
	while(!salir){
		
		limpiarConsola(); //lógicaVisual - Generales
		pantallaMenuPrincipal(competenciaGenerada); //logicaVisual - Generales
		
		
		gotoxy(103,5);
		seleccionarOpcion = _getch();
		
		dibujarFlechasMenuPrincipal(seleccionarOpcion); //logicaVisual - Menu principal
		
		confirmarOpcionMenuPrincipal(seleccionarOpcion,competenciaGenerada,competencia,salir,deporte_medallas,legajoIngresado,nombreArchivo); //logicaMenu - Menu principal
		
	}
	
	guardarArchivoCompetencia(nombreArchivo,competencia,deporte_medallas,legajoIngresado);
	
	gotoxy(66,21);
	cout<<"SALIENDO ...                      "<<endl;
	
	for(int i=3;i>0;i--){
		gotoxy(66,22);
		cout<<i<<"..."<<endl;
		Sleep(1000);
	}
}

void menuCargarMedallas(competidores competencia[],int deporte_medallas[87][3]){
	char seleccionarOpcion;
	bool salirSubMenu = false;
	
	while(!salirSubMenu){
		limpiarConsola(); //Lógica visual - generales
		
		pantallaMenuCargarMedalla(); //Lógica visual - Menu Cargar Medallas
		
		gotoxy(100,5);
		seleccionarOpcion = _getch();
		
		dibujarFlechasMenuCargarMedallas(seleccionarOpcion); //Lógica Menu - Menu Cargar Medallas
		
		confirmarOpcionMenuCargarMedallas(seleccionarOpcion,salirSubMenu,competencia,deporte_medallas); //Lógica Menú - Menu Cargar Medallas
	}
}

void menuMostrarMedallero(int deporte_medallas[87][3]){
	char seleccionarOpcion;
	bool salirSubMenu = false;
	
	while(!salirSubMenu){
		limpiarConsola(); //Lógica visual - generales
		
		pantallaMenuMostrarMedallero(); //Lógica visual - Menú Mostrar Medallero
		
		gotoxy(104,5);
		seleccionarOpcion = _getch();
		
		dibujarFlechasMenuMostrarMedallero(seleccionarOpcion); //Lógica Menu - Menú Mostrar Medallero
		
		confirmarOpcionMenuMostrarMedallero(seleccionarOpcion,salirSubMenu, deporte_medallas); //Lógica Menú - Menu Mostrar Medallero
	}
}
	
void menuGenerarCompetencia(competidores competencia[],int deporte_medallas[87][3],bool &competenciaGenerada,int legajoIngresado,string &nombreArchivo){
	char seleccionarOpcion;
	bool salirSubMenu = false;
	
	while(!salirSubMenu){
		limpiarConsola();
		
		pantallaMenuGenerarCompetencia();
		
		gotoxy(113,6);
		seleccionarOpcion = _getch();
		dibujarFlechasMenuGenerarCompetencia(seleccionarOpcion);
		
		confirmarOpcionMenuGenerarCompetencia(seleccionarOpcion,salirSubMenu,competenciaGenerada,
												competencia,deporte_medallas,legajoIngresado,nombreArchivo);
	}
}

void menuEstadisticas(int deporte_medallas[87][3]){
	char seleccionarOpcion;
	bool salirSubMenu = false;
	
	while(!salirSubMenu){
		limpiarConsola();
		
		pantallaMenuEstadisticas();
		gotoxy(103,5);
		seleccionarOpcion = _getch();
		dibujarFlechasMenuEstadisticas(seleccionarOpcion);
		confirmarOpcionMenuEstadisticas(seleccionarOpcion,salirSubMenu,deporte_medallas);
		
	}
}
