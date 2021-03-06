/*
** combat.c for  in 
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Wed Nov  8 23:00:30 2017 LEGOUEST Clement
** Last update Sat Nov 11 12:38:37 2017 LEGOUEST Clement
*/

#include "ftl.h"
#include "my_string.h"
#include <libmy.h>
#include <stdlib.h>
#include <math.h>

void		aff_pv(t_ship *ship)
{
  my_putstr_color("green", "| Vos PV : ");
  my_put_nbr(ship->hull);
  my_putstr("\n");
  my_putstr_color("red", "| PV de l'ennemi : ");
  if (ship->rebel_ship->life > 0)
    {
      my_put_nbr(ship->rebel_ship->life);
	  my_putstr("\n'---------->\n");
    }
  else
    my_putstr("0\n");
}

void		system_destroy(t_ship *ship)
{
  int		rand;
  
  rand = my_random(100) + 1;
  if (rand <= 100)
    {
      my_putstr_color("red", "| L'ennemi vous a detruit un systeme vital.\n");
      rand = my_random(3) + 1;
      if (rand == 1)
	{
	  my_putstr_color("red", "| reacteur detruit!\n");
	  free(ship->ftl_drive->system_state);
	  ship->ftl_drive->system_state = my_strdup("offline");
	}
      else if (rand == 2)
	{
	  my_putstr_color("red", "| compas detruit!\n");
	  free(ship->navigation_tools->system_state);
	  ship->navigation_tools->system_state = my_strdup("offline");
	}
      else if (rand == 3)
	{
	  my_putstr_color("red", "| systeme d'armement detruit!\n");
	  free(ship->weapon->system_state);
	  ship->weapon->system_state = "offline";
	}
    }
}

void		enemy_attack(t_ship *ship)
{
  my_putstr_color("red", "| L'enemi vous attaque.\n");
  if (my_random(100) <= ship->navigation_tools->evade)
    {
      my_putstr_color("green", "| L'ennemi vous a manque.\n");
    }
  else
    {
      ship->hull = ship->hull - ship->rebel_ship->damage;
      my_putstr_color("red", "| L'ennemi vous inflige des degats.\n");
      system_destroy(ship);
      
    }
}

void		enemy_ninja_attack(t_ship *ship)
{
  my_putstr_color("red", "| L'ennemi en profite pour vous attaquer.\n");
  enemy_attack(ship);
}

void		enemy_surprise_attack(t_ship *ship)
{
  my_putstr_color("red", "| L'ennemi vous attaque par surprise.\n");
  enemy_attack(ship);
}

void		ship_attack(t_ship *ship)
{
  if (ship->rebel_ship->exist == 1)
    {
      my_putstr("| Vous attaquez l'enemi.\n");
      ship->rebel_ship->life = ship->rebel_ship->life - ship->weapon->damage;
      my_putstr_color("green", "| Vous lui infligez des degats.\n");
      enemy_attack(ship);
      aff_pv(ship);
      if (ship->rebel_ship->life <= 0)
	{
	  my_putstr_color("green", "| Victoire! Vous avez défait le vaisseau rebelle.\n");
	  ship->rebel_ship->level += 1;
	  ship->rebel_ship->life_max *= 1.5;
	  ship->rebel_ship->damage *= 1.5;
	  if (my_random(100) <= 49)
	    {
	      my_putstr_color("yellow", "| Le combat fut rude, et couteux en energie.\n");
	      ship->ftl_drive->energy -= 1;
	    }
	  ship->rebel_ship->exist = 0;
	}
      my_putstr("'---------->\n");
    }
  else
    {
      my_putstr("| Il n'y a pas de vaisseau enemi dans ce secteur.\n");
      my_putstr("'---------->\n");
    }
}

void		combat(t_ship *ship)
{
  if (my_strcmp(ship->weapon->system_state, "online"))
    {
      my_putstr("| Vos systemes d'armes sont endomages\n");
      enemy_attack(ship);
    }
  else
    ship_attack(ship);
}

void		create_rebel_ship(t_ship *ship)
{
  ship->rebel_ship = malloc(sizeof(t_rebel_ship));
  ship->rebel_ship->damage = 10;
  ship->rebel_ship->life = 20;
  ship->rebel_ship->level = 0;
  ship->rebel_ship->life_max = 20;
  ship->rebel_ship->exist = 1;
}
