/*
** system_repair.c for  in /home/naniev/ETNA/FDI-DEVC/my_ftl/legoue_c
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Tue Nov  7 18:22:13 2017 LEGOUEST Clement
** Last update Sat Nov 11 12:35:39 2017 LEGOUEST Clement
*/

#include "ftl.h"
#include "my_string.h"
#include "system_repair.h"
#include <libmy.h>
#include <stdlib.h>

static const t_repair_command	REPAIR_COMMAND[] = {
  {"ftl_drive", &ftl_drive_system_repair},
  {"navigation_tools", &navigation_tools_system_repair},
  {"weapon", &weapon_system_repair},
  {NULL, NULL}};

void	ftl_drive_system_repair(t_ship *ship)
{
  my_putstr("| Reparation du reacteur en cours...\n");
  free(ship->ftl_drive->system_state);
  ship->ftl_drive->system_state = my_strdup("online");
  if (ship->ftl_drive->system_state == NULL)
    {
      my_putstr("| Les reparations du reacteur ont echoue.\n");
      return;
    }
  my_putstr("| Reparations terminees! Systeme reacteur OK!\n");
  my_putstr("'---------->");
}

void	navigation_tools_system_repair(t_ship *ship)
{
  my_putstr("Reparation du systeme de navigation en cours...\n");
  free(ship->navigation_tools->system_state);
  ship->navigation_tools->system_state = my_strdup("online");
  if (ship->navigation_tools->system_state == NULL)
    {
      my_putstr("| Les reparation du systeme de navigation ont echoue.\n");
      return;
    }
  my_putstr("| Reparations terminees! Systeme de navigation OK!\n");
  my_putstr("'---------->\n");
}

void	weapon_system_repair(t_ship *ship)
{
  my_putstr("| Reparation du systeme d'armement en cours...\n");
  free(ship->weapon->system_state);
  ship->weapon->system_state = my_strdup("online");
  if (ship->weapon->system_state == NULL)
    {
      my_putstr("| Les reparations du systeme d'armement ont echoue.\n");
      return;
    }
  my_putstr("| Reparations terminees! Systeme d'armement OK!\n");
  my_putstr("'---------->");
}

void	system_repair(t_ship *ship)
{
  char	*cmd;
  int	idx;

  idx = 0;
  my_putstr("| system_repair~>");
  cmd = readline();
  if (cmd == NULL)
    {
      my_putstr("| [SYSTEM FAILURE] : le lecteur de commandes est bloque.\n");
    }
  while (REPAIR_COMMAND[idx].repair_command != NULL)
    {
      if (my_strcmp(cmd, REPAIR_COMMAND[idx].repair_command) == 0)
	{
	  REPAIR_COMMAND[idx].function_pointer(ship);
	  return;
	}
      idx ++;
    }
  my_putstr("| [SYSTEM FAILURE] : commande inconnue.\n");
  my_putstr("'---------->");
}
