#ifndef Lista_T
#define Lista_T
template <typename T>

class Lista{
	public:
		Lista();
		void agregarElemento(T elemento);
		void eliminarPrimero();
		void eliminarElemento(int indice);
		T obtenerElemento() const;
		Lista<T> * obtenerSiguiente() const;
		void operator=(Lista<T> nuevaLista);
		bool listaVacia() const;
	private:
<<<<<<< Updated upstream
		struct Nodo{
			T elemento;
			Lista<T> * siguiente;
		}
		Nodo * primero;
};
=======
		T elemento;
		Lista<T> * siguiente;
};

#endif
>>>>>>> Stashed changes
