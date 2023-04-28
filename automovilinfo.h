#include <iostream>
#include <cstring>
using namespace std;
class Automovil{
  private:
     string marca;
     string modelo;  
     int numPasajeros;
     int anio;
     float kilometraje;
     int numPuertas;
     string color;
     float rendimientos;
     int capacidadTanque;
     float gasolinaEnTanque;
     
  public:
    Automovil();
    ~Automovil(){}
    string getMarca();
    string getModelo();
    int getAnio();
    int getKilometraje();
    int getNumPuertas();
    float getRendimientos();
    int getCapacidadTanque();
    float getGasolinaEnTanque();
    int getNumPasajeros();
    string getColor();
    void setMarca(string valor);
    void setModelo(string valor);
    void setAnio(int dato);
    void setKilometraje(int dato);
    void setNumPuertas(int dato);
    void setColor(string dato);
    void setNumPasajeros(int num);
    void setRendimientos(float dato);
    void setCapacidadTanque(int dato);
    void setGasolinaEnTanque(float num);
    void avanzaAutomovil(float, int);
    float calculaConsumo(float, int);
    void llenaTanque();
    void imprimeAutomovil();
    bool requiereMantenimiento();
    int validaGasolinaEnTanque();
};

Automovil::Automovil()
{
    marca = "CHEVROLET";
    modelo= "CORVETTE Z51-Coupe";  
    numPasajeros = 2;
    anio = 2023;
    kilometraje = 0;
    numPuertas = 2;
    color = "gris-plateado";
    rendimientos = 10.1;
    capacidadTanque = 70;
    gasolinaEnTanque = 70;
}

//setters
void Automovil::setMarca(string valor){
    marca = valor;
}
void Automovil::setModelo(string valor){
    modelo = valor;
}
void Automovil::setAnio(int dato){
    anio = dato;
}
void Automovil::setKilometraje(int dato){
    kilometraje = dato;
}
void Automovil::setNumPuertas(int dato){
    numPuertas = dato;
}
void Automovil::setColor(string dato){
    color = dato;
}
void Automovil::setNumPasajeros(int num){
    numPasajeros = num;
}
void Automovil::setRendimientos(float num){
    rendimientos = num;
}
void Automovil::setCapacidadTanque(int dato){
    capacidadTanque = dato;
}
void Automovil::setGasolinaEnTanque(float num){
    gasolinaEnTanque = num;
}


//getters
string Automovil::getMarca()
{
    return marca;
}
string Automovil::getModelo()
{
    return modelo;
}
int Automovil::getNumPasajeros()
{
    return numPasajeros;
}
int Automovil::getAnio()
{
    return anio;
}
int Automovil::getKilometraje()
{
    return kilometraje;
}
int Automovil::getNumPuertas()
{
    return numPuertas;
}
string Automovil::getColor()
{
    return color;
}
float Automovil::getRendimientos() //rendimiento = cuantos km por L de gasolina, gasEnTan - distancia
{
    return rendimientos;
}
int Automovil::getCapacidadTanque()
{
    return capacidadTanque;
}
float Automovil::getGasolinaEnTanque()
{
    return gasolinaEnTanque;
}


 //funciones especificas
void Automovil::imprimeAutomovil(){
    cout<<"--------------------------------------"<<endl;
    cout<<"* * I n f o   d e l   c a r r o  * *"<<endl;
    cout<<"La marca es: "<<marca<<endl;
    cout<<"El modelo es: "<<modelo<<endl;
    cout<<"El año es: "<<anio<<endl;
    cout<<"El num de pasajeros es de: "<<numPasajeros<<endl;
    cout<<"El num de puertas es de: "<<numPuertas<<endl;
    cout<<"El color del carro es: "<<color<<endl;
    cout<<"El kilometraje del carro es de: "<<kilometraje<<endl;
    cout<<"El rendimiento del carro es de: "<<rendimientos<<endl;
    cout<<"La capacidad del tanque es de: "<<capacidadTanque<<endl;
    cout<<"La gasolina en el tanque es de: "<<gasolinaEnTanque<<endl;
    cout<<"--------------------------------------"<<endl;
}

int Automovil::validaGasolinaEnTanque()
{
    int gasolina;
    do{
        cout<<"Dame el valor de la Gasolina en tanque: ";
        cin>>gasolina;
        if (gasolina>capacidadTanque){
            cout<<"Introduce un valor valido"<<endl;
        }
    } while (gasolina>capacidadTanque);{}
    gasolinaEnTanque=gasolina;
    return gasolinaEnTanque;
}

float Automovil::calculaConsumo(float distancia, int pasajeros){
    float consumoLitros=distancia/rendimientos;
    if (consumoLitros<gasolinaEnTanque){
        if (pasajeros == numPasajeros){
            consumoLitros=consumoLitros*1.05;
            return consumoLitros;
        }else if (pasajeros<numPasajeros){
            consumoLitros=consumoLitros*0.96;
            return consumoLitros;
        }
    }else{
        return -1;
    }
}

bool Automovil::requiereMantenimiento(){
    if (kilometraje>10000){
        cout<<"Mantenimiento requerido"<<endl;
        return true;
}else{
    return false;
}
}
void Automovil::avanzaAutomovil(float distancia, int pasajeros){
    bool mantenimientoResult= requiereMantenimiento();
    float consumo= calculaConsumo(distancia, pasajeros);
    if (consumo >= 0 && mantenimientoResult == false){
        cout<<"!Avance confirmado!"<<endl;
        kilometraje = kilometraje + distancia;
        gasolinaEnTanque = gasolinaEnTanque - consumo;
        cout<<"GASOLINA EN EL TANQUE"<<gasolinaEnTanque<<endl;
    } else if (mantenimientoResult == true){
        cout<<"Mantenimiento requerido"<<endl;
    } else if (consumo == -1){
        cout<<"No hay suficiente gasolina"<<endl;
    }
}

void Automovil::llenaTanque(){
    float falta = capacidadTanque-gasolinaEnTanque;
    cout<<"Para que el tanque se llene faltan: "<<falta<<" litros"<<endl;
    gasolinaEnTanque=capacidadTanque;
    cout<<"Tanque lleno"<<endl;
}