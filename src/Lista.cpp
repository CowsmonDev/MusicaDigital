#include "headers/Lista.h"
#include <string>
#include "headers/Canciones.h"

using namespace std;

template <typename T>
Lista<T>::Lista(){
	this->primero = new Nodo();
	this->primero->elemento = NULL;
}

template <typename T>
void Lista<T>::agregarElemento(T elemento){
	Nodo * nuevoElemento = new Nodo();
	nuevoElemento->elemento = elemento;
	nuevoElemento->siguiente = this->primero;
	this->primero = nuevoElemento;
}

template<typename T>
void Lista<T>::eliminarElemento(int indice){
	Nodo * cursor = primero;
	int i = 0;
	while ((i != indice) && (cursor->elemento != NULL)){
		cursor = cursor->siguiente;
		i++;
	}
	if (cursor->elemento != NULL)
	{
		Nodo * eliminado = cursor;
		cursor = cursor->siguiente;
		delete eliminado;
	}
}

template<typename T>
T Lista<T>::obtenerElemento() const{
	return primero->elemento;
}

template<typename T>
Lista<T> * Lista<T>::obtenerSiguiente() const{
	return primero->siguiente;
}
template class Lista<Canciones::cancion>;
template class Lista<string>;