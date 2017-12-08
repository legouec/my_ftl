/*
** main.c for  in /home/naniev
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Wed Nov  8 09:58:30 2017 LEGOUEST Clement
** Last update Fri Nov 10 21:05:07 2017 LEGOUEST Clement
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "air_shed.h"
#include "combat.h"
#include "container.h"
#include "ftl.h"
#include "game_turns.h"
#include <libmy.h>
#include "my_string.h"
#include "system_control.h"
#include "system_repair.h"
#include "text.h"

void		free_mem(t_ship *ship)
{
  while (ship->container->first != NULL)
    del_freight_from_container(ship, ship->container->first);
  free(ship->weapon->system_state);
  free(ship->weapon);
  free(ship->ftl_drive->system_state);
  free(ship->ftl_drive);
  free(ship->navigation_tools->system_state);
  free(ship->navigation_tools);
  free(ship->container->first);
  free(ship->container->last);
  free(ship->container);
  free(ship->rebel_ship);
}

void		init(t_ship *ship)
{
  my_putstr_color("clear", TEXT01);
  readline();
  my_putstr(TEXT_SHIP_BASE);
  readline();
  create_rebel_ship(ship);
  ship->rebel_ship->exist = 0;
  my_putstr(TEXT_SHIP_REACT);
  readline();
  add_ftl_drive_to_ship(ship);
  my_putstr(TEXT_SHIP_NAV);
  readline();
  add_navigation_tools_to_ship(ship);
  my_putstr(TEXT_SHIP_WEAP);
  readline();
  add_weapon_to_ship(ship);
  my_putstr(TEXT_SHIP_CONT);
  readline();
  add_container_to_ship(ship);
  my_putstr(TEXT_SHIP_FINAL);
}

int		main(void)
{
  t_ship	*ship;

  ship = create_ship();
  srand(time(NULL));
  init(ship);
  while ((ship->hull > 0) && (ship->navigation_tools->sector <10))
    {
      game_turns(ship);
    }
  if (ship->hull <= 0)
    my_putstr_color("red", TEXT_DEFEAT);
  else if (ship->navigation_tools->sector >= 10)
    my_putstr_color("green", TEXT_VICTORY);
  free_mem(ship);
  return(0);
}
