/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 1
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

#include "header.h"

// procedure to create a list
void create_List(list* L) {
    (*L).first = NULL;
}

// function to count elements
int count_Element(list L) {
    int result = 0;

    if (L.first != NULL) {
        /*list != NULL*/
        element* point;

        /*init*/
        point = L.first;
        while (point != NULL) {
            /*process*/
            result = result + 1;
            /*iteration*/
            point = point->next;
        }
    }
    return result;
}

// procedure to add first element's list
void add_First(char title[], char artist[], int no, list* L) {
    element* new;
    new = (element*)malloc(sizeof(element));  // memory allocation
    /*data*/
    strcpy(new->container.title, title);
    strcpy(new->container.artist, artist);
    new->container.no = no;
    /*condition for placement at the beginning of the list*/
    if ((*L).first == NULL) {
        new->next = NULL;
    } else {
        new->next = (*L).first;
    }
    (*L).first = new;
    new = NULL;
}

// procedure to print all element
void print_Element(list L) {
    if (L.first != NULL) {
        /*list != NULL*/
        /*init*/
        element* point = L.first;
        int i = 1;
        while (point != NULL) {
            /*process*/
            printf("%s - %s\n", point->container.title, point->container.artist);
            /*iteration*/
            point = point->next;
            i = i + 1;
        }
    } else {
        /*NULL list*/
        printf("List Kosong.\n");
    }
}

// procedure to sorting
void sorting(list* L, int x, int y) {
    /*init*/
    element* point = (*L).first;  // indicator as the start of swap
    element* a;                   // for comparison (pointer a)
    element* b;                   // for comparison (pointer b)
    element* end;                 // indicator as the end of swap
    lagu temp;                    // temporary data
    int swap;                     // swap marker

    // perulangan hingga seluruh data hingga data tidak ada yang ditukar
    do {
        // nilai swap untuk penanda ada data yang ditukar atau tidak
        swap = 0;

        // cek semua
        /*
            algorithm sorting:
            1. membuat pointer menunjukkan titik awal, pembanding a-b, dan titik akhir;
            2. titik awal untuk menunjukkan memulai sorting, pembanding a-b untuk menunjukkan mana yang akan dibandingkan, dan titik akhir untuk mengetahui sampai kapan sorting dilakukan;
            3. sorting dilakukan selama penunjuk akhir sampai di awal sesuai syarat sorting (asc/desc);
            4. a dan b dibandingkan masing" kemudian ditukar/swap, setelah itu maju dengan pointer next hingga akhir;
            5. fase 3-4 terus dilakukan hingga pointer akhir di awal.
        */

        if (x == 0) {  // untuk sorting "judul"
            for (end = NULL; end != point->next; end = a) {
                if (y == 0) {  // jika ascending
                    for (a = point; a->next != end; a = a->next) {
                        b = a->next;  // init b setelah a
                        if (strcmp(a->container.title, b->container.title) > 0) {
                            // tukar data
                            temp = a->container;
                            a->container = b->container;
                            b->container = temp;

                            // penanda bahwa ada data yang ditukar
                            swap = 1;
                        }
                    }
                } else if (y == 1) {  // jika descending
                    for (a = point; a->next != end; a = a->next) {
                        b = a->next;  // init b setelah a
                        if (strcmp(a->container.title, b->container.title) < 0) {
                            // tukar data
                            temp = a->container;
                            a->container = b->container;
                            b->container = temp;

                            // penanda bahwa ada data yang ditukar
                            swap = 1;
                        }
                    }
                }
            }
        } else if (x == 1) {  // untuk sorting "nomor"
            for (end = NULL; end != point->next; end = a) {
                if (y == 0) {  // jika ascending
                    for (a = point; a->next != end; a = a->next) {
                        b = a->next;  // init b setelah a
                        if (a->container.no > b->container.no) {
                            // tukar data
                            temp = a->container;
                            a->container = b->container;
                            b->container = temp;

                            // penanda bahwa ada data yang ditukar
                            swap = 1;
                        }
                    }
                } else if (y == 1) {  // jika descending
                    for (a = point; a->next != end; a = a->next) {
                        b = a->next;  // init b setelah a
                        if (a->container.no < b->container.no) {
                            // tukar data
                            temp = a->container;
                            a->container = b->container;
                            b->container = temp;

                            // penanda bahwa ada data yang ditukar
                            swap = 1;
                        }
                    }
                }
            }
        }
    } while (swap == 1);

    // print list
    print_Element(*L);
}