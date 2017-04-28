#include <stdio.h>
#include <stdlib.h>
#include "t_Conjunto.h"


bool igualesInt(void* num_a, void* num_b);
void mostrarInt(void* num_a);


int main()
{
	
	int a, b, c, d, f;
	a = 5;
	b = 6;
	c = 7;
	d = 7;
	f = 8;
	
	t_Conjunto* conjunto = crearConjunto(igualesInt);
	agregarElemento(conjunto, &a );
	//agregarElemento(conjunto, &b );
	//agregarElemento(conjunto, &c );
	
	mostrarConjunto(conjunto, mostrarInt);
	printf("Cardinalidad: %d\n", cardinalidad(conjunto));
	
	eliminarElemento(conjunto, &a);
	
	printf("Despues de eliminar\n");
	mostrarConjunto(conjunto, mostrarInt);
	printf("Cardinalidad: %d\n", cardinalidad(conjunto));
	
	agregarElemento(conjunto, &b );
	agregarElemento(conjunto, &c );
	mostrarConjunto(conjunto, mostrarInt);
	printf("Cardinalidad: %d\n", cardinalidad(conjunto));
	
	return 0;
}

bool igualesInt(void* num_a, void* num_b)
{
	return *((int*) num_a) == *((int*) num_b);
}

void mostrarInt(void* num_a)
{
	printf("%d\n", *((int*)num_a));
}
