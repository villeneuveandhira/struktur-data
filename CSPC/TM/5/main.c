/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 5
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

int main() {
    list L;
    createList(&L);
    box input;
    barang data;

    /* input */
    int n;
    scanf("%d", &n);
    eBaris* point;
    for (int i = 0; i < n; i++) {
        scanf("%s %s", &input.label, &input.code);
        addLastB(input.label, input.code, &L);
        if (i == 0) {
            point = L.first;
        } else {
            point = point->next;
        }
        // input kolom
        scanf("%s", &data.nama);
        addFirstK(data.nama, point);
        scanf("%s", &data.nama);
        addLastK(data.nama, point);
        scanf("%s", &data.nama);
        addAfterK(point->col->next_kol, data.nama);
        scanf("%s", &data.nama);
        addFirstK(data.nama, point);
    }
    delAfterK(L.first->next->col->next_kol);
    delFirstB(&L);
    delFirstK(L.first);
    printElement(L);
    delAllB(&L);
    printElement(L);

    return 0;
}