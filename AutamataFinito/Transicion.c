#include <stdlib.h>
#include <string.h>
#include "Transicion.h"

const int TAM_ESTADO = 21;
const int TAM_SIMBOLO  = 11;



t_Transicion* t_Transicion_nueva(t_Estado est_partida, t_Estado est_llegada, t_Simbolo simb_entrada)
{
	t_Transicion* nueva_trans; 
	
	
	nueva_trans = (t_Transicion*) malloc(sizeof(t_Transicion));
	memcpy(nueva_trans->est_partida, est_partida,TAM_ESTADO);
	memcpy(nueva_trans->est_llegada, est_llegada,TAM_ESTADO);
	memcpy(nueva_trans->simb_entrada, simb_entrada,TAM_SIMBOLO);
	
	
	return nueva_trans;
}

void t_Transicion_free(t_Transicion* trans)
{
	free(trans);
	trans = NULL;
}

void t_Transicion_get_est_partida(t_Transicion* trans, t_Estado est)
{
	memcpy(est, trans->est_partida,TAM_ESTADO);
}
void t_Transicion_get_est_llegada(t_Transicion* trans, t_Estado est)
{
	memcpy(est, trans->est_llegada,TAM_ESTADO);
}
void t_Transicion_get_simb(t_Transicion* trans, t_Simbolo simb)
{
	memcpy(simb, trans->simb_entrada,TAM_SIMBOLO);	
}


bool t_Transicion_iguales(t_Transicion* trans_a, t_Transicion* trans_b)
{
	if ( strcmp(trans_a->est_partida, trans_b->est_partida) ||
		strcmp(trans_a->est_llegada, trans_b->est_llegada) || 
		strcmp(trans_a->simb_entrada, trans_b->simb_entrada)  )
		return false;
	
	return true;
	
}

