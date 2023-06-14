#include <stdio.h>
#include <string.h>
typedef struct alu
{
  char nombre[30];
  char apellido[30];
  char legajo[10];
  int esDni;
  union
  {
    int dni;
    char pasaporte[12];
  } id;
} alumno;

void imprimirAlumno(alumno a);
void leerAlumno(alumno *a);
void strprint(char *string);

int main()
{
  alumno a;
  leerAlumno(&a);
  imprimirAlumno(a);
}

void strprint(char *string)
{
  while (*string != '\0')
  {
    printf("%c", *string);
    string++;
  }
  printf("\n");
}

void imprimirAlumno(alumno a)
{
  printf("Nombre:\n");
  printf("%s\n", a.nombre);
  printf("Apellido:\n");
  printf("%s\n", a.apellido);
  printf("Legajo:\n");
  printf("%s\n", a.legajo);
  if (a.esDni)
  {
    printf("DNI:\n");
    printf("%d\n", a.id.dni);
  }
  else
  {
    printf("Pasaporte:\n");
    printf("%s\n", a.id.pasaporte);
  }
}

void leerAlumno(alumno *a)
{
  printf("Nombre:\n");
  scanf("%s", &a->nombre);
  printf("Apellido:\n");
  scanf("%s", &a->apellido);
  printf("Legajo:\n");
  scanf("%s", &a->legajo);
  printf("Es DNI?\n");
  scanf("%d", &a->esDni);
  if (a->esDni)
  {
    printf("DNI:\n");
    scanf("%d", &a->id.dni);
  }
  else
  {
    printf("Pasaporte:\n");
    scanf("%s", &a->id.pasaporte);
  }
}