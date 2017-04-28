#include <stdio.h>
#include <stdlib.h>
#include "Transicion.h"

int main ()
{
	
	t_Transicion* tran1;
	t_Transicion* tran2;
	tran1 = t_Transicion_nueva("q0","q1","a");
	tran2 = t_Transicion_nueva("q0","q1", "a");
	t_Estado est_llegada, est_partida;
	t_Simbolo simb;
	
	t_Transicion_get_est_llegada(tran1,est_llegada);
	t_Transicion_get_est_partida(tran1,est_partida);
	t_Transicion_get_simb(tran1,simb);
	
	/*
	printf("Estado de partida: %s\n", est_partida );
	printf("Estado de llegada: %s\n", est_llegada );
	printf("Simbolo: %s\n", simb );
	*/
	
	if (t_Transicion_iguales(tran1,tran2))
	{
		printf("iguales");
	}
	t_Transicion_free(tran1);
	t_Transicion_free(tran2);
	
	return 0;
	
}
