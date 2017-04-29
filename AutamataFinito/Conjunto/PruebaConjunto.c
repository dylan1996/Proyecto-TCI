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
	d = 8;
	f = 9;
	
	t_Conjunto* conjunto = crearConjunto(igualesInt);
	agregarElemento(conjunto, &a );
	agregarElemento(conjunto, &b );
	agregarElemento(conjunto, &c );
	agregarElemento(conjunto, &d );
	agregarElemento(conjunto, &f );
	
	printf( "Cardinalidad: %d\n", cardinalidad(conjunto));
	
	freeConjunto(&conjunto);
	
	printf("conjunto: %p\n", conjunto);
	//agregarElemento(conjunto, &a);
	//mostrarConjunto(conjunto, mostrarInt);
	
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
