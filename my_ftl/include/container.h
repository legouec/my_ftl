/*
** container.h for  in 
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Wed Nov  8 10:58:18 2017 LEGOUEST Clement
** Last update Fri Nov 10 16:34:54 2017 LEGOUEST Clement
*/

#ifndef _CONTAINER_H_
#define _CONTAINER_H_
#include "ftl.h"

int	add_container_to_ship(t_ship *ship);
void	add_freight_to_container(t_ship *ship, t_freight *freight);
void	del_freight_from_container(t_ship *ship, t_freight *freight);
void	detect(t_ship *ship);
void	get_bonus(t_ship *ship);

#endif /* !_CONTAINER_H_*/
