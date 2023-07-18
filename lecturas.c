#include <stdio.h>
#include "Lecturas.h"

int leerEnteroPositivo(char *mensaje){
    
    int valor;
    
    do{
        printf("\n%s ",mensaje);
        scanf("%d",&valor);

    }while(valor <= 0);
    return valor;

}

int leerEnteroMayor(char *mensaje, int numero) {
    
    int valor;
    
    printf("\n%s ", mensaje);
    scanf("%d", &valor);
    
    while (valor <= numero) {
        
        printf("El número ingresado no es mayor que %d", valor);
        scanf("%d", &valor);
    }
    
    return valor;
}

int leerEnteroEntre(char *mensaje, int menor, int mayor){
    
    int valor;
    
    do{
        printf("\n%s entre %d y %d :",mensaje,menor,mayor);
        scanf("%d",&valor);

    }while(valor < menor || valor > mayor);
    
    return valor;

}

float leerFlotantePositivo(char *mensaje){
    
    float valor;
    
    do{
        printf("\n%s ",mensaje);
        scanf("%f",&valor);

    }while(valor <= 0);
    return valor;

}

float leerFlotanteMayor(char *mensaje, float numero) {
    
    float valor;
    
    printf("\n%s ", mensaje);
    scanf("%f", &valor);
    
    while (valor <= numero) {
        
        printf("El número ingresado no es mayor que %.2f", valor);
        scanf("%f", &valor);
    }
    
    return valor;
}

float leerFlotanteEntre(char *mensaje, float menor, float mayor){
    
    float valor;
    
    do{
        printf("\n%s entre %.2f y %.2f :",mensaje,menor,mayor);
        scanf("%f",&valor);

    }while(valor < menor || valor > mayor);
    return valor;


}

double leerDoublePositivo(char *mensaje){
    
    double valor;
    
    do{
        printf("\n%s ",mensaje);
        scanf("%f",&valor);

    }while(valor <= 0);
    return valor;

}

double leerDoubleMayor(char *mensaje, double numero) {
    
    double valor;
    
    printf("\n%s ", mensaje);
    scanf("%f", &valor);
    
    while (valor <= numero) {
        
        printf("El número ingresado no es mayor que %.2f", valor);
        scanf("%f", &valor);
    }
    
    return valor;
}

double leerDoubleEntre(char *mensaje, double menor, double mayor){
    
    double valor;
    
    do{
        printf("\n%s entre %.2f y %.2f :",mensaje,menor,mayor);
        scanf("%f",&valor);

    }while(valor < menor || valor > mayor);
    return valor;


}