#ifndef LOGICAVISUAL_H
#define LOGICAVISUAL_H


//Generales
void limpiarConsola();
void gotoxy(short,short);

//Bienvenida
void recuadroExterior();
void pantallaBienvenida();
void pantallaPebetero();
void pantallaAnillos();

//Login
void pantallaLogin();

//Menú Principal
void pantallaMenuPrincipal(bool & competenciaGenerada);
void dibujarFlechasMenuPrincipal(char &);

//Menu Generar Competencia
void pantallaMenuGenerarCompetencia();
void dibujarFlechasMenuGenerarCompetencia(char &seleccionarOpcion);

//Menu Cargar Medallas
void pantallaMenuCargarMedalla();
void dibujarFlechasMenuCargarMedallas(char &);
void mostrarRecuadroDeportes();
void recuadroPaises();

//Menu Mostrar Medallero
void pantallaMenuMostrarMedallero();
void dibujarFlechasMenuMostrarMedallero(char &);

void mostrarTechoTopPaises();
void mostrarPisoTopPaises();

void mostrarTechoTopDeportes();
void mostrarPisoTopDeportes();

void mostrarTechoTopMedallero();
void mostrarPisoTopMedallero();

//Cargar Medallas Individual
void pantallaCargaDeporteInvidual();
void pantallaCargaDeporteColectivo();

//Intermedios
void pantallaCargando();

//Menu estadisticas
void pantallaMenuEstadisticas();
void dibujarFlechasMenuEstadisticas(char &);

void mostrarEstadistica1();

void mostrarEstadistica2();
void mostrarMedallasObtenidasPorPais();

void mostrarEstadistica3();


#endif
