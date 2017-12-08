/*
** game_turns.c for  in 
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Wed Nov  8 18:56:25 2017 LEGOUEST Clement
** Last update Fri Nov 10 22:08:25 2017 LEGOUEST Clement
*/

#include "ftl.h"
#include "my_string.h"
#include "system_repair.h"
#include <libmy.h>
#include <stdlib.h>
#include "game_turns.h"
#include "combat.h"
#include "text.h"
#include "container.h"
#include "system_control.h"
#include "system_repair.h"

static const t_game_turns	GAME_TURNS[] = {
  {"attack", &combat},
  {"jump", &jump},
  {"stat", &stat},
  {"detect", &detect},
  {"get_bonus", &get_bonus},
  {"system_control", &system_control},
  {"system_repair", &system_repair},
  {NULL, NULL}};

void				stat(t_ship *ship)
{
  my_putstr_color("clear", STAT_START);
  my_put_nbr(ship->container->nb_elem);
  my_putstr(" objets");
  my_putstr("\t\\ ");
  my_put_nbr(ship->ftl_drive->energy);
  my_putstr("\t\t\\ ");
  my_put_nbr(ship->hull);
  my_putstr("\t\t\\ ");
  my_put_nbr(ship->weapon->damage);
  my_putstr("\n");
}

void				jump(t_ship *ship)
{
  if (!(my_strcmp(ship->ftl_drive->system_state, "online")))
    {
      if (ship->rebel_ship->exist == 0)
	{
	  my_putstr(JUMP_START);
	  readline();
	  ship->navigation_tools->sector += 1;
	  ship->ftl_drive->energy -= 1;
	  ship->navigation_tools->sector_detect = 0;
	  my_putstr_color("clear", JUMP_MID);
	  my_put_nbr(ship->navigation_tools->sector);
	  my_putstr("\n");
	  if ((my_random(100) <= 29) && (ship->navigation_tools->sector < 10))
	    {
	      ship->rebel_ship->exist = 1;
	      ship->rebel_ship->life = ship->rebel_ship->life_max;
	      my_putstr_color("yellow", "| Il y a un chasseur rebelle dans le secteur.\n");
	      if (my_random(100) <= 24)
		enemy_surprise_attack(ship);
	      my_putstr_color("yellow", "'--------->\n");
	    }
	  else if (ship->navigation_tools->sector < 10)
	    my_putstr(JUMP_SOLO);
	}
      else
	{
	  my_putstr_color("red", JUMP_CONT);
	  enemy_ninja_attack(ship);
	  my_putstr_color("red", "'--------->\n");
	}
    }
  else
    my_putstr("Votre reacteur est detruit et vous ne pouvez pas vous deplacer.\n");
}

void				game_turns(t_ship *ship)
{
  char	*cmd;
  int	idx;

  idx = 0;
  my_putstr("\n,---------->\n");
  my_putstr("| Veuillez entrer une commande de navigation :\n");
  my_putstr("| tarkin_w@empire $ ");
  cmd = readline();
  if (cmd == NULL)
    {
      my_putstr_color("red", "| [SYSTEM FAILURE] : le lecteur de commandes est bloque.\n");
    }
  while (GAME_TURNS[idx].game_turns != NULL)
    {
      if (!(my_strcmp(cmd, GAME_TURNS[idx].game_turns)))
	{
	  GAME_TURNS[idx].function_pointer(ship);
	  return;
	}
      idx ++;
    }
  my_putstr_color("red", "| [SYSTEM FAILURE] : commande inconnue.\n");
  my_putstr_color("red", "'---------->\n");
}
