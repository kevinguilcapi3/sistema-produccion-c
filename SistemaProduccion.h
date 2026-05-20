#ifndef SISTEMAPRODUCCION_H
#define SISTEMAPRODUCCION_H

#define MAX 5

void ingresarProductos(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int *n);

int buscarProducto(char nombres[MAX][50], int n, char nombreBuscar[]);

void editarProducto(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int n);

void eliminarProducto(char nombres[MAX][50], int cantidades[], float tiempos[], float recursos[], int *n);

void calcularProduccion(int cantidades[], float tiempos[], float recursos[], int n);

#include "Validaciones.h"

#endif