/*
** ftl.h for  in /home/naniev
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Mon Nov  6 10:13:52 2017 LEGOUEST Clement
** Last update Fri Nov 10 16:16:10 2017 LEGOUEST Clement
*/

#ifndef __FTL_H__
#define __FTL_H__
typedef struct s_freight
{
  char			*item;
  struct s_freight	*next;
  struct s_freight	*prev;
}t_freight;

typedef struct s_container
{
  int			nb_elem;
  t_freight		*first;
  t_freight		*last;
}t_container;

typedef struct s_navigation_tools
{
  char			*system_state;
  int			sector;
  int			sector_detect;
  int			evade;
}t_navigation_tools;

typedef struct s_ftl_drive
{
  char			*system_state;
  int			energy;
}t_ftl_drive;

typedef struct s_weapon
{
  char			*system_state;
  int			damage;
}t_weapon;

typedef struct	s_rebel_ship
{
  int			damage;
  int			life;
  int			level;
  int			life_max;
  int			exist;
}t_rebel_ship;

typedef struct	s_ship
{
  int			hull;
  t_weapon		*weapon;
  t_ftl_drive		*ftl_drive;
  t_navigation_tools	*navigation_tools;
  t_container		*container;
  t_rebel_ship		*rebel_ship;
}t_ship;

typedef struct s_repair_command
{
  char			*repair_command;
  void			(*function_pointer)(t_ship*);
}t_repair_command;

typedef struct s_game_turns
{
  char			*game_turns;
  void			(*function_pointer)(t_ship*);
}t_game_turns;
#endif
