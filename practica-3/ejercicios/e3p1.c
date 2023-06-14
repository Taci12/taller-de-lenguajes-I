#include <stdio.h>
#include <string.h>
#define DIM 3
typedef struct
{
  char calle[50];
  char ciudad[30];
  int codigoPostal;
  char pais[40];
} direccion;

typedef struct
{
  char apellido[50];
  char nombre[50];
  char legajo[8];
  float promedio;
  direccion domicilio;
} alumno;

int main()
{
  alumno vector[DIM];
  int i;
  char mayorNombre[50], mayorApellido[50];
  float mayorPromedio = 0;
  for (i = 0; i < DIM; i++)
  {
    leerAlumno(&vector[i]);
    if (vector[i].promedio > mayorPromedio)
    {
      mayorPromedio = vector[i].promedio
                          strcpy(mayorNombre, vector[i].nombre);
      strcpy(mayorApellido, vector[i].apellido);
    }
  }
  printf("El alumno con el mayor promedio es %s, %s", mayorApellido, mayorNombre);
}

void leerDomicilio(direccion *direc)
{
  printf("Ingrese calle:\n");
  scanf("%s", &direc->calle);
  printf("Ingrese ciudad:\n");
  scanf("%s", &direc->ciudad);
  printf("Ingrese codigo postal:\n");
  scanf("%d", &direc->codigoPostal);
  printf("Ingrese pais:\n");
  scanf("%s", &direc->pais);
}

void leerAlumno(alumno *alu)
{
  printf("Ingrese apellido:\n");
  scanf("%s", &alu->apellido);
  printf("Ingrese nombre:\n");
  scanf("%s", &alu->nombre);
  printf("Ingrese legajo:\n");
  scanf("%s", &alu->legajo);
  printf("Ingrese promedio:\n");
  scanf("%f", &alu->promedio);
  leerDomicilio(&alu->domicilio);
}
