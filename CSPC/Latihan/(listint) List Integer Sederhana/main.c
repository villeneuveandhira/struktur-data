#include "header.h"

int main() {
    /*list*/
    list L;
    create_List(&L);

    /*init*/
    int i, n;
    scanf("%d", &n);  // n input
    int angka;
    for (i = 0; i < n; i++) {  // input list angka
        scanf("%d", &angka);
        add_First(angka, &L);
    }
    print_Element(L);  // print list

    return 0;
}