/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 2 nomor 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    queue Q1, Q2;
    int n, m, i;
    data mahasiswa;
    createEmpty(&Q1);
    createEmpty(&Q2);

    // input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %d %d", &mahasiswa.nama, &mahasiswa.urut, &mahasiswa.smt);
        addPriority(mahasiswa.nama, mahasiswa.urut, mahasiswa.smt, &Q1);
    }

    scanf("%d", &m);
    move(&Q1, &Q2, m);

    // output
    printf("sudah mendapat beasiswa:\n");
    printQueue(Q2);
    printf("belum mendapat beasiswa:\n");
    printQueue(Q1);

    return 0;
}