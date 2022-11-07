#include <stdio.h>
#include <stdlib.h>
#include <string.h>
///structura
struct pasajero{
 char nombre[25];
 int edad;
 int posicion;
};
struct vehiculo{
 char marca[25];
 int anio;
 char color[25];
 struct pasajero pasa[4];
 float totalEdad;
};
///CREAR PASAJ AUX
void crearPasajerosAux(struct vehiculo *v, int cant);
struct pasajero pasajeroAux(char n[], int e, int p);
///MOSTRAR AUTO
void mostrarVehiculo(struct vehiculo v);
///MOSTAR PASAJERO
void mostarPasajeros(struct vehiculo v, int cant);
///CREAR PASAJERO
struct pasajero crearPasajeroParametros(char n[], int e, int p);
///CREAR AUTO
struct vehiculo crearVehiculoParametros(char m[], int a, char c[]);
///CREAR PASAJERO EN AUTO
void crearPasajeroEnAuto(struct vehiculo *v,char n[], int e, int p);
///ORDENAR PASAJERO POR POSICION
void ordenarPasajeros(struct vehiculo v, int cant);
int main()
{
    struct vehiculo v;
    v=crearVehiculoParametros("PEUGOT",2011,"NEGRO");
    mostrarVehiculo(v);
    crearPasajerosAux(&v,4);
    crearPasajeroEnAuto(&v, "Agustin",19,2);
    crearPasajeroEnAuto(&v,"FELIPE",19,3);
    crearPasajeroEnAuto(&v,"JOSE",24,1);
    mostarPasajeros(v,4);
    ordenarPasajeros(v,4);
    return 0;
}
///CREAR pasajero
struct pasajero crearPasajeroParametros(char n[], int e, int p){
struct pasajero pas;
strcpy(pas.nombre,n);
pas.edad=e;
pas.posicion=p;
return pas;
};
///CREAR AUTO
struct vehiculo crearVehiculoParametros(char m[], int a, char c[]){
struct vehiculo v;
strcpy(v.marca,m);
v.anio=a;
strcpy(v.color,c);
return v;
};
///CREAR PASAJERO EN AUTO
void crearPasajeroEnAuto(struct vehiculo *v,char n[], int e, int p ){
int a;
for(a=0;a<4;a++){
    if(v->pasa[a].edad==-1){
        v->pasa[a]=crearPasajeroParametros(n,e,p);
        break;
    }
 }
}
///MOSTRAR AUTO
void mostrarVehiculo(struct vehiculo v){
printf("\n    ::::::::::::");
printf("\n    MARCA: %s", v.marca);
printf("\n    COLOR: %s", v.color);
printf("\n    ANIO: %i", v.anio);
printf("\n    ::::::::::::");
}
///MOSTRAR PASAJERO
void mostarPasajeros(struct vehiculo v,int cant){
int e;
for(e=0;e<cant;e++){
   if(v.pasa[e].edad!=-1){
 printf("\n  PASAJERO:");
 printf("\n  NOMBRE: %s", v.pasa[e].nombre);
 printf("\n  EDAD: %i",v.pasa[e].edad);
 printf("\n  POSICION: %i\n", v.pasa[e].posicion);
   }
}
system("pause");
system("cls");
}
///CREAR PASAJ AUX
struct pasajero pasajeroAux(char n[], int e, int p){
struct pasajero pasa;
strcpy(pasa.nombre,n);
pasa.edad=e;
pasa.posicion=p;
return pasa;
};

void crearPasajerosAux(struct vehiculo *v, int cant){
int f;
for(f=0;f<cant;f++){
    v->pasa[f]=pasajeroAux("VACIO",-1,-1);
}
}
///ORDENAR PASAJERO POR POSICION
void ordenarPasajeros(struct vehiculo v, int cant){
int e,f;
struct pasajero aux;
for(e=0;e<cant;e++){
 for(f=0;f<cant;f++){
    if(v.pasa[f].posicion>v.pasa[f+1].posicion){
        aux=v.pasa[f];
        v.pasa[f]=v.pasa[f+1];
        v.pasa[f+1]=aux;
    }
  }
 }
   mostarPasajeros(v,cant);
}
