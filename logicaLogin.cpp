#include "logicaLogin.h"
#include "logicaVisual.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <limits>
using namespace std;

/*
Indice de Funciones
	SePresionaSPACE() - Línea 19
	login() - Linea 45
	mostrarContrasena() - Linea 122
	generarContrasena() - Linea 157
	hallarCapicua() - Linea 171
*/

bool sePresionaSPACE(bool &accesoLogin){
	
	bool sePresiono = false;
	
	gotoxy(14,22);
	cout<<"Presiona SPACE para continuar ...\n";
	gotoxy(47,22);
	
	while(not sePresiono){
		
		if(GetAsyncKeyState(VK_SPACE)){
			sePresiono = true;
			accesoLogin = true;
			
			//_kbhit() permite que los caracteres que se presionen no se escriban
			//en la consola.
			//Esto permite que no se escriban datos en el Login antes que se presione SPACE
			while(_kbhit()){
				_getch();
			}
		}
	}
	
	return sePresiono;
}
	
void login(bool & accesoMenu,int &legajoIngresado){
	bool esCorrecta = false;
	string legajoString;
	int legajoInt,contrasena;
	int contadorErrores = 0;
	
	recuadroExterior();
	pantallaLogin();
	
	while(not esCorrecta && contadorErrores<3){
		bool entradaValida = true;
		
		gotoxy(65,10);
		if(cin.peek()=='\n'){
			cin.ignore();
			entradaValida = false;
		}
		else if(!(cin>>legajoString) or !legajoValido(legajoString,legajoInt)){
			
			if(cin.eof()){
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				gotoxy(57,14);
				cout<<"Usuario invalido, intentelo otra vez";
				
			}
			else{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				gotoxy(57,14);
				cout<<"Usuario invalido, intentelo otra vez";
			}
			
			entradaValida = false;
			Sleep(1000);
			limpiarConsola();
			recuadroExterior();
			pantallaLogin();
			
		}
		
		if(entradaValida){
			
			while(not esCorrecta && contadorErrores<3){
				mostrarContrasena(contrasena);
				
				if(contrasena!=generarContrasena(legajoInt)){
					limpiarConsola();
					contadorErrores++;
					recuadroExterior();
					pantallaLogin();
					
					gotoxy(56,14);
					cout<<"Contrasena incorrecta"<<endl;
					gotoxy(56,15);
					cout<<3-contadorErrores<<" Intentos restantes ..."<<endl;
					gotoxy(65,10);
					cout<<legajoInt;
				}
				else if(contrasena==generarContrasena(legajoInt)){
					esCorrecta = true;
					accesoMenu = true;
				}
			}
		}
	}
	if(contadorErrores==3){
		gotoxy(56,15);
		cout<<"Alcanzaste el limite de intentos"<<endl;
		Sleep(1000);
	}
	else{
		legajoIngresado = legajoInt;
		gotoxy(56,14);
		cout<<"                         ";
		gotoxy(56,15);
		cout<<"                         ";
		gotoxy(57,15);
		cout<<"Accediendo ..."<<endl;
		Sleep(1000);
		limpiarConsola();
	}
}	
	
void mostrarContrasena(int &contrasena){
	bool valido = true;
	char caracter;
	contrasena = 0;
	
	gotoxy(68,12);
	
	while(valido){
		caracter = _getch();
		
		if(caracter == 13){
			//13 == codigo ASCII del ENTER
			//si se presiona, finaliza el ingreso de entrada
			cout<<"\n";
			valido = false;
		}
		else if(caracter == 8){
			//8 == codigo ASCII del BACKSPACE
			if(contrasena>0){
				//movemos el cursor hacia atras y reemplazamos
				//el caracter de la consola con un espacio
				cout<<"\b \b";
				//borramos el ultimo digito guardado
				contrasena/=10;
			}
		}
		else if(caracter!=32){
			//Se escribe un asterisco en consola
			//siempre y cuando no sea un espacio
			cout<<"*";
			contrasena = contrasena * 10 + (caracter - '0');
		}
	}
}
	
int generarContrasena(int legajo){
	int contrasenaGenerada;
	int numeroN;
	int ultimosTres;
	
	ultimosTres = (((legajo/100)%10)*100)+(((legajo/10)%10)*10)+(legajo%10);
	
	numeroN = ((legajo/10000)*100)+(((legajo/100)%10)*10)+(legajo%10);
	
	contrasenaGenerada = (2024 * hallarCapicua(numeroN)) + ultimosTres;
	
	return contrasenaGenerada;
}
	
int hallarCapicua(int numeroN){
	int capicua;
	bool encontrado = false;
	
	if(numeroN==999){
		capicua = 1001;
	}
	else{
		while(not encontrado){
			numeroN++;
			
			if(numeroN%10 == numeroN/100){
				capicua = numeroN;
				encontrado = true;
			}
		}
	}
	
	return capicua;
}
	
bool legajoValido(string legajoString, int & legajoInt){
	bool entradaValida = false;
	
	if(legajoString.length()==5){
		//Si la cadena tiene tamaño 5, se convierte a un arreglo de caracteres
		// y con atoi() se convierte a un int
		legajoInt = atoi(legajoString.c_str());
		
		//Se verifica que el entero generado este en el rango
		if(legajoInt>=10000 and legajoInt<100000){
			entradaValida = true;
		}
	}
	
	return entradaValida;
}
