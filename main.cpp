#include <iostream>
#include "src/headers/Canciones.h"
#include <string>

using namespace std;

const Canciones can = Canciones("./src/include/canciones.csv");

string toString(Lista<Canciones::cancion> * & listado){
        string retorno = "[\n";
        Lista<Canciones::cancion> * cursor = listado;
        while(!cursor->listaVacia()){
            Canciones::cancion cancion = cursor->obtenerElemento();
            retorno.append("(").append(to_string(cancion.id)).append(", ").append(cancion.nombre).append(", ").append(cancion.interprete).append(", ").append(to_string(cancion.lanzamiento)).append(", ").append(cancion.duracion).append(", ").append(cancion.genero).append(", ").append(to_string(cancion.reproducciones)).append(")\n");
            cursor = cursor->obtenerSiguiente();
        }
        retorno.append("]");
        return retorno;
}

int mostrarMenu(){
    while(true){
        cout<<"--------------------------- BIENVENIDOS ---------------------------"<<endl;
        cout<<"Elige una Opcion"<<endl;
        cout<<"1. Buscar Cancion"<<endl;
        cout<<"2. Listar Canciones Entre Fechas"<<endl;
        cout<<"3. Listar Top Canciones Por Genero"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        string opcion;
        cin>>opcion;
        if(opcion == "1"){
            cout<<"Ingrese El titulo de la cancion"<<endl;
            string titulo;
            cin>>titulo;
            Lista<Canciones::cancion> * resultado = can.busqueda(titulo);
            cout<<toString(resultado)<<endl;
        }else if(opcion == "2"){
            unsigned int primer_fecha, segunda_fecha;
            cout<<"Ingrese Las Dos Fechas"<<endl;
            cout<<"Fecha Inicial: ";
            cin>>primer_fecha;
            cout<<"Fecha Final: ";
            cin>>segunda_fecha;
            Lista <Canciones::cancion> * resultado = can.filtrado(primer_fecha, segunda_fecha);
            cout<<toString(resultado)<<endl;
        }else if(opcion == "3"){
            cout<<"Ingrese El genero a Buscar"<<endl;
            string genero;
            cin>>genero;
            Lista<Canciones::cancion> * resultado = can.obtenerTopCancionesGenero(genero);
            cout<<toString(resultado)<<endl;
        }else if(opcion == "4"){
            return 1;
        }else{
            cout<<"Esa Opcion no Existe, por favor elige otra"<<endl;
        }
    }
}

int main(){

    mostrarMenu();
    return 0;

}
