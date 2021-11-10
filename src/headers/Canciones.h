#include <string>
#include "Lista.h"
class Canciones{
	public:
		Canciones(const std::string & direccion);
		struct cancion {
			unsigned int id;
			std::string nombre;
			std::string interprete;
			unsigned int lanzamiento;
			std::string duracion;
			std::string genero;
			unsigned int reproducciones;
		};

		void obtenerTopCancionesGenero(const std::string & genero) const;
		Lista<cancion> * busqueda(std::string texto) const;
		Lista<cancion> * filtrado(unsigned int fInicial, unsigned int fFinal) const;
		std::string toString() const;
		std::string toString(cancion cancion) const;
	private:
		void agregarElemento(std::string & elemento, unsigned int id);
    	std::string quitarAcentos(std::string texto) const;
		bool busquedaPorPatron(std::string texto, std::string patron) const;
		unsigned int cantidad_canciones;

		Lista<cancion> * listado;
};
