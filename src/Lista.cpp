#include "headers/Lista.h"
#include "headers/Canciones.h"
#include <string>

using namespace std;

template <typename T>
Lista<T>::Lista(){
	this->siguiente = NULL;
}

template <typename T>
void Lista<T>::agregarElemento(T elemento){
	Lista<T> * nuevaLista = new Lista<T>();
	nuevaLista = this;
	this->elemento = elemento;
	this->siguiente = nuevaLista;
}

template<typename T>
void Lista<T>::eliminarElemento(int indice){
	Lista<T> * eliminado = this;
	this->elemento = this->siguiente->elemento;
	this->siguiente = this->siguiente->siguiente;
	delete eliminado;
}

template<typename T>
void Lista<T>::eliminarPrimero(){
	this->eliminarElemento(0);
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
void Lista<T>::operator=(Lista<T> nuevaLista){
	this->siguiente = nuevaLista->siguiente;
	this->elemento = nuevaLista->elemento;
}

template<typename T>
bool Lista<T>::listaVacia() const{
	return (this->siguiente == NULL);
}

template class Lista<Canciones::cancion>;
template class Lista<string>;