#include "headers/Canciones.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

/*
	* -> una palabra
	? -> un caracter
	sin acentos -> como si la consola los reconociera en primer lugar
*/
Lista<Canciones::Cancion> * Canciones::busqueda(string texto) const
{
	Lista<Cancion> * cursor = listado;
	Lista<Cancion> * listaResultado = new Lista<Cancion>();
	texto = quitarAcentos(texto);

	while (!cursor->listaVacia())
	{
		if (busquedaPorPatron(cursor->obtenerElemento().nombre, texto))
			listaResultado->agregarElemento(cursor->obtenerElemento());
		cursor = cursor->obtenerSiguiente();
	}

	return listaResultado;
}

bool Canciones::busquedaPorPatron(const string texto, const string patron) const
{
	if (patron.empty()) return texto.empty();

	if (patron[0] == '*')
		return busquedaPorPatron(texto, patron.substr(1));
	else
		return !texto.empty() && (texto[0] == patron[0] || patron[0] == '?') && busquedaPorPatron(texto.substr(1), patron.substr(1));
}

string Canciones::quitarAcentos(string texto) const
{
	string newString = texto; // No funciona reemplazando directamente
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

Lista<Canciones::Cancion> * Canciones::filtrado(const unsigned int inicial, const unsigned int final) const
{
	Lista<Cancion> * cursor = listado;
	Lista<Cancion> * listaResultado = new Lista<Cancion>();

	while (!cursor->listaVacia())
	{
		// Comprobar si la fecha entra en el rango y lo agrega a la lista resultante
		if (cursor->obtenerElemento().lanzamiento >= inicial && cursor->obtenerElemento().lanzamiento <= final)
			listaResultado->agregarElemento(cursor->obtenerElemento());
		cursor = cursor->obtenerSiguiente();
	}

	return listaResultado;
}