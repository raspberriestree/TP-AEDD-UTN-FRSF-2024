#include "logicaMostrarMedallero.h"
#include "logicaCargarMedallas.h"
#include "logicaMenus.h"
#include "logicaVisual.h"
#include "deportes.h"
#include "paises.h"
#include <string>
#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;


//Funciones de menú
void medalleroPorPais(int deporte_medallas[87][3]){
	int paises[197][3]={0}, arregloTopMedallero[197];
	int inicio=0, fin=196;
	
	limpiarConsola();
	
	convertirMatriz(deporte_medallas, paises);
	generarID(arregloTopMedallero);
	
	mergesortFuncion1(paises,arregloTopMedallero, inicio, fin);
	imprimirMedalleroPorPais(paises,arregloTopMedallero); 
	
	
}

void medalleroPorDeporte(int deporte_medallas[87][3]){
	int fila = 4;
	bool sePresionaX = false;
	char teclaX;
	limpiarConsola();
	
	mostrarTechoTopDeportes();

	for(int i=0; i<87; i++){
		
		if(!(deporte_medallas[i][2]==0 and deporte_medallas[i][1]==0 and deporte_medallas[i][0]==0)){
			
			//Deporte
			gotoxy(14,fila);cout<<"|";
			gotoxy(16,fila);imprimirDeporte(i+1);
			gotoxy(69,fila);cout<<"|";
			//Oro
			gotoxy(75,fila);imprimirAcronimoPais(deporte_medallas[i][0]);
			gotoxy(82,fila);cout<<"|";
			//Plata			
			gotoxy(89,fila);imprimirAcronimoPais(deporte_medallas[i][1]);
			gotoxy(95,fila);cout<<"|";
			//Bronce
			gotoxy(101,fila);imprimirAcronimoPais(deporte_medallas[i][2]);
			gotoxy(107,fila);cout<<"|";
			
			fila++;
		}
	}
	cout<<endl;
	gotoxy(13,fila);
	mostrarPisoTopDeportes();
	gotoxy(15,fila+1);
	cout<<"Presiona X para volver al menú ...";
	while(!sePresionaX){
		teclaX = _getch();
		
		if(teclaX == 'X' or teclaX == 'x'){
			sePresionaX = true;
		}
	}
}	
	
void topMedallero(int deporte_medallas[87][3]){
	int paises[197][3]={0}, arregloTopMedallero[197];
	int topInt, inicio=0, fin=196,paisesCargados = 0;
	bool sePresionaX = false;
	bool esValida = false;
	char teclaX;
	string topString;
	
	convertirMatriz(deporte_medallas,paises);
	
	generarID(arregloTopMedallero);
	mergesortFuncion3(paises,arregloTopMedallero,inicio,fin);
	
	paisesCargados = contarPaisesCargados(paises);
	
	gotoxy(71,20);
	cout<<"PRESIONE X PARA CANCELAR"<<endl;
	gotoxy(71,21);
	cout<<"INGRESE TOP QUE DESEA VER:";
	
	while(!sePresionaX){
		
		gotoxy(97,21);
		cin.clear();
		getline(cin, topString);
		
		//verifico que TOP sea un valor valido, osea de 1 a 196
		//ademas miro si presiona X
		esValida = entradaValidaTopMedallero(topString, topInt, sePresionaX);
		
		
		while (!esValida || (topInt > paisesCargados && !sePresionaX)){
			
			if(topInt>paisesCargados){
				gotoxy(71,22);cout<<"NO HAY SUFICIENTES PAISES CARGADOS";
				Sleep(752);
				gotoxy(71,22);cout<<"                                  ";
			}
			else{
				gotoxy(71,22);
				cout<<"TOP INVALIDO";
				Sleep(753);
				gotoxy(71,22);
				cout<<"             ";
			}
			gotoxy(97,21);
			cout<<"                 ";
			
			cin.clear();
			gotoxy(97,21);
			getline(cin, topString);
			esValida = entradaValidaTopMedallero(topString,topInt,sePresionaX);
			
		}
		
		if (!sePresionaX){
			
			limpiarConsola();
			
			imprimirTopMedallero(paises,arregloTopMedallero,topInt);
			
			while(!sePresionaX){
				teclaX = _getch();
				
				if(teclaX == 'X' or teclaX == 'x'){
					sePresionaX = true;
				}
			}
		}
	}
}

//Funciones de Impresion
void imprimirMedalleroPorPais (int paises[197][3],int arregloTopMedallero[197]){
	int i = 0;
	int fila = 4;
	bool sePresionaX = false;
	char teclaX;

	mostrarTechoTopPaises();
	
	while (i <= 196) {
		if (!(paises[i][0] == 0 && paises[i][1] == 0 && paises[i][2] == 0)) {
			gotoxy(24,fila);cout<<"|";
			
			gotoxy(25,fila);
			imprimirPais(arregloTopMedallero[i] - 1);
			gotoxy(53,fila);cout<<"|";
			
			//Oro
			gotoxy(59,fila);cout<<paises[i][0];
			gotoxy(66,fila);cout<<"|";
			//Plata
			gotoxy(73,fila);cout<<paises[i][1];
			gotoxy(79,fila);cout<<"|";
			//Bronce
			gotoxy(85,fila);cout<<paises[i][2];
			gotoxy(92,fila);cout<<"|";
			
			gotoxy(98,fila);cout<<paises[i][0] + paises[i][1] + paises[i][2];
			gotoxy(105,fila);cout<<"|";
			
			fila++;
		}
		i++;
	}
	cout<<endl;
	
	gotoxy(23,fila);
	mostrarPisoTopPaises();
	
	gotoxy(24,fila+1);
	cout<<"Presiona X para volver al menú ...";
	while(!sePresionaX){
		teclaX = _getch();
		
		if(teclaX == 'X' or teclaX == 'x'){
			sePresionaX = true;
		}
	}
}

void imprimirTopMedallero(int paises[197][3],int arregloTopMedallero[197], int top){
	int fila = 4;
	
	mostrarTechoTopMedallero();
	
	for(int i=0;i<top;i++){
		if((paises[i][0] + paises[i][1] + paises[i][2] )>0){
		
		//Posicion	
		gotoxy(27,fila);cout<<"|";
		gotoxy(29,fila);cout<<i+1;
		gotoxy(31,fila);cout<<"|";
		//Pais
		gotoxy(32,fila);
		imprimirPais(arregloTopMedallero[i]-1);
		gotoxy(60,fila);cout<<"|";
		
		//Oro
		gotoxy(64,fila);cout<<paises[i][0];
		gotoxy(69,fila);cout<<"|";
		//Plata
		gotoxy(74,fila);cout<<paises[i][1];
		gotoxy(79,fila);cout<<"|";
		//Bronca
		gotoxy(83,fila);cout<<paises[i][2];
		gotoxy(88,fila);cout<<"|";
		//total
		gotoxy(92,fila);cout<<paises[i][0]+paises[i][1]+paises[i][2];
		gotoxy(96,fila);cout<<"|";
		
		fila++;
		}
	}
	gotoxy(27,fila);
	mostrarPisoTopMedallero();
	
	gotoxy(28,fila+1);
	cout<<"Presiona X para volver al menú ...";
}

//Logica y Ordenamientos
void convertirMatriz(int deporte_medallas[87][3],int paises[197][3]){
	int country;
	
	for(int i=0;i<87;i++){
		for(int j=0;j<3;j++){
			country=deporte_medallas[i][j];
			if(country>0)
			paises[country][j]= paises[country][j] + 1;
		}
	}
}

void generarID(int arregloID[197]){
	int j=1;
	
	for (int i=0; i<197; i++){
		
		arregloID[i]=j;
		j++;
	}
}

void mergesortFuncion1(int paises[197][3],int id[197],int inicio,int fin){
	
	if(inicio<fin){
		int mitad = inicio + (fin-inicio)/2;
		mergesortFuncion1(paises,id,inicio,mitad);
		mergesortFuncion1(paises,id,mitad+1,fin);
		mergeFuncion1(paises,id,inicio,mitad,fin);
	}
}

void mergeFuncion1(int paises[197][3],int id[197], int inicio, int mitad, int fin){
	
	int i, j, k, p;
	int elementosizq = (mitad - inicio + 1), elementosder = (fin - mitad);
	
	int izq[100][3]; // Submatriz izquierda
	int der[100][3]; // Submatriz derecha
	int idizq[100], idder[100]; // IDs correspondientes
	
	// Copiar las submatrices y sus IDs
	for (i = 0; i < elementosizq; i++) {
		for (j = 0; j < 3; j++) {
			izq[i][j] = paises[inicio + i][j];
		}
		idizq[i] = id[inicio + i];
	}
	for (i = 0; i < elementosder; i++) {
		for (j = 0; j < 3; j++) {
			der[i][j] = paises[mitad + 1 + i][j];
		}
		idder[i] = id[mitad + 1 + i];
	}
	
	i = 0;  // Índice inicial para la submatriz izquierda
	j = 0;  // Índice inicial para la submatriz derecha
	k = inicio;  // Índice inicial para la matriz combinada
	
	// Combinar las dos submatrices
	while (i < elementosizq && j < elementosder) {
		// Comparar por medallas de oro, luego plata, luego bronce
		if (izq[i][0] > der[j][0] || 
			(izq[i][0] == der[j][0] && izq[i][1] > der[j][1]) || 
			(izq[i][0] == der[j][0] && izq[i][1] == der[j][1] && izq[i][2] > der[j][2])) {
			for (p = 0; p < 3; p++) paises[k][p] = izq[i][p];
			id[k] = idizq[i];
			i++;
		} 
			// Si son iguales en oro, plata y bronce, desempatar por ID (alfabético)
		else if (izq[i][0] == der[j][0] && izq[i][1] == der[j][1] && izq[i][2] == der[j][2]) {
			if (idizq[i] < idder[j]) {  // Desempatar por ID en orden ascendente
				for (p = 0; p < 3; p++) paises[k][p] = izq[i][p];
				id[k] = idizq[i];
				i++;
			} else {
				for (p = 0; p < 3; p++) paises[k][p] = der[j][p];
				id[k] = idder[j];
				j++;
			}
			} else {
			for (p = 0; p < 3; p++) paises[k][p] = der[j][p];
			id[k] = idder[j];
			j++;
		}
		k++;
	}
	
	// Copiar los elementos restantes de la submatriz izquierda
	while (i < elementosizq) {
		for (p = 0; p < 3; p++) paises[k][p] = izq[i][p];
		id[k] = idizq[i];
		i++;
		k++;
	}
	
	// Copiar los elementos restantes de la submatriz derecha
	while (j < elementosder) {
		for (p = 0; p < 3; p++) paises[k][p] = der[j][p];
		id[k] = idder[j];
		j++;
		k++;
	}
}
	
void mergesortFuncion3(int paises[197][3],int arregloTopMedallero[197],int inicio,int fin){
	
	if(inicio<fin){
		int mitad= inicio + (fin-inicio)/2;
		mergesortFuncion3(paises,arregloTopMedallero,inicio,mitad);
		mergesortFuncion3(paises,arregloTopMedallero,mitad+1,fin);
		mergeFuncion3(paises,arregloTopMedallero,inicio,mitad,fin);
	}
}

void mergeFuncion3(int paises[197][3],int arregloTopMedallero[197], int inicio, int mitad, int fin){
	int i,j,k,p;
	int elementosizq=mitad-inicio+1,elementosder=fin-mitad;
	
	int izq[100][3]; 
	int der[100][3];
	int idizq[100], idder[100];
	
	for(i=0;i<elementosizq;i++){
		
		for(j=0;j<3;j++){
			izq[i][j]=paises[inicio+i][j]; 
		}
		idizq[i]=arregloTopMedallero[inicio+i];
	}
	
	for(i=0;i<elementosder;i++){
		
		for(j=0;j<3;j++){
			der[i][j]=paises[mitad+1+i][j]; // ver [j]
		}
		
		idder[i]=arregloTopMedallero[mitad+1+i];
	}
	
	i=0;
	j=0;
	k=inicio;
	
	while(i<elementosizq and j<elementosder){
		
		if((izq[i][0] + izq[i][1] + izq[i][2]) >= (der[j][0] + der[j][1] + der[j][2])){
			
			for(p=0;p<3;p++) paises[k][p]=izq[i][p]; 
			
			arregloTopMedallero[k]=idizq[i];
			i++;
		}
		else{
			
			for(p=0;p<3;p++)paises[k][p]=der[j][p];
			arregloTopMedallero[k]=idder[j];
			j++;
		}
		k++;
	}
	
	while(j<elementosder){
		
		for(int p=0;p<3;p++){
			paises[k][p]=der[j][p];
		}
		
		arregloTopMedallero[k]=idder[j]; //cambio id correspondiente
		j++;
		k++;
	}
	while(i<elementosizq){
		
		for(int p=0;p<3;p++){
			paises[k][p]=izq[i][p];
		} 
		
		arregloTopMedallero[k]=idizq[i]; //cambio id correspondiente
		i++;
		k++;
	}
}
	
bool entradaValidaTopMedallero(string topString,int &topInt, bool &sePresionaX){
	bool esValida = false;
	
	if(topString.length()==3){
		if((topString[0]>='0' and topString[0]<='9') and (topString[1]>='0' and topString[1]<='9') and (topString[1]>='0' and topString[1]<='9')){
			topInt = atoi(topString.c_str());
			
			if(topInt>99 && topInt<=197){
				esValida = true;
			}
		}
	}
	if(topString.length()==2){
		if((topString[0]>='0' and topString[0]<='9') and (topString[1]>='0' and topString[1]<='9')){
			
			topInt = atoi(topString.c_str());
			
			if(topInt>9 && topInt<=99){
				esValida = true;
			}
		}
	}
	if(topString.length()==1){
		if((topString[0]>='0' and topString[0]<='9')){
			topInt = atoi(topString.c_str());
			
			if(topInt>0){
				esValida = true;
			}
		}
		else if((topString[0]>='x' or topString[0]<='X')){
			sePresionaX = true;
			esValida = true;
		}
	}
	return esValida;
}

int contarPaisesCargados(int paises[197][3]){
	int sumaFila = 0;
	int paisesCargados = 0;
	
	for(int i=0;i<197;i++){
		for(int j=0;j<3;j++){
			sumaFila+=paises[i][j];
		}
		if(sumaFila>0){
			paisesCargados++;
		}
		sumaFila = 0;
	}
	return paisesCargados;
}
