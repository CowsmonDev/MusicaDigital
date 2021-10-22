template <typename T>

class Lista{
	public:
		Lista();
		void agregarElemento(T elemento);
		void eliminarElemento(int indice);
		T obtenerElemento() const;
		Lista<T> * obtenerSiguiente() const;
	private:
		struct Nodo{
			T elemento;
			Lista<T> * siguiente;
		};
		Nodo * primero;
};