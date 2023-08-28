#include "Mascotas_Clientes.h"
#define OCUPADO 1
#define LIBRE 0

void mostrarClientesMascotas(eCliente cliente[],int tamCliente,eMascotas mascota[], int tamMascota,int estado){

    int i;
    int j;
    printf("\n******Listado de clientes con sus mascotas******");
    printf("\n*********NOMBRE*******APELLIDO******LOCALIDAD******TELEFONO********EDAD******SEXO*****lISTA DE ANIMALES");
    for(i=0;i<tamCliente;i++)
        {
            if(cliente[i].estado == estado){
                printf("\n%15s%15s%15s%15s%10d%10c",cliente[i].nombre
                                                   ,cliente[i].apellido
                                                   ,cliente[i].localidad
                                                   ,cliente[i].telefono
                                                   ,cliente[i].edad
                                                   ,cliente[i].sexo);
            }


            for(j=0;j<tamMascota;j++){
                if(cliente[i].estado==estado && cliente[i].idCliente==mascota[j].idDuenio){
                    printf("%10s: %10s",mascota[j].tipo,mascota[j].nombre);
                }
            }
        }


}

void mostrarMascota(eCliente cliente[],int tamCliente,eMascotas mascota[], int tamMascota,int estado){
    int i;
    int j;
    printf("\n******Listado de mascotas******");
    printf("\nID*********NOMBRE************TIPO**********RAZA************EDAD********PESO*********SEXO*******DUENIO");
    for(i=0;i<tamMascota;i++)
        {
            if(mascota[i].estado == estado){

                printf("\n%d%15s%16s%15s%15d%13.2f%10c ",mascota[i].idMascota
                                                        ,mascota[i].nombre
                                                        ,mascota[i].tipo
                                                        ,mascota[i].idRaza
                                                        ,mascota[i].edad
                                                        ,mascota[i].peso
                                                        ,mascota[i].sexo);
            }
            for(j=0;j<tamCliente;j++){
                if(mascota[i].estado==estado && mascota[i].idDuenio==cliente[j].idCliente){
                    printf("%15s",cliente[j].apellido);
                }
            }
        }
}

int altaMascota(eRaza razaPais[],int tamRaza, eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado,int contador){

    int guardarIndice;
    int auxRaza;
    int i;
    int j;
    int h;
    int aux=0;

    guardarIndice = buscarIndiceMascota(mascota, tamMascota,LIBRE);

    if(guardarIndice != -1){
        mascota[guardarIndice].idMascota=31+contador;

            while(aux!=1)
            {
            printf("\nIngrese un id de duenio valido: ");
            scanf("%d",&mascota[guardarIndice].idDuenio);
                for(j=0;j<tamCliente;j++){
                    if(mascota[guardarIndice].idDuenio==cliente[j].idCliente){
                        aux=1;
                        break;
                    }
                }


            }

        getString("\nIngrese el nombre de la mascota:",mascota[guardarIndice].nombre);
        getString("\nIngrese el tipo de la mascota[Perro, Gato, Raro]:",mascota[guardarIndice].tipo);
        while( strcmp(mascota[guardarIndice].tipo, "perro")!=0 &&  strcmp(mascota[guardarIndice].tipo, "gato")!=0 &&  strcmp(mascota[guardarIndice].tipo, "raro")!=0){
            getString("\nIngrese el tipo correcto [Perro, Gato, Raro] :",mascota[guardarIndice].tipo);
        }
        auxRaza=getInt("\nIngrese la raza de la mascota([1-Siames][2-Persa][3-BloodHound][4-Rootwailer][5-Lagarto][6-Buho]):","Ingrese una raza valida",1,6);
        for(h=0;h<tamRaza;h++){
            if(auxRaza==razaPais[h].idRaza){
                mascota[i].idRaza=razaPais[h].idRaza;
            }
        }

        mascota[guardarIndice].edad=getInt("\nIngrese la edad de la mascota:","ingrese una edad valida!!",0,100);
        printf("\nIngrese peso la mascota: ");
        scanf("%f",&mascota[guardarIndice].peso);
        mascota[guardarIndice].estado=estado;
        printf("\nIngrese el sexo de la mascota: ");
        fflush(stdin);
        scanf("%c",&mascota[guardarIndice].sexo);
        while(mascota[guardarIndice].sexo !='m'&& mascota[guardarIndice].sexo!='f'){
            printf("\nIngrese un sexo correcto: ");
            fflush(stdin);
            scanf("%c",&mascota[guardarIndice].sexo);
        }
        return 1;
    }
    return 0;

}

int bajaClienteCascada(eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado){
    int i;
    int j;
    int idBajar;
    int aux=0;
    printf("\nIngrese el id del cliente/duenio a dar de baja: ");
    scanf("%d",&idBajar);
    for(i=0; i < tamCliente; i++){
                if(cliente[i].idCliente == idBajar){
                    cliente[i].estado= estado;
                    aux=1;
                    for(j=0; j < tamMascota; j++){
                        if(cliente[i].idCliente==mascota[j].idDuenio){
                            mascota[j].estado=estado;
                    }
                }
                }

    }
    return aux;
    }

void listarMascotasMayores(eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado){
    int i;
    int j;
    printf("*****Listado de mascotas mayores de 3 a�os*****\n");
    for(i=0;i<tamMascota;i++){
        if(mascota[i].edad>3&&mascota[i].estado==estado){
                for(j=0;j<tamCliente;j++){
                    if(mascota[i].idDuenio==cliente[j].idCliente){
                        printf("\nMascota: %s y su duenio es: %s",mascota[i].nombre,cliente[j].nombre);
                    }
                }

        }
    }
}

void initMascotaCliente(eMascotaCliente mascotaCliente[], eCliente cliente[],int tamCliente){
    int i;
    for(i=0;i<tamCliente;i++){
        if(cliente[i].estado==OCUPADO){
        mascotaCliente[i].contadorMascotas=0;
    }
    }
    }

void contadorMascotasPorCliente(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota){
    int i;
    int j;
    for(i=0;i<tamCliente;i++){
        for(j=0;j<tamMascota;j++){
            if(cliente[i].estado == OCUPADO && cliente[i].idCliente == mascota[j].idDuenio){
                mascotaCliente[i].contadorMascotas++;

            }

        }
    }
}

void listarClientesMasUnaMascota(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota){
    int i;
    contadorMascotasPorCliente(mascotaCliente,cliente,tamCliente,mascota,tamMascota);
    printf("Los clientes con mas de una mascota son: ");
    for(i=0;i<tamCliente;i++){
        if(mascotaCliente[i].contadorMascotas > 1 && cliente[i].estado == OCUPADO){
            printf("\n - %s %s",cliente[i].nombre,cliente[i].apellido);
        }
    }


}

void ordenarClientesPorCantidadMascotas(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota){

    int i;
    int j;
    eCliente aux;
    eMascotaCliente auxUno;
    contadorMascotasPorCliente(mascotaCliente,cliente,tamCliente,mascota,tamMascota);
    for(i=0; i<tamCliente-1; i++)
    {
        for(j=i+1; j<tamCliente; j++)
        {
            if(mascotaCliente[i].contadorMascotas>mascotaCliente[j].contadorMascotas)
            {
                aux=cliente[i];
                cliente[i]=cliente[j];
                cliente[j]=aux;

                auxUno=mascotaCliente[i];
                mascotaCliente[i]=mascotaCliente[j];
                mascotaCliente[j]=auxUno;

            }

        }
    }

}

void ordenarClientesPorCantidadMascotasYNombres(eMascotaCliente mascotaCliente[],eCliente cliente[],int tamCliente,eMascotas mascota[],int tamMascota){
    int i;
    int j;
    eMascotaCliente auxUno;
    eCliente aux;

    contadorMascotasPorCliente(mascotaCliente,cliente,tamCliente,mascota,tamMascota);
    for(i=0; i<tamCliente-1; i++)
    {
        for(j=i+1; j<tamCliente; j++)
        {
            if(mascotaCliente[i].contadorMascotas>mascotaCliente[j].contadorMascotas)
            {
                aux=cliente[i];
                cliente[i]=cliente[j];
                cliente[j]=aux;


                auxUno=mascotaCliente[i];
                mascotaCliente[i]=mascotaCliente[j];
                mascotaCliente[j]=auxUno;

            }
            else
            {
                if(mascotaCliente[i].contadorMascotas==mascotaCliente[j].contadorMascotas && strcmpi(cliente[i].nombre,cliente[j].nombre)>0)
                {
                    aux=cliente[i];
                    cliente[i]=cliente[j];
                    cliente[j]=aux;

                    auxUno=mascotaCliente[i];
                    mascotaCliente[i]=mascotaCliente[j];
                    mascotaCliente[j]=auxUno;
                }

            }

        }
    }
}

void listarClientesMascotasMismoSexo(eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado){
    int i;
    int j;
    int contadorHembras=0;
    int contadorMachos=0;
    printf("***********Lista de duenios con mascotas del mismo sexo********");
    for(i=0;i<tamCliente;i++){
            for(j=0;j<tamMascota;j++)
                if(cliente[i].estado == OCUPADO && cliente[i].idCliente == mascota[j].idDuenio){
                {
                    if(mascota[j].idDuenio==cliente[i].idCliente){
                        if(mascota[j].sexo == 'm'){
                            contadorMachos++;
                        }
                        if(mascota[j].sexo == 'f'){
                            contadorHembras++;
                        }
                    }
                }

            }
            if(contadorHembras > 1 || contadorMachos > 1 && cliente[i].estado == OCUPADO){
                printf("\n%s %s",cliente[i].nombre,cliente[i].apellido);
        }

    }

}

int modificarMascotaConDuenio(eRaza razapais[],int tamRaza,eMascotas mascota[],int tamMascota,eCliente cliente[],int tamCliente, int estado){
    int i;
    int h;
    int idModificar;
    int aux;
    int auxRaza;
    printf("\nIngrese el id de la mascota a modificar: ");
    scanf("%d",&idModificar);

    for(i=0; i < tamMascota; i++){
            if(mascota[i].idMascota == idModificar && mascota[i].estado == estado )
                {
                    mostrarCliente(cliente,tamCliente,OCUPADO);
                    printf("\nIngrese el ID del nuevo duenio");
                    scanf("%d",&mascota[i].idDuenio);

                    getString("\nIngrese el nombre de la mascota:",mascota[i].nombre);
                    getString("\nIngrese el tipo de la mascota[Perro, Gato, Raro]:",mascota[i].tipo);
                    while( strcmp(mascota[i].tipo, "perro")!=0 &&  strcmp(mascota[i].tipo, "gato")!=0 &&  strcmp(mascota[i].tipo, "raro")!=0)
                    {
                        getString("\nIngrese el tipo correcto [Perro, Gato, Raro] :",mascota[i].tipo);
                    }
                    auxRaza=getInt("\nIngrese la raza de la mascota([1-Siames][2-Persa][3-BloodHound][4-Rootwailer][5-Lagarto][6-Buho]):","Ingrese una raza valida",1,6);

                    for(h=0;h<tamRaza;h++){
                        if(auxRaza==razapais[h].idRaza){
                                    mascota[i].idRaza=razapais[h].idRaza;
                                }
                            }

                    mascota[i].edad=getInt("\nIngrese la edad de la mascota:","ingrese una edad valida!!",0,100);
                    printf("\nIngrese peso la mascota: ");
                    scanf("%f",&mascota[i].peso);
                    mascota[i].sexo=getChar("\nIngrese el sexo de la mascota: ");

                    while(mascota[i].sexo !='m'&& mascota[i].sexo!='f'){
                        mascota[i].sexo=getChar("Ingrese un sexo correcto!!");
                }
        return 1;


                }

                }


    return 0;

}

