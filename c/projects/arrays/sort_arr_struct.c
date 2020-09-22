/*
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//printf("A=%d, Z=%d, a=%d, z=%d, Z-A+1=%d\n", (int) 'A', (int) 'Z', (int) 'a', (int) 'z', ((int) 'Z' - (int) 'A') + 1);
#define LETTERS_NUMBER 26
#define ASCII_LETTERS_OFFSET 65

typedef struct item {
    unsigned long int key;
    char name[20];
    int count;
} ITEM;

int double_cmp (const void * a, const void * b) 
{
    return ( *(double*)a - *(double*)b );
}

int items_cmp (const void * a, const void * b) 
{
    return ( ((ITEM*)a)->key - ((ITEM*)b)->key );
}


void init_items(ITEM *items, int items_num)
{
    int lett_offset = ASCII_LETTERS_OFFSET;
    int lett_num = LETTERS_NUMBER;

    /* Intializes random number generator */
    srand((unsigned) time(0));

    int i;
    for (i = 0; i < items_num; i++) {
        items[i].key = rand();
        items[i].name[0] = (char) (lett_offset + (rand() % lett_num));
        items[i].name[1] = (char) (lett_offset + (rand() % lett_num));
        items[i].name[2] = '\0';
        items[i].count = 1;
    }
}

void print_items(ITEM *items, int items_len)
{
    int i;
    for (i = 0; i < items_len; i++) {
        printf("Item, key: %lu, name: %s, count: %d\n", items[i].key, items[i].name, items[i].count);
    }
    printf("\n");
}

int main(int argc, char** argv)
{
    int items_num = 3;
    ITEM items[items_num];

    init_items(items, items_num);

    print_items(items, items_num);

    qsort(items, items_num, sizeof(items[0]), items_cmp);

    print_items(items, items_num);

    return EXIT_SUCCESS;
}
