#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include <cctype>
#include "logicaMostrarMedallero.h"
#include "logicaCargarMedallas.h"
#include "logicaMenus.h"
#include "logicaVisual.h"
#include "logicaMenuEstadisticas.h"
#include "deportes.h"
#include "paises.h"

using namespace std;

// 53 indices invididual

void pais_mas_medallas_1(int deporte_medallas[87][3]){
	
	bool sePresionaX = false;
	char teclaX;
	
	limpiarConsola();
	
	mostrarEstadistica1(); //Visual
	
	int paises[197][3] = {0};
	
	convertirMatriz(deporte_medallas, paises);
	
	int pais_mayor=0;
	int max_medallas=0, cant_medallas=0;
	
	for (int i=0; i<197; i++){
		
		cant_medallas=0;
		
		for (int j=0; j<3; j++){	
			
			cant_medallas+=paises[i][j];
		}
		
		if (cant_medallas>max_medallas){
			
			max_medallas = cant_medallas;
			pais_mayor = i;
		}
	}
	
	gotoxy(25,3);
	imprimirPais(pais_mayor);
	
	gotoxy(75,3);
	cout<<max_medallas;
	
	gotoxy(25,6);
	cout<<"Presiona X para volver al menú ...";
	
	while(!sePresionaX){
		teclaX = _getch();
		
		if(teclaX == 'X' or teclaX == 'x'){
			sePresionaX = true;
		}
	}
}
	
void medallas_obtenidas_2(int deporte_medallas[87][3]){
	bool sePresionaX = false;
	bool esValida = false;
	char teclaX;
	string idPais;
	
	limpiarConsola();
	
	int paises[197][3] = {0};
	convertirMatriz(deporte_medallas, paises);
	
	while(!sePresionaX){
		
		mostrarEstadistica2(); // Visual
		
		cin.clear();
		
		gotoxy(82,27);
		
		getline(cin,idPais);
		
		esValida = entradaValidaMedallasObtenidas(idPais,sePresionaX);
		
		if(esValida && not sePresionaX){
			limpiarConsola();
			mostrarMedallasObtenidasPorPais();
			int idPaisInt = atoi(idPais.c_str());
			
			gotoxy(19,4);imprimirPais(idPaisInt);
			gotoxy(56,4);cout<<paises[idPaisInt][0];
			gotoxy(67,4);cout<<paises[idPaisInt][1];
			gotoxy(79,4);cout<<paises[idPaisInt][2];
			gotoxy(19,6);cout<<"PRESIONE X PARA REGRESAR";
			
			while(!sePresionaX){
				teclaX = _getch();
				if(teclaX == 'x' or teclaX == 'X'){
					sePresionaX = true;
					
				}
			}
			
		}
		else if(!esValida){
			gotoxy(61,27);cout<<"ERROR, INTENTELO OTRA VEZ...           ";
			Sleep(700);
			limpiarConsola();
		}
	}
}
	
void estadistica3(int deporte_medallas[87][3]){
	int frec[197]={0};
	int indice, indiceIndividual, max;
	bool sePresionaX = false;
	char teclaX;
	
	for(indice=0; indice < 53; indice++){
		
		indiceIndividual = obtenerindiceindividual(indice);
		
		for(int j=0;j<3;j++){
			
			frec[deporte_medallas[indiceIndividual-1][j] - 1]++; //segun el pais que aparezca se le va sumando una
			
		} 
	}
	
	max = frec[0]; // max toma el valor de la cantidad de medallas individuales que tiene el primer pais
	indice = 0; // indice toma el indice de este pais
	
	for(int i=0;i<197;i++){
		
		if(frec[i]>max){
			
			max = frec[i];
			indice = i;
		}
	}
	
	limpiarConsola();
	mostrarEstadistica3();
	
	gotoxy(25,3);
	imprimirPais(indice+1);
	
	gotoxy(75,3); cout << max;
	
	gotoxy(25,6); cout << "Presiona X para volver al menú ...";
	
	while(!sePresionaX){
		teclaX = _getch();
		
		if(teclaX == 'x' or teclaX == 'X'){
			sePresionaX = true;
		}
	}
}
	
void estadistica4(int deporte_medallas[87][3]){
	int fila = 1;
	int coincidencias = 0;
	bool sePresionaX = false;
	char teclaX;
	string letra;
	
	cin.clear();
	
	gotoxy(14,20); cout << "Ingrese la letra con la que comienza el deporte a visualizar ... ";
	cin >> letra;
	
	while(letra.length() != 1 or !isalpha(letra[0])){
		gotoxy(14,20); cout << "Entrada invalida, intente nuevamente...                                                                       ";
		gotoxy(54,20); cin >> letra;
	}
	
	letra[0] = toupper(letra[0]);
	
	limpiarConsola();
	
	mostrarTechoTopDeportes();
	
	for(int indice=1;indice<=87;indice++){
		
		if(deporte_medallas[indice-1][0] != 0 && letraigual(indice,letra,coincidencias)){
			//Deporte
			gotoxy(14,fila+3); cout << "|";
			gotoxy(16,fila+3); imprimirDeporte(indice);
			gotoxy(69,fila+3); cout << "|";
			
			//Oro
			gotoxy(75,fila+3); imprimirAcronimoPais(deporte_medallas[indice-1][0]);
			gotoxy(82,fila+3); cout << "|";
			
			//Plata
			gotoxy(89,fila+3); imprimirAcronimoPais(deporte_medallas[indice-1][1]);
			gotoxy(95,fila+3); cout << "|";
			
			//Bronce
			gotoxy(101,fila+3); imprimirAcronimoPais(deporte_medallas[indice-1][2]);
			gotoxy(107,fila+3); cout << "|";
			
			fila++;
		}
	}
	if(coincidencias == 0){
		gotoxy(14,fila+3); cout << "| No se ha encontrado ningún deporte";
		gotoxy(69,fila+3); cout << "|";
		gotoxy(82,fila+3); cout << "|";
		gotoxy(95,fila+3); cout << "|";
		gotoxy(107,fila+3); cout << "|";
		gotoxy(13,fila+4); mostrarPisoTopDeportes();
	}
	else{
		cout << "\n";
		gotoxy(13,fila+3); mostrarPisoTopDeportes();
		
	}
	gotoxy(15,fila+5); cout << "Presiona X para volver al menú ...";
	
	while(!sePresionaX){
		teclaX = _getch();
		
		if(teclaX == 'x' or teclaX == 'X'){
			sePresionaX = true;
			
		}
	}
	cin.ignore();
	
}
	
bool entradaValidaMedallasObtenidas(string idPais,bool &sePresionaX){
	bool esValida = false;
	int idPaisInt;
	
	if(idPais.length() == 3){
		if((idPais[0]>='0' && idPais[0]<='9') && (idPais[1]>='0' && idPais[1]<='9') && (idPais[2]>='0' && idPais[2]<='9')){
			idPaisInt = atoi(idPais.c_str());
			
			if(idPaisInt>99 && idPaisInt<197){
				esValida = true;
			}
		}
	}
	if(idPais.length() == 2){
		if((idPais[0]>='0' && idPais[0]<='9') && (idPais[1]>='0' && idPais[1]<='9')){
			idPaisInt = atoi(idPais.c_str());
			
			if(idPaisInt>9 && idPaisInt<100){
				esValida = true;
			}
		}
	}
	if(idPais.length() == 1){
		
		if(idPais[0]>='0' && idPais[0]<='9'){
			idPaisInt = atoi(idPais.c_str());
			
			if(idPaisInt > 0){
				esValida = true;
			}
		}
		else if(idPais[0] == 'x' or idPais[0] == 'X'){
			esValida = true;
			sePresionaX = true;
		}
	}
	
	return esValida;
}
