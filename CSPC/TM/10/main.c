/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 10
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    graph G;
    char hapus;

    /* =============================== */

    scanf(" %c", &hapus);
    createEmpty(&G);
    addSimpul('1', &G);
    addSimpul('2', &G);
    addSimpul('3', &G);
    addSimpul('4', &G);
    addSimpul('5', &G);
    addSimpul('6', &G);
    addSimpul('7', &G);
    addSimpul('8', &G);

    simpul *begin = findSimpul('5', G);
    simpul *end = findSimpul('6', G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end, 0);
    }
    begin = findSimpul('6', G);
    end = findSimpul('3', G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end, 0);
    }
    begin = findSimpul('3', G);
    end = findSimpul('8', G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end, 0);
    }
    end = findSimpul('1', G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end, 0);
    }
    end = findSimpul('7', G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end, 0);
    }
    begin = findSimpul('8', G);
    end = findSimpul('1', G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end, 0);
    }
    end = findSimpul('6', G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end, 0);
    }
    begin = findSimpul('7', G);
    end = findSimpul('4', G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end, 0);
    }
    begin = findSimpul('4', G);
    end = findSimpul('2', G);
    if ((begin != NULL) && (end != NULL)) {
        addJalur(begin, end, 0);
    }

    /* =============================== */

    printGraph(G);
    printf("==============\n");

    /* =============================== */

    delSimpul(hapus, &G);
    printGraph(G);

    return 0;
}