/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 1 nomor _
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

/*program*/
int main() {
    // List
    list L_Satu, L_Dua;
    create_List(&L_Satu);
    create_List(&L_Dua);

    // integer jumlah elemen list
    int n1, n2;

    // input
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        perusahaan pertama;
        scanf("%s %s %d", &pertama.type, &pertama.name, &pertama.price);
        add_Last(pertama.type, pertama.name, pertama.price, &L_Satu);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        perusahaan kedua;
        scanf("%s %s %d", &kedua.type, &kedua.name, &kedua.price);
        add_Last(kedua.type, kedua.name, kedua.price, &L_Dua);
    }

    // process
    char jenis[101], apa[101];
    scanf("%s %s", &jenis, &apa);

    print_Element(L_Satu);
    print_Element(L_Dua);

    for (int i = 0; i < n1; i++) {
        // init
        int x = 0;
        perusahaan temp;
        // first, find the element.
        element* swap1 = get_Address("minuman", L_Satu);  // find type "minuman" in List_Satu
        if (swap1 == NULL) {                              // if  it's not in List_Satu
            x = 1;                                        // list satu/dua
            swap1 = get_Address("snack", L_Dua);          // find in list_Dua
        }
        element* swap2 = get_Address("snack", L_Satu);  // find type "minuman" in List_Dua
        if (swap2 == NULL) {                            // if it's not in list_Satu
            swap2 = get_Address("minuman", L_Dua);      // find in list_Dua
        }
        // next step.
        if (x == 0) {  // if the order is "minuman" in list_Satu & "snack" in list_Dua
            swap(swap1, swap2, &L_Satu, &L_Dua);
        } else {
            swap(swap2, swap1, &L_Satu, &L_Dua);
        }
    }

    for (int i = 0; i < n2; i++) {
        // init
        int x = 0;
        perusahaan temp;
        // first, find the element.
        element* swap1 = get_Address("minuman", L_Satu);  // find type "minuman" in List_Satu
        if (swap1 == NULL) {                              // if  it's not in List_Satu
            x = 1;                                        // list satu/dua
            swap1 = get_Address("snack", L_Dua);          // find in list_Dua
        }
        element* swap2 = get_Address("snack", L_Satu);  // find type "minuman" in List_Dua
        if (swap2 == NULL) {                            // if it's not in list_Satu
            swap2 = get_Address("minuman", L_Dua);      // find in list_Dua
        }
        // next step.
        if (x == 0) {  // if the order is "minuman" in list_Satu & "snack" in list_Dua
            swap(swap1, swap2, &L_Satu, &L_Dua);
        } else {
            swap(swap2, swap1, &L_Satu, &L_Dua);
        }
    }

    print_Element(L_Satu);
    print_Element(L_Dua);
    return 0;
}