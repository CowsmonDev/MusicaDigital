#include "headers/Canciones.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

Lista<Canciones::Cancion> * Canciones::busqueda(const string texto) const
{
	Lista<Cancion> * cursor = listado;
	Lista<Cancion> * listaResultado = new Lista<Cancion>();

	// Utilizar la libreria regex para expresiones regulares
	regex filtro(texto, regex_constants::ECMAScript | regex_constants::icase);

	while (cursor != nullptr)
	{
		// Comprobar si la busqueda está en el nombre y lo agrega a la lista resultante
		if (regex_search(cursor->obtenerElemento().nombre, filtro))
			listaResultado->agregarElemento(cursor->obtenerElemento());
		cursor = cursor->obtenerSiguiente();
	}
}

Lista<Canciones::Cancion> * Canciones::filtrado(const unsigned int inicial, const unsigned int final) const
{
	Lista<Cancion> * cursor = listado;
	Lista<Cancion> * listaResultado = new Lista<Cancion>();

	while (cursor != nullptr)
	{
		// Comprobar si la fecha entra en el rango y lo agrega a la lista resultante
		if (cursor->obtenerElemento().lanzamiento >= inicial && cursor->obtenerElemento().lanzamiento <= final)
			listaResultado->agregarElemento(cursor->obtenerElemento());
		cursor = cursor->obtenerSiguiente();
	}

	return listaResultado;
}