#include <stdio.h>
#include <stdlib.h>

int chyba(void) {
    printf("Zadal jste spatny vstup\n");
    return 0;
}
typedef struct vstupy {
    double dlazka;
    double spara;
} VSTUPY;

int cmpfunc (const void * a, const void * b) {
   return ( *(double*)a - *(double*)b );
}
/*
void kontrola(double pole[], int v, double s, double *w){
    int i;
    *w = 1;
    for (i = 0; i <= (v)*2; i= i+2) {
        *w = (*w)*pole[i];
    }
    
    *w = (*w)*(ceil((s)/(*w)))*100;   
}


void kontrola(double pole[], int *v, double *s, double *w){
    int i;
    *w = 1;
    for (i = 0; i <= (*v)*2; i= i+2) {
        *w = (*w)*pole[i];
    }
    
    *w = (*w)*(ceil((*s)/(*w)));   
}


double epsilon(void) {
    double d = 1;
    while (1.0 + d / 2 != 1.0) {
        d = d / 2;
    }
    return d;
}

double souradnice(double * x, double * y) {

    if (scanf("[%lf,%lf]", &*x, &*y) != 2) {
        while (scanf("[%lf,%lf]", &*x, &*y) != 2) {
            fgetc(stdin);
        }
    }


    return 0;
}



int souradnice(double * x) {

    if (scanf("%lf", &*x) != 1) {
        return 1;
    }
    return 0;
}

int zadavacka(double * x) {
    int v;

    while (scanf("%lf", &*x) != 1) {
        v = fgetc(stdin);

        while (v != 10) {
            v = fgetc(stdin);
        }
        printf("Zadal jste spatny vstup, pokuste se ho opravit\n");
    }
    return 0;
}

int znak(void) {
    int a;
    if (scanf("%d", &a) != 1) {
        while (scanf("%d", &a) != 1) {
            if (fgetc(stdin) != '[') {
                chyba();
                return 1;
            } else {
                printf("paradis\n");
                return 0;
            }
        }
    } else {
        chyba();
        return 1;
    }
    return 1;
}


int cti(double pole[], int v) {
    int i;
    printf("vase pole:\n");
    for (i = 0; i < v; i++) {
        printf("%.1f\n", pole[i]);
    }
    return 0;
}

/*int nacpole(double pole[], int *v) {
    int i = 0;
    printf("vyplnte vstup: (%d) \n", MAX_LEN);
    for (i; i < MAX_LEN; i = i + 2) {
        if ((*v = scanf("%lf", &pole[i])) != 1) {
            printf("v1 = %d\n", *v);
            if (*v != -1) {
                return 1;
            } else {
                *v = i;
                return 0;
            }

        }

        if ((*v = scanf("%lf", &pole[i + 1])) != 1) {
            printf("v2 = %d\n", *v);
            if (*v != -1) {
                return 1;
            } else {
                *v = i + 1;
                return 0;
            }


        }
    }
    return 0;
}

int nsn(int *n1, int *n2) {
    
    int i, gcd, lcm;

    

    for(i=1; i <= *n1 && i <= *n2; ++i)
    {
        // Checks if i is factor of both integers
        if(*n1%i==0 && *n2%i==0)
            gcd = i;
    }
    printf("gcd %d\n", gcd);

    lcm = ((*n1)*(*n2))/gcd;
    printf("The LCM of two numbers %d and %d is %d.", *n1, *n2, lcm);

    return 0;
}

int main(void) {
    double xa, ya, xb, yb, xc, yc, xa1, ya1, xb1, yb1, xc1, yc1;
    int a = 161;
    int b = 101;
    nsn(&a,&b);
   

    return 0;
}
*/
int main(void) {
    // VSTUPY pole[] = {9.2, 1, 2.6, 8.2, 7, 6};
    // int i;
    
    
    // for (i = 0; i < 3; i++) {
    //     printf("%.1f %.1f\n", pole[i].dlazka, pole[i].spara);   
    // }
    qsort(pole,3,sizeof(VSTUPY),cmpfunc);
    
    printf("\n");
    
    for (i = 0; i < 3; i++) {
        printf("%.1f %.1f\n", pole[i].dlazka, pole[i].spara);   
    }
    double mnozina[6];
    
    printf("\n");
    
    for (i=0; i < 3; i++) {
        mnozina[i*2]= pole[i].dlazka;
        mnozina[i*2+1] = pole[i].spara;
    }
    
    for (i = 0; i < 6; i++) {
        printf("%.1f\n", mnozina[i]);   
    }
    
         
    return 0;
}