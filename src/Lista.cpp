#include "headers/Lista.h"
#include <string>
#include "headers/Canciones.h"

using namespace std;

template <typename T>
Lista<T>::Lista(){
	this->siguiente = nullptr;
}

template <typename T>
void Lista<T>::agregarElemento(T elemento){
	Lista<T> * nuevaLista = new Lista<T>();
	nuevaLista = this;
	this->elemento = elemento;
	this->siguiente = nullptr;
}

template<typename T>
void Lista<T>::eliminarElemento(){
	Lista<T> * eliminado = this;
	this->elemento = this->siguiente->elemento;
	this->siguiente = this->siguiente->siguiente;
	delete eliminado;
}

template<typename T>
T Lista<T>::obtenerElemento() const{
	return elemento;
}

template<typename T>
Lista<T> * Lista<T>::obtenerSiguiente() const{
	return siguiente;
}

template<typename T>
void Lista<T>::operator=(Lista<T> * nuevaLista){
	this-> elemento = nuevaLista->elemento;
	this-> siguiente = nuevaLista->siguiente;
}

template<typename T>
bool Lista<T>::listaVacia() const{
	return (this->siguiente == nullptr);
}
template class Lista<Canciones::Cancion>;
template class Lista<string>;