/* File:   main.c
 * Author: langer
 *
 * Created on 29 December 2017, 12:05 */

#define MAX 100
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
 * TODO: broken, after question, what differs my animal from given, the dialog did not respond correctly. 
 */

typedef struct TNode {
    char text[MAX];
    struct TNode *yes, *no;
} TNODE;

TNODE *createNode(char *text, TNODE *yes, TNODE *no) {
    TNODE *n = (TNODE*) malloc(sizeof (*n));
    strncpy(n->text, text, sizeof (n->text));
    n->yes = yes;
    n->no = no;
    return n;
}

int isLeaf(TNODE * n) {
    return n->yes == NULL && n->no == NULL;
}

int positiveAns(void) {
    char ans[20];
    scanf("%19s", ans);
    /* porovn ́an ́ı ˇretˇezc ̊u, velk ́a = mal ́a p ́ısmena */
    return !strcasecmp(ans, "ano");
}

TNODE *initTree(void) {
    return createNode("Leta?",
            createNode("ptak", NULL, NULL),
            createNode("ryba", NULL, NULL));
}

void delTree(TNODE * n) {/* rekurzivn ́ı uvolnˇen ́ı stromu */
    if (!n) return;
    delTree(n->yes);
    delTree(n->no);
    free(n);
}

void updateKnowledge(TNODE *p) {
    char newAnim[MAX], newQue[MAX];
    printf("Neuhadl jsem."
        "Prosim o doplneni me baze znalosti:\n");
    printf("Jake zvire jsi myslel?\n");
    scanf("%99s", newAnim);
    printf("Otazka vystihujici rozdil mezi %s a %s?\n",
            newAnim, p->text);
    scanf("%99s", newQue);
    printf("Jaka odpoved je pro %s?\n", newAnim);
    if (positiveAns()) {
        p->yes = createNode(newAnim, NULL, NULL);
        p->no = createNode(p->text, NULL, NULL);
    } else {
        p->no = createNode(newAnim, NULL, NULL);
        p->yes = createNode(p->text, NULL, NULL);
    }
    strncpy(p->text, newQue, sizeof ( p->text));
}

int main(void) {
    TNODE *root = initTree();
    do {
        TNODE * node = root;
        printf("Vyber si nejake zvire. Ja ho uhodnu.\n");
        while (!isLeaf(node)) {
            printf("%s\n", node->text);
            if (positiveAns()) node = node->yes;
            else node = node->no;
        }
        printf("Je to %s?\n", node->text);
        if (!positiveAns()) updateKnowledge(node);
        printf("Chces pokracovat?\n");
    } while (positiveAns());
    delTree(root);
    return 0;
}

