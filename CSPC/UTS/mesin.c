/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Tengah Semester
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

// to create list
void createList(list *L) {
    (*L).first = NULL;
}

// to count Row elements in the list
int countElementB(list L) {
    int result = 0;
    if (L.first != NULL) {
        eRow *point;
        point = L.first;
        while (point != NULL) {
            result++;
            point = point->next;
        }
    }
    return result;
}

// to count Column elements in the list
int countElementK(eRow L) {
    int result = 0;
    if (L.col != NULL) {
        eColumn *point;
        point = L.col;
        while (point != NULL) {
            result++;
            point = point->next_col;
        }
    }
    return result;
}

// to add First for Row
void addFirstB(char kodeP[], char namaP[], list *L) {
    eRow *new;
    new = (eRow *)malloc(sizeof(eRow));
    new->col = NULL;
    strcpy(new->container.kodeP, kodeP);
    strcpy(new->container.namaP, namaP);
    if ((*L).first == NULL) {
        new->next = NULL;
    } else {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

// to add First for Column
void addFirstK(char kodeO[], char namaO[], int bulan, int tahun, char jenis[], eRow *L) {
    eColumn *new;
    new = (eColumn *)malloc(sizeof(eColumn));
    strcpy(new->container_col.kodeO, kodeO);
    strcpy(new->container_col.namaO, namaO);
    new->container_col.bulan = bulan;
    new->container_col.tahun = tahun;
    strcpy(new->container_col.jenis, jenis);
    if ((*L).col == NULL) {
        new->next_col = NULL;
    } else {
        new->next_col = (*L).col;
    }
    (*L).col = new;
    new = NULL;
}

// to add After for Row
void addAfterB(eRow *prev, char kodeP[], char namaP[]) {
    eRow *new;
    new = (eRow *)malloc(sizeof(eRow));
    new->col = NULL;
    strcpy(new->container.kodeP, kodeP);
    strcpy(new->container.namaP, namaP);
    if (prev->next == NULL) {
        new->next = NULL;
    } else {
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}

// to add After for Coloumn
void addAfterK(eColumn *prev, char kodeO[], char namaO[], int bulan, int tahun, char jenis[]) {
    eColumn *new;
    new = (eColumn *)malloc(sizeof(eColumn));
    strcpy(new->container_col.kodeO, kodeO);
    strcpy(new->container_col.namaO, namaO);
    new->container_col.bulan = bulan;
    new->container_col.tahun = tahun;
    strcpy(new->container_col.jenis, jenis);
    if (prev->next_col == NULL) {
        new->next_col = NULL;
    } else {
        new->next_col = prev->next_col;
    }
    prev->next_col = new;
    new = NULL;
}

// to add Last for Row
void addLastB(char kodeP[], char namaP[], list *L) {
    if ((*L).first == NULL) {
        addFirstB(kodeP, namaP, L);
    } else {
        eRow *last = (*L).first;
        while (last->next != NULL) {
            last = last->next;
        }
        addAfterB(last, kodeP, namaP);
    }
}

// to add Last for Coloumn
void addLastK(char kodeO[], char namaO[], int bulan, int tahun, char jenis[], eRow *L) {
    if ((*L).col == NULL) {
        addFirstK(kodeO, namaO, bulan, tahun, jenis, L);
    } else {
        eColumn *last = (*L).col;
        while (last->next_col != NULL) {
            last = last->next_col;
        }
        addAfterK(last, kodeO, namaO, bulan, tahun, jenis);
    }
}

// to del First for Column
void delFirstK(eRow *L) {
    if ((*L).col != NULL) {
        eColumn *del = (*L).col;
        if (countElementK(*L) == 1) {
            (*L).col = NULL;
        } else {
            (*L).col = (*L).col->next_col;
            del->next_col = NULL;
        }
        free(del);
    }
}

// to del After for Column
void delAfterK(eColumn *prev) {
    eColumn *del = prev->next_col;
    if (del != NULL) {
        if (del->next_col == NULL) {
            prev->next_col = NULL;
        } else {
            prev->next_col = del->next_col;
            del->next_col = NULL;
        }
        free(del);
    }
}

// to del Last for Column
void delLastK(eRow *L) {
    if ((*L).col != NULL) {
        if (countElementK(*L) == 1) {
            delFirstK(L);
        } else {
            eColumn *last = (*L).col;
            eColumn *before_last;

            while (last->next_col != NULL) {
                before_last = last;
                last = last->next_col;
            }
            delAfterK(before_last);
        }
    }
}

// to del all for Column
void delAllK(eRow *L) {
    if (countElementK(*L) != 0) {
        for (int i = countElementK(*L); i >= 1; i--) {
            delLastK(L);
        }
    }
}

// to del First for Row
void delFirstB(list *L) {
    if ((*L).first != NULL) {
        eRow *del = (*L).first;
        if (del->col != NULL) {
            delAllK(del);
        }
        if (countElementB(*L) == 1) {
            (*L).first = NULL;
        } else {
            (*L).first = (*L).first->next;
        }
        del->next = NULL;
        free(del);
    } else {
        printf("list_kosong\n");
    }
}

// to del After for Row
void delAfterB(eRow *prev) {
    if (prev != NULL) {
        eRow *del = prev->next;
        if (del != NULL) {
            if (del->col != NULL) {
                delAllK(del);
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

// to del Last for Row
void delLastB(list *L) {
    if ((*L).first != NULL) {
        if (countElementB(*L) == 1) {
            delFirstB(L);
        } else {
            eRow *last = (*L).first;
            eRow *before_last;
            while (last->next != NULL) {
                before_last = last;
                last = last->next;
            }
            delAfterB(before_last);
        }
    }
}

// to del All for Row
void delAllB(list *L) {
    if (countElementB(*L) != 0) {
        for (int i = countElementB(*L); i >= 1; i--) {
            delLastB(L);
        }
    }
}

// to print all elements in the list
void printElement(list L) {
    if (L.first != NULL) {
        eRow *point = L.first;
        while (point != NULL) {
            printf("%s %s\n", point->container.kodeP, point->container.namaP);
            eColumn *eCol = point->col;
            while (eCol != NULL) {
                printf("- %s %s %d %d %s\n", eCol->container_col.kodeO, eCol->container_col.namaO, eCol->container_col.bulan, eCol->container_col.tahun, eCol->container_col.jenis);
                eCol = eCol->next_col;
            }
            point = point->next;
        }
    } else {
        printf("list_kosong\n");
    }
}

eRow *searchRow(char kodeP[], list L) {
    eRow *rows = L.first;
    int found = 0;

    if (L.first != NULL) {
        while ((rows != NULL) && (found == 0)) {
            if (strcmp(rows->container.kodeP, kodeP) == 0) {
                found = 1;
            } else {
                rows = rows->next;
            }
        }
    }
    return rows;
}

void searchCopy(int bulan, int tahun, list *L) {
    if (L->first != NULL) {
        eRow *pointB = L->first;           // menunjuk ke baris yg sedang di cek
        eRow *org = searchRow("org", *L);  // menunjuk ke elemen baris organisasi berwenang
        eColumn *prevMoved = org->col;     // menunjuk ke elemen kolom organisasi

        eColumn *pointK;  // elemen kolom yg ditunjuk
        eColumn *after;   // menunjuk ke setelah elemen yg ditunjuk
        eColumn *before;  // menunjuk ke sebelum elemen kolom yg ditunjuk

        while (pointB != org) {
            pointK = pointB->col;
            while (pointK != NULL) {
                after = pointK->next_col;
                // mengecek obat dari list kolom yg ditunjuk
                if ((strcmp(pointK->container_col.jenis, "sirup") == 0) && ((pointK->container_col.tahun > tahun) || ((pointK->container_col.tahun == tahun) && (pointK->container_col.bulan >= bulan)))) {
                    // jika ditarik

                    if (pointK == pointB->col)  // jika kolom yg ditunjuk elemen pertama
                    {
                        pointB->col = after;
                    } else {
                        before->next_col = after;
                    }

                    if (org->col == NULL)  // jika kolom organisasi berwenang masih kosong
                    {
                        org->col = pointK;
                        pointK->next_col = NULL;
                    } else {
                        pointK->next_col = prevMoved->next_col;
                        prevMoved->next_col = pointK;
                    }

                    prevMoved = pointK;
                    pointK = after;
                } else  // jika tidak ditarik
                {
                    before = pointK;
                    pointK = after;

                    if (after != NULL)  // jika after bukan null
                    {
                        after = after->next_col;
                    }
                }
            }

            // iterasi elemen baris
            pointB = pointB->next;
        }
    }
}

/*
void searchCopy(list *L1, list *L2, obat berwenang, int n) {
    int total = 0;
    obat tempObat;
    obat dua;
    if (L1->first != NULL) {
        int copy = 0;
        int i, j;
        eRow *point = L1->first;
        eRow *row;
        i = 1;
    while (point != NULL) {  // jika data List tidak kosong
    addLastB(point->container.kodeP, point->container.namaP, L2);
    if (point == L1->first) {
        row = L1->first;
    } else {
        row = row->next;
    }
    eColumn *curr = point->col;  // masuk ke kolom
    while (curr != NULL) {
        if ((curr->container_col.bulan >= berwenang.bulan) && (curr->container_col.tahun >= berwenang.tahun)) {
            // addLastK(curr->container_col.kodeO, curr->container_col.namaO, curr->container_col.bulan, curr->container_col.tahun, curr->container_col.jenis, row);
            strcpy(dua.kodeO, curr->container_col.kodeO);
            strcpy(dua.namaO, curr->container_col.namaO);
            dua.bulan = curr->container_col.bulan;
            dua.tahun = curr->container_col.tahun;
            strcpy(dua.jenis, curr->container_col.jenis);

            strcpy(tempObat.kodeO, curr->container_col.kodeO);
            strcpy(tempObat.namaO, curr->container_col.namaO);
            tempObat.bulan = curr->container_col.bulan;
            tempObat.tahun = curr->container_col.tahun;
            strcpy(tempObat.jenis, curr->container_col.jenis);

            total++;
        }
        curr = curr->next_col;
    }
    point = point->next;
    i++;

    if (L2->first != NULL) {
        eRow *tunjuk = L2->first;
        int i = 1;
        while (tunjuk != NULL) {
            printf("%s %s\n", tunjuk->container.kodeP, tunjuk->container.namaP);
            eColumn *eCol = tunjuk->col;
            for (int x = 0; x < total; x++) {
                printf("- %s %s %d %d %s\n", tempObat.kodeO, tempObat.namaO, tempObat.bulan, tempObat.tahun, tempObat.jenis);
            }
            tunjuk = tunjuk->next;
            i++;
        }
        printf("org OrganisasiBerwenang\n");
        for (int x = 0; x < total; x++) {
            printf("- %s %s %d %d %s\n", tempObat.kodeO, tempObat.namaO, tempObat.bulan, tempObat.tahun, tempObat.jenis);
        }
    }
}
*/