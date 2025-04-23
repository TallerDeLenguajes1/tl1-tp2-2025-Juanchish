#include <stdio.h>
#include <time.h>

int main()
{
    typedef struct compu
    {
        int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
        int anio;             // Año de fabricación (valor entre 2015 y 2024)
        int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
        char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
    } compu;

    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core",
                         "Pentium"};
    srand(time(NULL));
    compu pc[5];
    for (int i = 0; i < 5; i++) // genero numeros aleatorios siguiendo los limites del enunciado
    {
        pc[i].velocidad = 1 + rand() % 3;
        pc[i].anio = 2015 + rand() % 2024;
        pc[i].cantidad_nucleos = 1 + rand() % 8;
        pc[i].tipo_cpu = tipos[rand() % 6];
    }
    

    

    return 0;
}
