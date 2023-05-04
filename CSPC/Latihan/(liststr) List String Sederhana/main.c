#include "header.h"

int main() {
    /*list*/
    list L;
    create_List(&L);

    /*init*/
    int i, n;
    scanf("%d", &n);  // n input
    char string[99];
    for (i = 0; i < n; i++) {  // input list string
        scanf("%s", &string);
        add_First(string, &L);
    }
    print_Element(L);  // print list

    return 0;
}