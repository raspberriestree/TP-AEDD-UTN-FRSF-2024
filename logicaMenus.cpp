#include "logicaMenus.h"
#include "logicaVisual.h"
#include "logicaCargarMedallas.h"
#include "logicaMostrarMedallero.h"
#include "logicaArchivos.h"
#include "logicaMenuEstadisticas.h"
#include "paises.h"
#include "deportes.h"
#include "menus.h"
#include <conio.h>
#include <ctime>
#include <string>
#include <windows.h>
#include <iostream>
using namespace std;

//Menu Principal

void generarCompetencia(competidores competencia[]){
	srand(time(NULL));
	
	for (int i = 0; i < 87; i++) {
		bool paisAsignado[196] = {false}; //Arreglo local para evitar repeticiones dentro de la misma competencia
		competencia[i].TL = rand() % 13 + 4; //Tamaño lógico entre 4 y 16 de cada elemento de competencia[]
		
		for (int j = 0; j < competencia[i].TL; j++) {
			competencia[i].paises[j] = asignarIDPais(paisAsignado); //Asigna un país único para esta competencia
		}
	}
}
	
int asignarIDPais(bool paisAsignado[196]){
	int idPais;
	
	do {
		idPais = rand() % 196; 
		//Genera un número entre 0 y 195
		
	} while (paisAsignado[idPais]); 
	//Repite si ya ha sido asignado en esta competencia comparando el valor de verdad
	//Si no ha sido seleccionado estará en 0, por lo tanto sale del bucle, si está en 1 significa que ya fue tomado antes, repite el bucle.
	
	//Marca el país como asignado para esta competencia asi no es asignado luego
	paisAsignado[idPais] = true; 
	
	return idPais + 1; //Devuelve el país (entre 1 y 196)
}
	
void confirmarOpcionMenuPrincipal(char &seleccionarOpcion,bool &competenciaGenerada,competidores competencia[87],bool &salir,int deporte_medallas[87][3],
								int legajoIngresado,string &nombreArchivo){
	if(seleccionarOpcion!='0'){//Si es una opcion válida ingresa
		
		gotoxy(103,5);
		if(_getch() == 13){ //Si se presiona ENTER se evalua la condicion de seleccionarOpcion
			
			switch(seleccionarOpcion){
				case '1':
					
					if(not competenciaGenerada){
						
						menuGenerarCompetencia(competencia,deporte_medallas,competenciaGenerada,legajoIngresado,nombreArchivo);
						
					}
					else{
						gotoxy(66,21);cout<<"YA SE HA CREADO O CARGADO UNA COMPETENCIA"<<endl;
						Sleep(1000);
						limpiarConsola();
						
					}
				break;
					//Case 1 tiene que haber sido seleccionado
				case '2':
					if(competenciaGenerada){
						//Verifica si ya se genero una competencia
						menuCargarMedallas(competencia,deporte_medallas);
					}
					else{
						gotoxy(66,21);cout<<"SE DEBE CREAR UNA COMPETENCIA ANTES";
						Sleep(1000);
					}
					limpiarConsola();
				break;
					
				case '3':
					if(competenciaGenerada){
						if(seCargaronMedallas(deporte_medallas)){ 
							menuMostrarMedallero(deporte_medallas);
						} else {
							
							gotoxy(66,21); cout<<"NO EXISTEN MEDALLAS CARGADAS ..."<<endl;
							Sleep(1000);
						}
					}
					else{
						gotoxy(66,21);cout<<"SE DEBE CREAR UNA COMPETENCIA O CARGAR MEDALLAS";
						Sleep(1000);
					}
					limpiarConsola();
				break;
				
				case '4':
					if(competenciaGenerada){
						if(seCargaronMedallas(deporte_medallas)){ 
							menuEstadisticas(deporte_medallas);
						}
						else{
							
							gotoxy(66,21); cout<<"NO EXISTEN MEDALLAS CARGADAS ..."<<endl;
							Sleep(1000);
						}
					}
					else{
						gotoxy(66,21);cout<<"SE DEBE CREAR UNA COMPETENCIA O CARGAR MEDALLAS";
						Sleep(1000);
					}
					limpiarConsola();
					break;
					
				case 'x':
				case 'X':
					if(confirmarSalidaPrincipal()){
						salir = true;
					}
				break;
			}
		}
	}
}

bool confirmarSalidaPrincipal(){
	char confirmacionSalir;
	bool confirmacion = false;
	gotoxy(66,21);
	cout<<"¿CONFIRMAR SALIDA? (S/N):";
	//Lee la entrada hasta que sea valida (S o N)
	do{
		gotoxy(91,21);
		confirmacionSalir = _getch();
	} while(confirmacionSalir !='S' && confirmacionSalir !='s' && confirmacionSalir!='n' && confirmacionSalir !='N');
	
	//Si es S/s asigna valor de verdad a confirmacion y cambia la variable booleana de MenuPrincipal
	//Haciendo que rompa la condicion del while, dando por finalizado el programa
	if(confirmacionSalir=='s' or confirmacionSalir=='S'){
		confirmacion = true;
		gotoxy(66,21);
		cout<<"                           ";
	}
	return confirmacion;
}

//Menu Cargar Medallas
void confirmarOpcionMenuCargarMedallas(char &seleccionarOpcion,bool &salirSubMenu,competidores competencia[],int deporte_medallas[87][3]){
	
	if(seleccionarOpcion!='0'){
		
		gotoxy(100,5);
		if(_getch()==13){//Consulta si la tecla presionada es ENTER
			switch(seleccionarOpcion){
			case '1':
				
				cargarMedallasIndividual(competencia,deporte_medallas);
				
				break;
			case '2':
				
				cargarMedallasColectivo(competencia,deporte_medallas);
				
				break;
				
			case'x':
			case 'X':
				salirSubMenu = true;
				//Devuelve al menu principal
			}
		}
	}
}

//Menu Mostrar Medallero
void confirmarOpcionMenuMostrarMedallero(char &seleccionarOpcion,bool &salirSubMenu, int deporte_medallas[87][3]){
	
	if(seleccionarOpcion!='0'){
		gotoxy(104,5);
		if(_getch()==13){
			
			switch(seleccionarOpcion){
			case '1':
				medalleroPorPais(deporte_medallas);
				
				break;
			case '2':
				medalleroPorDeporte(deporte_medallas); 
				
				break;
			case '3':
				topMedallero(deporte_medallas);
				
				break;
			case 'x':
			case 'X':
				salirSubMenu = true;
				
			}
		}
	}
}

//verificar si al menos hay un podio cargado, osea una competencia cargada
bool seCargaronMedallas (int deporte_medallas[87][3]){
	bool hayPodio = false;
	int i=0;
	//miro si al menos hay algun bronce cargado, recorro columna 2
	
	while (!hayPodio and i<87){
		
		if (deporte_medallas[i][2]!=0) hayPodio = true;
		else i++;
	}
	
	return hayPodio;
}

	
void confirmarOpcionMenuGenerarCompetencia(char &seleccionarOpcion,bool &salirSubMenu,bool& competenciaGenerada,
										   competidores competencia[],int deporte_medallas[87][3],int legajoIngresado,string &nombreArchivo){
	
	if(seleccionarOpcion!='0'){
		gotoxy(113,6);
		if(_getch()==13){
			
			switch(seleccionarOpcion){
			case '1':
				if(!competenciaGenerada){
					generarArchivoCompetencia(competencia,deporte_medallas,legajoIngresado,competenciaGenerada,nombreArchivo);
				}
				else{
					gotoxy(78,19);cout<<"YA HAY UNA COMPETENCIA GENERADA";
					Sleep(1500);
				}
				
				
				break;
			case '2':
				if(!competenciaGenerada){
					cargarArchivoCompetencia(competencia,deporte_medallas,legajoIngresado,competenciaGenerada,nombreArchivo);
				}
				else{
					gotoxy(78,19);cout<<"YA HAY UNA COMPETENCIA GENERADA";
					Sleep(1500);
				}
				
				break;
			case 'x':
			case 'X':
				salirSubMenu = true;
				
			}
		}
	}
}

void confirmarOpcionMenuEstadisticas(char &seleccionarOpcion,bool &salirSubMenu,int deporte_medallas[87][3]){
	
	if(seleccionarOpcion!='0'){
		gotoxy(103,5);
		if(_getch()==13){
			
			switch(seleccionarOpcion){
			case '1':
					pais_mas_medallas_1(deporte_medallas);
				break;
			case '2':
					medallas_obtenidas_2(deporte_medallas);
				break;
			case '3':
					estadistica3(deporte_medallas);
				break;
			case '4':
					estadistica4(deporte_medallas);
				break;
			case 'x':
			case 'X':
				salirSubMenu = true;
				break;
			}
		}
	}
}
