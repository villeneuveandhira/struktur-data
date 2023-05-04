/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 7
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    queue Q1, Q2;
    createEmpty(&Q1);
    createEmpty(&Q2);
    data game;
    int priority;

    printf("******************\n");

    scanf("%s %d", &game.nama, &game.nilai);
    add(game.nama, game.nilai, &Q1);
    scanf("%s %d", &game.nama, &game.nilai);
    add(game.nama, game.nilai, &Q1);
    scanf("%s %d", &game.nama, &game.nilai);
    addPriority(game.nama, game.nilai, 2, &Q1);
    printf("Queue 1\n");
    printQueue(Q1);

    printf("******************\n");

    del(&Q1, &Q2);
    printf("Queue 1\n");
    printQueue(Q1);

    printf("******************\n");

    printf("Queue 2\n");
    printQueue(Q2);

    printf("******************\n");

    scanf("%s %d", &game.nama, &game.nilai);
    addPriority(game.nama, game.nilai, 1, &Q1);
    scanf("%s %d", &game.nama, &game.nilai);
    addPriority(game.nama, game.nilai, 99, &Q1);
    printf("Queue 1\n");
    printQueue(Q1);

    printf("******************\n");

    del(&Q1, &Q2);
    del(&Q1, &Q2);
    scanf("%s %d", &game.nama, &game.nilai);
    add(game.nama, game.nilai, &Q1);
    printf("Queue 1\n");
    printQueue(Q1);

    printf("******************\n");

    printf("Queue 2\n");
    printQueue(Q2);

    printf("******************\n");

    return 0;
}