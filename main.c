/*Programa de proyecto final, realizado por Martín Clavijo y Estefano Bernal*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"
#include "verificadores.h"
#include "menu.h"
#include "lecturas.h"

int main() {

    printf("\t\t\t********Bienvenido al inventario de Sarita********");

    int opcPrincipal;
    int opcModificar;

    do{
        menuPrincipal();

        scanf("%d", &opcPrincipal);

        switch (opcPrincipal) {
            
            case 1:{

                agregarProducto();

            } break;

            case 2:{

                borrarProducto();

            }break;
                
                
            case 3:{

                do{
                    menuModificar();
                    scanf("%d", &opcModificar);

                    switch(opcModificar){

                        case 1:{

                            modificarPrecio();

                        }break;

                        case 2:{

                            modificarCantidad();

                        }break;

                        case 3:{

                            printf("\n");
                            printf("Regresando al menu principal....");
                            printf("\n");

                        }break;

                        default:{

                        printf("Opción inválida. Intente nuevamente.\n");

                        }break;
                    }

                }while(opcModificar!=3);
            
            
            }break;
                
                
            case 4:{

                listarProductos();

            }break;
                
            case 5:{

                printf("\n");
                printf("TODOS LOS DATOS FUERON GUARDADOS CORRECTAMETNE\n");

            }break;
                
            default:{

                printf("Opción inválida. Intente nuevamente.\n");

            }break;
                
        }
    }while(opcPrincipal!=5);
}