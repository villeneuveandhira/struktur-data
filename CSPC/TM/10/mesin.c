/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 10
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

void createEmpty(graph *G) {
    (*G).first = NULL;
}

void addSimpul(char c, graph *G) {
    simpul *new;
    new = (simpul *)malloc(sizeof(simpul));
    new->container = c;
    new->next = NULL;
    new->arc = NULL;
    if ((*G).first == NULL) {
        (*G).first = new;
    } else {
        simpul *last = (*G).first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new;
    }
}

void addJalur(simpul *awal, simpul *goal, int beban) {
    lane *new;
    new = (lane *)malloc(sizeof(lane));
    new->container_lane = beban;
    new->next_lane = NULL;
    new->goal = goal;
    if (awal->arc == NULL) {
        awal->arc = new;
    } else {
        lane *last = awal->arc;
        while (last->next_lane != NULL) {
            last = last->next_lane;
        }

        last->next_lane = new;
    }
}

simpul *findSimpul(char c, graph G) {
    simpul *hasil = NULL;
    simpul *dot = G.first;
    int found = 0;
    while ((dot != NULL) && (found == 0)) {
        if (dot->container == c) {
            hasil = dot;
            found = 1;
        } else {
            dot = dot->next;
        }
    }

    return hasil;
}

void delJalur(char point, simpul *awal) {
    lane *del = awal->arc;
    if (del != NULL) {
        lane *prev = NULL;
        int found = 0;
        while ((del != NULL) && (found == 0)) {
            if (del->goal->container == point) {
                found = 1;
            } else {
                prev = del;
                del = del->next_lane;
            }
        }

        if (found == 1) {
            if (prev == NULL) {
                awal->arc = del->next_lane;
                del->next_lane = NULL;
            } else {
                if (del->next_lane == NULL) {
                    prev->next_lane = NULL;
                } else {
                    prev->next_lane = del->next_lane;
                    del->next_lane = NULL;
                }
            }
            free(del);
        }
    }
}

void delAll(simpul *awal) {
    lane *dot;
    dot = awal->arc;
    lane *del;
    while (dot != NULL) {
        del = dot;
        dot = dot->next_lane;
        awal->arc = dot;
        del->next_lane = NULL;
        free(del);
    }
}

void delSimpul(char c, graph *G) {
    simpul *del = (*G).first;
    if (del != NULL) {
        simpul *prev = NULL;
        int found = 0;
        while ((del != NULL) && (found == 0)) {
            if (del->container == c) {
                found = 1;
            } else {
                prev = del;
                del = del->next;
            }
        }
        if (found == 1) {
            simpul *dot;
            dot = (*G).first;
            while (dot != NULL) {
                if (dot != del) {
                    delJalur(del->container, dot);
                }
                dot = dot->next;
            }
            delAll(del);
            if (prev == NULL) {
                (*G).first = del->next;
                del->next = NULL;
            } else {
                if (del->next == NULL) {
                    prev->next = NULL;
                } else {
                    prev->next = del->next;
                    del->next = NULL;
                }
            }
            free(del);
        }
    }
}

void printGraph(graph G) {
    simpul *dot = G.first;
    if (dot != NULL) {
        while (dot != NULL) {
            printf("Node %c\n", dot->container);
            lane *bantu_jalur = dot->arc;
            while (bantu_jalur != NULL) {
                printf("- Jalur %c ke %c\n", dot->container, bantu_jalur->goal->container);
                bantu_jalur = bantu_jalur->next_lane;
            }
            dot = dot->next;
        }
    } else {
        printf("graf kosong\n");
    }
}