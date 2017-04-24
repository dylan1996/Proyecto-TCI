#include <stdlib.h>
#include <string.h>
#include "Transicion.h"


t_Transicion t_Transicion_nueva(t_Estado est_partida, t_Estado est_llegada, t_Simbolo simb_entrada)
{
	t_Transicion nueva_trans; 
	
	nueva_trans = (t_Transicion) malloc(sizeof(Transicion));
	memcpy(nueva_trans->est_partida, est_partida,21);
	memcpy(nueva_trans->est_llegada, est_llegada,21);
	memcpy(nueva_trans->simb_entrada, simb_entrada,11);
	
	
	return nueva_trans;
}

void t_Transicion_free(t_Transicion trans)
{
	free(trans);
	trans = NULL;
}

void t_Transicion_get_est_partida(t_Transicion trans, t_Estado est)
{
	memcpy(est, trans->est_partida,21);
}
void t_Transicion_get_est_llegada(t_Transicion trans, t_Estado est)
{
	memcpy(est, trans->est_llegada,21);
}
void t_Transicion_get_simb(t_Transicion trans, t_Simbolo simb)
{
	memcpy(simb, trans->simb_entrada,11);	
}
