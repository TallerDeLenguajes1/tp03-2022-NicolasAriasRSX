#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *TiposProductos[]= {"Galletas","Snack","Cigarrillos","Caramelos","bebidas"};

struct Productos{
    int ProductoID;            //Numeto en ciclos iterativos
    int Cantidad;              //entre 1 y 10
    char *TiposProducto;       //Algun valor del arreglo TipoProductos
    int PrecioUnitario;      // entre 10 y 100
};
typedef struct Productos producto;
struct Cliente{
    int ClienteID;             //Numeto en ciclos iterativos
    char *NombreCliente;       //ingreasdo por el usuario
    int CantidadProductosAPedir; //Aleatorio entre 1 y 5
    producto *Productos;         // EL tamaño de este arreglo depende de la variable CantidadProductosAPedir
};
typedef struct Cliente cliente;

//----------------Declaracion de funciones-------------------//

void cargar_cliente(int cantClientes, cliente *nuevoCliente);
void mostrar_cliente(int cantCLinetes, cliente *clientesCargados);
void mostrar_costo_por_cliente(int cantCliente,cliente *clientesCargados);
        //--------------MAIN-----------//
int main ()
{   
    srand(time(NULL));
    int cantCliente;
    printf("Bienvenido a la carga preventista.\nIngrese la cantidad de clientes.\n");
    scanf("%d", &cantCliente);
    
    cliente *vectorClientes;
    vectorClientes= (cliente*) malloc(sizeof(cliente) * cantCliente);

    cargar_cliente(cantCliente,vectorClientes);
    mostrar_cliente(cantCliente,vectorClientes);
    mostrar_costo_por_cliente(cantCliente,vectorClientes);

    getchar();

    return 0;
}
//_____________Funciones_____________//
void cargar_cliente(int cantClientes, cliente *nuevoCliente)
{
    char aux[50];
    for (int i = 0; i < cantClientes; i++)
    {
        printf("Ingrese el nombre del cliente:  ");
        //gets(aux);//preguntar por que no funcionaba bien.
        scanf("%s",aux);
        nuevoCliente[i].NombreCliente= (char *) malloc(sizeof(char) * strlen(aux));
        strcpy(nuevoCliente[i].NombreCliente, aux);
        fflush(stdin);
        nuevoCliente[i].ClienteID= i + 1;
        nuevoCliente[i].CantidadProductosAPedir= 1 + rand() % 5;
        nuevoCliente[i].Productos= (producto*) malloc(sizeof(producto) * nuevoCliente[i].CantidadProductosAPedir);
        for (int j = 0; j < nuevoCliente[i].CantidadProductosAPedir; j++)
        {
            nuevoCliente[i].Productos[j].ProductoID= j + 1;
            nuevoCliente[i].Productos[j].Cantidad= 1 + rand() % 10;
            nuevoCliente[i].Productos[j].PrecioUnitario= 10 + rand() % 91;
            nuevoCliente[i].Productos[j].TiposProducto= (char *) malloc(sizeof(char) * strlen(*(TiposProductos + rand() % 5)));
            strcpy(nuevoCliente[i].Productos[j].TiposProducto, *(TiposProductos + rand() % 5));
        }
    }   
}
void mostrar_cliente(int cantCLinetes, cliente *clientesCargados)
{
    for (int i = 0; i < cantCLinetes; i++)
    {
        printf("______________________________________________________\n");
        printf("Nombre del cliente: %s \n", clientesCargados[i].NombreCliente);
        printf("ID del cliente: %d\n", clientesCargados[i].ClienteID);
        printf("Cantidad de productos pedidos: %d\n", clientesCargados[i].CantidadProductosAPedir);
        printf("PRODUCTOS:\n");
        for (int j = 0; j < clientesCargados[i].CantidadProductosAPedir; j++)
        {
            printf("-------------------------------------------\n\n");
            printf("ID del producto: %d\n", clientesCargados[i].Productos[j].ProductoID);
            printf("Tipo de producto: %s\n", clientesCargados[i].Productos[j].TiposProducto);
            printf("Cantidad de productos: %d\n", clientesCargados[i].Productos[j].Cantidad);
            printf("Precio por unidad: %d\n", clientesCargados[i].Productos[j].PrecioUnitario);
        } 
    }
}
void mostrar_costo_por_cliente(int cantCliente, cliente *clientesCargados)
{
    int total;
    printf("\n\nTotal a pagar por cliente\n");
    for (int i = 0; i < cantCliente; i++)
    {
        total= 0;
        printf("--------------------------\nclinete: %s\n", clientesCargados[i].NombreCliente);
        for (int j = 0; j < clientesCargados[i].CantidadProductosAPedir; j++)
        {
            total= total + (clientesCargados[i].Productos[j].Cantidad * clientesCargados[i].Productos[j].PrecioUnitario);
        }
        printf("El cliente con ID numero %d, compro $%d\n", clientesCargados[i].ClienteID, total);
    }
}