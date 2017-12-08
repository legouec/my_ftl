/*
** system_control.h for  in 
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Wed Nov  8 10:53:51 2017 LEGOUEST Clement
** Last update Fri Nov 10 19:27:55 2017 LEGOUEST Clement
*/

#ifndef _SYSTEM_CONTROL_H_
#define _SYSTEM_CONTROL_H_

void	ftl_drive_system_check(t_ship *ship);
void	navigation_tools_system_check(t_ship *ship);
void	weapon_system_check(t_ship *ship);
void	system_control(t_ship *ship);

#endif /* !_SYSTEM_CONTROL_H_*/
