/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 6
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    // stack
    stack S1, S2;
    createEmpty(&S1);
    createEmpty(&S2);
    food input;

    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S1);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S2);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S2);
    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    pop(&S1);
    popMove(&S2, &S1);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S1);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S2);
    scanf("%s %d", &input.nama, &input.harga);
    push(input.nama, input.harga, &S1);
    pop(&S2);
    popMove(&S1, &S2);
    printf("S1:\n");
    printStack(S1);
    printf("S2:\n");
    printStack(S2);
    printf("==================\n");

    return 0;
}