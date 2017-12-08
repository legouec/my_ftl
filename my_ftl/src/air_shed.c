/*
** air_shed.c for  in /home/naniev
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Mon Nov  6 10:57:11 2017 LEGOUEST Clement
** Last update Fri Nov 10 22:43:29 2017 LEGOUEST Clement
*/
#include "ftl.h"
#include "my_string.h"
#include <libmy.h>
#include <stdlib.h>

t_ship			*create_ship(void)
{
  t_ship		*ship;

  my_putstr_color("yellow", "| Construction du vaisseau en cours...\n");
  ship = malloc(sizeof(t_ship));
  if (ship == NULL)
    {
      my_putstr_color("red", "| Le vaisseau n'a pas pu etre construit par");
      my_putstr_color("red", " manque de materiaux.\n");
      return(NULL);
    }
  my_putstr_color("green", "| Amelioration du vaisseau teminee!\n");
  ship->hull = 50;
  ship->weapon = NULL;
  ship->ftl_drive = NULL;
  ship->navigation_tools = NULL;
  ship->container = NULL;
  return(ship);
}

int			add_weapon_to_ship(t_ship *ship)
{
  t_weapon		*weapon;
  
  my_putstr_color("yellow", "| Ajout des armes en cours...\n");
  weapon = malloc(sizeof(t_weapon));
  if (weapon == NULL)
    {
      my_putstr_color("red", "| Votre vaisseau a explose quand vous avez");
      my_putstr_color("red", "| tente d'ajouter les armes.\n");
      return(0);
    }
  my_putstr_color("green", "| Les armes ont ete ajoutees avec succes!\n");
  weapon->damage = 10;
  weapon->system_state = my_strdup("online");
  ship->weapon = weapon;
  return(1);
}

int			add_ftl_drive_to_ship(t_ship *ship)
{
  t_ftl_drive		*ftl_drive;
  
  my_putstr_color("yellow", "| Ajout du réacteur en cours...\n");
  ftl_drive = malloc(sizeof(t_ftl_drive));
  if (ftl_drive == NULL)
    {
      my_putstr_color("red", "| Votre vaisseau a explose lorsque vous avez");
      my_putstr_color("red", "| pose le reacteur.\n");
      return(0);
    }
  my_putstr_color("green", "| Le reacteur a ete ajoute avec succes!\n");
  ftl_drive->energy = 10;
  ftl_drive->system_state = my_strdup("online");
  ship->ftl_drive = ftl_drive;
  return(1);
}

int			add_navigation_tools_to_ship(t_ship *ship)
{
  t_navigation_tools	*navigation_tools;

  my_putstr_color("yellow", "| Ajout des outils de navigation...\n");
  navigation_tools = malloc(sizeof(t_navigation_tools));
  if (navigation_tools == NULL)
    {
      my_putstr_color("red", "| Votre vaisseau a explose lorsque vous avez");
      my_putstr_color("red", "| pose les outils de navgation.\n");
      return(0);
    }
  my_putstr_color("green", "| Les outils de navigation ont ete ajoutes");
  my_putstr_color("green", "| avec succes!\n");
  navigation_tools->sector = 0;
  navigation_tools->evade = 25;
  navigation_tools->system_state = my_strdup("online");
  ship->navigation_tools = navigation_tools;
  return(1);
}
