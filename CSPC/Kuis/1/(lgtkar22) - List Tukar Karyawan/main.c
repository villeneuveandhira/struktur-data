/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 1 nomor 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

/*program*/
int main() {
    // list
    list L_Satu, L_Dua;
    create_List(&L_Satu);
    create_List(&L_Dua);

    // input
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        karyawan pertama;
        scanf("%d %s %s", &pertama.id, &pertama.nama, &pertama.bagian);
        add_Last(pertama.id, pertama.nama, pertama.bagian, &L_Satu);
    }
    for (int i = 0; i < n; i++) {
        karyawan kedua;
        scanf("%d %s %s", &kedua.id, &kedua.nama, &kedua.bagian);
        add_Last(kedua.id, kedua.nama, kedua.bagian, &L_Dua);
    }

    // output
    swap(&L_Satu, &L_Dua);
    return 0;
}