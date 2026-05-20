#include <stdio.h>
#include <string.h>
#include "SistemaProduccion.h"
#include "Validaciones.h"

int leerEntero(char mensaje[]) {
    int numero;
    int resultado;

    do {
        printf("%s", mensaje);
        resultado = scanf("%d", &numero);

        if(resultado != 1) {
            printf("Error: solo se permiten numeros enteros.\n");
            while(getchar() != '\n');
        } else {
            while(getchar() != '\n');
            return numero;
        }

    } while(1);
}

float leerFloat(char mensaje[]) {
    float numero;
    int resultado;

    do {
        printf("%s", mensaje);
        resultado = scanf("%f", &numero);

        if(resultado != 1) {
            printf("Error: solo se permiten numeros.\n");
            while(getchar() != '\n');
        } else {
            while(getchar() != '\n');
            return numero;
        }

    } while(1);
}

void leerNombre(char mensaje[], char nombre[]) {
    do {
        printf("%s", mensaje);
        scanf("%49s", nombre);
        while(getchar() != '\n');

    } while(!validarNombreSoloLetras(nombre));
}

void ingresarProductos(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int *n) {

    int i;
    int cantidadProductos;

    do {
        cantidadProductos = leerEntero("\nCuantos productos desea ingresar? Maximo 5: ");
    } while(!validarCantidadProductos(cantidadProductos));

    *n = cantidadProductos;

    for(i = 0; i < *n; i++) {

        printf("\nProducto %d\n", i + 1);

        leerNombre("Nombre: ", nombres[i]);

        do {
            cantidades[i] = leerEntero("Cantidad demandada: ");
        } while(!validarEnteroPositivo(cantidades[i]));

        do {
            tiempos[i] = leerFloat("Tiempo por unidad: ");
        } while(!validarDecimalPositivo(tiempos[i]));

        do {
            recursos[i] = leerFloat("Recursos por unidad: ");
        } while(!validarDecimalPositivo(recursos[i]));
    }
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

    leerNombre("\nIngrese el nombre del producto a editar: ", nombreBuscar);

    posicion = buscarProducto(nombres, n, nombreBuscar);

    if(posicion == -1) {
        printf("Producto no encontrado.\n");
    } else {

        leerNombre("Nuevo nombre: ", nombres[posicion]);

        do {
            cantidades[posicion] = leerEntero("Nueva cantidad: ");
        } while(!validarEnteroPositivo(cantidades[posicion]));

        do {
            tiempos[posicion] = leerFloat("Nuevo tiempo por unidad: ");
        } while(!validarDecimalPositivo(tiempos[posicion]));

        do {
            recursos[posicion] = leerFloat("Nuevo recurso por unidad: ");
        } while(!validarDecimalPositivo(recursos[posicion]));

        printf("Producto editado correctamente.\n");
    }
}

void eliminarProducto(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int *n) {

    char nombreBuscar[50];
    int posicion;
    int i;

    leerNombre("\nIngrese el nombre del producto a eliminar: ", nombreBuscar);

    posicion = buscarProducto(nombres, *n, nombreBuscar);

    if(posicion == -1) {
        printf("Producto no encontrado.\n");
    } else {

        for(i = posicion; i < *n - 1; i++) {
            strcpy(nombres[i], nombres[i + 1]);
            cantidades[i] = cantidades[i + 1];
            tiempos[i] = tiempos[i + 1];
            recursos[i] = recursos[i + 1];
        }

        (*n)--;

        printf("Producto eliminado correctamente.\n");
    }
}

void calcularProduccion(int cantidades[], float tiempos[], float recursos[], int n) {

    int i;
    float tiempoTotal = 0;
    float recursosTotal = 0;
    float tiempoDisponible;
    float recursosDisponible;

    if(n == 0) {
        printf("Primero debe ingresar productos.\n");
        return;
    }

    for(i = 0; i < n; i++) {
        tiempoTotal = tiempoTotal + cantidades[i] * tiempos[i];
        recursosTotal = recursosTotal + cantidades[i] * recursos[i];
    }

    printf("\nTiempo total requerido: %.2f\n", tiempoTotal);
    printf("Recursos totales requeridos: %.2f\n", recursosTotal);

    do {
        tiempoDisponible = leerFloat("Ingrese tiempo disponible: ");
    } while(!validarDecimalPositivo(tiempoDisponible));

    do {
        recursosDisponible = leerFloat("Ingrese recursos disponibles: ");
    } while(!validarDecimalPositivo(recursosDisponible));

    if(tiempoTotal <= tiempoDisponible && recursosTotal <= recursosDisponible) {
        printf("La fabrica SI puede cumplir con la demanda.\n");
    } else {
        printf("La fabrica NO puede cumplir con la demanda.\n");
    }
}
