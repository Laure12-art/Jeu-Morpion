#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "morpion.h"

int main() {
    Score score = {0, 0};
    char joueur = 'X', ordinateur = 'O';
    char grille[TAILLE][TAILLE];

    while (1) {
        printf("\n********************************\n");
        printf("Jeu du Morpion (%dx%d)\n", TAILLE, TAILLE);
        printf("***********************************\n");
        printf("Score : Ordinateur : %d | Joueur : %d\n", score.ordinateur, score.joueur);
        printf("----------------------------------\n");
        printf("1. Jouer une nouvelle partie\n");
        printf("2. Quitter\n");
        printf("----------------------------------\n");
        printf("Votre choix : ");

        int choix = 0;
        if (scanf("%d", &choix) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Entrée invalide. Réessayez.\n");
            continue;
        }

        switch (choix) {

            case 1:
                initialiserGrille(grille);
                jouerPartie(grille, joueur, ordinateur, &score);
                break;


            case 2:
                printf("Merci de votre visite . Au revoir !!\n");
                return 0;

            default:
                printf("Choix inconnu. Ressayez.\n");
                break;
        }
    }
    return 0;
}
