#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
} compu;

void listarPCs(compu pcs[], int cantidad);
void mostrarMasVieja(compu pcs[], int cantidad);
void mostrarMasVeloz(compu pcs[], int cantidad);

int main()
{

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
                         "Pentium"};
    compu pc[5];
    srand(time(NULL));
    for (int i = 0; i < 5; i++) // genero numeros aleatorios siguiendo los limites del enunciado
    {
        pc[i].velocidad = 1 + rand() % 3;
        pc[i].anio = 2015 + rand() % 10;
        pc[i].cantidad_nucleos = 1 + rand() % 8;
        pc[i].tipo_cpu = tipos[rand() % 6];
    }

    listarPCs(pc, 5);
    mostrarMasVieja(pc, 5);
    mostrarMasVeloz(pc,5);

    return 0;
}

void listarPCs(compu pcs[], int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        printf("Pc n %d:\n", i + 1);
        printf("\t Velocidad: %d Ghz\n", pcs[i].velocidad);
        printf("\t Anio: %d\n", pcs[i].anio);
        printf("\t Cantidad de nucleos: %d\n", pcs[i].cantidad_nucleos);
        printf("\t Tipo de cpu: %s\n", pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(compu pcs[], int cantidad)
{
    int i, aux = 0;
    for (i = 1; i < cantidad; i++)
    {
        if (pcs[i].anio < pcs[aux].anio)
        {
            aux = i;
        }
    }
    printf("La pc mas vieja es: %d\n", aux + 1);
    listarPCs(&pcs[aux], 1);
}

void mostrarMasVeloz(compu pcs[], int cantidad)
{
    int i, aux = 0;
    for (i = 0; i < cantidad; i++)
    {
        if (pcs[i].velocidad > pcs[aux].velocidad)
        {
            aux = i;
        }
    }
    printf("La pc mas veloz es: %d\n", aux + 1);
    listarPCs(&pcs[aux], 1);
}