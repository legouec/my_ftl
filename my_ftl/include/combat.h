/*
** combat.h for  in 
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Thu Nov  9 13:15:38 2017 LEGOUEST Clement
** Last update Thu Nov  9 23:03:36 2017 LEGOUEST Clement
*/

#ifndef _COMBAT_H_
#define _COMBAT_H_

void	enemy_attack(t_ship *ship);
void	enemy_ninja_attack(t_ship *ship);
void	enemy_surprise_attack(t_ship *ship);
void	combat(t_ship *ship);
void	*create_rebel_ship(t_ship *ship);

#endif /* _COMBAT_H_*/
