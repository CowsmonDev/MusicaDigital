#include "headers/Canciones.h"
#include <iostream>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

void Canciones::agregarElemento(string & elemento){
	cancion nueva_cancion;
	size_t pos_final = 0;
	string space_delimiter = ",";

	pos_final = elemento.find(space_delimiter);
	nueva_cancion.interprete = elemento.substr(0, pos_final);
	elemento.erase(0, pos_final + space_delimiter.length());

	pos_final = elemento.find(space_delimiter);
	nueva_cancion.nombre = elemento.substr(0, pos_final);
	elemento.erase(0, pos_final + space_delimiter.length());

	pos_final = elemento.find(space_delimiter);
	nueva_cancion.duracion = elemento.substr(0, pos_final);
	elemento.erase(0, pos_final + space_delimiter.length());

	pos_final = elemento.find(space_delimiter);
	nueva_cancion.lanzamiento= atoi(elemento.substr(0, pos_final).c_str());
	elemento.erase(0, pos_final + space_delimiter.length());

	pos_final = elemento.find(space_delimiter);
	nueva_cancion.genero = elemento.substr(0, pos_final);
	elemento.erase(0, pos_final + space_delimiter.length());

	pos_final = elemento.find(space_delimiter);
	nueva_cancion.reproducciones = atoi(elemento.substr(0, pos_final).c_str());
	elemento.erase(0, pos_final + space_delimiter.length());

	listado->agregarElemento(nueva_cancion);

}


Canciones::Canciones(const string & direccion){
	this->listado = new Lista<cancion>();
	setlocale(LC_ALL, "");
	ifstream archivo(direccion);
	if(!archivo.is_open())
		cout << "No se pudo abrir el archivo: " << direccion << endl;
	else{
		string linea;
		getline(archivo, linea);
		this->cantidad_canciones = atoi(linea.c_str());
		int cantidad_canciones = atoi(linea.c_str());
		cout<< "Se cargaron " << cantidad_canciones << " canciones." << endl;
		while (getline(archivo, linea))
			agregarElemento(linea);
	}
};

Lista<Canciones::cancion> * Canciones::obtenerTopCancionesGenero(const string & genero) const{
	Lista<cancion> * cursor = listado;
	Lista<cancion> * top_canciones_genero = new Lista<cancion>();

	top_canciones_genero->agregarElemento(cursor->obtenerElemento());
	cursor = cursor->obtenerSiguiente();

	for (int i = 1; i < this->cantidad_canciones; i++){
		if(cursor->obtenerElemento().genero.find(genero) != string::npos){
			Lista<cancion> * cursor_lista = top_canciones_genero;
			for(int j = 1; j <= 10; j++){
				if(cursor_lista->obtenerElemento().reproducciones > cursor->obtenerElemento().reproducciones){
					cursor_lista->agregarElemento(cursor->obtenerElemento());
					if(!(i < 10))
						top_canciones_genero->eliminarElemento(0);
					break;
				}
				cursor_lista = cursor_lista->obtenerSiguiente();
			}
		}
		cursor = cursor->obtenerSiguiente();
	}
	
	return top_canciones_genero;
}