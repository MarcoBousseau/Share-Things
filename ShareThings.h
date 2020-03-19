//
//  ShareThings.h
//  
//
//  Created by Marco Bousseau on 10/03/2020.
//

#ifndef ShareThings_h
#define ShareThings_h

#include <stdio.h>

/*
typedef struct Ressource;

typedef struct Personne;

typedef struct Date;*/

int MenuAccueil();
unsigned int HashCode(char *);
int authentificationAdmin(char []);
int authentificationClient(char []);

int menuAdmin();

int ajouterPersonne(struct Personne p1);
int modifPersonne();
int supprPersonne();
int afficheListeClients();

int menuDemandeurPreteur();

struct Ressource rechercheParType();
int nbRessEmprPrete();
int nbRessPrete();
int ListeOperationsPeriod(struct Date /*debut*/, struct Date /*fin*/);
struct Date finDePret(struct Ressource r);
int retirerRessource();
int supprCoord();
int transfert();

#endif /* ShareThings_h */
