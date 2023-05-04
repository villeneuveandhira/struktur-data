/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 2
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

// procedure to create list
void create_List(list *L) {
    (*L).first = NULL;
    (*L).tail = NULL;
}

// function to count element
int count_Element(list L) {
    int result = 0;
    if (L.first != NULL) {
        element *point;
        point = L.first;
        while (point != NULL) {
            result++;
            point = point->next;
        }
    }
    return result;
}

// procedure for add first
void add_First(char nama[], int tgl_masuk, char kode[], list *L) {
    element *new;
    new = (element *)malloc(sizeof(element));
    strcpy(new->container.nama, nama);
    new->container.tgl_masuk = tgl_masuk;
    strcpy(new->container.kode, kode);
    if ((*L).first == NULL) {
        new->prev = NULL;
        new->next = NULL;
        (*L).tail = new;
    } else {
        new->prev = (*L).first;
        new->next = NULL;
        (*L).first->prev = new;
    }
    (*L).first = new;
    new = NULL;
}

// procedure for add after
void add_After(element *before, char nama[], int tgl_masuk, char kode[], list *L) {
    if (before != NULL) {
        element *new;
        new = (element *)malloc(sizeof(element));
        strcpy(new->container.nama, nama);
        new->container.tgl_masuk = tgl_masuk;
        strcpy(new->container.kode, kode);
        if (before->next == NULL) {
            new->next = NULL;
            (*L).tail = new;
        } else {
            new->next = before->next;
            new->next->prev = new;
        }
        new->prev = before;
        before->next = new;
        new = NULL;
    }
}

// procedure for add last
void add_Last(char nama[], int tgl_masuk, char kode[], list *L) {
    if ((*L).first == NULL) {
        add_First(nama, tgl_masuk, kode, L);
    } else {
        add_After((*L).tail, nama, tgl_masuk, kode, L);
    }
}

// procedure for delete first
void del_First(list *L) {
    if ((*L).first != NULL) {
        element *del = (*L).first;
        if (count_Element(*L) == 1) {
            (*L).first = NULL;
            (*L).tail = NULL;
        } else {
            (*L).first = (*L).first->next;
            (*L).first->prev = NULL;
            del->next = NULL;
        }
        free(del);
    }
}

// procedure for delete after
void del_After(element *before, list *L) {
    element *del = before->next;
    if (del != NULL) {
        if (del->next == NULL) {
            L->tail = before;
            before->next = NULL;
        } else {
            before->next = del->next;
            del->next->prev = before;
        }
        del->prev = NULL;
        del->next = NULL;
    }
}

// procedure for delete last
void del_Last(list *L) {
    if ((*L).first != NULL) {
        if (count_Element(*L) == 1) {
            del_First(L);
        } else {
            del_After((*L).tail->prev, L);
        }
    }
}

// procedure for print list 'delete'
void print_Delete(list *L) {
    if (L->first != NULL) {
        /*init*/
        element *point = L->first;
        while (point != NULL) {
            if (point->container.tgl_masuk % 5 == 0) {                  // kondisi jika tgl_masuk = kelipatan 5
                printf("%s telah dihapus.\n", &point->container.kode);  // jika kelipatan 5, print dahulu
                point = point->next;                                    // iterasi
                /* kemudian cek posisi data */
                if (point == NULL) {                   // jika data = elemen terakhir
                    del_Last(L);                       // pakai delete last
                } else if (point->prev == L->first) {  // jika data = elemen pertama
                    del_First(L);                      // pakai delete first
                } else {                               // jika berada ditengah
                    del_After(point->prev->prev, L);   // pakai delete after
                }
            } else {                  // tgl_masuk != kelipatan 5
                point = point->next;  // iterasi
            }
        }
    }
}

// procedure for print list 'sisa barang'
void print_Element(list L) {
    element *point = L.tail;
    while (point != NULL) {
        printf("%s %s\n", point->container.kode, point->container.nama);
        point = point->prev;
    }
}

// procedure for sorting "Kode"
void sort_Kode(list *L) {
    element *before, *after;                                                     // pointer for before, after element
    element *curr;                                                               // pointer for current element
    int sorted = 0;                                                              // mark as swapped (0 = false, 1 = true)
    while (sorted == 0) {                                                        // loop as long as there is no swapped pointer
        sorted = 1;                                                              // mark list sorted
        curr = L->first;                                                         // current pointer start from the beginning of list
        while (curr->next != NULL) {                                             // current pointer will stop at the end of the list
            if (strcmp(curr->container.kode, curr->next->container.kode) > 0) {  // check value ascending (kode)
                before = curr->prev;                                             //"before" pointer
                after = curr->next;                                              //"after" pointer
                if (before != NULL) {                                            // if current is not at beginning of list
                    before->next = after;                                        // set as after
                } else {                                                         // current is at beginning of list
                    L->first = after;                                            // set as after
                }
                curr->next = after->next;  // points to after next
                if (after->next != NULL) {
                    after->next->prev = curr;  // sets prev pointer for current
                } else {
                    L->tail = curr;  // handling if current is the last element
                }
                curr->prev = after;  // points to what after pointed
                after->next = curr;  // places node after next one
                after->prev = before;
                /* mark as the list is not sorted */
                sorted = 0;
            } else {
                curr = curr->next;  // iteration
            }
        }
    }
    print_Delete(L);
}

// procedure for sorting "Tanggal_Masuk"
void sort_Tgl(list *L) {
    if (L->first != NULL) {
        /* same as sort_Kode, but only different at comparing data*/
        element *before, *after;
        element *curr;
        int sorted = 0;
        while (sorted == 0) {
            sorted = 1;
            curr = L->first;
            while (curr->next != NULL) {
                if (curr->container.tgl_masuk > curr->next->container.tgl_masuk) {
                    before = curr->prev;
                    after = curr->next;
                    if (before != NULL) {
                        before->next = after;
                    } else {
                        L->first = after;
                    }
                    curr->next = after->next;
                    if (after->next != NULL) {
                        after->next->prev = curr;
                    } else {
                        L->tail = curr;
                    }
                    curr->prev = after;
                    after->next = curr;
                    after->prev = before;
                    sorted = 0;
                } else {
                    curr = curr->next;
                }
            }
        }
        print_Element(*L);
    } else {
        printf("Listnya kosong nihh..\n");
    }
}