/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 2 nomor 1
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    stack S;
    int n, m, i;
    char nama[51][99], kounter[51][99], daerah[51][99], kota[99];
    createEmpty(&S);

    // input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %s %s", &nama[i], &kounter[i], &daerah[i]);
    }
    for (i = n - 1; i >= 0; i--) {
        push(nama[i], kounter[i], daerah[i], &S, 0);
    }
    scanf("%d", &m);
    stack S2[m];
    for (i = 0; i < m; i++) {
        createEmpty(&S2[i]);
        scanf("%s", &kota);
        move(&S, &S2[i], m, n, kota);
    }
    printStack(S2, m);
    popAll(&S);

    return 0;
}