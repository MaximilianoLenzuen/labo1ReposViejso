#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados;
    listaEmpleados = ll_newLinkedList();
    do{
            menu();
            option = getInt("\n Ingrese una opcion","Ingrese una opcion valida!!",0,10);
            switch(option)
            {

                case 1:
                    system("cls");
                    controller_loadFromText("data.csv",listaEmpleados);
                    break;
                case 2:
                    system("cls");
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    break;
                case 3:
                    system("cls");
                    controller_addEmployee(listaEmpleados);
                    break;
                case 4:
                    if(ll_len(listaEmpleados)>0){
                    system("cls");
                    controller_editEmployee(listaEmpleados);
                    }else
                    {
                        printf("\n No hay empleados para editar");
                    }
                    break;
                case 5:
                    if(ll_len(listaEmpleados)>0){
                    system("cls");
                    controller_removeEmployee(listaEmpleados);
                    }else
                    {
                        printf("\No hay empleados que remover!");
                    }
                    break;
                case 6:
                    if(ll_len(listaEmpleados)>0){
                    system("cls");
                    controller_ListEmployee(listaEmpleados);
                    }else
                    {
                        printf("\nNo hay empleados que listar");
                    }
                    break;
                case 7:
                    system("cls");
                    controller_sortEmployee(listaEmpleados);
                    break;
                case 8:
                    system("cls");
                    controller_saveAsText("data.csv",listaEmpleados);
                    break;
                case 9:
                    system("cls");
                    controller_saveAsBinary("data.bin",listaEmpleados);
                    break;



        }
    }while(option != 10);

    return 0;
}
