#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <stdio.h>
#include <string.h>
#include "SistemaProduccion.h"

static int validarNumeroProductos(int cantidad) {

    if(cantidad > MAX) {

        printf("Error: solo se permiten maximo 5 productos.\n");

        return 0;
    }

    if(cantidad <= 0) {

        printf("Error: debe ingresar al menos 1 producto.\n");

        return 0;
    }

    return 1;
}

static int validarNombre(char nombre[]) {

    if(strlen(nombre) >= 50) {

        printf("Error: el nombre no puede tener mas de 49 caracteres.\n");

        return 0;
    }

    return 1;
}

static int validarCantidad(int cantidad) {

    if(cantidad <= 0) {

        printf("Error: la cantidad debe ser mayor a 0.\n");

        return 0;
    }

    return 1;
}

static int validarDecimalPositivo(float numero) {

    if(numero < 0) {

        printf("Error: no se permiten numeros negativos.\n");

        return 0;
    }

    return 1;
}

static int inventarioVacio(int n) {

    if(n == 0) {

        printf("Error: no existen productos registrados.\n");

        return 1;
    }

    return 0;
}

static int productoRepetido(char nombres[MAX][50], int n, char nuevoNombre[]) {

    int i;

    for(i = 0; i < n; i++) {

        if(strcmp(nombres[i], nuevoNombre) == 0) {

            printf("Error: el producto ya existe.\n");

            return 1;
        }
    }

    return 0;
}

static int inventarioLleno(int n) {

    if(n >= MAX) {

        printf("Error: el inventario esta lleno.\n");

        return 1;
    }

    return 0;
}

#endif