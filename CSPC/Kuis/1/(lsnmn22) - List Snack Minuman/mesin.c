/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 1 nomor _
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

// procedure to create list
void create_List(list* L) {
    L->first = NULL;
}

// funtion to count element in list
int count_Element(list L) {
    int result = 0;
    if (L.first != NULL) {
        element* point;
        point = L.first;
        while (point != NULL) {
            result++;
            point = point->next;
        }
    }
    return result;
}

// procedure for add first
void add_First(char type[], char name[], int price, list* L) {
    element* new;
    new = (element*)malloc(sizeof(element));
    strcpy(new->data.type, type);
    strcpy(new->data.name, name);
    new->data.price = price;
    if (L->first == NULL) {
        new->next = NULL;
    } else {
        new->next = L->first;
    }
    L->first = new;
    new = NULL;
}

// procedure for add after
void add_After(element* prev, char type[], char name[], int price, list* L) {
    element* new;
    new = (element*)malloc(sizeof(element));
    strcpy(new->data.type, type);
    strcpy(new->data.name, name);
    new->data.price = price;
    if (prev->next == NULL) {
        new->next = NULL;
    } else {
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}

// procedure for add last
void add_Last(char type[], char name[], int price, list* L) {
    if (L->first == NULL) {
        add_First(type, name, price, L);
    } else {
        element* prev = L->first;
        while (prev->next != NULL) {
            prev = prev->next;
        }
        add_After(prev, type, name, price, L);
    }
}

// procedure for delete first
void del_First(list* L) {
    if (L->first != NULL) {
        element* delete = L->first;
        if (count_Element(*L) == 1) {
            L->first = NULL;
        } else {
            L->first = L->first->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

// procedure for delete after
void del_After(element* prev, list* L) {
    element* delete = prev->next;
    if (delete != NULL) {
        if (delete->next == NULL) {
            prev->next = NULL;
        } else {
            prev->next = delete->next;
            delete->next = NULL;
        }
        free(delete);
    }
}

// procedure for delete last
void del_Last(list* L) {
    if (L->first != NULL) {
        if (count_Element(*L) == 1) {
            del_First(L);
        } else {
            element* last = L->first;
            element* prev;
            while (last->next != NULL) {
                prev = last;
                last = last->next;
            }
            del_After(prev, L);
        }
    }
}

// procedure for delete all
void del_All(list* L) {
    if (count_Element(*L) != 0) {
        for (int i = count_Element(*L); i >= 1; i--) {
            del_Last(L);
        }
    }
}

// procedure to print element
void print_Element(list L) {
    if (L.first != NULL) {
        element* point = L.first;
        int i = 1;
        while (point != NULL) {
            printf("%s %s %d\n", point->data.type, point->data.name, point->data.price);
            point = point->next;
            i++;
        }
    } else {
        printf("List Kosong.\n");
    }
}

// function to find pointer in element
element* get_Address(char type[], list L) {
    element* current = L.first;                       // start from the first element
    while (current != NULL) {                         // loop to the end of list
        if (strcmp(current->data.type, type) == 0) {  // if current data is same as data in the list
            return current;                           // return pointer current
            break;                                    // also break the loop
        }
        current = current->next;  // iteration
    }
    return NULL;  // if function didn't find same data, then NULL
}

// function to get last element pointer from list
element* get_Last(list L) {
    element* current = L.first;      // start from the first element
    while (current->next != NULL) {  // loop till the end
        current = current->next;     // iteration
    }
    return current;
}

// function to find the previous element
element* get_Prev(element* point, list L) {
    element* prev = L.first;  // init
    if (point == L.first) {   // if it's the first element
        return NULL;          // it means there is no prev
    }
    while (prev->next != point) {
        prev = prev->next;  // iteration
    }
    return prev;
}

// function to swap pointer from elemen A to B
void swap(element* A, element* B, list* L1, list* L2) {
    // find the pointer elemen A & B
    element* prev1 = get_Prev(A, *L1);
    element* prev2 = get_Prev(B, *L2);

    // find the last element from list
    element* last1 = get_Last(*L1);
    element* last2 = get_Last(*L2);

    if (A == last1) {     // jika A elemen terakhir dari list 1
        prev1->next = B;  // set pointer next elemen sebelum A ke B
    } else {              // jika bukan
        last1->next = B;  // set pointer next elemen terakhir dari list 1 ke B
    }
    if (B == last2) {     // jika B elemen terakhir dari list 2
        prev2->next = A;  // set pointer next elemen sebelum B ke A
    } else {              // jika bukan
        last2->next = A;  // set pointer next elemen terakhir dari list 2 ke A
    }
    if (prev1 == NULL) {        // jika A merupakan elemen pertama dari list 1
        L1->first = A->next;    // set pointer first list pertama ke elemen setelah A
    } else if (A != last1) {    // jika A bukan elemen pertama dan terakhir dari list 1
        prev1->next = A->next;  // set pointer next elemen sebelum A ke elemen sesudah A
    }
    if (prev2 == NULL) {        // jika B merupakan elemen pertama dari list 2
        L2->first = B->next;    // set pointer first list kedua ke elemen setelah B
    } else if (B != last2) {    // jika B bukan elemen pertama dan terakhir dari list 2
        prev2->next = B->next;  // set pointer next elemen sebelum B ke elemen sesudah B
    }
    A->next = NULL;
    B->next = NULL;
}