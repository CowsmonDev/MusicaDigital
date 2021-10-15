#include <string>
using namespace std;
class Canciones{
	public:
		Canciones(const string & direccion) const;
	private: 
		struct cancion {
			string id;
			string nombre;
			string interprete;
			string lanzamiento;
			string duracion;
			string genero;
			unsigned int repoducciones;
		};

		Lista<cancion> * listado;
};