#include <stdio.h>
#include "SistemaProduccion.h"
#include "Validaciones.h"

int main() {

    char nombres[MAX][50];
    int cantidades[MAX];
    float tiempos[MAX];
    float recursos[MAX];

    int n = 0;
    int opcion;

    do {

        printf("\n--- MENU PRODUCCION ---\n");
        printf("1. Ingresar productos\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular produccion\n");
        printf("5. Salir\n");

        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {

            case 1:
                ingresarProductos(nombres, cantidades, tiempos, recursos, &n);
                break;

            case 2:
                if(inventarioVacio(n)) {
                    break;
                }

                editarProducto(nombres, cantidades, tiempos, recursos, n);
                break;

            case 3:
                if(inventarioVacio(n)) {
                    break;
                }

                eliminarProducto(nombres, cantidades, tiempos, recursos, &n);
                break;

            case 4:
                if(inventarioVacio(n)) {
                    break;
                }

                calcularProduccion(cantidades, tiempos, recursos, n);
                break;

            case 5:
                printf("Programa finalizado.\n");
                break;

            default:
                printf("Opcion incorrecta.\n");
        }

    } while(opcion != 5);

    return 0;
}