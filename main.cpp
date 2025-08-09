#include <iostream>
#include "logicaMenus.h"
#include "logicaVisual.h"
#include "logicaLogin.h"
#include "menus.h"
#include <windows.h>
using namespace std;

int main (int argc, char *argv[]) {
	int legajoIngresado;
	system("mode con: cols=160 lines=260");
	
	bool accesoMenu = false, accesoLogin = false;
	
	recuadroExterior();
	pantallaBienvenida();
	pantallaPebetero();
	pantallaAnillos();
 
	if(sePresionaSPACE(accesoLogin)){
		
		if(accesoLogin){
			
			limpiarConsola();
			login(accesoMenu,legajoIngresado);
			
			if(accesoMenu){
				cin.clear();
				limpiarConsola();
				menuPrincipal(legajoIngresado);
			}
		}
	}
	
	gotoxy(4,22);
	cout<<" "<<endl;
	
	return 0;
}

