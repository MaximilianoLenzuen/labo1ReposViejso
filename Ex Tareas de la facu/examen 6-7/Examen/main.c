#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define P 3
#define L 3


typedef struct
{
    char dni[50];
    char nombre[50];
    int localidad;
}ePersona;

typedef struct
{
    int id;
    char descripcion[150];
    int codigoPostal;
}eLocalidad;

void Ordenar(ePersona lista[],int tamPersona, eLocalidad localidad[], int tamLocalidad);
void listarPersonas(ePersona persona[], int tamPersona,eLocalidad localidad[],int tamLocalidad);
void obtenerLocalidad(int id,eLocalidad lista[],int tam,char* descripcion);

int main()
{
    ePersona persona[P]={ {"39242857","maximiliano",1}, {"39656666", "german" , 2}, {"35646458","octavio",3} };
    eLocalidad localidades[L] ={ {1,"Longchamps: Ciudad zona sur",1854}, {3, "Burzaco: CIUDAD ZONA SUR DE AMBA" , 1666}, {2,"Hurlingham CIUDAD NORTE",1332} };

    listarPersonas(persona,P,localidades,L);
    Ordenar(persona,P,localidades,L);
    listarPersonas(persona,P,localidades,L);
}



void Ordenar(ePersona lista[],int tamPersona, eLocalidad localidad[], int tamLocalidad)
{
    int i;
    int j;
    int h;
    char auxiliarUno[60];
    char auxiliarDos[60];
    ePersona aux;
    for(i=0; i<tamPersona-1; i++)
    {
        for(j=i+1; j<tamPersona; j++)
        {
            if(strcmp(lista[i].nombre,lista[j].nombre)>0)
            {
                aux=lista[i];
                lista[i]=lista[j];
                lista[j]=aux;
            }
            else
                obtenerLocalidad(lista[i].localidad,lista,tamPersona,auxiliarUno);
                obtenerLocalidad(lista[j].localidad,lista,tamPersona,auxiliarDos);
                if( strcmp(lista[i].nombre,lista[j].nombre)>0 && strcmp(auxiliarUno,auxiliarDos) > 0 )
                {
                    aux=lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux;
                }

            }
        }
}


void listarPersonas(ePersona persona[], int tamPersona,eLocalidad localidad[],int tamLocalidad)
{
    int i;
    int j;
    for(i=0;i<tamPersona;i++)
    {
        for (j=0;j<tamLocalidad;j++)
        {
            if(persona[i].localidad == localidad[j].id)
            {
                        printf("%s , %s , %s\n",persona[i].dni,persona[i].nombre,localidad[j].descripcion);
            }

        }

    }
}

void obtenerLocalidad(int id,eLocalidad lista[],int tam,char* descripcion)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(id == lista[i].id)
        {
            strcpy(descripcion,lista[i].descripcion);
            break;
        }
    }

}


/*
        Una funcion es un fragmento de codigo que realiza determinada tarea, ademas de hacer más prolijo y práctico el código.
        La recursividad es la llamada de una funcion dentro de una misma(la función A llama a la función B, que a su vez vuelve a llamar a A).
        Existen los parametros formales, que son especificados en la cabecera de la funcion, y los parametros actuales,
        Cuando creamos una funcion definimos los parametros formales, y cuando la llamamos le pasamos los parametros acuales.
        que son las expresiones pasadas como argumento al momento de llamar a la funcion. Tanto las funciones como la recursividad
        se almacenan en la pila, que es una estructura de datos que permite almacenarlos.
*/

