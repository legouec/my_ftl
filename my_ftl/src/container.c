/*
** container.c for  in /home/naniev/ETNA/FDI-DEVC/my_ftl/legoue_c
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Mon Nov  6 21:18:00 2017 LEGOUEST Clement
** Last update Fri Nov 10 21:42:03 2017 LEGOUEST Clement
*/

#include <stdlib.h>
#include "container.h"
#include "my_string.h"
#include <libmy.h>

int		add_container_to_ship(t_ship *ship)
{
  t_container	*container;

  my_putstr_color("yellow", "| Ajout du container en cours...\n");
  container = malloc(sizeof(t_container));
  if (container == NULL)
    {
      my_putstr("| Votre vaisseau a explose lorsque vous");
      my_putstr("| avez pose le container.\n");
      return(0);
    }
  my_putstr_color("green", "| Le container a ete ajoute avec succes!\n");
  container->first = NULL;
  container->last = NULL;
  container->nb_elem = 0;
  ship->container = container;
  return(1);
}

void		add_freight_to_container(t_ship *ship, t_freight *freight)
{
  if ((ship == NULL) || (freight == NULL))
    return;
  if ((ship->container->first == NULL) && (ship->container->last == NULL))
    {
      ship->container->first = freight;
      ship->container->last = freight;
      freight->next = NULL;
      freight->prev = NULL;
    }
  else
    {
      ship->container->last->next = freight;
      freight->prev = ship->container->last;
      freight->next = NULL;
      ship->container->last = freight;
    }
  ship->container->nb_elem += 1;
}

void		del_freight_from_container(t_ship *ship, t_freight *freight)
{
  if ((ship == NULL) || (freight == NULL) || (ship->container->nb_elem == 0))
    return;
  if ((ship->container->first == freight) && (ship->container->last == freight))
    {
      ship->container->first = NULL;
      ship->container->last = NULL;
    }
  else if (freight == ship->container->first)
      ship->container->first = ship->container->first->next;
  else if (freight == ship->container->last)
    ship->container->last = ship->container->last->prev;
  else
    {
      freight->prev->next = freight->next;
      freight->next->prev = freight->prev;
    }
  free (freight->item);
  free (freight);
}

void		detect(t_ship *ship)
{
  int		idx;

  idx = 0;
  if (ship->navigation_tools->sector_detect == 0)
    {
      while (idx < 10)
	{
	  t_freight	*freight;
	  int		test;
	  
	  freight = malloc(sizeof(t_freight));
	  test = my_random(100);
	  if (test < 30)
	    {
	      test = my_random(100);
	      if (test <= 32)
		freight->item = my_strdup("energy");
	      else if (test <= 65)
		freight->item = my_strdup("attackbonus");
	      else if (test <= 98)
		freight->item = my_strdup("evadebonus");
	      else
		freight->item = my_strdup("scrap");
	    }
	  else
	    freight->item = my_strdup("scrap");
	  add_freight_to_container(ship, freight);
	  idx ++;
	}
      ship->navigation_tools->sector_detect = 1;
    }
  else
    my_putstr("| Vous avez deja utilise les scanners sur ce systeme.\n");
    my_putstr("'---------->");
}

void		get_bonus(t_ship *ship)
{
  while (ship->container->first != NULL)
    {
      if (my_strcmp(ship->container->first->item, "attackbonus") == 0)
	{
	  ship->weapon->damage += 5;
	  my_putstr("| Les armes ont ete ameliorees.\n");
	  del_freight_from_container(ship, ship->container->first);
	}
      else if (my_strcmp(ship->container->first->item, "evadebonus") == 0)
	{
	  ship->navigation_tools->evade += 3;
	  my_putstr("| Vous gagnez un bonus de furtivite.\n");
	  del_freight_from_container(ship, ship->container->first);
	}
      else if (my_strcmp(ship->container->first->item, "energy") == 0)
	{
	  ship->ftl_drive->energy += 1;
	  my_putstr("| Ajout d'energie au reacteur.\n");
	  del_freight_from_container(ship, ship->container->first);
	}
      else if (my_strcmp(ship->container->first->item, "scrap") == 0)
	{
	  my_putstr("| Débris sans interet reperes, evacuation immediate.\n");
	  del_freight_from_container(ship, ship->container->first);
	}
    }
  my_putstr("| Vous n'avez plus de cargaison\n");
  my_putstr("'---------->");
  ship->container->nb_elem = 0;
  return;
}
