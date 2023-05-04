/*Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Akhir Semester
Graf Jalur Langsung Tak Langsung (gjltl22)
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

/*create empty graph*/
void createEmpty(graph *G) {
    (*G).first = NULL;
}

/*add node*/
void addNode(char c, graph *G) {
    node *new;
    new = (node *)malloc(sizeof(node));
    new->container = c;
    new->next = NULL;
    new->arc = NULL;
    // if the graph is empty
    if ((*G).first == NULL) {
        (*G).first = new;
    } else {
        // add new node at the end of graph
        node *last = (*G).first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new;
    }
}

/*add path*/
void addLane(node *begin, node *goal, int w) {
    lane *new;
    new = (lane *)malloc(sizeof(lane));
    new->container_lane = w;
    new->next_lane = NULL;
    new->goal = goal;
    // if the list of path is empty
    if (begin->arc == NULL) {
        begin->arc = new;
    } else {
        // add new path at the end of path's list
        lane *last = begin->arc;
        while (last->next_lane != NULL) {
            last = last->next_lane;
        }
        last->next_lane = new;
    }
}

/*find node*/
node *findNode(char c, graph G) {
    node *result = NULL;
    node *point = G.first;
    int ketemu = 0;
    while ((point != NULL) &&
           (ketemu == 0)) {
        if (point->container == c) {
            result = point;
            ketemu = 1;
        } else {
            point = point->next;
        }
    }
    return result;
}

/*proses mencari lane langsung dan tidak langsung*/
void pathing(node *awal, char (*path)[][100], int *i, int *j, int *iterasi, int *flag, char tAwal, char tAkhir) {
    // Kalau masih iterasi pertama
    if (*iterasi == 0) {
        // Set nilai awal path
        *j += 1;
        (*path)[*i][*j] = awal->container;
        *iterasi += 1;
    }

    // proses pencarian jalur
    lane *bantu_jalur = awal->arc;
    while (bantu_jalur != NULL) {
        *j += 1;
        if (*flag == 1) {
            // cari jalur selanjutnya
            strcpy((*path)[*i + 1], (*path)[*i]);
            *i += 1;
            *flag = 0;
        }
        // menambah node goal
        (*path)[*i][*j] = bantu_jalur->goal->container;
        // rekursif
        pathing(bantu_jalur->goal, path, i, j, iterasi, flag, tAwal, tAkhir);
        // string
        if (*flag == 0) {
            (*path)[*i][*j + 1] = '\0';
        }
        *j -= 1;
        // Iterasi
        bantu_jalur = bantu_jalur->next_lane;
        *flag = 1;
    }

    // proses output
    if (bantu_jalur == NULL && awal->container == tAwal) {
        int banyak[2] = {0};
        for (int index = 0; index < *i + 1; index++) {
            // identifikasi jalur
            if ((*path)[index][strlen((*path)[index]) - 1] == tAkhir) {
                // jalur lansung
                if ((*path)[index][1] == tAkhir) {
                    banyak[1]++;
                }
                // tidak langsung
                else {
                    banyak[0]++;
                }
            }
        }

        // keluaran
        printf("jumlah lane: %d\n", banyak[0] + banyak[1]);
        printf("terdiri dari:\n");
        printf("- %d lane langsung\n", banyak[1]);
        printf("- %d lane tidak langsung\n", banyak[0]);
    }
}

// /*print graph*/
// void printGraph(char x, char y, graph G) {
//     // init
//     int direct = 0, indirect = 0;
//     node *point = G.first;
//     // process
//     if (point != NULL) {
//         // jika graf tidak kosong
//         while (point != NULL) {
//             if (point->container == x) {
//                 lane *pointLane = point->arc;
//                 node *goal = findNode(y, G);
//                 while (pointLane != NULL) {
//                     if (pointLane->goal == goal) {
//                         if (point->container == x) {
//                             direct++;
//                         }
//                         indirect++;
//                     }
//                     pointLane = pointLane->next_lane;
//                 }
//             }
//             point = point->next;
//         }
//     }

//     // output
//     printf("jumlah lane: %d\n", direct + indirect);
//     printf("terdiri dari:\n");
//     printf("- %d lane langsung\n", direct);
//     printf("- %d lane tidak langsung\n", indirect);
// }