#include <iostream>
#include <fstream>
#include <windows.h>
#include <time.h>
#include <string>
#include <iomanip>
#include "logicaArchivos.h"
#include "logicaMenus.h"
#include "logicaVisual.h"

using namespace std;


struct archivoCompentencia{
	competidores competencia[87];
	int deporte_medallas[87][3];
	tm fechaCreacion;
	int legajo;
	
};

void generarArchivoCompetencia(competidores competencia[],int deporte_medallas[87][3],int legajoIngresado,bool &competenciaGenerada,string &fileName){
	archivoCompentencia f;
	time_t ahora = time(0);
	//Se genera un arreglo competencia
	generarCompetencia(competencia);
	
	//se guarda en la estructura
	for(int i=0;i<87;i++){
		f.competencia[i] = competencia[i];
		
		for(int j=0;j<3;j++){
			f.deporte_medallas[i][j] = deporte_medallas[i][j];
		}
	}
	
	f.legajo = legajoIngresado;
	f.fechaCreacion = *localtime(&ahora);
	
	string nombreArchivo = obtenerFecha(f.fechaCreacion);
	//se crea un archivo de escritura en el cual se depositan los datos creados
	ofstream archivo(nombreArchivo, ios::binary);
	if(archivo.is_open()){
		archivo.write(reinterpret_cast<char*>(&f), sizeof(f));
		//operacion de escritura en caso de que se haya decidido crear un archivo nuevo
		//se crea un archivo con el tamano necesario de f para escribir los datos necesarios, previamente inicializados
		gotoxy(78,19);cout << "ARCHIVO GENERADO: " << nombreArchivo;
		Sleep(2000);
		
		competenciaGenerada = true;
		fileName = nombreArchivo;
		
		archivo.close();
		//se cierra el archivo para proceder con el programa normalmente. Al finalizar la ejecución
		//se abrirá nuevamente y se guardarán los cambios efectuados
	}
	else{
		gotoxy(78,19);cout << "ERROR AL CREAR EL ARCHIVO";
		Sleep(1000);
	}
}
	
void cargarArchivoCompetencia(competidores competencia[],int deporte_medallas[87][3],int legajoIngresa,bool &competenciaGenerada,string &fileName){
	string nombreArchivo;
	
	gotoxy(78,19);
	cout<<"INGRESE NOMBRE DEL ARCHIVO: ";
	
	gotoxy(78,20);
	cin>>nombreArchivo;
	
	archivoCompentencia f;
	ifstream archivo (nombreArchivo, ios::binary);
	
	if(archivo.is_open()){
		archivo.read(reinterpret_cast<char*>(&f), sizeof(f));
		//operacion de lectura para tomar los datos guardados e incorporarlos en la ejecucion
		//reinterpret_cast convierte la direccion de memoria de f en a un puntero de tipo char*
		//Se lee una cierta cantidad de bytes del archivo. En detalle lee la cantidad exacta del tamaño de f
		
		//Se cargan los datos guardados en el archivo
		for (int i = 0; i < 87; i++) {
			competencia[i] = f.competencia[i];
			for (int j = 0; j < 3; j++) {
				deporte_medallas[i][j] = f.deporte_medallas[i][j];
			}
		}
		
		gotoxy(78,19);cout<<"SE HA CARGADO EL ARCHIVO:        ";
		gotoxy(78,20);cout<<nombreArchivo;
		
		gotoxy(78,21);cout<<"PERTENECIENTE AL LEGAJO: ";
		gotoxy(78,22);cout<<f.legajo;
		
		gotoxy(78,23);cout<<"FECHA DE CREACION: ";
		mostrarFechaDesdeNombre(nombreArchivo);
		
		fileName = nombreArchivo;
		
		Sleep(2000);
		
		archivo.close();
		
		competenciaGenerada = true;
		
	}
	else{
		gotoxy(78,20);cout << "ERROR AL CARGAR EL ARCHIVO               ";
		Sleep(1500);
	}
	
}

void guardarArchivoCompetencia(string nombreArchivo,competidores competencia[],int deporte_medallas[87][3],int legajoIngresado){
	archivoCompentencia f;
	//Se vuelven a escribir los datos en f
	for(int i=0;i<87;i++){
		f.competencia[i] = competencia[i];
		
		for(int j=0;j<3;j++){
			f.deporte_medallas[i][j] = deporte_medallas[i][j];
		}
	}
	f.legajo = legajoIngresado;
	//Operacion de escritura
	ofstream archivo(nombreArchivo, ios::binary);
	if(archivo.is_open()){
		archivo.write(reinterpret_cast<char*>(&f), sizeof(f));
		archivo.close();
		
		gotoxy(66,20);cout<<"DATOS GUARDADOS";
		Sleep(1000);
	}
	else{
		gotoxy(66,20);cout<<"ERROR AL GUARDAR LOS DATOS";
		Sleep(1000);
	}
	
}

string obtenerFecha(const tm& fecha){
	ostringstream oss;			//ostringstream permite formar cadenas de string más fácil
	oss << setw(4) << setfill('0') << fecha.tm_year + 1900 << "-"			//Operador << funciona similar que con los cout <<
		<< setw(2) << setfill('0') << fecha.tm_mon + 1 << "-"
		<< setw(2) << setfill('0') << fecha.tm_mday << "-"
		<< setw(2) << setfill('0') << fecha.tm_hour << "-"
		<< setw(2) << setfill('0') << fecha.tm_min << "-"
		<< setw(2) << setfill('0') << fecha.tm_sec << ".bin";
	
	return oss.str();           //Devuelve oss como una variable string
}

void mostrarFechaDesdeNombre(string nombreArchivo) {
	// Extraer año, mes, día, hora, minuto y segundo
	string anio = nombreArchivo.substr(0, 4);        // AAAA
	string mes = nombreArchivo.substr(5, 2);         // MM
	string dia = nombreArchivo.substr(8, 2);         // DD
	string hora = nombreArchivo.substr(11, 2);       // HH
	string minuto = nombreArchivo.substr(14, 2);     // MM
	string segundo = nombreArchivo.substr(17, 2);    // SS
	
	// Mostrar fecha y hora en formato legible
	gotoxy(78,24);cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
	gotoxy(78,25);cout << "Hora: " << hora << ":" << minuto << ":" << segundo << endl;
}

