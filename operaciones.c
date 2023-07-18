#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "verificadores.h"

#define MAX_PRODUCTOS 100
#define MAX_LONGITUD_NOMBRE 50
int numProductos = 0; 

// Función para agregar un producto al inventario
void agregarProducto() {
    if (numProductos == MAX_PRODUCTOS) {
        printf("Error: No se pueden agregar más productos.\n");
        return;
    }

    int id, cantidad;
    float precio;
    char nombre[MAX_LONGITUD_NOMBRE];

    printf("Ingrese el identificador del producto: ");
    scanf("%d", &id);

    // Verificar si el identificador ya existe
    if (verificarIdentificadorExistente(id)) {
        printf("Error: El identificador ya existe.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf(" %[^\n]", nombre);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);
    printf("Ingrese la cantidad del producto: ");
    scanf("%d", &cantidad);

    FILE *archivo = fopen("inventario.txt", "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    fprintf(archivo, "%d,%s,%.2f,%d\n", id, nombre, precio, cantidad);
    fclose(archivo);

    printf("Producto agregado correctamente.\n");
}

// Función para borrar un producto del inventario
void borrarProducto() {
    int id;

    printf("Ingrese el identificador del producto a borrar: ");
    scanf("%d", &id);

    int indice = buscarProductoPorId(id);
    if (indice == -1) {
        printf("Error: El identificador no existe.\n");
        return;
    }

    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    FILE *archivoTemporal = fopen("inventario_temp.txt", "w");
    if (archivoTemporal == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        fclose(archivo);
        return;
    }

    char linea[100];
    int productoId;

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        sscanf(linea, "%d", &productoId);
        if (productoId != id) {
            fprintf(archivoTemporal, "%s", linea);
        }
    }

    fclose(archivo);
    fclose(archivoTemporal);

    remove("inventario.txt");
    rename("inventario_temp.txt", "inventario.txt");

    printf("Producto borrado correctamente.\n");
}
// Función para modificar el precio de un producto en el inventario
void modificarPrecio() {
    int id;
    float nuevoPrecio;

    printf("Ingrese el identificador del producto a modificar: ");
    scanf("%d", &id);

    int indice = buscarProductoPorId(id);
    if (indice == -1) {
        printf("Error: El identificador no existe.\n");
        return;
    }

    printf("Ingrese el nuevo precio del producto: ");
    scanf("%f", &nuevoPrecio);

    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    FILE *archivoTemporal = fopen("inventario_temp.txt", "w");
    if (archivoTemporal == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        fclose(archivo);
        return;
    }

    char linea[100];
    int productoId;
    char nombre[MAX_LONGITUD_NOMBRE];
    float precio;
    int cantidad;

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        sscanf(linea, "%d,%[^,],%f,%d", &productoId, nombre, &precio, &cantidad);
        if (productoId == id) {
            fprintf(archivoTemporal, "%d,%s,%.2f,%d\n", id, nombre, nuevoPrecio, cantidad);
        } else {
            fprintf(archivoTemporal, "%s", linea);
        }
    }

    fclose(archivo);
    fclose(archivoTemporal);

    remove("inventario.txt");
    rename("inventario_temp.txt", "inventario.txt");

    printf("Precio modificado correctamente.\n");
}

// Función para modificar la cantidad de un producto en el inventario
void modificarCantidad() {
    int id;
    int nuevaCantidad;

    printf("Ingrese el identificador del producto a modificar: ");
    scanf("%d", &id);

    int indice = buscarProductoPorId(id);
    if (indice == -1) {
        printf("Error: El identificador no existe.\n");
        return;
    }

    printf("Ingrese la nueva cantidad del producto: ");
    scanf("%d", &nuevaCantidad);

    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    FILE *archivoTemporal = fopen("inventario_temp.txt", "w");
    if (archivoTemporal == NULL) {
        printf("Error al abrir el archivo temporal.\n");
        fclose(archivo);
        return;
    }

    char linea[100];
    int productoId;
    char nombre[MAX_LONGITUD_NOMBRE];
    float precio;
    int cantidad;

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        sscanf(linea, "%d,%[^,],%f,%d", &productoId, nombre, &precio, &cantidad);
        if (productoId == id) {
            fprintf(archivoTemporal, "%d,%s,%.2f,%d\n", id, nombre, precio, nuevaCantidad);
        } else {
            fprintf(archivoTemporal, "%s", linea);
        }
    }

    fclose(archivo);
    fclose(archivoTemporal);

    remove("inventario.txt");
    rename("inventario_temp.txt", "inventario.txt");

    printf("Cantidad modificada correctamente.\n");
}

// Función para listar todos los productos del inventario
void listarProductos() {
    FILE *archivo = fopen("inventario.txt", "r");
    if (archivo == NULL) {
        printf("No se encontró un archivo de inventario existente.\n");
        return;
    }

    char linea[100];
    int productoId;
    char nombre[MAX_LONGITUD_NOMBRE];
    float precio;
    int cantidad;

    printf("\n--- LISTA DE PRODUCTOS ---\n");

    while (fgets(linea, sizeof(linea), archivo) != NULL) {
        sscanf(linea, "%d,%[^,],%f,%d", &productoId, nombre, &precio, &cantidad);
        printf("Identificador: %d\n", productoId);
        printf("Nombre: %s\n", nombre);
        printf("Precio: %.2f\n", precio);
        printf("Cantidad: %d\n", cantidad);
        printf("-------------------------\n");
    }

    fclose(archivo);
}