#include <iostream>
#include "src/headers/Canciones.h"
#include <string>

using namespace std;

const Canciones can = Canciones("./src/include/canciones.csv");

int mostrarMenu(){
    while(true){
        cout<<"--------------------------- BIENVENIDOS ---------------------------"<<endl;
        cout<<"Elige una Opcion"<<endl;
        cout<<"1. Buscar Cancion"<<endl;
        cout<<"2. Listar Canciones Entre Fechas"<<endl;
        cout<<"3. Listar Top Canciones Por Genero"<<endl;
        cout<<"4. Listar Canciones"<<endl;
        cout<<"5. Salir"<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        string opcion;
        cin>>opcion;
        if(opcion == "1"){
            cout<<"Ingrese El titulo de la cancion"<<endl;
            string titulo;
            cin>>titulo;
            can.busqueda(titulo);
        }else if(opcion == "2"){
            unsigned int primer_fecha, segunda_fecha;
            cout<<"Ingrese Las Dos Fechas"<<endl;
            cout<<"Fecha Inicial: ";
            cin>>primer_fecha;
            cout<<"Fecha Final: ";
            cin>>segunda_fecha;
            can.filtrado(primer_fecha, segunda_fecha);
        }else if(opcion == "3"){
            cout<<"Ingrese El genero a Buscar"<<endl;
            string genero;
            cin>>genero;
            can.obtenerTopCancionesGenero(genero);
        }else if(opcion == "4")
            cout<<can.toString();
        else if(opcion == "5"){
            return 0;
        }else{
            cout<<"Esa Opcion no Existe, por favor elige otra"<<endl;
        }
    }
}

int main(){
    mostrarMenu();
    return 0;
}
