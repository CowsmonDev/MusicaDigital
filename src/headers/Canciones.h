#include <string>
class Canciones{
	public:
		Canciones(const std::string & direccion) const;
	private: 
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