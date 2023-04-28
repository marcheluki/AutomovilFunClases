#include <iostream>
#include <cstring>
#include "automovilinfo.h"
using namespace std;

int main(){
    cout<<"\nSistema de control de uso de autos\n"; 
    Automovil miCoche; 
    miCoche.imprimeAutomovil(); 
    miCoche.validaGasolinaEnTanque();
    //listo hasta aqui 
    cout<<"\nQue distancia quieres recorrer?: "; 
    float distancia; 
    cin>>distancia; 
    cout<<"Cuantos pasajeros viajaran?: "<<"El maximo es 2! "<<endl; 
    float pasajeros; 
    cin>>pasajeros; 
    miCoche.avanzaAutomovil(distancia,pasajeros); 
    miCoche.imprimeAutomovil(); 
    miCoche.llenaTanque(); 
    miCoche.imprimeAutomovil();
    return 0; 
}