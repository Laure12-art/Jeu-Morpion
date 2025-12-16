#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "morpion.h"

#define PROFONDEUR_MAX 5

void jouerPartie(char grille[TAILLE][TAILLE], char joueur, char ordinateur, Score *score) {
    while (1) {
        int ligne, colonne;
        printf("Entrez votre coup (ligne colonne Ex(1 2) : ");
        if (scanf("%d %d", &ligne, &colonne) != 2) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Entree invalide.\n");
            continue;
        }

        if (ligne < 1 || ligne > TAILLE || colonne < 1 || colonne > TAILLE) {
            printf("Coordonnees hors limites.\n");
            continue;
        }

        if (!jouerCoup(grille, ligne - 1, colonne - 1, joueur)) {
            printf("Case occupee.\n");
            continue;
        }

        if (verifierVictoire(grille, joueur)) {
            afficherGrille(grille);
            printf("Vous avez gagne !\n");
            score->joueur++;
            break;
        }

        if (grillePleine(grille)) {
            afficherGrille(grille);
            printf("Match nul !\n");
            break;
        }

        coupOrdinateur(grille, ordinateur, joueur);
        afficherGrille(grille);

        if (verifierVictoire(grille, ordinateur)) {
            printf("L'ordinateur a gagne !\n");
            score->ordinateur++;
            break;
        }

        if (grillePleine(grille)) {
            printf("Match nul !\n");
            break;
        }
    }
}

void initialiserGrille(char grille[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            grille[i][j] = ' ';
        }
    }
}

void afficherGrille(char grille[TAILLE][TAILLE]) {
    printf("\n");
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            printf(" %c ", grille[i][j]);
            if (j < TAILLE - 1) printf("|");
        }
        printf("\n");
        if (i < TAILLE - 1) {
            for (int j = 0; j < TAILLE; j++) {
                printf("---");
                if (j < TAILLE - 1) printf("+");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int jouerCoup(char grille[TAILLE][TAILLE], int ligne, int colonne, char symbole) {
    if (ligne < 0 || ligne >= TAILLE || colonne < 0 || colonne >= TAILLE) return 0;
    if (grille[ligne][colonne] != ' ') return 0;
    grille[ligne][colonne] = symbole;
    return 1;
}

int verifierVictoire(char grille[TAILLE][TAILLE], char symbole) {
    for (int i = 0; i < TAILLE; i++) {
        int lignevalide = 1;
        for (int j = 0; j < TAILLE; j++) {
            if (grille[i][j] != symbole) { lignevalide = 0; break; }
        }
        if (lignevalide) return 1;
    }
    for (int j = 0; j < TAILLE; j++) {
        int colonnevalide = 1;
        for (int i = 0; i < TAILLE; i++) {
            if (grille[i][j] != symbole) { colonnevalide= 0; break; }
        }
        if (colonnevalide) return 1;
    }
    // diagonale principale
    int diagonale = 1;
    for (int i = 0; i < TAILLE; i++) {
        if (grille[i][i] != symbole) { diagonale = 0; break; }
    }
    if (diagonale) return 1;
    // diagonale secondaire
    diagonale = 1;
    for (int i = 0; i < TAILLE; i++) {
        if (grille[i][TAILLE - i - 1] != symbole) { diagonale = 0; break; }
    }
    return diagonale;
}

int grillePleine(char grille[TAILLE][TAILLE]) {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille[i][j] == ' ') return 0;
        }
    }
    return 1;
}

void coupOrdinateur(char grille[TAILLE][TAILLE], char ordinateur, char joueur) {
    int ligne, colonne;
    int coupValide = 0;

    if (grillePleine(grille)) {
        return;
    }

    do {
        ligne = rand() % TAILLE;
        colonne = rand() % TAILLE;

        if (grille[ligne][colonne] == ' ') {
            grille[ligne][colonne] = ordinateur;
            coupValide = 1;
        }
    } while (!coupValide);

    printf("L'ordinateur joue  en (%d, %d).\n", ligne + 1, colonne + 1);
}
