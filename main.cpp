// Curso de programación C++
// Steck Orozco Durán
// Danilo Rojas Chanto
// PRACTICA 3
// 

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct INVENTARIO_IOT {
  string NOMBRE;
  string TIPO;
  float CONSUMO;
  float TIEMPO;
} DISPOSITIVOS[10];

string TIPOS[10];
string auxTIPOS[10];
string mystr;
float TOTALES[10];
short int n,m,x,y,cantDISPOSITIVOS;

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

void getTIEMPOS (){
  cout << "\nIngrese los tiempos de consumo EN HORAS de los dispositivos:\n";
  cout << "================================================================"<< endl;
  for (n=0; n<cantDISPOSITIVOS; n++){
    cout << DISPOSITIVOS[n].NOMBRE<<" : ";
    getline (cin,mystr);
    stringstream(mystr) >> DISPOSITIVOS[n].TIEMPO;
  }
}

void determinaTIPOS(){
  for(m=0;m<cantDISPOSITIVOS;m++){
    for (n=m+1; n<cantDISPOSITIVOS; n++){
      if(auxTIPOS[m]>auxTIPOS[n]){
        mystr=auxTIPOS[m];
        auxTIPOS[m]=auxTIPOS[n];
        auxTIPOS[n]=mystr;
      }
    }
  }
  TIPOS[0]=auxTIPOS[0];
  n=0;
  for(m=1;m<cantDISPOSITIVOS;m++){
    if(TIPOS[n]!=auxTIPOS[m]){
      n+=1;
      TIPOS[n]=auxTIPOS[m];
    }
  }
  x=n+1;
}

void printTOTALES(){
  for (n=0; n<x; n++){
    for(m=0;m<cantDISPOSITIVOS;m++){
      if(DISPOSITIVOS[m].TIPO==TIPOS[n]){
        TOTALES[n]+=(DISPOSITIVOS[m].CONSUMO*DISPOSITIVOS[m].TIEMPO);
      }
    }
  }
    cout << "================================================================"<< endl;  
    cout << "\nReporte del Total consumido por TIPO de dispositivo:\n";
    cout << "================================================================"<< endl;
    for(n=0;n<x;n++){
      cout<<TIPOS[n]<<": "<<TOTALES[n]<<" Watts-hora\n" ;
      TOTALES[n]=0;
    }
    cout << "================================================================"<< endl;
}





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

    cout << "\nDigite 0 para salir o cualquier numero para reiniciar: ";
    getline (cin,mystr);
    stringstream(mystr) >> z;

  }
  return 0;
}

