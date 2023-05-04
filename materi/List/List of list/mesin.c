#include "header.h"

void create_List(list* L) {
    (*L).first = NULL;
}

int countElement_Baris(list L) {
    int result = 0;
    if (L.first != NULL) {
        eBaris* point;
        point = L.first;
        while (point != NULL) {
            result++;
            point = point->next;
        }
    }
    return result;
}
int countElemen_Kolom(eBaris L) {
    int result = 0;
    if (L.col != NULL) {
        eKolom* point;
        point = L.col;
        while (point != NULL) {
            result++;
            point = point->next_Kol;
        }
    }
    return result;
}

void addFirst_Baris(char nim[], char nama[], list* L) {
    eBaris* new;
    new = (eBaris*)malloc(sizeof(eBaris));
    strcpy(new->container.nim, nim);
    strcpy(new->container.nama, nama);
    new->col = NULL;
    if ((*L).first == NULL) {
        new->next = NULL;
    } else {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}
void addFirst_Kolom(char kode[], char nilai[], eBaris* L) {
    eKolom* new;
    new = (eKolom*)malloc(sizeof(eKolom));
    strcpy(new->container_Kol.kode, kode);
    strcpy(new->container_Kol.nilai, nilai);
    if ((*L).col == NULL) {
        new->next_Kol = NULL;
    } else {
        new->next_Kol = (*L).col;
    }
    (*L).col = new;
    new = NULL;
}

void addAfter_Baris(eBaris* prev, char nim[], char nama[]) {
    eBaris* new;
    new = (eBaris*)malloc(sizeof(eBaris));
    strcpy(new->container.nim, nim);
    strcpy(new->container.nama, nama);
    new->col = NULL;
    if (prev->next == NULL) {
        new->next = NULL;
    } else {
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}
void addAfter_Kolom(eKolom* prev, char kode[], char nilai[]) {
    eKolom* new;
    new = (eKolom*)malloc(sizeof(eKolom));
    strcpy(new->container_Kol.kode, kode);
    strcpy(new->container_Kol.nilai, nilai);
    if (prev->next_Kol == NULL) {
        new->next_Kol = NULL;
    } else {
        new->next_Kol = prev->next_Kol;
    }
    prev->next_Kol = new;
    new = NULL;
}

void addLast_Baris(char nim[], char nama[], list* L) {
    if ((*L).first == NULL) {
        addFirst_Baris(nim, nama, L);
    } else {
        eBaris* last = (*L).first;
        while (last->next != NULL) {
            last = last->next;
        }
        addAfter_Baris(last, nim, nama);
    }
}
void addLast_Kolom(char kode[], char nilai[], eBaris* L) {
    if ((*L).col == NULL) {
        addFirst_Kolom(kode, nilai, L);
    } else {
        eKolom* last = (*L).col;
        while (last->next_Kol != NULL) {
            last = last->next_Kol;
        }
        addAfter_Kolom(last, kode, nilai);
    }
}

void delFirst_Kolom(eBaris* L) {
    if ((*L).col != NULL) {
        eKolom* del = (*L).col;
        if (countElemen_Kolom(*L) == 1) {
            (*L).col = NULL;
        } else {
            (*L).col = (*L).col->next_Kol;
            del->next_Kol = NULL;
        }
        free(del);
    }
}
void delAfter_Kolom(eKolom* prev) {
    eKolom* del = prev->next_Kol;
    if (del != NULL) {
        if (del->next_Kol == NULL) {
            prev->next_Kol = NULL;
        } else {
            prev->next_Kol = del->next_Kol;
            del->next_Kol = NULL;
        }
        free(del);
    }
}
void delLast_Kolom(eBaris* L) {
    if ((*L).col != NULL) {
        if (countElemen_Kolom(*L) == 1) {
            delFirst_Kolom(L);
        } else {
            eKolom* last = (*L).col;
            eKolom* before_Last;
            while (last->next_Kol != NULL) {
                before_Last = last;
                last = last->next_Kol;
            }
            delAfter_Kolom(before_Last);
        }
    }
}
void delAll_Kolom(eBaris* L) {
    if (countElemen_Kolom(*L) != 0) {
        for (int i = countElemen_Kolom(*L); i >= 1; i--) {
            delLast_Kolom(L);
        }
    }
}

void delFirst_Baris(list* L) {
    if ((*L).first != NULL) {
        eBaris* del = (*L).first;
        if (del->col != NULL) {
            delAll_Kolom(del);
        }
        if (countElement_Baris(*L) == 1) {
            (*L).first = NULL;
        } else {
            (*L).first = (*L).first->next;
        }
        del->next = NULL;
        free(del);
    } else {
        printf("list kosong\n");
    }
}
void delAfter_Baris(eBaris* prev) {
    if (prev != NULL) {
        eBaris* del = prev->next;
        if (del != NULL) {
            if (del->col != NULL) {
                delAll_Kolom(del);
            }
            if (del->next == NULL) {
                prev->next = NULL;
            } else {
                prev->next = del->next;
            }
            del->next = NULL;
            free(del);
        }
    }
}
void delLast_Baris(list* L) {
    if ((*L).first != NULL) {
        if (countElement_Baris(*L) == 1) {
            delFirst_Baris(L);
        } else {
            eBaris* last = (*L).first;
            eBaris* before_Last;
            while (last->next != NULL) {
                before_Last = last;
                last = last->next;
            }
            delAfter_Baris(before_Last);
        }
    }
}
void dellAll_Baris(list* L) {
    if (countElement_Baris(*L) != 0) {
        for (int i = countElement_Baris(*L); i >= 1; i--) {
            delLast_Baris(L);
        }
    }
}

void print_Element(list L) {
    if (L.first != NULL) {
        eBaris* point = L.first;
        int i = 1;
        while (point != NULL) {
            printf("elemen ke : %d\n", i);
            printf("nim : %s\n", point->container.nim);
            printf("nama : %s\n", point->container.nama);

            eKolom* eCol = point->col;
            while (eCol != NULL) {
                printf("kode kuliah : %s\n", eCol->container_Kol.kode);
                printf("nilai : %s\n", eCol->container_Kol.nilai);
                eCol = eCol->next_Kol;
            }
            printf("------------\n");
            point = point->next;
            i = i + 1;
        }
    } else {
        printf("list kosong\n");
    }
}
