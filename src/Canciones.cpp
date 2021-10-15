#include "headers/Canciones.h"
#include <iostream>
#include <string>

using namespace std;

void Canciones::agregarElemento(const string & elemento){
	cancion nueva_cancion;

	//Primer posici�n del separador ;
	int pos_inicial = 0;
	int pos_final = elemento.find(',');

	//Informacion entre pos_inicial y pos_final
	nueva_cancion.interprete = elemento.substr(pos_inicial, pos_final);

	//Segunda posici�n del separador ;
	pos_inicial = pos_final + 1;
	pos_final = elemento.find(',', pos_inicial);
	nueva_cancion.nombre = elemento.substr(pos_inicial, pos_final - pos_inicial);

	//Tercera posici�n del separador ;
	pos_inicial = pos_final + 1;
	pos_final = elemento.find(',', pos_inicial);
	nueva_cancion.duracion = atoi(elemento.substr(pos_inicial, pos_final - pos_inicial).c_str());

	//Cuarta posici�n del separador ;
	pos_inicial = pos_final + 1;
	pos_final = elemento.find(',', pos_inicial);
	nueva_cancion.lanzamiento = elemento.substr(pos_inicial, pos_final - pos_inicial);

	//Quinta posici�n del separador ;
	//LISTA de GENEROS
	pos_inicial = pos_final + 1;
	pos_final = elemento.find(',', pos_inicial);
	nueva_cancion.genero= elemento.substr(pos_inicial, pos_final - pos_inicial);

	//Sexta posici�n del separador ;
	pos_inicial = pos_final + 1;
	pos_final = elemento.find(';', pos_inicial);
	nueva_cancion.reproducciones = atoi(elemento.substr(pos_inicial, pos_final - pos_inicial).c_str());

	listado->agregarElemento(nueva_cancion);

}


Canciones::Canciones(const string & direccion){
	listado = new Lista();
	setlocale(LC_ALL, "");
	ifstream archivo(direccion);
	if(!archivo.is_open())
		cout << "No se pudo abrir el archivo: " << direccion << endl;
	else{
		string linea;
		getline(archivo, linea);
		int cantidad_canciones = atoi(linea.c_str());
		cout<< "Se cargaron " << cantidad_canciones << " canciones." << endl;
		while (getline(archivo, linea))
			agregarElemento(linea);
	}
};