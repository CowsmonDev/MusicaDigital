#include "headers/Canciones.h"
#include <iostream>
#include <string>
#include <fstream>
#include <clocale>
#include <regex>

using namespace std;

void Canciones::agregarElemento(string & elemento, unsigned int id){
	cancion nueva_cancion;
	unsigned int pos_final = 0;
	string space_delimiter = ",";

	nueva_cancion.id = id;

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
	listado = new Lista<cancion>();
	setlocale(LC_ALL, "");
	ifstream archivo(direccion);
	if(!archivo.is_open())
		cout << "No se pudo abrir el archivo: " << direccion << endl;
	else{
		string linea;
		getline(archivo, linea);
		cantidad_canciones = atoi(linea.c_str());
		unsigned int i = cantidad_canciones;
		cout<< "Se cargaron " << cantidad_canciones << " canciones." << endl;
		while (getline(archivo, linea))
			agregarElemento(linea, i--);
	}
};

void Canciones::obtenerTopCancionesGenero(const string & genero) const{
	Lista<cancion> * cursor = listado;
	Lista<cancion> * top_canciones_genero = new Lista<cancion>();
	Lista<cancion> * cursor_lista;

	for (unsigned int i = 0; i < cantidad_canciones; i++){
		if(cursor->obtenerElemento().genero.find(genero) != string::npos){
			cursor_lista = top_canciones_genero;
			for (int h = 0; (!cursor_lista->listaVacia()) && (h<10); h++)
			{
				if(cursor_lista->obtenerElemento().reproducciones < cursor->obtenerElemento().reproducciones){
					cursor_lista->agregarElemento(cursor->obtenerElemento());
					h = 10;
				}else
					cursor_lista = cursor_lista->obtenerSiguiente();
			}
			if(cursor_lista->listaVacia())
				cursor_lista->agregarElemento(cursor->obtenerElemento());
		}
		cursor = cursor->obtenerSiguiente();
	}
	unsigned int j=10;
	cout<<"\nTop 10";
	while(!top_canciones_genero->listaVacia() && (j > 0)){
		cout<<endl<<"Posicion: "<<j;
		cout<<toString(top_canciones_genero->obtenerElemento());
		top_canciones_genero = top_canciones_genero->obtenerSiguiente();
		j--;
	}
}

Lista<Canciones::cancion> * Canciones::busqueda(const string texto) const
{
	Lista<cancion> * cursor = listado;
	Lista<cancion> * listaResultado = new Lista<cancion>();

	// Utilizar la libreria regex para expresiones regulares
	regex filtro(texto, regex_constants::ECMAScript | regex_constants::icase);

	while (!cursor->listaVacia())
	{
		// Comprobar si la busqueda está en el nombre y lo agrega a la lista resultante
		if (regex_search(cursor->obtenerElemento().nombre, filtro))
			listaResultado->agregarElemento(cursor->obtenerElemento());
		cursor = cursor->obtenerSiguiente();
	}
	return listaResultado;
}

void Canciones::filtrado(const unsigned int fInicial, const unsigned int fFinal) const
{
	Lista<cancion> * cursor = listado;
	while (!cursor->listaVacia())
	{
		// Comprobar si la fecha entra en el rango y lo agrega a la lista resultante
		if (cursor->obtenerElemento().lanzamiento >= fInicial && cursor->obtenerElemento().lanzamiento <= fFinal)
			cout<<this->toString(cursor->obtenerElemento());
		cursor = cursor->obtenerSiguiente();
	}

}

string Canciones::toString() const{
	string retorno = "\n|------------------------------  Canciones  ------------------------------|\n";
	Lista<cancion> * cursor = listado;
	while(!cursor->listaVacia()){
		retorno.append(toString(cursor->obtenerElemento()));
		cursor = cursor->obtenerSiguiente();
	}
	return retorno;
}

string Canciones::toString(cancion cancion) const{
	string retorno = "\n------------------------------  Cancion  ------------------------------\n";
	retorno.append("Nombre: ")
		.append(cancion.nombre)
		.append("\nInprete: ")
		.append(cancion.interprete)
		.append("\nLanzamiento: ")
		.append(to_string(cancion.lanzamiento))
		.append("\nDuracion: ")
		.append(cancion.duracion)
		.append("\nGenero: ")
		.append(cancion.genero)
		.append("\nReproducciones: ")
		.append(to_string(cancion.reproducciones))
		.append("\n-----------------------------------------------------------------------\n");
	return retorno;
}
