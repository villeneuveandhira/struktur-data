/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Kuis 1 nomor 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

// procedure to create list
void create_List(list *L) {
    (*L).first = -1;
    (*L).tail = -1;
    for (int i = 0; i < 100; i++) {
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

// function to count element
int count_Element(list L) {
    int result = 0;
    if (L.first != -1) {
        int point;
        point = L.first;
        while (point != -1) {
            result++;
            point = L.data[point].next;
        }
    }
    return result;
}

// function to check empty element
int empty_Element(list L) {
    int result = -1;
    if (count_Element(L) < 100) {
        int found = 0;
        int i = 0;
        while ((found == 0) && (i < 100)) {
            if (L.data[i].next == -2) {
                result = i;
                found = 1;
            } else {
                i++;
            }
        }
    }
    return result;
}

// procedure for add first
void add_First(int id, char nama[], char bagian[], list *L) {
    if (count_Element(*L) < 100) {
        int new = empty_Element(*L);
        (*L).data[new].container.id = id;
        strcpy((*L).data[new].container.nama, nama);
        strcpy((*L).data[new].container.bagian, bagian);
        if ((*L).first == -1) {
            (*L).data[new].prev = -1;
            (*L).data[new].next = -1;
            (*L).tail = new;
        } else {
            (*L).data[new].prev = -1;
            (*L).data[new].next = (*L).first;
            (*L).data[(*L).first].prev = new;
        }
        (*L).first = new;
    } else {
        printf("List Full.\n");
    }
}

// procedure for add after
void add_After(int before, int id, char nama[], char bagian[], list *L) {
    if (count_Element(*L) < 100) {
        int new = empty_Element(*L);
        (*L).data[new].container.id = id;
        strcpy((*L).data[new].container.nama, nama);
        strcpy((*L).data[new].container.bagian, bagian);
        if ((*L).data[before].next != -1) {
            (*L).data[new].prev = before;
            (*L).data[new].next = (*L).data[before].next;
            (*L).data[before].next = new;
            (*L).data[(*L).data[new].next].prev = new;
        } else {
            (*L).data[new].prev = before;
            (*L).data[before].next = new;
            (*L).data[new].next = -1;
            (*L).tail = new;
        }
    } else {
        printf("List Full.\n");
    }
}

// procedure for add last
void add_Last(int id, char nama[], char bagian[], list *L) {
    if ((*L).first == -1) {
        add_First(id, nama, bagian, L);
    } else {
        add_After((*L).tail, id, nama, bagian, L);
    }
}

// procedure for delete first
void del_First(list *L) {
    if ((*L).first != -1) {
        int delete = (*L).first;
        if (count_Element(*L) == 1) {
            (*L).first = -1;
            (*L).tail = -1;
        } else {
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = -1;
        }
        (*L).data[delete].prev = -2;
        (*L).data[delete].next = -2;
    } else {
        printf("List Kosong.\n");
    }
}

// procedure for delete after
void del_After(int before, list *L) {
    int delete = (*L).data[before].next;
    if (delete != -1) {
        if ((*L).data[delete].next == -1) {
            (*L).tail = before;
            (*L).data[before].next = -1;
        } else {
            (*L).data[before].next = (*L).data[delete].next;
            (*L).data[(*L).data[delete].next].prev = before;
        }
        (*L).data[delete].prev = -2;
        (*L).data[delete].next = -2;
    }
}

// procedure for delete last
void del_Last(list *L) {
    if ((*L).first != -1) {
        if (count_Element(*L) == 1) {
            del_First(L);
        } else {
            del_After((*L).data[(*L).tail].prev, L);
        }
    } else {
        printf("List Kosong.\n");
    }
}

// procedure for delete all
void del_All(list *L) {
    for (int i = count_Element(*L); i >= 1; i--) {
        del_Last(L);
    }
}

// procedure to print element
void print_Element(list L) {
    if (L.first != -1) {
        int point = L.first, i = 1;
        while (point != -1) {
            printf("%d %s %s\n", L.data[point].container.id, L.data[point].container.nama, L.data[point].container.bagian);
            point = L.data[point].next;
            i++;
        }
    } else {
        printf("List Kosong.\n");
    }
}

// procedure for swap
void swap(list *L1, list *L2) {
    // init
    int depan = (*L1).first;
    int belakang = (*L2).tail;
    karyawan temp;

    // process
    for (int i = 0; i < count_Element(*L1) / 2; i++) {
        // id
        temp.id = (*L1).data[depan].container.id;
        (*L1).data[depan].container.id = (*L2).data[belakang].container.id;
        (*L2).data[belakang].container.id = temp.id;
        // nama
        strcpy(temp.nama, (*L1).data[depan].container.nama);
        strcpy((*L1).data[depan].container.nama, (*L2).data[belakang].container.nama);
        strcpy((*L2).data[belakang].container.nama, temp.nama);
        // bagian
        strcpy(temp.bagian, (*L1).data[depan].container.bagian);
        strcpy((*L1).data[depan].container.bagian, (*L2).data[belakang].container.bagian);
        strcpy((*L2).data[belakang].container.bagian, temp.bagian);

        // iteration
        depan = (*L1).data[depan].next;
        belakang = (*L2).data[belakang].prev;
    }

    // print
    print_Element(*L1);
    print_Element(*L2);
}