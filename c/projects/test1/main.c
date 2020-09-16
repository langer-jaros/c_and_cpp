

#include <stdio.h>
#include <stdlib.h>

void chyba() {
    printf("chyba\n");
}

int nactiCastku(int* castka) {
    int x;
    int c;
    if (c = scanf("%d", &x) != 1) {
        if (c == -1) {
            return -1;
        }
        return 1;
    }
    if (x < 0) {
        return 1;
    }
    *castka = x;
    return 0;
}

int nactiBankovky(int *bankovkyREAL, int* castka) {
    char x;
    int bankovky[12];
    int bankovka;
    int pocet;
    char znak;
    int i;
    if (scanf(" %c", &x) != 1) {
        chyba();
        return 1;
    }
    if (x != '[') {
        chyba();
        return 1;
    }
    int omg;
    while (1) {
        scanf("%dx%d", &pocet, &bankovka);
        if (pocet < 0) {
            chyba();
            return 1;
        }
        if (bankovka == 5000) {
            bankovky[0] += pocet;
        } else {
            if (bankovka == 2000) {
                bankovky[1] += pocet;
            } else {
                if (bankovka == 1000) {
                    bankovky[2] += pocet;
                } else {
                    if (bankovka == 500) {
                        bankovky[3] += pocet;
                    } else {
                        if (bankovka == 200) {
                            bankovky[4] += pocet;
                        } else {
                            if (bankovka == 100) {
                                bankovky[5] += pocet;
                            } else {
                                if (bankovka == 50) {
                                    bankovky[6] += pocet;
                                } else {
                                    if (bankovka == 20) {
                                        bankovky[7] += pocet;
                                    } else {
                                        if (bankovka == 10) {
                                            bankovky[8] += pocet;
                                        } else {
                                            if (bankovka == 5) {
                                                bankovky[9] += pocet;
                                            } else {
                                                if (bankovka == 2) {
                                                    bankovky[10] += pocet;
                                                } else {
                                                    if (bankovka == 1) {
                                                        bankovky[11] += pocet;
                                                    } else {
                                                        printf("8\n");
                                                        chyba();
                                                        return 1;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        *castka -= bankovka*pocet;
        scanf(" Kc%c", znak);
        if (znak != ',') {
            scanf(" %c", znak);
            if (znak != ']') {
                printf("%c\n", znak);
                printf("1\n");
                chyba();
                return 1;
            } else {
                break;
            }
        }
    }

    if (*castka > 0) {
        printf("2\n");
        chyba();
        return 1;
    }
    for (i = 0; i < 12; i++) {
        bankovkyREAL[i] += bankovky[i];
    }


    return 0;
}

int main(void) {
    int castka;
    int bankovky[12];
    int i;
    int flag = 1;
    int control;
    for (i = 0; i < 12; i++) {
        bankovky[i] = 0;
    }

    while (1) {
        if (control = nactiCastku(&castka) != 0) {
            if (control == -1) {
                break;
            }
            chyba();
            return 0;
        }

        if (nactiBankovky(bankovky, &castka) != 0) {
            printf("3\n");
            chyba();
            return 0;
        }
        printf("Kasa: [ ");
        for (i = 0; i < 12; i++) {
            if (bankovky[i] != 0) {
                switch (i) {
                    case 0: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx5000 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 1: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx2000 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 2: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx1000 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 3: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx500 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 4: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx200 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 5: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx100 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 6: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx50 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 7: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx20 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 8: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx10 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 9: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx5 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 10: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx2 Kc", bankovky[i]);
                        flag = 0;
                        break;
                    case 11: if (flag = 0) {
                            printf(", ");
                        }
                        printf("%dx1 Kc", bankovky[i]);
                        flag = 0;
                        break;
                }
            }
        }
        printf(" ]\n");
        printf("Spropitne: %d\n", castka);
    }

    return (EXIT_SUCCESS);
}

