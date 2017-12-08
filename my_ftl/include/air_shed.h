/*
** air_shed.h for  in 
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Wed Nov  8 11:00:07 2017 LEGOUEST Clement
** Last update Wed Nov  8 11:06:58 2017 LEGOUEST Clement
*/

#ifndef _AIR_SHED_H_
#define _AIR_SHED_H_
#include "ftl.h"
t_ship		*create_ship(void);
int		add_weapon_to_ship(t_ship *ship);
int		add_ftl_drive_to_ship(t_ship *ship);
int		add_navigation_tools_to_ship(t_ship *ship);

#endif /* !_AIR_SHED_H_*/
