#ifndef T_CONJUNTO_H
#define T_CONJUNTO_H
#include <stdbool.h>

typedef struct _nodo t_nodo;

struct _nodo
{
	void* elemento;
	t_nodo* sig;
};

typedef bool (*igualesElemento)(void*,void*);
typedef void (mostrarElemento)(void*);
typedef void (freeElemento)(void*);

typedef struct 
{
	t_nodo* primer_elem;
	t_nodo* ultimo_elem;
	int cardinalidad;
	igualesElemento funcion_iguales;
}t_Conjunto;


t_Conjunto* crearConjunto(igualesElemento funcion_iguales);
bool esVacio(t_Conjunto* conjunto);
int cardinalidad(t_Conjunto*);
bool agregarElemento(t_Conjunto* conjunto, void* elemento);
bool eliminarElementoFree(t_Conjunto* conjunto, void* elemento, freeElemento funcion_free_elemento);
bool eliminarElemento(t_Conjunto* conjunto, void* elemento);
bool pertenece(t_Conjunto* conjunto, void* elemento);



void freeConjunto(t_Conjunto**);
void mostrarConjunto(t_Conjunto* conjunto, mostrarElemento funcion_mostrar_elemento);

#endif
