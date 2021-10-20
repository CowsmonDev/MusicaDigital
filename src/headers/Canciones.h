#include <string>

using namespace std;

class Canciones{
	public:
		Canciones(const string & direccion);
		Lista<string> obtenerTopCancionesGenero(string genero) const;
		Lista<string> busqueda(string texto) const;
		Lista<string> filtrado(int fInicial, int fFinal) const;
	private:
		void agregarElemento(const string & elemento);
		struct Cancion {
			string id;
			string nombre;
			string interprete;
			string lanzamiento;
			string duracion;
			string genero;
			unsigned int reproducciones;
		};

		Lista<Cancion> * listado;
};
