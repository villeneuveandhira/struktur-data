/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 3
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

// membuat stack kosong
void createEmpty(stack *S) {
    (*S).top = NULL;
}

// cek apabila stack kosong
int isEmpty(stack S) {
    int result = 0;
    if (S.top == NULL) {
        result = 1;
    }
    return result;
}

// menghitung jumlah elemen dalam stack
int countElement(stack S) {
    int result = 0;
    if (S.top != NULL) {
        element *point;
        point = S.top;
        while (point != NULL) {
            result++;
            point = point->next;
        }
    }
    return result;
}

// memasukan elemen ke dalam stack
void push(int harga, char nama[], int kalori, stack *S) {
    // membuat pointer bantu
    element *point;
    point = (element *)malloc(sizeof(element));
    // memasukan data
    point->container.harga = harga;
    strcpy(point->container.nama, nama);
    point->container.kalori = kalori;
    if ((*S).top == NULL) {
        point->next = NULL;
    } else {
        point->next = (*S).top;
    }
    (*S).top = point;
    point = NULL;
}

// mengeluarkan elemen dari stack
void pop(stack *S) {
    // jika stack tidak kosong
    if ((*S).top != NULL) {
        // membuat pointer delete menunjuk ke elemen paling luar
        element *del = (*S).top;
        if (countElement(*S) == 1) {
            (*S).top == NULL;
        } else {
            (*S).top = (*S).top->next;
        }
        del->next = NULL;
        free(del);
    }
}

// untuk memindahkan elemen ke wishlist stack sesuai total kode ASCII
void popMove(stack *S, stack *satu, stack *dua, int n) {
    // membuat elemen bantu menunjuk ke elemen paling luar
    element *point = S->top;
    // jika stack tidak kosong
    if ((*S).top != NULL) {
        for (int x = 0; x < n; x++) {
            int ascii = 0, len = 0;
            // jumlah panjang string nama makanan
            len = strlen(point->container.nama);
            // looping untuk menghitung total ASCII
            for (int i = 0; i < len; i++) {
                ascii = ascii + point->container.nama[i];
            }
            // jika total ASCII genap
            if (ascii % 2 == 0) {
                push(point->container.harga, point->container.nama, point->container.kalori, satu);
            }
            // jika total ASCII ganjil
            else if (ascii % 2 != 0) {
                push(point->container.harga, point->container.nama, point->container.kalori, dua);
            }
            // iterasi
            point = point->next;
        }
    }
}

// print elemen stack khusus "Pedas"
void printStack_Pedas(stack S) {
    printf("Wishlist Makanan Pedas:\n");
    printf("===================\n");
    // jika stack tidak kosong
    if (S.top != NULL) {
        element *point = S.top;
        int i = 1;
        while (point != NULL) {
            printf("%d. ", i);
            printf("%s\n", point->container.nama);
            point = point->next;
            i++;
        }
    }
    // jika stack kosong
    else {
        printf("LEMAH!\n");
    }
}

// print elemen stack khusus "Manis"
void printStack_Manis(stack S) {
    printf("Wishlist Makanan Manis:\n");
    printf("===================\n");
    // jika stack tidak kosong
    if (S.top != NULL) {
        element *point = S.top;
        int i = 1;
        while (point != NULL) {
            printf("%d. ", i);
            printf("%s\n", point->container.nama);
            point = point->next;
            i++;
        }
    }
    // jika stack kosong
    else {
        printf("NDAK SEHAT!\n");
    }
}