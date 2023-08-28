#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int idMascota;
    int idDuenio;
    char nombre[30];
    char tipo[30];
    int idRaza;
    int edad;
    float peso;
    char sexo;
    int estado;
}eMascotas;

typedef struct
{
    int idRaza;
    char raza[30];
    char pais[30];

}eRaza;


void HardcodeRazas(eRaza[],int tam);
void HardcodeMascotas(eMascotas[],int tam);
int buscarIndiceMascota(eMascotas mascota[],int tam, int estado);
void initMascota(eMascotas mascota[], int tam,int estado);
int bajaMascota(eMascotas mascota[], int tam,int estado);
int modificarMascota(eRaza razapais[],int tamRaza,eMascotas mascota[], int tam,int estado);
void ordenarMascotas(eMascotas mascota[],int tam);
void listarMascotasPorTipo(eMascotas mascota[],int tam,int estado);
void listarPromedioEdadMascotas(eMascotas mascota[],int tam,int estado);
void mostrarPromedioDeEdadMascotas(eMascotas mascota[],int tam,int estado);
void mostrarPromedioPorTipo(eMascotas mascota[],int tam,int estado);
