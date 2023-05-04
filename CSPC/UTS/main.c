/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Tengah Semester
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    // list
    list L;
    createList(&L);

    // init
    int n, m, i, j;
    perusahan baris;
    obat kolom;
    eRow* point;
    int month, year;

    // input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%s %s", &baris.kodeP, &baris.namaP);
        addLastB(baris.kodeP, baris.namaP, &L);

        point = searchRow(baris.kodeP, L);

        scanf("%d", &m);
        for (j = 0; j < m; j++) {
            scanf("%s %s %d %d %s", &kolom.kodeO, &kolom.namaO, &kolom.bulan, &kolom.tahun, &kolom.jenis);
            addLastK(kolom.kodeO, kolom.namaO, kolom.bulan, kolom.tahun, kolom.jenis, point);
        }
    }

    addLastB("org", "OrganisasiBerwenang", &L);

    scanf("%d %d", &month, &year);
    searchCopy(month, year, &L);

    // output
    printElement(L);

    return 0;
}