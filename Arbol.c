#include <stdio.h>
#include <stdlib.h>
#include "Arbol.h"
#define TAM 80
ArbolBinario Arbol;
char comilla = '"';

void NuevoArbol(ArbolBinario *raiz, ArbolBinario ramaIzq, int x, ArbolBinario ramaDer)
{
   *raiz = CrearNodo(x);
   (*raiz)->izq = ramaIzq;
   (*raiz)->der = ramaDer;
}

ArbolBinario CrearNodo(int x)
{
   ArbolBinario a;
   a = (ArbolBinario)malloc(sizeof(Nodo));
   a->dato = x;
   a->izq = a->der = NULL;

   return a;
}

void Visitar(int x)
{
   printf("%i ",x);
}
//Funcion para crear un archivo donde contiene la profundidad del árbol binario
void prof(ArbolBinario raiz)
{
  FILE *pro;
  pro=fopen("Prof.txt","a");
  int x;
  x=Profundidad(raiz);
  fprintf(pro, "%i ", x);
  fclose(pro);
}
//función que le manda el recorrido PreOrden  al archivo Pre.txt
void visitarpre(int x)
{
  FILE *pre;
  pre=fopen("Pre.txt","a");
  fprintf(pre, "%i ", x);
  fclose(pre);
}
//función que le manda el recorrido EnOrden  al archivo En.txt
void visitaren(int x)
{
  FILE *en;
  en=fopen("En.txt","a");
  fprintf(en, "%i ", x);
  fclose(en);
}
//función que le manda el recorrido PostOrden  al archivo Post.txt
void visitarpos(int x)
{
  FILE *pos;
  pos=fopen("Post.txt","a");
  fprintf(pos, "%i ", x);
  fclose(pos);
}

void PreOrden(ArbolBinario raiz)
{
  if(raiz){
    Visitar(raiz->dato);
    visitarpre(raiz->dato);
    PreOrden(raiz->izq);
    PreOrden(raiz->der);
  }
}

void EnOrden(ArbolBinario raiz)
{
  if(raiz){
    EnOrden(raiz->izq);
    Visitar(raiz->dato);
    visitaren(raiz->dato);
    EnOrden(raiz->der);
  }
}

void PostOrden(ArbolBinario raiz)
{
  if(raiz){
    PostOrden(raiz->izq);
    PostOrden(raiz->der);
    Visitar(raiz->dato);
    visitarpos(raiz->dato);
  }
}

int Profundidad(ArbolBinario raiz)
{
  if(!raiz)
       return 0;

  else{
    int ProfundidadI = Profundidad(raiz->izq);
    int ProfundidadD = Profundidad(raiz->der);
    if(ProfundidadI > ProfundidadD)
        return ProfundidadI + 1;
    else
        return ProfundidadD + 1;
  }
}

Nodo *Buscar(Nodo *raiz, int buscado)
{
  if(!raiz)
      return 0;

  else if(buscado == raiz->dato)
      return raiz;
  else if(buscado < raiz->dato)
      return Buscar(raiz->izq, buscado);
  else
       return Buscar(raiz->der, buscado);
}

void Insertar(Nodo** raiz, int dato)
{
  if(!(*raiz))
       *raiz = CrearNodo(dato);
  else if(dato < (*raiz)->dato)
       Insertar(&((*raiz)->izq),dato);
  else
       Insertar(&((*raiz)->der),dato);
}

void Eliminar(Nodo** r, int dato)
{
  if(!(*r))
       puts("Nodo no encontrado");
  else if(dato < (*r)->dato)
       Eliminar(&(*r)->izq,dato);
  else if(dato > (*r)->dato)
       Eliminar(&(*r)->der,dato);
  else{  /*Nodo encontrado*/
    Nodo* q; /*Puntero al nodo a suprimir*/
    q = (*r); /*r es el ptr del nodo padre*/
    if(q->izq == NULL)
          (*r) = q->der;
    else if(q->der == NULL)
           (*r) = q->izq;
    else /*Tiene rama izquierda y derecha*/
          Reemplazar(&q);
     free(q);
  }
}

void Reemplazar(Nodo** act)
{
  Nodo* a,*p;

  p = *act;
  a = (*act)->izq; /*Menores a izquierda*/

  while(a->der){
    p = a; /*Buscamos el mayor a derecha*/
    a = a->der;
  }
  ;/*Cambio de campo de datos*/
  (*act)->dato = a->dato;
  /*Al abuelo p se hace cargo  de nieto IZQ*/
  if(p == (*act))
      p->izq = a->izq;
  else
      p->der = a->izq;
  (*act) = a;
}


void capturar()
{
	int band = 0;
  int bandera=0,q;
	char coma;
  ArbolBinario raiz;
	int nodo;
	FILE *entrada;
	FILE *salida;
	int visualizacion[TAM];


	entrada = fopen("Nodos.txt", "r");
	salida = fopen("Arbol.dot", "w");
	fprintf(salida,"%s %s{\n", "digraph", "ArbolBinario" );
  //se capturan los datos del archivo y se guardan en un vector llamado visualizacion
	while(feof(entrada) != 1)
	{
    bandera=0;
		fscanf(entrada, "%d %c", &nodo, &coma);
    //revisamos que no se repitan los numeros
    for(q=0;q<band;q++)
    {
      if(nodo==visualizacion[q])
      bandera=1;
    }
    if(bandera==1)
    {
      printf("se repite %d\n",nodo);
    }else
    {
      visualizacion[band]= nodo;
      band += 1;
    }
}
//Se manda a llamar a la función  Graphviz para mandar los datos al archivo Arbol.dot
	Graphviz(salida, visualizacion, band, comilla);

  //Se  introduce el primer dato para generar la raiz del árbol
	NuevoArbol(&raiz, NULL, visualizacion[0], NULL);
		for(int l=1;l<band;l++)
		{
			Insertar(&raiz, visualizacion[l]);
		}
	printf("PreOrden: ");
	PreOrden(raiz);
	printf("\n");
	printf("EnOrden: ");
	EnOrden(raiz);
	printf("\n");
	printf("PostOrden: ");
	PostOrden(raiz);
	printf("\n");
	printf("Profundidad: %d\n", Profundidad(raiz));
  prof(raiz);

	fprintf(salida, "\n%c", '}');
	fclose(entrada);
	fclose(salida);
	system("dot -Tpng Arbol.dot > Arbol.png");
	//return 0;
}

void Graphviz(FILE *salida, int visualizacion[20], int band, char comilla)
{
	int i, j;
  int der[TAM]={0};
	int izq[TAM]={0};
	int izqder[TAM]={-1};
	for(i = 0; i < band; i++)
	{
		if(i == 0)
		{
			fprintf(salida, "node [shape = record,height=.1];\n");
			fprintf(salida, "nodo%d[label = %c<f0> |<f1> %d| <f2> %c];\n", i, comilla, visualizacion[i], comilla);
		}else
		{
			fprintf(salida, "nodo%d[label = %c<f0> |<f1> %d| <f2> %c];\n", i, comilla, visualizacion[i], comilla);
		}
	}
//Separamos los números que son mayores o menores de la raiz con solo la posición de cada uno
for (int k = 1; k < band; k++)
 {
	if(visualizacion[k]<visualizacion[0])
	izqder[k]=0;
	else
	izqder[k]=1;
}

NuevoArbol(&Arbol, NULL, visualizacion[0], NULL );
for(i = 1; i < band; i++)
{
    Insertar(&Arbol, visualizacion[i]);
    for(j = 0; j < i; j++)
    {
      if(izqder[i]==0&&(izqder[j]==0||izqder[j]==-1))
      {
        if(visualizacion[i] < visualizacion[j])//acabar
        {
          if( izq[j]==0)
          {
            fprintf(salida, "%cnodo%d%c:f0 -> %cnodo%d%c:f1;\n", comilla, j, comilla, comilla, i, comilla);
            izq[j]=i;
            break;
          }else
          {
            j=izq[j]-1;
          }

        }else if(visualizacion[i]>visualizacion[j])
        {
          if(der[j]==0)
          {
            fprintf(salida, "%cnodo%d%c:f2 -> %cnodo%d%c:f1;\n", comilla, j, comilla, comilla, i, comilla);
            der[j]=i;
            break;
          }else{
            j=der[j]-1;
          }
        }
      }else if(izqder[i]==1&&(izqder[j]==1||izqder[j]==-1))
      {
        if(visualizacion[i] < visualizacion[j])//acabar
        {
          if(izq[j]==0)
          {
            fprintf(salida, "%cnodo%d%c:f0 -> %cnodo%d%c:f1;\n", comilla, j, comilla, comilla, i, comilla);
            izq[j]=i;
            break;
          }else
          {
            j=izq[j]-1;
          }
        }else if(visualizacion[i]>visualizacion[j])
        {
          if(der[j]==0)
          {
            fprintf(salida, "%cnodo%d%c:f2 -> %cnodo%d%c:f1;\n", comilla, j, comilla, comilla, i, comilla);
            der[j]=i;
            break;
          }else{
            j=der[j]-1;
        }
    }
  }
}
}
}
