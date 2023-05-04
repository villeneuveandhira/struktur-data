/*Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Akhir Semester
Graf Jalur Langsung Tak Langsung (gjltl22)
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    /*init*/
    graph G;
    createEmpty(&G);
    node *begin, *end;
    int n;         // integer banyaknya jalur dari graf
    int flag = 0;  // proses pencarian
    int iterasi = 0;

    /*input*/
    scanf("%d", &n);
    char jalur[n + 10][n + 10];
    char awal, akhir;
    for (int i = 0; i < n; i++) {
        scanf(" %c %c", &awal, &akhir);
        if (findNode(awal, G) == NULL) {
            addNode(awal, &G);
        }
        if (findNode(akhir, G) == NULL) {
            addNode(akhir, &G);
        }
        begin = findNode(awal, G);
        end = findNode(akhir, G);
        addLane(begin, end, 0);
    }
    scanf(" %c %c", &awal, &akhir);

    int i = 0, j = -1;
    begin = findNode(awal, G);

    /*output*/
    pathing(begin, &jalur, &i, &j, &iterasi, &flag, awal, akhir);

    return 0;
}