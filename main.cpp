/*
Curso de programación C++
Steck Orozco Durán
Danilo Rojas Chanto
PRACTICA 3

El algoritmo desarrollado para la PRACTICA 3 es basicamente el siguiente:

1.Empezar con pantalla de inicio
2.Preguntar cuandos dispositivos se desea inventariar
3.Llenar el inventario basado en "NOMBRE", "TIPO" y "CONSUMO" para cada dispositivo
4.Preguntar cuantas horas estuvo cada dispositivo en uso
5.Del inventario determinar los "TIPO" de dispositvos que se ingresaron
6.Calcular el TOTAL de Watts-hora por TIPO de dispositivos.
7.Mostrar el resultado del cálculo de los totales.
8.Preguntar si se desea volver a inventariar dispositivos o si se desea salir del programa.
9.Terminar programa.

*/

// Inluir las librerias necesarias para el programa
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Declaración de estructura que almacenará el inventario de máximo 10 dispositivos
struct INVENTARIO_IOT {
  string NOMBRE;
  string TIPO;
  float CONSUMO;
  float TIEMPO;
} DISPOSITIVOS[10];

//Declaración de variables globales que se utilizaran en las funciones
string TIPOS[10];
string auxTIPOS[10];
string mystr;
float TOTALES[10];
short int n,m,cantTIPOS,y,cantDISPOSITIVOS;


//Función que muestra en pantalla lo que hace el programa
void principal(void){
  cout << "================================================================"<< endl;
  cout << "|          SISTEMA DE INVENTARIO Y CONTROL DE CONSUMO          |"<< endl;
  cout << "|                     DE DISPOSITIVOS IOT                      |"<< endl;
  cout << "|                                                              |"<< endl;
  cout << "|         Desarrollado por:                                    |"<< endl;
  cout << "|                          Steck Orozco Duran                  |"<< endl;
  cout << "|                          Danilo Rojas Chanto                 |"<< endl;
  cout << "================================================================"<< endl;
}

//Función que solicita al usuario un numero entre 1 a 10 que corresponde
//al numero de dispositivos a inventariar; se sale de la función únicamente
//digitando un numero en ese rango el cual sera almacenado en "cantDISPOSITIVOS"
void getCANTIDAD (){
  y=1;
  while(y){
    cout<<"Digite el numero de dispositivos que desea registrar (1-10): ";
    getline (cin,mystr);
    stringstream(mystr) >> cantDISPOSITIVOS;
    if (cantDISPOSITIVOS<=0 || cantDISPOSITIVOS>10){
      cout<< "Número fuera del rango permitido\n";
      y=1;
    }
    else{
      y=0;
    } 
  }
}

//Función que de acuerdo a la cantidad de dispositivos a inventariar
//solicita los datos que seran almacenados en la estructura tales
//como "NOMBRE","TIPO" y "CONSUMO" para cada uno de los dispositivos.
//Al mismo tiempo que se llena el dato "TIPO" se respalda en un arreglo llamado
//auxTIPOS[] ya que mas adelante servirá para hacer la clasificación de dispositivos
void getINVENTARIO (){
  cout << "================================================================"<< endl;
  cout << "\nIngrese los parametros de los dispositivos\n";
  cout << "================================================================"<< endl;
  for (n=0; n<cantDISPOSITIVOS; n++){
    cout << "\nNombre del dispositivo: ";
    getline (cin,DISPOSITIVOS[n].NOMBRE);
    cout << "Tipo                  : ";
    getline (cin,DISPOSITIVOS[n].TIPO);
    auxTIPOS[n]=DISPOSITIVOS[n].TIPO;
    cout << "Consumo (Watts)       : ";
    getline (cin,mystr);
    stringstream(mystr) >> DISPOSITIVOS[n].CONSUMO;
  cout << "================================================================"<< endl;
  }
}

//Función que solicita al usuario ingresar las "horas de consumo" de los dispositivos
//el cual será almacenado en la estructura en la variable "TIEMPO"
//para cada uno de los dispositivos identificados en pantalla por el "NOMBRE"
//que el mismo usuario ingresó para cada dispositivo
void getTIEMPOS (){
  cout << "\nIngrese los tiempos de consumo EN HORAS de los dispositivos:\n";
  cout << "================================================================"<< endl;
  for (n=0; n<cantDISPOSITIVOS; n++){
    cout << DISPOSITIVOS[n].NOMBRE<<" : ";
    getline (cin,mystr);
    stringstream(mystr) >> DISPOSITIVOS[n].TIEMPO;
  }
}

//Función que determina los tipos de dispositivos utilizando el arreglo que sirvió de 
//respaldo llamado "auxTIPOS[]",  guardando en el arreglo en orden alfabetico ascendente,  
//los tipos de dispositivos que el usuario digitó
void determinaTIPOS(){
//Este ciclo ordena alfabeticamente todos los "TIPOS" de dispositivos
//respaldados en el arreglo auxTIPOS[].
//Asi por ejemplo si al final de que el usuario ingresara la información el arreglo queda
// "auxTIPOS[]{luz,cámaras,tomas,luz}" luego quedaría "auxTIPOS[]{cámaras,luz,luz,tomas}"
  for(m=0;m<cantDISPOSITIVOS;m++){
    for (n=m+1; n<cantDISPOSITIVOS; n++){
      if(auxTIPOS[m]>auxTIPOS[n]){
        mystr=auxTIPOS[m];
        auxTIPOS[m]=auxTIPOS[n];
        auxTIPOS[n]=mystr;
      }
    }
  }
//En este ciclo se toma la información que resultó del arreglo auxTIPOS[]
//y se almacena sólo las palabras sin repetir en otro arreglo llamado "TIPOS[]""
//así por ejemplo si en el arreglo respaldo era: "auxTIPOS[]{cámaras,luz,luz,tomas}"
//en el otro arreglo quedaría "TIPOS[]{cámaras,luz,tomas}"
  TIPOS[0]=auxTIPOS[0];
  n=0;
  for(m=1;m<cantDISPOSITIVOS;m++){
    if(TIPOS[n]!=auxTIPOS[m]){
      n+=1;
      TIPOS[n]=auxTIPOS[m];
    }
  }
  cantTIPOS=n+1;
}

//Función que determina los totales del consumo en Watts-hora  y
//muestra en pantalla el total para cada TIPO de dispositivo. 
void printTOTALES(){
  cout << "================================================================"<< endl;  
  cout << "\nReporte del Total consumido por TIPO de dispositivo:\n";
  cout << "================================================================"<< endl;
//Este ciclo explora en la estructura los TIPOS de dipositivos y calcula el consumo
//de Watts-hora por cada dispositivo y lo suma con el consumo de los otros dispositivos
//que sean del mismo TIPO. 
  for(n=0;n<cantTIPOS;n++){
    for(m=0;m<cantDISPOSITIVOS;m++){
      if(DISPOSITIVOS[m].TIPO==TIPOS[n]){
        TOTALES[n]+=(DISPOSITIVOS[m].CONSUMO*DISPOSITIVOS[m].TIEMPO);
      }
    }
    cout<<TIPOS[n]<<": "<<TOTALES[n]<<" Watts-hora\n" ;
    TOTALES[n]=0;
  }
  cout << "================================================================"<< endl;
}



//Función principal que llama a cada una de las otras funciones

int main(void){

  short int z; 
  z=1;

  while(z!=0){
    
    principal();

    getCANTIDAD ();

    getINVENTARIO ();

    getTIEMPOS ();

    determinaTIPOS();

    printTOTALES();

//Presenta al usuario la opción de continuar o volver a ingresar información
    cout << "\nDigite 0 para salir o cualquier numero para reiniciar: ";
    getline (cin,mystr);
    stringstream(mystr) >> z;

  }
  return 0;
}

