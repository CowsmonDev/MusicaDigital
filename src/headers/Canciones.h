#include <string>
using namespace std;
class Canciones{
	public:
		Canciones(const string & direccion);
		[]string obtenerTopCancionesGenero(string genero) const;
	private: 
		void agregarElemento(const string & elemento);
		struct cancion {
			string id;
			string nombre;
			string interprete;
			string lanzamiento;
			string duracion;
			string genero;
			unsigned int reproducciones;
		};

		Lista<cancion> * listado;
};