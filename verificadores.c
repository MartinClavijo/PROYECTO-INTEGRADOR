#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verificadores.h"

// Función para verificar si un identificador ya existe en el inventario
int verificarIdentificadorExistente(int id) {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return 0;
    }

    char linea[100];
    int productoId;

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        sscanf(linea, "%d", &productoId);
        if (productoId == id) {
            fclose(archivo);
            return 1; // El identificador ya existe
        }
    }

    fclose(archivo);
    return 0; // El identificador no existe
}

// Función para buscar un producto por su identificador
int buscarProductoPorId(int id) {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return -1;
    }

    char linea[100];
    int productoId;
    int indice = 0;

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        sscanf(linea, "%d", &productoId);
        if (productoId == id) {
            fclose(archivo);
            return indice; // Índice del producto encontrado
        }
        indice++;
    }

    fclose(archivo);
    return -1; // Producto no encontrado
}
