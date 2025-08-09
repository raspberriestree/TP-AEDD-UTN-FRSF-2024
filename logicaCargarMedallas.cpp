#include "logicaCargarMedallas.h"
#include "logicaMenus.h"
#include "logicaVisual.h"
#include "deportes.h"
#include "paises.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <limits>
using namespace std;

void cargarMedallasIndividual(competidores competencia[],int deporte_medallas[87][3]){
	bool sePresionaX = false;
	string IDDeporteString;
	int IDDeporteInt;
	//limpiarConsola();
	
	while(!sePresionaX){
		//cin.clear();
		pantallaCargaDeporteInvidual();
		
		//Debe ingresar el ID del deporte en la lista
		//Con .ignore() no se considera el residuo que haya quedado en el buffer
		cin.clear();
		getline(cin,IDDeporteString);
		
		if(entradaValidaCargaMedallaDeporte(IDDeporteString,IDDeporteInt,sePresionaX) && !sePresionaX){
			//Verificar si está en la lista
			if(estaEnListaIndividual(IDDeporteInt)){
				
				if(!filaLlena(IDDeporteInt,deporte_medallas)){
					//Si hay lugar en la fila de la matriz accede a la carga de medallas
					cargarMedallas(IDDeporteInt,competencia,deporte_medallas);
					
				}
				else{
					gotoxy(65,28);
					cout<<":                                                    ";
					gotoxy(65,28);
					cout<<"Disciplina cargada totalmente"<<endl;
					Sleep(1000);
				}
			}
			else if(not sePresionaX){
				gotoxy(65,28);
				cout<<":                                                    ";
				gotoxy(65,28);
				cout<<"ID invalido, intentelo nuevamente"<<endl;
				Sleep(1000);
			}
		}
		else if(!sePresionaX){
			gotoxy(65,28);
			cout<<":                                                    ";
			gotoxy(65,28);
			cout<<"ID invalido, intentelo nuevamente";
			Sleep(1000);
		}
	}
}
	
void cargarMedallasColectivo(competidores competencia[],int deporte_medallas[87][3]){
	bool sePresionaX = false;
	string IDDeporteString;
	int IDDeporteInt;
	//limpiarConsola();
		
	while(!sePresionaX){
		pantallaCargaDeporteColectivo();
			
		//Debe ingresar el ID del deporte en la lista
		cin.clear();
		getline(cin,IDDeporteString);
		
		if(entradaValidaCargaMedallaDeporte(IDDeporteString,IDDeporteInt,sePresionaX) && !sePresionaX){
				
			//Verificar si está en la lista
			if(estaEnListaColectivo(IDDeporteInt)){
				
				if(!filaLlena(IDDeporteInt,deporte_medallas)){
					//Si hay lugar en la fila de la matriz accede a la carga de medallas
					cargarMedallas(IDDeporteInt,competencia,deporte_medallas);
						
				}
				else{
					gotoxy(65,28);
					cout<<":                                                    ";
					gotoxy(65,28);
					cout<<"Disciplina cargada totalmente"<<endl;
					Sleep(1000);
				}
			}
			else if(not sePresionaX){
				gotoxy(65,28);
				cout<<":                                                    ";
				gotoxy(65,28);
				cout<<"ID invalido, intentelo nuevamente";
				Sleep(1000);
			}
		}
		else if(!sePresionaX){
			gotoxy(65,28);
			cout<<":                                                    ";
			gotoxy(65,28);
			cout<<"ID invalido, intentelo nuevamente";
			Sleep(1000);
		}
	}
}

	
	
void cargarMedallas(int IDDeporteInt,competidores competencia[],int deporte_medallas[87][3]){
	bool sePresionaX = false;
	string IDPaisString;
	int IDPaisInt;
	
	int i = 0;
	
	limpiarConsola();
	pantallaCargando();
	
	recuadroPaises();
	gotoxy(47,3);
	imprimirDeporte(IDDeporteInt);
	
	int fila = 7;
	
	for(int j = 0; j<competencia[IDDeporteInt-1].TL; j++){
		
		
		gotoxy(49,fila);
		cout<<competencia[IDDeporteInt-1].paises[j];
		
		gotoxy(54,fila);
		imprimirPais(competencia[IDDeporteInt-1].paises[j]);	
		
		fila++;
	}	
	
	
	while(!sePresionaX && i<3){
		
		gotoxy(41,24);
		cout<<"Presione X para salir";
		
		if(i==0){
			gotoxy(41,25);
			cout<<"Ingrese el ID del pais que ha ganado el oro:                ";
			gotoxy(85,25);
			cin.clear();
			getline(cin,IDPaisString);
		}
		else if(i==1){
			gotoxy(41,25);
			cout<<"Ingrese el ID del pais que ha ganado la plata:              ";
			gotoxy(87,25);
			cin.clear();
			getline(cin,IDPaisString);
		}
		else if(i==2){
			gotoxy(41,25);
			cout<<"Ingrese el ID del pais que ha ganado el bronce:             ";
			gotoxy(88,25);
			cin.clear();
			getline(cin,IDPaisString);
		}
		
		
		//Verifica que la entrada sea valida
		if(entradaValidaCargaMedallaPais(IDPaisString,IDPaisInt,sePresionaX)){
			
			//Verifica si el equipo esta en el arreglo de esa competencia
			if(equipoCompite(IDPaisInt,IDDeporteInt,competencia)){
				//Accede a la logica de carga de la matriz
				cargarMatrizDeporteMedallas(i,IDPaisInt,IDDeporteInt,sePresionaX,deporte_medallas);
				
			}
			else if(not sePresionaX){
				gotoxy(41,26);
				cout<<"El pais no participa de la disciplina...";
				Sleep(757);
				
				gotoxy(41,26);
				cout<<"                                        ";
				i--;
			}
		}
		else{
			gotoxy(41,26);
			cout<<"ID invalido";
			Sleep(757);
			
			gotoxy(41,26);
			cout<<"           ";
			i--;
		}
		i++;
		
	}
	
}

void cargarMatrizDeporteMedallas(int &i,int IDPaisInt,int IDDeporteInt,bool sePresionaX,int deporte_medallas[87][3]){
	bool seRepite = false;
	int k = 0;
	
	if(sePresionaX){
		deporte_medallas[IDDeporteInt-1][0] = 0;
		deporte_medallas[IDDeporteInt-1][1] = 0;
		deporte_medallas[IDDeporteInt-1][2] = 0;
		//Borra la fila en caso de que no se haya cargado completamente la fila
	}
	else {
		while(!seRepite && k<3){			
			//Verificar que no se haya cargado antes el ID
			if(IDPaisInt==deporte_medallas[IDDeporteInt-1][k]){
				seRepite = true;
			}
			else k++;
		}
		if(!seRepite){
			if(deporte_medallas[IDDeporteInt-1][i]==0){
				deporte_medallas[IDDeporteInt-1][i] = IDPaisInt;
			}
		}
		else{
			i--;
			gotoxy(41,26);
			cout<<"Este pais ya ha ganado una medalla en esta competencia ...";
			Sleep(757);
			
			gotoxy(41,26);
			cout<<"                                                          ";
		}
	}
}

bool entradaValidaCargaMedallaDeporte(string IDDeporteString,int & IDDeporteInt, bool & sePresionaX){
	bool esValida = false;
	
	if(IDDeporteString.length() == 2){
		//Verifica si los dos caracteres son números
		if((IDDeporteString[0]>='0' and IDDeporteString[0]<='9') and (IDDeporteString[1]>='0' and IDDeporteString[1]<='9')){
			
			//Convierte en entero la variable string para mejor manejo de datos
			IDDeporteInt = ((IDDeporteString[0]-'0')*10)+(IDDeporteString[1]-'0');
			esValida = true;
		}
	}
	else if(IDDeporteString.length() == 1){
		if(IDDeporteString[0]>='0' and IDDeporteString[0]<='9'){
			
			IDDeporteInt = IDDeporteString[0]-'0';
			esValida = true;
		}
		else if(IDDeporteString[0]=='x' or IDDeporteString[0]=='X'){
			sePresionaX = true;
			esValida = true;
		}
	}
	
	return esValida;
}
	
bool entradaValidaCargaMedallaPais(string IDPaisString,int & IDPaisInt,bool & sePresionaX){
	bool esValida = false;
	
	if(IDPaisString.length()==3){
		if((IDPaisString[0]>='0' and IDPaisString[0]<='9') && (IDPaisString[1]>='0' and IDPaisString[1]<='9') && (IDPaisString[2]>='0' and IDPaisString[2]<='9')){
			
			IDPaisInt = ((IDPaisString[0]-'0')*100)+((IDPaisString[1]-'0')*10)+(IDPaisString[2]-'0');
			esValida = true;
		}
	}
	if(IDPaisString.length() == 2){
		//Verifica si los dos caracteres son números
		if((IDPaisString[0]>='0' and IDPaisString[0]<='9') and (IDPaisString[1]>='0' and IDPaisString[1]<='9')){
			
			//Convierte en entero la variable string para mejor manejo de datos
			IDPaisInt = ((IDPaisString[0]-'0')*10)+(IDPaisString[1]-'0');
			esValida = true;
		}
	}
	else if(IDPaisString.length() == 1){
		if(IDPaisString[0]>='0' and IDPaisString[0]<='9'){
			
			IDPaisInt = IDPaisString[0]-'0';
			esValida = true;
		}
		else if(IDPaisString[0]=='x' or IDPaisString[0]=='X'){
			sePresionaX = true;
			esValida = true;
		}
	}
	
	return esValida;
}

bool equipoCompite(int IDPaisInt,int IDDeporteInt,competidores competencia[87]){
	bool elEquipoCompite = false;
	
	int i = 0;
	//Verificar si el ID del Pais se encuentra en la competicion seleccionada
	while(!elEquipoCompite && i<competencia[IDDeporteInt-1].TL){
		if(IDPaisInt == competencia[IDDeporteInt-1].paises[i]){
			elEquipoCompite = true;
		}
		else i++;
	}
	
	return elEquipoCompite;
}
	
bool filaLlena(int IDDeporteInt,int deporte_medallas[87][3]){
	bool estaLlena = true;
	
	for(int j=0;j<3;j++){
		if(deporte_medallas[IDDeporteInt-1][j]==0){
			//Si hay al menos un cero entonces se puede ingresar datos
			estaLlena = false;
			
		}
		//Si no hay ceros, la fila está completa, entonces no deja cargar datos
	}
	return estaLlena;
}
