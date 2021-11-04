#include <string>
#include "Lista.h"
class Canciones{
	public:
		Canciones(const std::string & direccion);
		struct cancion {
			std::string id;
			std::string nombre;
			std::string interprete;
			unsigned int lanzamiento;
			std::string duracion;
			std::string genero;
			unsigned int reproducciones;
		};

		Lista<cancion> * obtenerTopCancionesGenero(const string & genero) const;
		Lista<cancion> * busqueda(string texto) const;
		Lista<cancion> * filtrado(unsigned int fInicial, unsigned int fFinal) const;
	private:
		void agregarElemento(string & elemento);
		unsigned int cantidad_canciones;

		Lista<cancion> * listado;
};
