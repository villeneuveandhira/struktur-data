#include "header.h"

int main() {
    list L;
    create_List(&L);
    print_Element(L);
    printf("====================\n");

    addFirst_Baris("1", "Orang_1", &L);
    addFirst_Kolom("IF40K1", "A", L.first);

    addAfter_Kolom(L.first->col, "IF40Z1", "A");
    addLast_Kolom("IF40Z2", "A", L.first);

    addAfter_Baris(L.first, "2", "Orang_2");
    addFirst_Kolom("TI5141", "A", L.first->next);
    addLast_Kolom("IF5021", "A", L.first->next);

    addLast_Baris("3", "Orang_3", &L);
    addFirst_Kolom("IF5321", "A", L.first->next->next);
    print_Element(L);
    printf("=================\n");
    dellAll_Baris(&L);
    print_Element(L);
    printf("=================\n");

    return 0;
}