//
//  ShareThings.c
//  
//
//  Created by Marco Bousseau on 10/03/2020.
//
#include <pwd.h>
#include <unistd.h>
#include "ShareThings.h"

typedef struct Ressource {
    enum { LIVRE=0, PC=1, OUTILS=2, CAPTEURS=3, AUTRE=4 }type;
    int *disponible;
    struct Personne *emprunteur;
    struct Personne *proprietaire;
}Ressource;

typedef struct Personne {
    char *Nom[30];
    char *Prenom[30];
    char *identifiant[30];
    char *mdp[15];
    struct Ressource *emprunts[30];
    struct Ressource *prets[30];
}Personne;

typedef struct Date {
    int jour;
    int mois;
    int annee;
}Date;

int menuAccueil(){
    printf("\t\tMENU\n\n\t\t(1)Administrateur\n\t\t(2)Client\n\t\t(3)Quitter\n");
    int entree;
    scanf("%d", &entree);
    return entree;
}

int authentificationAdmin(char mdpAdmin[]){
    char entree[15];
    int i;
    for (i=0; i<15; i++) {
        entree[i] = '_';
    }
    char c;
    i=0;
    //while(i<15){
    printf("\t\tAuthentification\n\n\t\tmdp (en entrant à chaque caractère) : %s", entree);
    scanf("%s", &entree);
//        entree[i] = c;
    i++;
    //}
    switch(HashCode(mdpAdmin) == HashCode(entree)){
        case 1:
            return 1;
        case 0:
            return 0;
        default:
            return 0;
    }

}

/*char chiffrement(char mot[]){
    
}*/

unsigned int HashCode (char  *ligne)
{
    unsigned int Code = 0;
    size_t const len = strlen (ligne);
    size_t i;
    
    //  printf ("ligne = '%s'\n", ligne);
    
    for (i = 0; i < len; i++)
    {
        Code = ligne[i] + 31 * Code;
    }
    return Code % 101;
}

int authentificationClient(char mdpClient[]){return 1;}

int main(){
    char mdpAdmin[10];
    printf("Entrer mdp Admin :\n");
    scanf("%s", mdpAdmin);
    int menu;
    menu = menuAccueil();
    switch (menu) {
        case 1:
            while(! authentificationAdmin(mdpAdmin)){
                authentificationAdmin(mdpAdmin);
            }
            
            break;
        case 2:
            while(! authentificationClient(mdpAdmin)){
                authentificationClient(mdpAdmin);
            }
            menuDemandeurPreteur();
        default:
            menuAccueil();
            break;
    }
}
