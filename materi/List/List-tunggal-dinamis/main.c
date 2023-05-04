#include "header.h"

int main() {
    list L;

    create_List(&L);
    print_Element(L);
    printf("====================\n");

    add_First("1", "orang_1", "A", &L);
    add_After(L.first, "2", "orang_2", "A", &L);
    add_Last("3", "orang_3", "A", &L);
    print_Element(L);
    printf("====================\n");

    del_Last(&L);
    del_After(L.first, &L);
    del_First(&L);
    print_Element(L);

    printf("====================\n");

    return 0;
}