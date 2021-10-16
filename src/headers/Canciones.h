#include <string>
class Canciones{
	public:
		Canciones(const string & direccion);
		[]string obtenerTopCancionesGenero(string genero) const;
	private: 
		void agregarElemento(const string & elemento);
		struct cancion {
			std::string id;
			std::string nombre;
			std::string interprete;
			std::string lanzamiento;
			std::string duracion;
			std::string genero;
			unsigned int repoducciones;
		};

		Lista<cancion> * listado;
};