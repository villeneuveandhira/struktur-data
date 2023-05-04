/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    // declaration
    list L;
    create_List(&L);
    barang minimarket;

    // input
    do {  // looping as long as the title is not '--stop--'
        scanf("%s", &minimarket.nama);
        if (strcmp(minimarket.nama, "--stop--") != 0) {
            scanf("%d %s", &minimarket.tgl_masuk, &minimarket.kode);
            add_Last(minimarket.nama, minimarket.tgl_masuk, minimarket.kode, &L);  // add at the last of the list, so the order is same
        }
    } while (strcmp(minimarket.nama, "--stop--") != 0);

    // kode barang yang dihapus
    sort_Kode(&L);  // sorting kode secara ascending sebelum menghapus data

    // list sisa barang
    printf("==== List Barang ====\n");
    sort_Tgl(&L);  // descending berdasarkan tanggal.
    printf("=====================\n");

    return 0;
}