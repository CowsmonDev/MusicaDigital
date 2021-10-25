#include <string>
#include "Lista.h"

using namespace std;

class Canciones{
	public:
		Canciones(const string & direccion);
		struct Cancion {
			string id;
			string nombre;
			string interprete;
			unsigned int lanzamiento;
			string duracion;
			string genero;
			unsigned int reproducciones;
		};

		Lista<Cancion> * obtenerTopCancionesGenero(string genero) const;
		Lista<Cancion> * busqueda(string texto) const;
		Lista<Cancion> * filtrado(unsigned int inicial, unsigned int final) const;
	private:
		void agregarElemento(string & elemento);
		unsigned int cantidad_canciones;

		Lista<Cancion> * listado;
};