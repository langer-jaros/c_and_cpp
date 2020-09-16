#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

void chyba() {
    printf("chybny vstup\n");
    return;
}

int nactiZnak(const char pozadavek) {
    char znak;
    int control;
    if ((control = scanf(" %c", &znak)) == -1) {
        return -1;
    }
    if (znak != pozadavek) {
        return 1;
    }
    return 0;
}

int nactiLod(int *x, int* y) {
    int X;
    int Y;
    int control;
    if ((control = nactiZnak('['))) {
        if (control == -1) {
            return -1;
        }
        return 1;
    }

    if (scanf("%d", &X) != 1) {
        return 1;
    }

    if (nactiZnak(',')) {
        return 1;
    }
    if (scanf("%d", &Y) != 1) {
        return 1;
    }
    if (nactiZnak(']')) {
        return 1;
    }
    *x = X;
    *y = Y;
    return 0;
}

int nactiKonec() {
    char znak = '?';
    scanf(" %c", &znak);
    if (znak != ',') {
        if (znak != '}') {
            return 1;
        }
        return -1;
    }
    return 0;
}

int nactiLode(int* (*pole), int* pocet) {
    int x;
    int y;
    int i = 0;
    int control;
    int delkaPole = 5;
    pole[0] = (int*) malloc(sizeof (*pole[i]) * delkaPole);
    pole[1] = (int*) malloc(sizeof (*pole[i]) * delkaPole);
    if (nactiZnak('{')) {
        return 1;
    }
    while (1) {
        nactiLod(&x, &y);
        pole[0][i] = x;
        pole[1][i] = y;
        i++;
        if (delkaPole = i) {
            delkaPole = (3 * delkaPole) / 2;
            pole[0] = (int*) realloc(pole[0], sizeof (*pole[i]) * delkaPole);
            pole[1] = (int*) realloc(pole[1], sizeof (*pole[i]) * delkaPole);            
        }
        if ((control = nactiKonec()) != 0) {
            if (control == 1) {
                return 1;
            } else {
                if (control == -1) {
                    break;
                }
            }
        }
    }
    *pocet = i;
    return 0;
}

double spoctiMax(int* pole[], int *ukazatel, int *x, int *y) {
    double max;
    double vyska;
    double sirka;
    double mezimax;
    sirka = (double) abs(pole[0][*ukazatel]-*x);
    vyska = (double) abs(pole[1][*ukazatel]-*y);
    max = fabs((sirka * sirka) + (vyska * vyska));
    max = sqrt(max);

    return max;
}

int nactiCile(int* (*pole), int *pocet) {
    int i = 0;
    int x;
    int y;
    int control;
    double max = 0;
    double mezimax;
    printf("Cile:\n");
    while (1) {
        max = 0;
        if ((control = nactiLod(&x, &y)) != 0) {
            if (control != -1) {
                return 1;
            }
            break;
        }
        for (i = 0; i < *pocet; i++) {
            if ((mezimax = spoctiMax(pole, &i, &x, &y)) > max) {
                max = mezimax;
            }
        }
        printf("Max: %f\n", max);
    }

    return 0;
}

int main(void) {
    int* pole[2];
    int pocet;

    printf("Nepritel\n");

    if (nactiLode(pole, &pocet) != 0) {
        chyba();
        return 0;
    }
    if (nactiCile(pole, &pocet) != 0) {
        chyba();
        return 0;
    }
    free(pole[0]);
    free(pole[1]);
    
    return (EXIT_SUCCESS);
}

