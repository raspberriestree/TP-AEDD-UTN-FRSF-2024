#include <iostream>
#include "deportes.h"
#include "logicaVisual.h"
#include "logicaCargarMedallas.h"
#define totalDeportes 87
#define deportesIndividuales 53
#define deportesColectivos 34
using namespace std;
const char* deportes[] = {
	"Carreras de velocidad - 100 metros",
		"Carreras de velocidad - 200 metros",
		"Carreras de velocidad - 400 metros",
		"Carreras de medio fondo - 800 metros",
		"Carreras de medio fondo - 1500 metros",
		"Carreras de fondo - 5000 metros",
		"Carreras de fondo - 10000 metros",
		"Marat�n (42.195 km)",
		"Carreras con vallas - 110 metros vallas (hombres)",
		"Carreras con vallas - 100 metros vallas (mujeres)",
		"Carreras con vallas - 400 metros vallas",
		"Carreras de relevos - 4x100 metros",
		"Carreras de relevos - 4x400 metros",
		"Marcha atl�tica - 20 km marcha",
		"Marcha atl�tica - 35 km marcha",
		"Saltos - Salto de altura",
		"Saltos - Salto con p�rtiga",
		"Saltos - Salto de longitud",
		"Saltos - Triple salto",
		"Lanzamientos - Lanzamiento de peso",
		"Lanzamientos - Lanzamiento de disco",
		"Lanzamientos - Lanzamiento de martillo",
		"Lanzamientos - Lanzamiento de jabalina",
		"Pruebas combinadas - Decatl�n (hombres)",
		"Pruebas combinadas - Heptatl�n (mujeres)",
		"Badminton",
		"Baloncesto",
		"Baloncesto 3x3",
		"Balonmano",
		"B�isbol",
		"Softbol",
		"Boxeo",
		"Ciclismo BMX",
		"Ciclismo de monta�a",
		"Ciclismo de pista",
		"Ciclismo de ruta",
		"Escalada deportiva",
		"Esgrima",
		"F�tbol",
		"Gimnasia art�stica",
		"Gimnasia r�tmica",
		"Trampol�n",
		"Golf",
		"Halterofilia",
		"Hockey sobre c�sped",
		"Judo",
		"Karate",
		"Kata",
		"Kumite",
		"Lucha libre",
		"Lucha grecorromana",
		"Nataci�n - Estilo libre - 50 metros",
		"Nataci�n - Estilo libre - 100 metros",
		"Nataci�n - Estilo libre - 200 metros",
		"Nataci�n - Estilo libre - 400 metros",
		"Nataci�n - Estilo libre - 800 metros",
		"Nataci�n - Estilo libre - 1500 metros",
		"Nataci�n - Estilo espalda - 100 metros",
		"Nataci�n - Estilo espalda - 200 metros",
		"Nataci�n - Estilo braza - 100 metros",
		"Nataci�n - Estilo braza - 200 metros",
		"Nataci�n - Estilo mariposa - 100 metros",
		"Nataci�n - Estilo mariposa - 200 metros",
		"Nataci�n - Estilos combinados - 200 metros combinados",
		"Nataci�n - Estilos combinados - 400 metros combinados",
		"Nataci�n - Relevos - 4x100 metros libre",
		"Nataci�n - Relevos - 4x200 metros libre",
		"Nataci�n - Relevos - 4x100 metros estilos",
		"Nataci�n en aguas abiertas - 10 km",
		"Nataci�n art�stica",
		"Pentatl�n moderno",
		"Pirag�ismo en eslalon",
		"Pirag�ismo en sprint",
		"Remo",
		"Rugby 7",
		"Skateboarding",
		"Surf",
		"Taekwondo",
		"Tenis",
		"Tenis de mesa",
		"Tiro con arco",
		"Tiro deportivo",
		"Triatl�n",
		"Vela",
		"Voleibol de pista",
		"Voleibol de playa",
		"Waterpolo"
};

int indicesIndividuales[] = {
	1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 
		25, 33, 34, 35, 36, 37, 46, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 
		59, 60, 61, 62, 63, 64, 71, 72, 73, 77, 78, 80, 82
};

int indicesColectivos[] = {
	12, 13, 26, 27, 28, 29, 30, 31, 32, 38,39, 40, 41, 42, 43, 44, 45, 47, 65, 66, 67, 68, 69, 70, 74, 75, 76, 79, 81, 83, 
		84, 85, 86, 87
};

void imprimirDeporte(int indice) {
	if (indice >= 1 && indice <= totalDeportes) {
		cout << deportes[indice - 1] << endl;
	} else {
		cout << "Indice fuera de rango" << endl;
	}
}
void mostrarDeportes() {
	for (int indice=0; indice < totalDeportes;indice++) {
		cout <<indice+1<<" - "<< deportes[indice] << ", ";
	}
}

void mostrarDeportesIndividuales() {
	int veces=0;
	
	for (int indice=0; indice < deportesIndividuales; indice++) {
		veces++;
		
		if (veces<=27){
			gotoxy(2,veces+1);
			cout << indicesIndividuales[indice];
			gotoxy(6,veces+1);
			cout<<deportes[indicesIndividuales[indice]-1];
			
		} else {
			
			gotoxy(61,veces-26);
			cout <<indicesIndividuales[indice];
			gotoxy(65,veces-26);
			cout<<deportes[indicesIndividuales[indice]-1];
		}
		
		
	}
	gotoxy(65,28);
	cout<<":                                      ";
	gotoxy(65,28);
	cout<<"Seleccione un deporte o X para salir:";
}

void mostrarDeportesColectivos() {
	int veces=0;
	
	for (int indice=0; indice < deportesColectivos; indice++) {
		veces++;
		
		if (veces<=27){
			gotoxy(2,veces+1);
			cout << indicesColectivos[indice];
			gotoxy(6,veces+1);
			cout<<deportes[indicesColectivos[indice]-1];
			
		} else {
			
			gotoxy(61,veces-26);
			cout <<indicesColectivos[indice];
			gotoxy(65,veces-26);
			cout<<deportes[indicesColectivos[indice]-1];
		}
		
		
	}
	gotoxy(65,28);
	cout<<":                                      ";
	gotoxy(65,28);
	cout<<"Seleccione un deporte o X para salir:";
}

bool estaEnListaIndividual(int IDDeporteInt){
	bool estaEnLista = false;
	int i = 0;
	
	while(not estaEnLista && i<53){
		if(IDDeporteInt == indicesIndividuales[i]){
			estaEnLista = true;
		}
		else i++;
	}
	
	return estaEnLista;
}
	
bool estaEnListaColectivo(int IDDeporteInt){
	bool estaEnLista = false;
	int i = 0;
	
	while(not estaEnLista && i<34){
		if(IDDeporteInt == indicesColectivos[i]){
			estaEnLista = true;
		}
		else i++;
	}

	return estaEnLista;
}	
bool letraigual(int indice,string letra,int &coincidencias){
	bool letrita=false;
	
	if(deportes[indice-1][0]==letra[0]){
		coincidencias++;
		letrita=true;
	}
	
	return letrita;
}
int obtenerindiceindividual(int i){
	
	return indicesIndividuales[i];
}
	/*
	
	void mostrarDeportesIndividuales() {
		for (int indice=0; indice < deportesIndividuales;indice++) {
			cout <<indicesIndividuales[indice]<<" - "<< deportes[indicesIndividuales[indice]-1] << ", "<<endl;
		}
	}
	
	void mostrarDeportesColectivos() {
		for (int indice=0; indice < deportesColectivos;indice++) {
			cout <<indicesColectivos[indice]<<" - "<< deportes[indicesColectivos[indice]-1] << ", "<<endl;
		}
	}	
	
	//copia de las funciones antes de modificarlas
	
	*/
/*	
	void mostrarDeportesColectivos() {
		for (int indice=0; indice < deportesColectivos;indice++) {
			cout <<indicesColectivos[indice]<<" - "<< deportes[indicesColectivos[indice]-1] << ", "<<endl;
		}
	}
*/	
