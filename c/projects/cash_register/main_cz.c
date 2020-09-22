#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct kasa {
    int bankovka;
    int pocet;
} KASA;

void nastavitBankovky(KASA* kasa) {
    int i;
    for (i = 0; i < 12; i++) {
        kasa[i].pocet = 0;
        switch (i) {
            case 0: kasa[i].bankovka = 5000;
                break;
            case 1: kasa[i].bankovka = 2000;
                break;
            case 2: kasa[i].bankovka = 1000;
                break;
            case 3: kasa[i].bankovka = 500;
                break;
            case 4: kasa[i].bankovka = 200;
                break;
            case 5: kasa[i].bankovka = 100;
                break;
            case 6: kasa[i].bankovka = 50;
                break;
            case 7: kasa[i].bankovka = 20;
                break;
            case 8: kasa[i].bankovka = 10;
                break;
            case 9: kasa[i].bankovka = 5;
                break;
            case 10: kasa[i].bankovka = 2;
                break;
            case 11: kasa[i].bankovka = 1;
                break;
        }
    }
}

void chyba() {
    printf("chyba\n");
}

int nacitani(int* bankovka, int* pocet) {
    int kontrola;
    char znak;

    if ((kontrola = scanf("%d", pocet)) != 1) {
        printf("spatnej pocet\n");
        return 1;
    }
    if ((kontrola = scanf(" %c", &znak)) != 1) {
        printf("wtf\n");
        return 1;
    }
    if (znak != 'x') {
        printf("nemas tam krat vole\n");
        return 1;
    }
    if ((kontrola = scanf("%d", bankovka)) != 1) {
        printf("spatna bankovka vole\n");
        return 1;
    }
    if ((kontrola = scanf(" %c", &znak)) != 1) {
        printf("wtf\n");
        return 1;
    }
    if (znak != 'K') {
        printf("nemas tam k vole\n");
        return 1;
    }
    if ((kontrola = scanf(" %c", &znak)) != 1) {
        printf("wtf\n");
        return 1;
    }
    if (znak != 'c') {
        printf("nemas tam c vole\n");
        return 1;
    }
    if (pocet < 0) {
        printf("zapornej pocet vole\n");
        return 1;
    }
    return 0;
}

int transakce(int* castka, KASA * kasa, int* spropitne) {
    KASA bankovky[12];    
    int i;
    int kontrola;
    char znak;
    int pocet;
    int bankovka;
    int mezicastka = *castka;

    nastavitBankovky(bankovky);

    if ((kontrola = scanf(" %c", &znak)) != 1) {
        printf("wtf\n");
        return 1;
    }
    if (znak != '[') {
        printf("nemas tam zavorku vole\n");
        return 1;
    }
    while (1) {
        if (nacitani(&bankovka, &pocet) != 0) {
            return 1;
        }

        for (i = 0; i < 12; i++) {
            if (bankovka == bankovky[i].bankovka) {
                bankovky[i].pocet = pocet;
                mezicastka -= pocet*bankovka;
                pocet = 0;
                break;
            }
        }
        if (pocet != 0) {
            printf("spatna bankovka voe vole\n");
            return 1;
        }
        if ((kontrola = scanf("%c", &znak)) != 1) {
            printf("wtf\n");
            return 1;
        }
        if (znak != ',') {

            if ((kontrola = scanf(" %c", &znak)) != 1) {
                printf("wtf\n");
                return 1;
            }
            if (znak != ']') {
                printf("nemas tam ]\n");
                return 1;
            } else {
                break;
            }
        }

    }
    if (mezicastka > 0) {
        printf("nemas dost penez voe\n");
        return 0;
    }
    *spropitne += abs(mezicastka);
    for (i = 0; i < 12; i++) {
        kasa[i].pocet += bankovky[i].pocet;
    }
    printf("Kasa: [");
    int flag = 1;
    for (i = 0; i < 12; i++) {
        if (kasa[i].pocet != 0) {
            if (flag == 0) {
                printf(",");
            }
            printf(" %dx%d Kc", kasa[i].pocet, kasa[i].bankovka);
            flag = 0;
        }
    }
    printf(" ]\n");
    printf("Spropitne: %d\n", *spropitne);
    return 0;
}

int nacistCastku(int *castka) {
    int kontrola;
    int penize;
    if ((kontrola = scanf("%d", &penize)) != 1) {
        if (kontrola == -1) {
            printf("EOF\n");
            return -1;
        } else {
            printf("spatnej vstup\n");
            return 1;
        }
    }
    if (penize < 0) {
        printf("malo penez\n");
        return 1;
    }
    *castka = penize;
    return 0;
}

int main(void) {
    KASA kasa[12];
    int i;
    int castka;
    int kontrola;
    int spropitne = 0;

    nastavitBankovky(kasa);
    /*
        for (i = 0; i < 12; i++) {
            printf("bankovka %d pocet %d\n", kasa[i].bankovka, kasa[i].pocet);
        }*/

    while (1) {
        if ((kontrola = nacistCastku(&castka)) != 0) {
            if (kontrola == -1) {
                break;
            } else {
                chyba();
                return 0;
            }
        }
        if ((kontrola = transakce(&castka, kasa, &spropitne)) != 0) {
            chyba();
            return 0;
        }
    }
    return (EXIT_SUCCESS);
}

