#include <stdlib.h>
#include "Employee.h"
#include <string.h>

Employee* employee_new()
{
    Employee* this;
    this = (Employee*) malloc(sizeof(Employee));
    return this;
}
Employee* employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr,int sueldoStr)
{
    Employee* punteroEmployee = employee_new();
    if(punteroEmployee != NULL)
    {
        employee_setId(punteroEmployee,idStr);
        employee_setHorasTrabajadas(punteroEmployee,horasTrabajadasStr);
        employee_setNombre(punteroEmployee, nombreStr);
        employee_setSueldo(punteroEmployee,sueldoStr);
    }
    return punteroEmployee;
}
void employee_delete(Employee* this)
{
    	if(this != NULL)
	{
		free(this);
	}
}
//// ID
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    if(this!= NULL && id > 0)
    {
        this->id = id;
        retorno = 1;
    }
    return retorno;
}
int employee_getId(Employee* this,int* id)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *id = this->id;
        retorno = 1;
    }
    return 1;
}
//////// NOMBRE
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        retorno = 1;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if(this!=NULL && nombre!= NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 1;
    }
}
////////HORAS TRABAJADAS
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if(this!= NULL && horasTrabajadas > 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 1;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 1;
    }
    return 1;
}
////////// SUELDO
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if(this!= NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        retorno = 1;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;

    if(this!=NULL)
    {
        *sueldo = this->sueldo;
        retorno = 1;
    }
    return 1;
}


//
int employee_sortByName(void* empA, void* empB){
	int retorno=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;
	char nombre1[20];
	char nombre2[20];


	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;
		employee_getNombre(emp1,nombre1);
		employee_getNombre(emp2,nombre2);
		if(stricmp(nombre1,nombre2)==1)
		{
			retorno=1;
		}

		else if(stricmp(nombre1,nombre2)==-1){
			retorno=0;
		}

	}
	return retorno;
}

int employee_sortBySalary(void* empA, void* empB){
	int retorno=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;
    int sueldo1;
    int sueldo2;

	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;

		employee_getSueldo(emp1,&sueldo1);
		employee_getSueldo(emp2,&sueldo2);
		if(sueldo1 > sueldo2)
		{
			retorno=1;
		}

		else if(sueldo1 < sueldo2){
			retorno=0;
		}

	}
	return retorno;
}

int employee_sortByHours(void* empA, void* empB){
	int retorno=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;
    int horas1,horas2;
	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;

		employee_getHorasTrabajadas(emp1,&horas1);
		employee_getHorasTrabajadas(emp2,&horas2);
		if(horas1 > horas2)
		{
			retorno=1;
		}

		else if(horas1 < horas2){
			retorno=0;
		}

	}
	return retorno;
}

int employee_sortById(void* empA, void* empB){
	int retorno=-1;
	Employee* emp1=NULL;
	Employee* emp2=NULL;
    int id1;
    int id2;

	if(empA!=NULL && empB!=NULL){
		emp1=(Employee*)empA;
		emp2=(Employee*)empB;

		employee_getId(emp1,&id1);
		employee_getId(emp2,&id2);
		if(id1 > id2)
		{
			retorno=1;
		}

		else if(id1 < id2){
			retorno=0;
		}

	}
	return retorno;
}

void sortMenu(){

	printf("1-Ordenar por Nombre\n2-Ordenar por Horas trabajadas\n3-Ordenar por sueldo\n4-Ordenar Por Id\n5-Salir\n");

}



