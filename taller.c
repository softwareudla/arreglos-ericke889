#include <stdio.h> 
#include <string.h>

int main(int argc, char *argv[]) {
    char id_estudiante[5][10], aux[10];
    char nombre_estudiante[5][30];
    float calificaciones[5][3];
    char asignaturas[3][20] = {"Matematica", "Lengua", "Ingles"};
    int opc1, cont = 0, len = 0, i, j;

    do {
        printf("\n1. Registrar estudiante\n");
        printf("2. Ver calificaciones\n");
        printf("3. Ver promedio por estudiante\n");
        printf("4. Ver promedio por asignatura\n");
        printf("5. Ver nota mayor y menor por asignatura\n");
        printf("6. Ver cantidad de aprobados por asignatura\n");
        printf("7. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opc1);
        fflush(stdin);

        switch (opc1) {
        case 1:
            if (cont >= 5) {
                printf("No se pueden registrar más estudiantes.\n");
                break;
            }
            printf("Ingrese el ID del estudiante %d: \n", cont + 1);
            scanf("%s", id_estudiante[cont]);
            fflush(stdin);
            printf("Ingrese el nombre del estudiante %d: \n", cont + 1);
            fgets(nombre_estudiante[cont], 30, stdin);
            len = strlen(nombre_estudiante[cont]) - 1;
            nombre_estudiante[cont][len] = '\0';

            for (j = 0; j < 3; j++) {
                int val;
                do {
                    printf("Ingrese la calificacion en %s: \n", asignaturas[j]);
                    val = scanf("%f", &calificaciones[cont][j]);
                    fflush(stdin);
                    if (val != 1) {
                        printf("Error: ingrese un número válido.\n");
                    } else if (calificaciones[cont][j] < 0 || calificaciones[cont][j] > 10) {
                        printf("Error: la nota debe estar entre 0 y 10.\n");
                        val = 0; 
                    }
                } while (val != 1);
            }

            cont++;
            break;

        case 2:
            printf("ID\t\tNombre\t\tMatematica\tLengua\t\tIngles\n");
            for (i = 0; i < cont; i++) {
                printf("%s\t\t%s\t\t%.2f\t\t%.2f\t\t%.2f\n", id_estudiante[i], nombre_estudiante[i],
                       calificaciones[i][0], calificaciones[i][1], calificaciones[i][2]);
            }
            break;

        case 3:
            for (i = 0; i < cont; i++) {
                float suma = 0;
                for (j = 0; j < 3; j++) {
                    suma += calificaciones[i][j];
                }
                printf("Promedio de %s: %.2f\n", nombre_estudiante[i], suma / 3);
            }
            break;

        case 4:
            for (j = 0; j < 3; j++) {
                float suma = 0;
                for (i = 0; i < cont; i++) {
                    suma += calificaciones[i][j];
                }
                printf("Promedio en %s: %.2f\n", asignaturas[j], suma / cont);
            }
            break;

        case 5:
            for (j = 0; j < 3; j++) {
                float max = calificaciones[0][j];
                float min = calificaciones[0][j];
                for (i = 1; i < cont; i++) {
                    if (calificaciones[i][j] > max)
                        max = calificaciones[i][j];
                    if (calificaciones[i][j] < min)
                        min = calificaciones[i][j];
                }
                printf("En %s - Nota mayor: %.2f, Nota menor: %.2f\n", asignaturas[j], max, min);
            }
            break;

        case 6:
            for (j = 0; j < 3; j++) {
                int aprobados = 0;
                for (i = 0; i < cont; i++) {
                    if (calificaciones[i][j] >= 7.0) {
                        aprobados++;
                    }
                }
                printf("Estudiantes aprobados en %s: %d\n", asignaturas[j], aprobados);
            }
            break;

        case 7:
            printf("Saliendo \n");
            break;

        default:
            printf("ERROR.\n");
            break;
        }

    } while (opc1 != 7);

    return 0;
}
