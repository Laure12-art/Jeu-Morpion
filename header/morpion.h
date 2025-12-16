#ifndef MORPION_H
#define MORPION_H

#define TAILLE 4

typedef struct {
    int ordinateur;
    int joueur;
} Score;

void initialiserGrille(char grille[TAILLE][TAILLE]);
void jouerPartie(char grille[TAILLE][TAILLE], char joueur, char ordinateur, Score *score);
void afficherGrille(char grille[TAILLE][TAILLE]);
int jouerCoup(char grille[TAILLE][TAILLE], int ligne, int colonne, char symbole);
int verifierVictoire(char grille[TAILLE][TAILLE], char symbole);
int grillePleine(char grille[TAILLE][TAILLE]);
void coupOrdinateur(char grille[TAILLE][TAILLE], char ordinateur, char joueur);
#endif
