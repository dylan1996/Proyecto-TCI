#ifndef TRANSICION_H
#define TRANSICION_H



typedef char t_Estado[21]; /* Estado */
typedef char t_Simbolo[11]; /* Simbolo */

typedef struct{
	t_Estado est_partida; /* Estado de partida */
	t_Simbolo simb_entrada; /* Simbolo de entrada */
	t_Estado est_llegada; /* Estado de llegada */
	
}Transicion;

typedef Transicion* t_Transicion;

t_Transicion t_Transicion_nueva(t_Estado est_partida, t_Estado est_llegada, t_Simbolo simb_entrada);
void t_Transicion_free(t_Transicion);


void t_Transicion_get_est_partida(t_Transicion trans, t_Estado est);
void t_Transicion_get_est_llegada(t_Transicion trans, t_Estado est);
void t_Transicion_get_simb(t_Transicion trans, t_Simbolo simb);

#endif
