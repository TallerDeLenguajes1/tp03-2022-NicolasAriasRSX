#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#define TAM 5

int main()
{
    int TAM;
    printf("Ingrese la cantidad de nombres a ingresar (en numeros)");
    scanf("%d", &TAM);
    char *v[TAM];
    char *aux;
    aux= (char *)malloc(50 * sizeof(char));//Reserva de memoria para una variable auxiliar
    //Uso for para cargar cada uno de los elementos del vector.
    printf("Carga de nombres en el vector.\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d) ingrese un nombre -> ", i+1);
        //gets(aux);
        scanf("%s",aux);
        v[i]= (char *) malloc(strlen(aux) * 1 * sizeof(char));
        strcpy(v[i], aux);
    }
    printf("Mostrando por pantalla los elementos del vector.\n");
    for (int i = 0; i < TAM; i++)
    {
        puts(v[i]);
        printf("\n");
    }
    //Limpiar la memoria ocupada.
    for (int i = 0; i < TAM; i++)
    {
        free(v[i]);
    }
    free(aux);
    
    //getchar();
    scanf(" %d");
}