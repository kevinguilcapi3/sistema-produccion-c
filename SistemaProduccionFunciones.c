#include <stdio.h>
#include <string.h>
#include "SistemaProduccion.h"

void ingresarProductos(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int *n) {

    int i;

    if(inventarioLleno(*n)) {
        return;
    }

    printf("\nCuantos productos desea ingresar? Maximo 5: ");
    scanf("%d", n);

    if(!validarNumeroProductos(*n)) {
        return;
    }

    for(i = 0; i < *n; i++) {

        printf("\nProducto %d\n", i + 1);

        printf("Nombre: ");
        scanf("%49s", nombres[i]);

        if(!validarNombre(nombres[i])) {
            return;
        }

        if(productoRepetido(nombres, i, nombres[i])) {
            return;
        }

        printf("Cantidad demandada: ");
        scanf("%d", &cantidades[i]);

        if(!validarCantidad(cantidades[i])) {
            return;
        }

        printf("Tiempo por unidad: ");
        scanf("%f", &tiempos[i]);

        if(!validarDecimalPositivo(tiempos[i])) {
            return;
        }

        printf("Recursos por unidad: ");
        scanf("%f", &recursos[i]);

        if(!validarDecimalPositivo(recursos[i])) {
            return;
        }
    }

    printf("Productos registrados correctamente.\n");
}

int buscarProducto(char nombres[MAX][50], int n, char nombreBuscar[]) {

    int i;

    for(i = 0; i < n; i++) {

        if(strcmp(nombres[i], nombreBuscar) == 0) {

            return i;
        }
    }

    return -1;
}

void editarProducto(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int n) {

    char nombreBuscar[50];

    int posicion;

    printf("\nIngrese el nombre del producto a editar: ");
    scanf("%49s", nombreBuscar);

    posicion = buscarProducto(nombres, n, nombreBuscar);

    if(posicion == -1) {

        printf("Producto no encontrado.\n");

    } else {

        printf("Nuevo nombre: ");
        scanf("%49s", nombres[posicion]);

        if(!validarNombre(nombres[posicion])) {
            return;
        }

        printf("Nueva cantidad: ");
        scanf("%d", &cantidades[posicion]);

        if(!validarCantidad(cantidades[posicion])) {
            return;
        }

        printf("Nuevo tiempo por unidad: ");
        scanf("%f", &tiempos[posicion]);

        if(!validarDecimalPositivo(tiempos[posicion])) {
            return;
        }

        printf("Nuevo recurso por unidad: ");
        scanf("%f", &recursos[posicion]);

        if(!validarDecimalPositivo(recursos[posicion])) {
            return;
        }

        printf("Producto editado correctamente.\n");
    }
}

void eliminarProducto(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int *n) {

    char nombreBuscar[50];

    char confirmar;

    int posicion;

    int i;

    printf("\nIngrese el nombre del producto a eliminar: ");
    scanf("%49s", nombreBuscar);

    posicion = buscarProducto(nombres, *n, nombreBuscar);

    if(posicion == -1) {

        printf("Producto no encontrado.\n");

    } else {

        printf("Seguro que desea eliminar el producto? (s/n): ");
        scanf(" %c", &confirmar);

        if(confirmar == 's' || confirmar == 'S') {

            for(i = posicion; i < *n - 1; i++) {

                strcpy(nombres[i], nombres[i + 1]);

                cantidades[i] = cantidades[i + 1];

                tiempos[i] = tiempos[i + 1];

                recursos[i] = recursos[i + 1];
            }

            (*n)--;

            printf("Producto eliminado correctamente.\n");

        } else {

            printf("Eliminacion cancelada.\n");
        }
    }
}

void calcularProduccion(int cantidades[], float tiempos[], float recursos[], int n) {

    int i;

    float tiempoTotal = 0;

    float recursosTotal = 0;

    float tiempoDisponible;

    float recursosDisponible;

    for(i = 0; i < n; i++) {

        tiempoTotal = tiempoTotal + cantidades[i] * tiempos[i];

        recursosTotal = recursosTotal + cantidades[i] * recursos[i];
    }

    printf("\nTiempo total requerido: %.2f\n", tiempoTotal);

    printf("Recursos totales requeridos: %.2f\n", recursosTotal);

    printf("Ingrese tiempo disponible: ");
    scanf("%f", &tiempoDisponible);

    if(!validarDecimalPositivo(tiempoDisponible)) {
        return;
    }

    printf("Ingrese recursos disponibles: ");
    scanf("%f", &recursosDisponible);

    if(!validarDecimalPositivo(recursosDisponible)) {
        return;
    }

    if(tiempoTotal <= tiempoDisponible && recursosTotal <= recursosDisponible) {

        printf("La fabrica SI puede cumplir con la demanda.\n");

    } else {

        printf("La fabrica NO puede cumplir con la demanda.\n");
    }
}