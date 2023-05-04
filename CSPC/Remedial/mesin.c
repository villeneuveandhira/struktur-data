/*
Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan remedial dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/

/*lib*/
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

void addFirst_Baris(char nama[], int banyak, list* L) {
    eBaris* new;
    new = (eBaris*)malloc(sizeof(eBaris));
    strcpy(new->container.nama, nama);
    new->container.banyak = banyak;
    new->col = NULL;
    if ((*L).first == NULL) {
        new->next = NULL;
    } else {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}
void addFirst_Kolom(char namaBahan[], int berat, eBaris* L) {
    eKolom* new;
    new = (eKolom*)malloc(sizeof(eKolom));
    strcpy(new->container_Kol.namaBahan, namaBahan);
    new->container_Kol.berat = berat;
    if ((*L).col == NULL) {
        new->next_Kol = NULL;
    } else {
        new->next_Kol = (*L).col;
    }
    (*L).col = new;
    new = NULL;
}

void addAfter_Baris(eBaris* prev, char nama[], int banyak) {
    eBaris* new;
    new = (eBaris*)malloc(sizeof(eBaris));
    strcpy(new->container.nama, nama);
    new->container.banyak = banyak;
    new->col = NULL;
    if (prev->next == NULL) {
        new->next = NULL;
    } else {
        new->next = prev->next;
    }
    prev->next = new;
    new = NULL;
}
void addAfter_Kolom(eKolom* prev, char namaBahan[], int berat) {
    eKolom* new;
    new = (eKolom*)malloc(sizeof(eKolom));
    strcpy(new->container_Kol.namaBahan, namaBahan);
    new->container_Kol.berat = berat;
    if (prev->next_Kol == NULL) {
        new->next_Kol = NULL;
    } else {
        new->next_Kol = prev->next_Kol;
    }
    prev->next_Kol = new;
    new = NULL;
}

void addLast_Baris(char nama[], int banyak, list* L) {
    if ((*L).first == NULL) {
        addFirst_Baris(nama, banyak, L);
    } else {
        eBaris* last = (*L).first;
        while (last->next != NULL) {
            last = last->next;
        }
        addAfter_Baris(last, nama, banyak);
    }
}
void addLast_Kolom(char namaBahan[], int berat, eBaris* L) {
    if ((*L).col == NULL) {
        addFirst_Kolom(namaBahan, berat, L);
    } else {
        eKolom* last = (*L).col;
        while (last->next_Kol != NULL) {
            last = last->next_Kol;
        }
        addAfter_Kolom(last, namaBahan, berat);
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
        while (point != NULL) {
            printf("%s\n", point->container.nama);
            eKolom* eCol = point->col;
            while (eCol != NULL) {
                printf("- %s %d\n", eCol->container_Kol.namaBahan, eCol->container_Kol.berat);
                eCol = eCol->next_Kol;
            }
            point = point->next;
        }
    } else {
        printf("list kosong\n");
    }
}

eBaris* findData(char nama[], list L) {
    eBaris* result = L.first;
    int found = 0;
    if (L.first != NULL) {
        while ((result != NULL) && (found == 0)) {
            if (strcmp(result->container.nama, nama) == 0) {
                found = 1;
            } else {
                result = result->next;
            }
        }
    }
    return result;
}

eKolom* findBahan(char nama[], eBaris* peserta) {
    eKolom* result = peserta->col;
    int found = 0;
    if (peserta != NULL) {
        while ((peserta != NULL) && (found == 0)) {
            if (strcmp(result->container_Kol.namaBahan, nama) == 0) {
                found = 1;
            } else {
                result = result->next_Kol;
            }
        }
    }
    return result;
}

void move(eBaris* point, eKolom* data1, eKolom* data2, char nama1[], char nama2[], char namaBahan1[], char namaBahan2[], list* L) {
    eKolom* prevCol = point->col;
    // jika kolom yang ingin dipindahkan merupakan kolom pertama di baris list
    if (prevCol == data1) {
        point->col = data1->next_Kol;
    } else {
        // cari elemen sebelum kolom yang ingin dipindahkan
        while (prevCol->next_Kol != data1) {
            prevCol = prevCol->next_Kol;
        }
        prevCol->next_Kol = data1->next_Kol;
    }
    eBaris* baris1 = findData(nama1, *L);
    eBaris* baris2 = findData(nama2, *L);
    if (baris1->col == NULL) {
        baris1->col = data1;
    } else {
        // cari kolom terakhir dari baris terakhir
        eKolom* kolom1 = findBahan(namaBahan1, baris1);
        eKolom* kolom2 = findBahan(namaBahan2, baris2);
        kolom1->next_Kol = data1;
    }
    data1->next_Kol = NULL;
}

// void searchCopy(char cari[], char namaBahan[], list* L) {
//     if (L->first != NULL) {
//         // init
//         eBaris* pointB = L->first;         // menunjuk ke baris yg sedang di cek
//         eBaris* org = findData(cari, *L);  // menunjuk ke elemen baris data peserta
//         eKolom* prevMoved = org->col;      // menunjuk ke elemen kolom data bahan
//         eKolom* pointK;                    // elemen kolom yg ditunjuk
//         eKolom* after;                     // menunjuk ke setelah elemen yg ditunjuk
//         eKolom* before;                    // menunjuk ke sebelum elemen kolom yg ditunjuk
//         while (pointB != org) {
//             pointK = pointB->col;
//             while (pointK != NULL) {
//                 after = pointK->next_Kol;
//                 // mengecek nama dari list kolom yg ditunjuk
//                 if ((strcmp(pointK->container_Kol.namaBahan, namaBahan) == 0)) {
//                     // jika kolom yg ditunjuk elemen pertama
//                     if (pointK == pointB->col) {
//                         pointB->col = after;
//                     } else {
//                         before->next_Kol = after;
//                     }
//                     // jika kolom data bahan masih kosong
//                     if (org->col == NULL) {
//                         org->col = pointK;
//                         pointK->next_Kol = NULL;
//                     } else {
//                         pointK->next_Kol = prevMoved->next_Kol;
//                         prevMoved->next_Kol = pointK;
//                     }
//                     prevMoved = pointK;
//                     pointK = after;
//                 } else {
//                     before = pointK;
//                     pointK = after;
//                     // jika after bukan null
//                     if (after != NULL) {
//                         after = after->next_Kol;
//                     }
//                 }
//             }
//             // iterasi elemen baris
//             pointB = pointB->next;
//         }
//     }
// }