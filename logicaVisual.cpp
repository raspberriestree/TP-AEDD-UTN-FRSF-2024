#include "logicaVisual.h"
#include "deportes.h"
#include "paises.h"
#include <windows.h>
#include <iostream>
#include <iomanip>
using namespace std;

//Limpiar pantalla
void limpiarConsola(){
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
//Gotoxy
void gotoxy(SHORT x,SHORT y){
	
	COORD cp = {x,y};
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cp);		
}
	
//Pantallas de Bienvenida	
void recuadroExterior(){
	
	cout<<" ______________________________________________________________________________________________________________________ "<<endl;
	cout<<"|  __________________________________________________________________________________________________________________  |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |                                                                                                                  | |"<<endl;
	cout<<"| |__________________________________________________________________________________________________________________| |"<<endl;
	cout<<"|______________________________________________________________________________________________________________________|"<<endl;
	
}

void pantallaBienvenida(){
	gotoxy(5,2); cout<<"  ____   _                           _     _       ";
	gotoxy(5,3); cout<<" |  _ \\ (_)                         (_)   | |      ";
	gotoxy(5,4); cout<<" | |_) | _  ___ _ ____   _____ _ __  _  __| | ___  ";
	gotoxy(5,5); cout<<" |  _ < | |/ _ \\ '_ \\ \\ / / _ \\ '_ \\| |/ _` |/ _ \\ ";
	gotoxy(5,6); cout<<" | |_) || |  __/ | | \\ V /  __/ | | | | (_| | (_) |";
	gotoxy(5,7); cout<<" |____/ |_|\\___|_| |_|\\_/ \\___|_| |_|_|\\__,_|\\___/ ";

}
	
void pantallaPebetero(){
	
	
	gotoxy(65,2);cout<<"                        &&                  ";
	gotoxy(65,3);cout<<"                       & &&&                ";
	gotoxy(65,4);cout<<"                      &+    &&              ";
	gotoxy(65,5);cout<<"                   ;&&       &&             ";
	gotoxy(65,6);cout<<"                  &&          &             ";
	gotoxy(65,7);cout<<"                 &&           &+.&&&        ";
	gotoxy(65,8);cout<<"               &&&X           && .&         ";
	gotoxy(65,9);cout<<"               &&&&              &&        ";
	gotoxy(65,10);cout<<"              &&  &&&             &X       ";
	gotoxy(65,11);cout<<"              &&     &       &&    &       ";
	gotoxy(65,12);cout<<"              ;&     &&&&&&&&.;&   &&      ";
	gotoxy(65,13);cout<<"               &&    &&         &&&&&      ";
	gotoxy(65,14);cout<<"                 &&&&&            &&       ";
	gotoxy(65,15);cout<<"             :&                     &;     ";
	gotoxy(65,16);cout<<"              &  &                  &      ";
	gotoxy(65,17);cout<<"              && &&                &&      ";
	gotoxy(65,18);cout<<"               && x&&             &&       ";
	gotoxy(65,19);cout<<"                 &&  &;         &&         ";
	gotoxy(65,20);cout<<"                   &  :        &           ";
	gotoxy(65,21);cout<<"                   &  &        &           ";
	gotoxy(65,22);cout<<"                   &&         &&           ";
	gotoxy(65,23);cout<<"                     &&:   :&&             ";
	gotoxy(65,24);cout<<"                      &:   :&              ";
	gotoxy(65,25);cout<<"                      &:   :&              ";
	gotoxy(65,26);cout<<"                      &&&&&&&              ";
	
	
}
void pantallaAnillos(){
	gotoxy(10,9); cout<<"                                        ";
	gotoxy(10,10);cout<<"    @@@@@@       @@@@@@       @@@@@@    ";
	gotoxy(10,11);cout<<"  @       @@   @        @   @@       @  ";
	gotoxy(10,12);cout<<" @          @ @          @ @          @ ";
	gotoxy(10,13);cout<<" @        % @           @@ @@         @ ";
	gotoxy(10,14);cout<<" @       @  @ @       @  @ @  @       @ ";
	gotoxy(10,15);cout<<"  @       @@   @@    @ @@   @@ @     @  ";
	gotoxy(10,16);cout<<"    @@@ @        @@@@@%        @@@@@    ";
	gotoxy(10,17);cout<<"        @            @         @        ";
	gotoxy(10,18);cout<<"         @       @    @       @         ";
	gotoxy(10,19);cout<<"           @@@@@        @@@@@           ";
	gotoxy(10,20);cout<<"                                        ";
}
//Pantalla del Login

void pantallaLogin(){
	
	gotoxy(15,6); cout<<"                     %@@@@#                                                        "<<endl;
	gotoxy(15,7); cout<<"                @@@@%     @@@@@ _________________________________________________  "<<endl;
	gotoxy(15,8); cout<<"              @@       @@       @@_____________________________________________  | "<<endl;
	gotoxy(15,9); cout<<"            @@      @@@  @@@      @@                                           | | "<<endl;
	gotoxy(15,10);cout<<"          @@       @        @       @@    USUARIO:                             | | "<<endl;
	gotoxy(15,11);cout<<"         @@        @        @        @@                                        | | "<<endl;
	gotoxy(15,12);cout<<"        %@         @       @@         @+  CONTRASEÑA:                          | | "<<endl;
	gotoxy(15,13);cout<<"        @           @@@@@@@@           @                                       | | "<<endl;
	gotoxy(15,14);cout<<"        @                              @                                       | | "<<endl;
	gotoxy(15,15);cout<<"        @           @@@@@@@@           @                                       | | "<<endl;
	gotoxy(15,16);cout<<"        @        @@@        @@         @ ______________________________________| | "<<endl;
	gotoxy(15,17);cout<<"        @@      @@            @@      @@_________________________________________| "<<endl;
	gotoxy(15,18);cout<<"         @%    @@              @@    @@                                            "<<endl;
	gotoxy(15,19);cout<<"          @@   @                @   @@                                             "<<endl;
	gotoxy(15,20);cout<<"           @@   %#@@@@@@@@@@@@#%   @@                                              "<<endl;
	gotoxy(15,21);cout<<"             @@                  @@                                                "<<endl;
	gotoxy(15,22);cout<<"               @@@@          @@@:                                                  "<<endl;
	gotoxy(15,23);cout<<"                   @@@@@@@@@@                                                      "<<endl;
	
	
}	

void pantallaMenuPrincipal(bool & competenciaGenerada){
	cout << "\n\n\n";
	cout << "             ____________________________________________________" << endl;
	cout << "            |  ________________________________________________  |" << endl;
	cout << "            | |             __  __              __             | | SELECCIONAR OPCION Y PRESIONAR ENTER" << endl;
	cout << "            | |            |  \\/  |            /_/             | |____________________________________" << endl;
	cout << "            | |            | \\  / | ___ _ __  _   _            |  __________________________________  |" << endl;
	cout << "            | |            | |\\/| |/ _ \\ '_ \\| | | |           | |                                  | |" << endl;
	cout << "            | |            | |  | |  __/ | | | |_| |           | |                                  | |" << endl;
	cout << "            | |            |_|__|_|\\___|_| |_|\\__,_|           | |                                  | |" << endl;
	cout << "            | |   ______      _            _              _    | |                                  | |" << endl;
	cout << "            | |   |  __ \\    (_)          (_)            | |   | |                                  | |" << endl;
	cout << "            | |   | |__) | __ _ _ __   ___ _ _ __   __ _ | |   | |                                  | |" << endl;
	cout << "            | |   |  ___/ '__| | '_ \\ / __| | '_ \\ / _` || |   | |                                  | |" << endl;
	cout << "            | |   | |   | |  | | | | | (__| | |_) | (_| || |   | |                                  | |" << endl;
	cout << "            | |   |_|   |_|  |_|_| |_|\\___|_| .__/ \\__,_||_|   | |                                  | |" << endl;
	cout << "            | |                              | |               | |                                  | |" << endl;
	cout << "            | |                              |_|               | |__________________________________| |" << endl;
	cout << "            | |________________________________________________|  ____________________________________|" << endl;
	cout << "            |____________________________________________________|                                     " << endl;
	cout << "                                                                                                       " << endl;
	cout << "                                                                                                       " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;
	
	
	//verifico que se haya generado una competencia
	if (competenciaGenerada){
		
		gotoxy(72,9);
		cout<<"1 . GENERAR COMPETENCIAS";
		gotoxy(72,11);
		cout<<"2 . CARGAR MEDALLAS";
		gotoxy(72,13);
		cout<<"3 . MOSTRAR MEDALLERO";
		gotoxy(72,15);
		cout<<"4 . MOSTRAR ESTADISTICAS";
		gotoxy(72,17);
		cout<<"X . SALIR DEL PROGRAMA";
		
	} else {
		
		gotoxy(72,9);
		cout<<"1 . GENERAR COMPETENCIAS";
		gotoxy(72,11);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),8);
		cout<<"2 . CARGAR MEDALLAS";
		gotoxy(72,13);
		cout<<"3 . MOSTRAR MEDALLERO";
		gotoxy(72,15);
		cout<<"4 . MOSTRAR ESTADISTICAS";
		gotoxy(72,17);
		SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),7);
		cout<<"X . SALIR DEL PROGRAMA";
	}
	//si no se hizo, muestro la opcion 2 y 3 en gris para mostrar que son invalidas en ese momento
}
	
void dibujarFlechasMenuPrincipal(char &seleccionarOpcion){
	switch(seleccionarOpcion){
		case '1':
			gotoxy(67,9);cout<<"--->";
			gotoxy(67,11);cout<<"    ";
			gotoxy(67,13);cout<<"    ";
			gotoxy(67,15);cout<<"    ";
			gotoxy(67,17);cout<<"    ";
			break;
			
		case '2':
			gotoxy(67,9);cout<<"    ";
			gotoxy(67,11);cout<<"--->";
			gotoxy(67,13);cout<<"    ";
			gotoxy(67,15);cout<<"    ";
			gotoxy(67,17);cout<<"    ";
			break;
			
		case '3':
			gotoxy(67,9);cout<<"    ";
			gotoxy(67,11);cout<<"    ";
			gotoxy(67,13);cout<<"--->";
			gotoxy(67,15);cout<<"    ";
			gotoxy(67,17);cout<<"    ";
			break;
			
		case '4':
			gotoxy(67,9);cout<<"    ";
			gotoxy(67,11);cout<<"    ";
			gotoxy(67,13);cout<<"    ";
			gotoxy(67,15);cout<<"--->";
			gotoxy(67,17);cout<<"    ";
			break;
			
		case 'x':
		case 'X':
			gotoxy(67,9);cout<<"    ";
			gotoxy(67,11);cout<<"    ";
			gotoxy(67,13);cout<<"    ";
			gotoxy(67,15);cout<<"    ";
			gotoxy(67,17);cout<<"--->";
			break;
			
		default:{
			seleccionarOpcion = '0';
		}
	}
}
	
	
	
//Logica visual del Menu de carga de medallas
void pantallaMenuCargarMedalla(){
	
	cout << "\n\n\n";
	cout<<"             _________________________________________________ "<<endl;
	cout<<"            |  _____________________________________________  |"<<endl;
	cout<<"            | |        _____                                | | SELECCIONAR OPCION Y PRESIONAR ENTER"<<endl;
	cout<<"            | |       / ____|                               | |____________________________________________"<<endl;
	cout<<"            | |      | |     __ _ _ __ __ _  __ _ _ __      |  __________________________________________  |"<<endl;
	cout<<"            | |      | |    / _` | '__/ _` |/ _` | '__|     | |                                          | |"<<endl;
	cout<<"            | |      | |___| (_| | | | (_| | (_| | |        | |                                          | |"<<endl;    
	cout<<"            | |       \\_____\\__,_|_|  \\__, |\\__,_|_|        | |      1 . CARGA POR DEPORTE INDIVIDUAL    | |"<<endl;
	cout<<"            | |                        __/ |                | |                                          | |"<<endl;
	cout<<"            | |                       |___/                 | |      2 . CARGA POR DEPORTE COLECTIVO     | |"<<endl;
	cout<<"            | |    __  __          _       _ _              | |                                          | |"<<endl;
	cout<<"            | |   |  \\/  |        | |     | | |             | |      X . VOLVER AL MENU PRINCIPAL        | |"<<endl;
	cout<<"            | |   | \\  / | ___  __| | __ _| | | __ _ ___    | |                                          | |"<<endl;
	cout<<"            | |   | |\\/| |/ _ \\/ _` |/ _` | | |/ _` / __|   | |                                          | |"<<endl;
	cout<<"            | |   | |  | |  __/ (_| | (_| | | | (_| \\__ \\   | |__________________________________________| |"<<endl;
	cout<<"            | |   |_|  |_|\\___|\\__,_|\\__,_|_|_|\\__,_|___/   |  ____________________________________________|"<<endl;                                            
	cout<<"            | |                                             | | "<<endl;       
	cout<<"            | | ____________________________________________| |"<<endl;
	cout<<"            |_________________________________________________|"<<endl;
	
}
	
void mostrarRecuadroDeportes(){

	gotoxy(1,1);  cout<<"|ID|-------------------------------------------------------|ID|------------------------------------------------------|";
	gotoxy(1,2);  cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,3);  cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,4);  cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,5);  cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,6);  cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,7);  cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,8);  cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,9);  cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,10); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,11); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,12); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,13); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,14); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,15); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,16); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,17); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,18); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,19); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,20); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,21); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,22); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,23); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,24); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,25); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,26); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,27); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,28); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,29); cout<<"|  |                                                       |  |                                                      |";
	gotoxy(1,30); cout<<"|--|-------------------------------------------------------|--|------------------------------------------------------|";

}
	
void recuadroPaises(){
	
	gotoxy(47,4);  cout<<"||---|-----------------------------||";
	gotoxy(47,5);  cout<<"||IDP|             PAIS            ||";
	gotoxy(47,6);  cout<<"||---|-----------------------------||";
	gotoxy(47,7);  cout<<"||   |                             ||";
	gotoxy(47,8);  cout<<"||   |                             ||";
	gotoxy(47,9);  cout<<"||   |                             ||";
	gotoxy(47,10); cout<<"||   |                             ||";
	gotoxy(47,11); cout<<"||   |                             ||";
	gotoxy(47,12); cout<<"||   |                             ||";
	gotoxy(47,13); cout<<"||   |                             ||";
	gotoxy(47,14); cout<<"||   |                             ||";
	gotoxy(47,15); cout<<"||   |                             ||";
	gotoxy(47,16); cout<<"||   |                             ||";
	gotoxy(47,17); cout<<"||   |                             ||";
	gotoxy(47,18); cout<<"||   |                             ||";
	gotoxy(47,19); cout<<"||   |                             ||";
	gotoxy(47,20); cout<<"||   |                             ||";
	gotoxy(47,21); cout<<"||   |                             ||";
	gotoxy(47,22); cout<<"||   |                             ||";
	gotoxy(47,23); cout<<"||---|-----------------------------||";
	
}
	
	
	
void dibujarFlechasMenuCargarMedallas(char &seleccionarOpcion){
	
	switch(seleccionarOpcion){
		case '1':
			gotoxy(64,10);cout<<"--->";
			gotoxy(64,12);cout<<"    ";
			gotoxy(64,14);cout<<"    ";
			break;
			
		case '2':
			gotoxy(64,10);cout<<"    ";
			gotoxy(64,12);cout<<"--->";
			gotoxy(64,14);cout<<"    ";
			break;
			
		case 'x':
		case 'X':
			gotoxy(64,10);cout<<"    ";
			gotoxy(64,12);cout<<"    ";
			gotoxy(64,14);cout<<"--->";
			break;
		default: seleccionarOpcion = '0';
	}
}

//Logica visual del menu mostrar medallero
void pantallaMenuMostrarMedallero(){
	
	cout << "\n\n\n";
	cout << "             _____________________________________________________" << endl;
	cout << "            |  _________________________________________________  |" << endl;
	cout << "            | |     __  __          _       _ _                 | | SELECCIONAR OPCION Y PRESIONAR ENTER" << endl;
	cout << "            | |    |  \\/  |        | |     | | |                | |____________________________________________" << endl;
	cout << "            | |    | \\  / | ___  __| | __ _| | | ___ _ __ ___   |  __________________________________________  |" << endl;
	cout << "            | |    | |\\/| |/ _ \\/ _` |/ _` | | |/ _ \\ '__/ _ \\  | |                                          | |" << endl;
	cout << "            | |    | |  | |  __/ (_| | (_| | | |  __/ |  |(_)|  | |      1 . MEDALLERO POR PAIS              | |" << endl;    
	cout << "            | |    |_|  |_|\\___|\\__,_|\\__,_|_|_|\\___|_|  \\___/  | |                                          | |" << endl;
	cout << "            | |                                                 | |      2 . MEDALLERO POR DEPORTE           | |" << endl;
	cout << "            | |       ____  _    __             _               | |                                          | |" << endl;
	cout << "            | |      / __ \\| |  /_/            (_)              | |      3 . TOP MEDALLERO                   | |" << endl;
	cout << "            | |     | |  | | |_ _ __ ___  _ __  _  ___ ___      | |                                          | |" << endl;
	cout << "            | |     | |  | | | | '_ ` _ \\| '_ \\| |/ __/ _ \\     | |      X . VOLVER AL MENU PRINCIPAL        | |" << endl;
	cout << "            | |     | |__| | | | | | | | | |_) | | (_| (_) |    | |                                          | |" << endl;
	cout << "            | |      \\____/|_|_|_| |_| |_| .__/|_|\\___\\___/     | |__________________________________________| |"<< endl;
	cout << "            | |                          | |                    |  ____________________________________________|"<< endl;                                            
	cout << "            | |                          |_|                    | | "<< endl;       
	cout << "            | |_________________________________________________| |"<< endl; 
	cout << "            |_____________________________________________________|"<< endl;
	
}
	
void dibujarFlechasMenuMostrarMedallero(char &seleccionarOpcion){
	
	switch(seleccionarOpcion){
		case '1':
			gotoxy(68,9);cout<<"--->";
			gotoxy(68,11);cout<<"    ";
			gotoxy(68,13);cout<<"    ";
			gotoxy(68,15);cout<<"    ";
			break;
			
		case '2':
			gotoxy(68,9);cout<<"    ";
			gotoxy(68,11);cout<<"--->";
			gotoxy(68,13);cout<<"    ";
			gotoxy(68,15);cout<<"    ";
			break;
			
		case '3':
			gotoxy(68,9);cout<<"    ";
			gotoxy(68,11);cout<<"    ";
			gotoxy(68,13);cout<<"--->";
			gotoxy(68,15);cout<<"    ";
			break;
			
		case 'x':
		case 'X':
			gotoxy(68,9);cout<<"    ";
			gotoxy(68,11);cout<<"    ";
			gotoxy(68,13);cout<<"    ";
			gotoxy(68,15);cout<<"--->";
			break;
		default: seleccionarOpcion = '0';
	}
}
	
void pantallaCargaDeporteInvidual(){
	limpiarConsola();

	mostrarRecuadroDeportes();
	
	mostrarDeportesIndividuales();
	
	
}
	
void pantallaCargaDeporteColectivo(){
	limpiarConsola();
	
	mostrarRecuadroDeportes();
	
	mostrarDeportesColectivos();
}

void pantallaCargando(){
	
	gotoxy(50,10);cout<<" _____________________";
	gotoxy(50,11);cout<<"||                   ||";
	gotoxy(50,12);cout<<"||  C A R G A N D O  ||";
	gotoxy(50,13);cout<<"||                   ||";
	gotoxy(50,14);cout<<"||           %       ||";
	gotoxy(50,15);cout<<"||___________________||";
	
	for(int i=0;i<=100;i++){
		gotoxy(60,14);cout<<i;
		Sleep(12);
	}
	limpiarConsola();
}
	
void mostrarTechoTopPaises(){
	
	gotoxy(23,1);cout<<"  ________________________________________________________________________________ ";
	gotoxy(23,2);cout<<" |           PAISES           |    ORO     |    PLATA   |   BRONCE   |    TOTAL   |";
	gotoxy(23,3);cout<<" |____________________________|____________|____________|____________|____________|";
	
}
	
void mostrarPisoTopPaises(){
	cout<<" |____________________________|____________|____________|____________|____________|";
}

void mostrarTechoTopDeportes(){
	gotoxy(14,1);cout<<" ____________________________________________________________________________________________ ";
	gotoxy(14,2);cout<<"|                       DEPORTE                        |    ORO     |    PLATA   |   BRONCE  |";
	gotoxy(14,3);cout<<"|______________________________________________________|____________|____________|___________|";
	
}

void mostrarPisoTopDeportes(){
	cout<<" |______________________________________________________|____________|____________|___________|";
}
	
void mostrarTechoTopMedallero(){
	
	gotoxy(27,1);cout<<" ____________________________________________________________________ ";
	gotoxy(27,2);cout<<"|TOP|           PAIS             |  ORO   |  PLATA  | BRONCE | TOTAL |";
	gotoxy(27,3);cout<<"|___|____________________________|________|_________|________|_______|";
}

void mostrarPisoTopMedallero(){
	cout<<"|___|____________________________|________|_________|________|_______|";
}

	void pantallaMenuGenerarCompetencia() {
		cout << "\n\n\n";
		cout << "    ________________________________________________________________________        " << endl;
		cout << "   |  ____________________________________________________________________  |" << endl;
		cout << "   | |      _____                                                         | |" << endl;
		cout << "   | |     / ____|                                                        | | SELECCIONAR OPCION Y PRESIONAR ENTER" << endl;
		cout << "   | |    | |  __  ___ _ __   ___ _ __ __ _ _ __                          | |_____________________________________" << endl;
		cout << "   | |    | | |_ |/ _ \\ '_ \\ / _ \\ '__/ _` | '__|                         |  ___________________________________  |" << endl;
		cout << "   | |    | |__| |  __/ | | |  __/ | | (_| | |                            | |                                   | |" << endl;
		cout << "   | |     \\_____|\\___|_| |_|\\___|_|  \\__,_|_|                            | |     1 . GENERAR COMPETENCIA       | |" << endl;
		cout << "   | |     _____                            _                  _          | |     2 . CARGAR COMPETENCIA        | |" << endl;
		cout << "   | |    / ____|                          | |                (_)         | |                                   | |" << endl;
		cout << "   | |    | |     ___  _ __ ___  _ __   ___| |_ ___ _ __   ___ _  __ _    | |     X . VOLVER AL MENU PRINCIPAL  | |" << endl;
		cout << "   | |    | |    / _ \\| '_ ` _ \\| '_ \\ / _ \\ __/ _ \\ '_ \\ / __| |/ _` |   | |___________________________________| |" << endl;
		cout << "   | |    | |___| (_) | | | | | | |_) |  __/ ||  __/ | | | (__| | (_| |   |  _____________________________________|" << endl;
		cout << "   | |     \\_____\\___/|_| |_| |_| .__/ \\___|\\__\\___|_| |_ \\___|_|\\__,_|   | |  " << endl;
		cout << "   | |                          | |                                       | | " << endl;
		cout << "   | |                          |_|                                       | |  " << endl;
		cout << "   | |____________________________________________________________________| |" << endl;
		cout << "   |________________________________________________________________________|" << endl;
	}
	
void dibujarFlechasMenuGenerarCompetencia(char &seleccionarOpcion){
	
	switch(seleccionarOpcion){
	case '1':
		gotoxy(77,10);cout<<"--->";
		gotoxy(77,11);cout<<"    ";
		gotoxy(77,13);cout<<"    ";
		break;
		
	case '2':
		gotoxy(77,10);cout<<"    ";
		gotoxy(77,11);cout<<"--->";
		gotoxy(77,13);cout<<"    ";
		break;
		
	case 'x':
	case 'X':
		gotoxy(77,10);cout<<"    ";
		gotoxy(77,11);cout<<"    ";
		gotoxy(77,13);cout<<"--->";
		break;
	default: seleccionarOpcion = '0';
	}
}
	
void pantallaMenuEstadisticas(){
	
	cout << "\n\n\n";
	cout << "             ____________________________________________________" << endl;
	cout << "            |  ________________________________________________  |" << endl;
	cout << "            | |             __  __              __             | | SELECCIONAR OPCION Y PRESIONAR ENTER" << endl;
	cout << "            | |            |  \\/  |            /_/             | |____________________________________________________" << endl;
	cout << "            | |            | \\  / | ___ _ __  _   _            |______  ____________________________________________  |" << endl;
	cout << "            | |            | |\\/| |/ _ \\ '_ \\| | | |                  | |                                           | |" << endl;
	cout << "            | |            | |  | |  __/ | | | |_| |                  | |                                           | |" << endl;
	cout << "            | |            |_|__|_|\\___|_| |_|\\__,_|                  | |                                           | |" << endl;
	cout << "            | |  ______     _            _  __   _   _                | |                                           | |" << endl;
	cout << "            | | |  ____|   | |          | |/_/  | | (_)               | |                                           | |" << endl;
	cout << "            | | | |__   ___| |_ __ _  __| |_ ___| |_ _  ___ __ _ __   | |                                           | |" << endl;
	cout << "            | | |  __| / __| __/ _` |/ _` | / __| __| |/ __/ _` / __| | |                                           | |" << endl;
	cout << "            | | | |____\\__ \\ || (_| | (_| | \\__ \\ |_| | (_| (_| \\__ \\ | |                                           | |" << endl;
	cout << "            | | |______|___/\\__\\__,_|\\__,_|_|___/\\__|_|\\___\\__,_|___/ | |                                           | |" << endl;
	cout << "            | |                                                       | |                                           | |" << endl;
	cout << "            | |_______________________________________________________| |___________________________________________| |" << endl;
	cout << "            |___________________________________________________________|_____________________________________________|" << endl;
	cout << "                                                                                                       " << endl;
	cout << "                                                                                                        " << endl;
	cout << "                                                                                                        " << endl;	
	
	
	
	gotoxy(78,9);
	cout<<"1 . PAIS CON MAS MEDALLAS";
	gotoxy(78,11);
	cout<<"2 . MEDALLAS DEL PAIS";
	gotoxy(78,13);
	cout<<"3 . PAIS CON MAS DEPORTES INDIVIDUALES";
	gotoxy(78,15);
	cout<<"4 . PAISES PREMIADOS DEL DEPORTE";
	gotoxy(78,17);
	cout<<"X . VOLVER AL MENU PRINCIPAL";
}	
void dibujarFlechasMenuEstadisticas(char &seleccionarOpcion){
	switch(seleccionarOpcion){
	case '1':
		gotoxy(73,9);cout<<"--->";
		gotoxy(73,11);cout<<"    ";
		gotoxy(73,13);cout<<"    ";
		gotoxy(73,15);cout<<"    ";
		gotoxy(73,17);cout<<"    ";
		break;
	case '2':
		gotoxy(73,9);cout<<"    ";
		gotoxy(73,11);cout<<"--->";
		gotoxy(73,13);cout<<"    ";
		gotoxy(73,15);cout<<"    ";
		gotoxy(73,17);cout<<"    ";
		break;
	case '3':
		gotoxy(73,9);cout<<"    ";
		gotoxy(73,11);cout<<"    ";
		gotoxy(73,13);cout<<"--->";
		gotoxy(73,15);cout<<"    ";
		gotoxy(73,17);cout<<"    ";
		break;
	case '4':
		gotoxy(73,9);cout<<"    ";
		gotoxy(73,11);cout<<"    ";
		gotoxy(73,13);cout<<"    ";
		gotoxy(73,15);cout<<"--->";
		gotoxy(73,17);cout<<"    ";
		break;
	case 'x':
	case'X':
		gotoxy(73,9);cout<<"    ";
		gotoxy(73,11);cout<<"    ";
		gotoxy(73,13);cout<<"    ";
		gotoxy(73,15);cout<<"    ";
		gotoxy(73,17);cout<<"--->";
		break;
	}
}
void mostrarEstadistica1(){
	gotoxy(14,1);cout<<" ____________________________________________________________________";
	gotoxy(14,2);cout<<"|          PAIS CON MAYOR CANTIDAD DE MEDALLAS         |    TOTAL    |";
	gotoxy(14,3);cout<<"|                                                      |             |";
	gotoxy(14,4);cout<<"|______________________________________________________|_____________|";
	
}
	
void mostrarEstadistica3(){
	gotoxy(14,1);cout<<" ____________________________________________________________________";
	gotoxy(14,2);cout<<"|  PAIS CON MAYOR CANTIDAD DE MEDALLAS (Deportes Ind)  |    TOTAL    |";
	gotoxy(14,3);cout<<"|                                                      |             |";
	gotoxy(14,4);cout<<"|______________________________________________________|_____________|";
	
}

	
void mostrarEstadistica2(){
	
	int id = 1;
	int pais = 1;// ID inicial
	int fila = 3;
	int columna = 12;
	// Encabezados de la tabla
	gotoxy(12, 0); cout << " _______________________________________________________________________________________________ ";
	gotoxy(12, 1); cout << "|ID  -  PAIS|ID  -  PAIS|ID  -  PAIS|ID  -  PAIS|ID  -  PAIS|ID  -  PAIS|ID  -  PAIS|ID  -  PAIS|";
	gotoxy(12, 2); cout << "|___________|___________|___________|___________|___________|___________|___________|___________|";
	
	while(id<=197){
		
		if(id<=196){
			gotoxy(columna,fila);cout<<"|"<<setfill(' ')<<setw(3)<<id<<" -  ";imprimirAcronimoPais(pais);
			columna+=12;
			
			if(columna == 108){
				gotoxy(columna,fila);cout<<"|";
				columna = 12;
				fila++;
			}
			if(id == 196){
				gotoxy(columna,fila);cout<<"|";
				gotoxy(108,fila);cout<<"|";
			}
		}
		id++;
		pais++;
	}
	// Línea final de la tabla
	gotoxy(12, fila+1); cout << "|___________|___________|___________|___________|_______________________________________________|";
	gotoxy(columna+1,fila);cout<<"Ingrese ID del pais: ";
}

void mostrarMedallasObtenidasPorPais(){
	gotoxy(18,1);cout<<" ___________________________________________________________________ ";
	gotoxy(18,2);cout<<"|             PAIS             |    ORO    |   PLATA   |   BRONCE   |";
	gotoxy(18,3);cout<<"|______________________________|___________|___________|____________|";
	gotoxy(18,4);cout<<"|                              |           |           |            |";
	gotoxy(18,5);cout<<"|______________________________|___________|___________|____________|";
} 

	
