#include <iostream>
#include "logicaMenuEstadisticas.h"
#define numPaises 196
using namespace std;
const char* paises[] = {"Afganistán", "Albania", "Alemania", "Andorra", "Angola",
	"Antigua y Barbuda", "Arabia Saudita", "Argelia", "Argentina", "Armenia",
	"Australia", "Austria", "Azerbaiyán", "Bahamas", "Bangladés",
	"Barbados", "Baréin", "Belarús", "Bélgica", "Belice",
	"Benín", "Bermudas", "Bhután", "Bolivia", "Bosnia y Herzegovina",
	"Botsuana", "Brasil", "Brunei", "Bulgaria", "Burkina Faso",
	"Burundi", "Cabo Verde", "Camboya", "Camerún", "Canadá",
	"Catar", "Chad", "Chile", "China", "Chipre",
	"Colombia", "Comoras", "Congo", "Corea del Norte", "Corea del Sur",
	"Costa de Marfil", "Costa Rica", "Croacia", "Cuba", "Dinamarca",
	"Dominica", "Ecuador", "Egipto", "El Salvador", "Emiratos Arabes Unidos",
	"Eritrea", "Eslovaquia", "Eslovenia", "España", "Estados Unidos",
	"Estonia", "Esuatini", "Etiopía", "Filipinas", "Fiyi",
	"Finlandia", "Francia", "Gabón", "Gambia", "Georgia",
	"Ghana", "Granada", "Grecia", "Guatemala", "Guinea",
	"Guinea-Bisáu", "Guinea Ecuatorial", "Guyana", "Haití", "Honduras",
	"Hungría", "India", "Indonesia", "Irak", "Irán",
	"Irlanda", "Islandia", "Islas Cook", "Islas Marshall", "Islas Salomón",
	"Israel", "Italia", "Jamaica", "Japón", "Jordania",
	"Kazajistán", "Kenia", "Kirguistán", "Kiribati", "Kosovo",
	"Kuwait", "Laos", "Lesoto", "Letonia", "Líbano",
	"Liberia", "Libia", "Liechtenstein", "Lituania", "Luxemburgo",
	"Madagascar", "Malasia", "Malaui", "Maldivas", "Malí",
	"Malta", "Marruecos", "Mauricio", "Mauritania", "México",
	"Micronesia", "Moldavia", "Mónaco", "Mongolia", "Montenegro",
	"Mozambique", "Namibia", "Nauru", "Nepal", "Nicaragua",
	"Níger", "Nigeria", "Noruega", "Nueva Zelanda", "Omán",
	"Países Bajos", "Pakistán", "Palaos", "Palestina", "Panamá",
	"Papúa Nueva Guinea", "Paraguay", "Perú", "Polonia", "Portugal",
	"Puerto Rico", "Reino Unido", "República Centroafricana",
	"República Checa", "República del Congo", "República Dominicana",
	"Ruanda", "Rumanía", "Rusia", "Samoa", 	"Samoa Americana", 
	"San Cristóbal y Nieves", "San Marino", 
	"San Vicente y las Granadinas", "Santa Lucía",
	"Santo Tomé y Príncipe", "Senegal", "Serbia", "Seychelles", 
	"Sierra Leona",	"Singapur", "Siria", "Somalia", "Sri Lanka",
	"Sudáfrica", "Sudán", "Sudán del Sur", "Suecia", "Suiza", "Surinam",
	"Tailandia", "Tayikistán", "Tanzania", "Timor Oriental", "Togo",
	"Tonga", "Trinidad y Tobago", "Túnez", "Turquía", "Turkmenistán",
	"Tuvalu", "Ucrania", "Uganda", "Uruguay", "Uzbekistán",
	"Vanuatu", "Venezuela", "Vietnam", "Yemen", "Yibuti",
	"Zambia", "Zimbabue"};

void imprimirPais(int indice) {
	if (indice >= 1 && indice <= numPaises) {
		cout << paises[indice - 1] << endl; 
	} else {
		cout << "Indice fuera de rango" << endl;
	}
}
void listarPaises() {

	
	for (int indice=0; indice <= numPaises; indice++) {
		cout <<indice+1<<" - "<< paises[indice]<<", "; 
	} 
}
//Acronimos en formato ISO en inglés para evitar confusiones
const char* paisesAcronimos[] = {
		"AFG", "ALB", "GER", "AND", "AGO",
		"ATG", "KSA", "DZA", "ARG", "ARM",
		"AUS", "AUT", "AZE", "BHS", "BGD",
		"BRB", "BHR", "BLR", "BEL", "BLZ",
		"BEN", "BMU", "BTN", "BOL", "BIH",
		"BWA", "BRA", "BRN", "BGR", "BFA",
		"BDI", "CPV", "KHM", "CMR", "CAN",
		"QAT", "TCD", "CHL", "CHN", "CYP",
		"COL", "COM", "COG", "NKO", "SKO",
		"CIV", "CRI", "CRO", "CUB", "DNK",
		"DMA", "ECU", "EGY", "SLV", "ARE",
		"ERI", "SVK", "SVN", "ESP", "USA",
		"EST", "SWZ", "ETH", "PHL", "FJI",
		"FIN", "FRA", "GAB", "GMB", "GEO",
		"GHA", "GRD", "GRC", "GTM", "GIN",
		"GNB", "GNQ", "GUY", "HTI", "HND",
		"HUN", "IND", "IDN", "IRQ", "IRN",
		"IRL", "ISL", "COK", "MHL", "SLB",
		"ISR", "ITA", "JAM", "JPN", "JOR",
		"KAZ", "KEN", "KGZ", "KIR", "XKX",
		"KWT", "LAO", "LSO", "LVA", "LBN",
		"LBR", "LBY", "LIE", "LTU", "LUX",
		"MDG", "MYS", "MWI", "MDV", "MLI",
		"MLT", "MAR", "MUS", "MRT", "MEX",
		"FSM", "MDA", "MCO", "MNG", "MNE",
		"MOZ", "NAM", "NRU", "NPL", "NIC",
		"NER", "NGA", "NOR", "NZL", "OMN",
		"NLD", "PAK", "PLW", "PSE", "PAN",
		"PNG", "PRY", "PER", "POL", "PRT",
		"PRI", "GBR", "CAF", "CZE", "COG",
		"DOM", "RWA", "ROU", "RUS", "WSM",
		"ASM", "KNA", "SMR", "VCT", "LCA",
		"STP", "SEN", "SRB", "SYC", "SLE",
		"SGP", "SYR", "SOM", "LKA", "ZAF",
		"SDN", "SSD", "SWE", "CHE", "SUR",
		"THA", "TJK", "TZA", "TLS", "TGO",
		"TON", "TTO", "TUN", "TUR", "TKM",
		"TUV", "UKR", "UGA", "URY", "UZB",
		"VUT", "VEN", "VNM", "YEM", "DJI",
		"ZMB", "ZWE"
};

void imprimirAcronimoPais(int indice) {
	if (indice >= 1 && indice <= numPaises) {
		cout << paisesAcronimos[indice - 1] << endl; 
	} else {
		cout << "Indice fuera de rango" << endl;
	}
}
