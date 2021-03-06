/*
** text.h for  in 
** 
** Made by LEGOUEST Clement
** Login   <legoue_c@etna-alternance.net>
** 
** Started on  Fri Nov 10 00:55:51 2017 LEGOUEST Clement
** Last update Fri Nov 10 22:02:04 2017 LEGOUEST Clement
*/

#ifndef _TEXT_H_
#define _TEXT_H_

#define TEXT01 "\n\t\t\t\t###############\n\t\t\t\t#            \
 #\n\t\t\t\t#   MY  FTL   #\n\t\t\t\t#             #\n\t\t\t\t####\
###########\n\n,---------->\n| Suite a un violent affrontement contre u\
ne flotte rebelle,\n| votre unite s'abime sur une petite planete couverte de f\
oret.\n| La flotte rebelle ne va pas tarder a debarquer,\n| heureusement, vous\
 avez des competences de construction ainsi que des pieces a disposition.\n| V\
ous vous lancez dans la construction improvisee d'un petit vaisseau de fortune\
\n'---------->\n"

#define TEXT_SHIP_BASE ",---------->\n| Commencez par créer une base p\
our votre vaisseau."

#define TEXT_SHIP_REACT "'---------->\n\n,---------->\n| Il aura besoin \
d'un reacteur pour se deplacer."

#define TEXT_SHIP_NAV "'---------->\n\n,---------->\n| Les outils de nav\
igation sont necessaires pour se reperer dans l'espace."

#define TEXT_SHIP_WEAP "'---------->\n\n,---------->\n| Ajoutez lui des \
armes."

#define TEXT_SHIP_CONT "'---------->\n\n,---------->\n| Un container ser\
a utile pour recuperer des objets utiles dans l'espace."

#define TEXT_SHIP_FINAL "'---------->\n,---------->\n| Votre vaisseau te\
rmine, votre mission peut reprendre.\n| Maintenant demarrez votre vaisseau et \
allez livrer ces ordres au quartier général.\n'---------->\n"

#define JUMP_START "| Initialisation du saut hyperespace.\n| Veuillez va\
lider le deplacement."

#define JUMP_MID "\n,---------->\n| Vous avez atteint le secteur n° "

#define JUMP_CONT "| Vous etes au contact de l'ennemi,vous ne pouvez pas\
 vous desengager\n"

#define JUMP_SOLO "| Vous etes seul dans ce secteur.\n'---------->\n"

#define STAT_START "\n\t\t\t\t###############\n\t\t\t\t#            \
 #\n\t\t\t\t# SHIP STATUS #\n\t\t\t\t#             #\n\t\t\t\t####\
###########\n\n / CONTAINER \t/ ENERGIE   \t/ COQUE     \t/ PUISSANCE\n \\ "

#define TEXT_VICTORY "| Vous avez finalement reussi a traverser le secteur\
controle par les rebelles\n| et avez atteint une base de l'empire\n| Vous remett\
ez les informations au general responsable du secteur.\n| Le protocole N°66 pe\
ut etre engage.\n'---------->\n"

#define TEXT_DEFEAT ",---------->\n| Votre vaisseau a ete detruit,vous a\
vez failli \n| a votre mission, l'oprobe est sur vous a tout \n| jamais.\n'---\
------->\n"

#endif /* !_TEXT_H_*/
