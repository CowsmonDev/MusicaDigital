template <typename T>

class Lista{
	public:
		Lista();
		void agregarElemento(T elemento);
		void eliminarPrimero();
		void eliminarElemento(int indice);
		T obtenerElemento() const;
		Lista<T> * obtenerSiguiente() const;
	private:
		struct Nodo{
			T elemento;
			Lista<T> * siguiente;
		}
		Nodo * primero;
};