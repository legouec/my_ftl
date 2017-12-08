/*
** system_control.c for  in /home/naniev/ETNA/FDI-DEVC/my_ftl/legoue_c
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Tue Nov  7 17:07:39 2017 LEGOUEST Clement
** Last update Fri Nov 10 19:36:23 2017 LEGOUEST Clement
*/

#include "ftl.h"
#include "my_string.h"

void	ftl_drive_system_check(t_ship *ship)
{
  my_putstr("| Verification du reacteur en cours...\n");
  if (!(my_strcmp(ship->ftl_drive->system_state, "online")))
    my_putstr("| Reacteur OK!\n");
  else
    my_putstr("| Reacteur hors service!\n");
}

void	navigation_tools_system_check(t_ship *ship)
{
  my_putstr("| Verification du syteme de navigation encours...\n");
  if (!(my_strcmp(ship->navigation_tools->system_state, "online")))
    my_putstr("| Systeme de navigation OK!\n");
  else
    my_putstr("| Systeme de navigation hors service!\n");
}

void	weapon_system_check(t_ship *ship)
{
  my_putstr("| Verification du systeme d'armement en cours...\n");
  if (!(my_strcmp(ship->weapon->system_state, "online")))
    my_putstr("| systeme d'armement OK!\n");
  else
      my_putstr("| Systeme d'armement hors service\n");
  my_putstr("'---------->");
}

void	system_control(t_ship *ship)
{
  ftl_drive_system_check(ship);
  navigation_tools_system_check(ship);
  weapon_system_check(ship);
}
