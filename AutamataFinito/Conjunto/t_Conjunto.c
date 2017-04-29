#include "t_Conjunto.h"
#include <stdio.h>
#include <stdlib.h>

/* PROTOTIPO DE FUNCIONES PRIVADAS */

t_nodo* crearNodo(void* elemento);
void freeNodo(t_nodo* nodo);
t_nodo* buscarNodoAnterior(t_Conjunto* conjunto, void* elemento);
void* eliminarNodo(t_Conjunto* conjunto, void* elemento);
void incrementaCardinal(t_Conjunto* conjunto);
void decrementaCardinal(t_Conjunto* conjunto);

/* IMPLEMENTACION DE FUNCIONES PUBLICAS */

t_Conjunto* crearConjunto(igualesElemento funcion_compara)
{
	t_Conjunto* conjunto = (t_Conjunto*) malloc(sizeof(t_Conjunto));
	conjunto->primer_elem = NULL;
	conjunto->ultimo_elem = NULL;
	conjunto->cardinalidad = 0;
	conjunto->funcion_iguales = funcion_compara;
}
bool esVacio(t_Conjunto* conjunto)
{
	return conjunto->cardinalidad == 0;
}
int cardinalidad(t_Conjunto* conjunto)
{
	return conjunto->cardinalidad;
}
bool agregarElemento(t_Conjunto* conjunto, void* elemento)
{
	t_nodo* anterior = NULL;
	if ( conjunto->cardinalidad == 0 )
	{
		conjunto->primer_elem = conjunto->ultimo_elem = crearNodo(elemento);
		conjunto->cardinalidad += 1;
		return true;
	}
	if ( !pertenece(conjunto, elemento) )
	{
		anterior = conjunto->ultimo_elem;
		conjunto->ultimo_elem = crearNodo(elemento);
		anterior->sig = conjunto->ultimo_elem;
		conjunto->cardinalidad += 1;
		return true;
	}
	
	return false;
}

bool eliminarElementoFree(t_Conjunto* conjunto, void* elemento, freeElemento funcion_free_elemento)
{
	void* elemento_eliminar = eliminarNodo(conjunto,elemento);
	if ( elemento_eliminar == NULL )
		return false;
	funcion_free_elemento(elemento_eliminar);
	return true;
}
bool eliminarElemento(t_Conjunto* conjunto, void* elemento)
{
	if ( eliminarNodo(conjunto, elemento) != NULL  )
		return true;
	return false;
}


bool pertenece(t_Conjunto* conjunto, void* elemento)
{
	t_nodo* aux = NULL;
	if ( conjunto->funcion_iguales(conjunto->primer_elem->elemento, elemento) )
		return true;
	if (conjunto->funcion_iguales(conjunto->ultimo_elem->elemento, elemento) )
		return true;
	
	aux = conjunto->primer_elem->sig;
	
	while( aux != NULL && !conjunto->funcion_iguales(aux->elemento, elemento) )
		aux = aux->sig;
	
	return aux != NULL;
}

void mostrarConjunto(t_Conjunto* conjunto, mostrarElemento funcion_mostrar_elemento)
{
	int i;
	
	t_nodo* aux = conjunto->primer_elem;
	for ( i = 0; i < conjunto->cardinalidad; i++)
	{
		funcion_mostrar_elemento(aux->elemento);
		aux = aux->sig;
	}
}


void freeConjunto(t_Conjunto** conjunto)
{
	int i;
	t_nodo* eli;
	t_nodo* aux;
	eli = (*conjunto)->primer_elem;
	
	for ( i = 0; i < cardinalidad(*conjunto); i++ ){
		aux = eli->sig;
		freeNodo(eli);
		eli = aux;
	}
	(*conjunto)->cardinalidad = -1;
	free(*conjunto);
	*conjunto = NULL;
}

/* FUNCIONES PRIVADAS */


t_nodo* crearNodo(void* elemento)
{
	t_nodo* nodo_nuevo = (t_nodo*) malloc(sizeof(t_nodo));
	nodo_nuevo->elemento = elemento;
	nodo_nuevo->sig = NULL;
}

void freeNodo(t_nodo* nodo)
{
	free(nodo);
}

t_nodo* buscarNodoAnterior(t_Conjunto* conjunto, void* elemento)
{
	/*
		Si el nodo buscado es el primero, retorna el primer nodo;
		Si el nodo no se encuentra, retorna NULL;
		en otro caso retorna el nodo anterior;
	*/
	
	t_nodo* nodo_anterior = conjunto->primer_elem;
	
	if ( conjunto->funcion_iguales(nodo_anterior->elemento, elemento) )
		return conjunto->primer_elem;
		
	while ( nodo_anterior->sig != NULL && !conjunto->funcion_iguales(nodo_anterior->sig->elemento, elemento) )
		nodo_anterior = nodo_anterior->sig;
	
	if ( !(nodo_anterior->sig == NULL) )
		return nodo_anterior;
	
	return NULL;
}

void* eliminarNodo(t_Conjunto* conjunto, void* elemento)
{
	t_nodo* nodo_anterior;
	t_nodo* nodo_eliminar;
	void* elemento_eliminar;
	if ( esVacio(conjunto) )
		return NULL;
	
	if ( conjunto->funcion_iguales(conjunto->primer_elem->elemento, elemento) ){
		nodo_eliminar = conjunto->primer_elem;
		elemento_eliminar = conjunto->primer_elem->elemento;
		if ( cardinalidad(conjunto) == 1 )
			conjunto->primer_elem = conjunto->ultimo_elem = NULL;
		else
			conjunto->primer_elem = conjunto->primer_elem->sig;
	}
	else{
		nodo_anterior = conjunto->primer_elem;
		while ( nodo_anterior->sig != NULL && !conjunto->funcion_iguales(nodo_anterior->sig->elemento, elemento) )
			nodo_anterior = nodo_anterior->sig;
		if ( nodo_anterior->sig == NULL )
			return NULL;
		nodo_eliminar = nodo_anterior->sig;
		elemento_eliminar = nodo_eliminar->elemento;
		nodo_anterior->sig = nodo_eliminar->sig;
		if ( conjunto->ultimo_elem == nodo_eliminar )
			conjunto->ultimo_elem = nodo_anterior;
	}
	
	freeNodo(nodo_eliminar);
	decrementaCardinal(conjunto);
	return elemento_eliminar;	
}




void incrementaCardinal(t_Conjunto* conjunto)
{
	conjunto->cardinalidad += 1;
}
void decrementaCardinal(t_Conjunto* conjunto)
{
	conjunto->cardinalidad -= 1;
}
