/*
Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan remedial dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/

/*lib*/
#include "header.h"

int main() {
    // init
    list L;
    create_List(&L);
    int i, j, n, k;
    peserta data;
    bahan list;

    // input banyak peserta
    scanf("%d", &n);
    eBaris *point;
    for (i = 0; i < n; i++) {
        // input nama peserta
        scanf("%s %d", &data.nama, &data.banyak);
        addLast_Baris(data.nama, data.banyak, &L);
        if (i == 0) {
            point = L.first;
        } else {
            point = point->next;
        }
        // input bahan
        for (j = 0; j < data.banyak; j++) {
            scanf("%s %d", &list.namaBahan, &list.berat);
            addLast_Kolom(list.namaBahan, list.berat, point);
        }
    }

    // input banyak tukar
    scanf("%d", &k);
    char tukarNama_Satu[k][99], tukarBahan_Satu[k][99], tukarNama_Dua[k][99], tukarBahan_Dua[k][99];
    for (i = 0; i < k; i++) {
        // input tukar data
        scanf("%s %s %s %s", &tukarNama_Satu[i], &tukarBahan_Satu[i], &tukarNama_Dua[i], &tukarBahan_Dua[i]);
        // searchCopy(tukarNama_Satu[i], tukarBahan_Satu[i], &L);
    }

    // output
    print_Element(L);
    // for (i = 0; i < k; i++) {
    //     printf("%s %s %s %s\n", tukarNama_Satu[i], tukarBahan_Satu[i], tukarNama_Dua[i], tukarBahan_Dua[i]);
    // }

    return 0;
}