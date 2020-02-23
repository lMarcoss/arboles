#include <stdio.h>

typedef struct nodo{
  int dato;
  struct nodo *izq;
  struct nodo *der;
}Nodo;

typedef Nodo *ArbolBinario;

void capturar();
void visitarpre(int x);
void visitaren(int x);
void visitarpos(int x);
void prof();
void Graphviz(FILE *salida, int visualizacion[20],int band, char comilla);

void NuevoArbol(ArbolBinario* raiz, ArbolBinario ramaIzq, int x, ArbolBinario ramaDer);
ArbolBinario CrearNodo(int x);
void Visitar(int x);
void PreOrden(ArbolBinario raiz);
void EnOrden(ArbolBinario raiz);
void PostOrden(ArbolBinario raiz);
int Profundidad(ArbolBinario raiz);
Nodo *Buscar(Nodo *raiz,int buscado);
void Insertar(Nodo** raiz, int dato);
void Eliminar(Nodo** r, int dato);
void Reemplazar(Nodo** act);
