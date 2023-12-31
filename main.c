/*Programa de proyecto final, realizado por Martín Clavijo y Estefano Bernal*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operaciones.h"
#include "verificadores.h"
#include "menu.h"
#include "lecturas.h"

int main() {

    printf("\n");
    printf("\t\t\t******** Bienvenido al inventario de Sarita ********");
    printf("\n");

    int opcPrincipal;
    int opcModificar;

    do{
        menuPrincipal();

        opcPrincipal=leerEnteroPositivo("Ingrese la opción a realizar: ");

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
                    opcModificar=leerEnteroPositivo("Ingrese la opción a realizar: ");

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

                            printf("\n");
                            printf("Opción inválida. Intente nuevamente.\n");
                            printf("\n");

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

                printf("\n");
                printf("Opción inválida. Intente nuevamente.\n");
                printf("\n");

            }break;
                
        }
    }while(opcPrincipal!=5);
}