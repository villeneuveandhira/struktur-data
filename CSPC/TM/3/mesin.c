/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 3
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

void createList(list *L) {
    (*L).first = -1;
    (*L).tail = -1;
    int i;

    for (i = 0; i < 10; i++) {
        /*proses menginisialisasi isi array*/
        (*L).data[i].prev = -2;
        (*L).data[i].next = -2;
    }
}

int countElement(list L) {
    int hasil = 0;
    if (L.first != -1) {
        /*list tidak kosong*/
        int bantu;
        /*inisialisasi*/
        bantu = L.first;
        while (bantu != -1) {
            /*proses*/
            hasil = hasil + 1;
            /*iterasi*/
            bantu = L.data[bantu].next;
        }
    }
    return hasil;
}

int emptyElement(list L) {
    int hasil = -1;
    if (countElement(L) < 10) {
        int ketemu = 0;
        int i = 0;
        while ((ketemu == 0) && (i < 10)) {
            if (L.data[i].next == -2) {
                hasil = i;
                ketemu = 1;
            } else {
                i = i + 1;
            }
        }
    }
    return hasil;
}

void addFirst(char nama[], char tgl_Masuk[], char jumlah[], list *L) {
    if (countElement(*L) < 10) {
        int baru = emptyElement(*L);
        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.tgl_Masuk, tgl_Masuk);
        strcpy((*L).data[baru].kontainer.jumlah, jumlah);

        if ((*L).first == -1) {
            /*jika list kosong*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }

        else {
            /*jika list tidak
            kosong*/
            (*L).data[baru].prev = -1;
            (*L).data[baru].next = (*L).first;
            (*L).data[(*L).first].prev = baru;
        }

        (*L).first = baru;
    } else {
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

void addAfter(int before, char nama[], char tgl_Masuk[], char jumlah[], list *L) {
    if (countElement(*L) < 10) {
        int baru = emptyElement(*L);

        strcpy((*L).data[baru].kontainer.nama, nama);
        strcpy((*L).data[baru].kontainer.tgl_Masuk, tgl_Masuk);
        strcpy((*L).data[baru].kontainer.jumlah, jumlah);
        if ((*L).data[before].next != -1) {
            // jika baru bukan menjadi elemen terakhir
            (*L).data[baru].prev = before;
            (*L).data[baru].next = (*L).data[before].next;

            (*L).data[before].next = baru;
            (*L).data[(*L).data[baru].next].prev = baru;
        } else {
            // jika baru menjadi elemen terakhir
            (*L).data[baru].prev = before;
            (*L).data[before].next = baru;
            (*L).data[baru].next = -1;
            (*L).tail = baru;
        }
    } else {
        /*proses jika array penuh*/
        printf("sudah tidak dapat ditambah\n");
    }
}

void addLast(char nama[], char tgl_Masuk[], char jumlah[], list *L) {
    if ((*L).first == -1) {
        /*proses jika list masih kosong*/
        addFirst(nama, tgl_Masuk, jumlah, L);
    } else {
        /*proses jika list telah berisi elemen*/
        addAfter((*L).tail, nama, tgl_Masuk, jumlah, L);
    }
}

void delFirst(list *L) {
    if ((*L).first != -1) {
        int hapus = (*L).first;
        if (countElement(*L) == 1)  // kalo cuman ada 1 elemen doang
        {
            (*L).first = -1;
            (*L).tail = -1;
        } else {
            (*L).first = (*L).data[(*L).first].next;
            (*L).data[(*L).first].prev = -1;
        }
        /*elemen awal sebelumnya dikosongkan*/
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    } else {
        /*proses jika list kosong*/
        printf("List Kosong.\n");
    }
}

void delAfter(int before, list *L) {
    int hapus = (*L).data[before].next;
    if (hapus != -1) {
        if ((*L).data[hapus].next == -1)  // ini kalo elemen terakhir
        {
            (*L).tail = before;
            (*L).data[before].next = -1;
        } else  // ini kalo elemen ditengah
        {
            (*L).data[before].next = (*L).data[hapus].next;
            (*L).data[(*L).data[hapus].next].prev = before;
        }
        /*pengosongan elemen*/
        (*L).data[hapus].prev = -2;
        (*L).data[hapus].next = -2;
    }
}

void delLast(list *L) {
    if ((*L).first != -1) {
        if (countElement(*L) == 1) {
            /*proses jika list hanya berisi satu elem
            en*/
            delFirst(L);
        } else {
            /*elemen sebelum elemen terakhir menjadi
            elemen terakhir*/
            delAfter((*L).data[(*L).tail].prev, L);
        }
    } else {
        /*proses jika list kosong*/
        printf("List Kosong.\n");
    }
}

void delAll(list *L) {
    int i;
    for (i = countElement(*L); i >= 1; i--) {
        /*proses menghapus elemen list*/
        delLast(L);
    }
}

void printElement(list L) {
    if (L.first != -1) {
        /*inisialisasi*/
        int bantu = L.first;
        int i = 1;
        while (bantu != -1) {
            /*proses*/
            printf("%s %s %s\n", L.data[bantu].kontainer.tgl_Masuk, L.data[bantu].kontainer.nama, L.data[bantu].kontainer.jumlah);

            /*iterasi*/
            bantu = L.data[bantu].next;
            i = i + 1;
        }
    } else {
        /*proses jika list kosong*/
        printf("List Kosong.\n");
    }
}

void printElement_Reverse(list L) {
    if (L.tail != -1) {
        /*inisialisasi*/
        int bantu = L.tail;
        int i = 1;
        while (bantu != -1) {
            /*proses*/
            printf("%s %s %s\n", L.data[bantu].kontainer.tgl_Masuk, L.data[bantu].kontainer.nama, L.data[bantu].kontainer.jumlah);

            /*iterasi*/
            bantu = L.data[bantu].prev;
            i = i + 1;
        }
    } else {
        /*proses jika list kosong*/
        printf("List Kosong.\n");
    }
}