#include "headers/Canciones.h"
#include <iostream>
#include <string>
#include <fstream>
#include <clocale>

using namespace std;

/*
	* -> una palabra
	? -> un caracter
	sin acentos -> como si la consola los reconociera en primer lugar
*/
void Canciones::busqueda(string texto) const
{
	Lista<cancion> * cursor = listado;

	texto = quitarAcentos(texto);

	while (!cursor->listaVacia())
	{
		if (busquedaPorPatron(cursor->obtenerElemento().nombre, texto))
            cout<<this->toString(cursor->obtenerElemento());
		cursor = cursor->obtenerSiguiente();
	}
}

bool Canciones::busquedaPorPatron(const string texto, const string patron) const
{
	if (patron.empty()) return texto.empty();

	if (texto.empty())
        return (patron[0] == '*' && patron[1] == NULL) || patron.empty();

	if (patron[0] == '*')
    {
        if (patron[1] == NULL)
            return busquedaPorPatron(texto.substr(1), patron);

        if (texto[0] != patron[1])
            return busquedaPorPatron(texto.substr(1), patron);
        else
            return busquedaPorPatron(texto, patron.substr(1));
    }
	else
		return !texto.empty() && (texto[0] == patron[0] || patron[0] == '?') && busquedaPorPatron(texto.substr(1), patron.substr(1));
}

string Canciones::quitarAcentos(string texto) const
{
	string newString = texto;
    for(int i=0; i < texto.size(); i++){
        if (newString[i] == 'á')
			newString[i] == 'a';
		else if (newString[i] == 'Á')
			newString[i] == 'A';
		else if (newString[i] == 'é')
			newString[i] == 'e';
		else if (newString[i] == 'É')
			newString[i] == 'E';
		else if (newString[i] == 'í')
			newString[i] == 'i';
		else if (newString[i] == 'Í')
			newString[i] == 'I';
		else if (newString[i] == 'ó')
			newString[i] == 'o';
		else if (newString[i] == 'Ó')
			newString[i] == 'O';
		else if (newString[i] == 'ú')
			newString[i] == 'u';
		else if (newString[i] == 'Ú')
			newString[i] == 'U';
    }
	return newString;
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
