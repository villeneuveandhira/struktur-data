#include "header.h"

void createEmpty(graph *G) {
    (*G).first = NULL;
}

void addNode(char c, graph *G) {
    node *new;
    new = (node *)malloc(sizeof(node));
    new->container = c;
    new->next = NULL;
    new->arc = NULL;
    if ((*G).first == NULL) {
        /*jika graf kosong*/
        (*G).first = new;
    } else {
        /*menambahkan node new pada akhir
        graph*/
        node *last = (*G).first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new;
    }
}

void addLane(node *begin, node *goal, int w) {
    lane *new;
    new = (lane *)malloc(sizeof(lane));
    new->container_lane = w;
    new->next_lane = NULL;
    new->goal = goal;
    if (begin->arc == NULL) {
        /*jika list lane kosong*/
        begin->arc = new;
    } else {
        /*menambahkan lane new pada akhir list
        lane*/
        lane *last = begin->arc;
        while (last->next_lane != NULL) {
            last = last->next_lane;
        }
        last->next_lane = new;
    }
}

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

void delLane(char ctujuan, node *begin) {
    lane *del = begin->arc;
    if (del != NULL) {
        lane *prev = NULL;
        /*mencari lane yang akan dihapus*/
        int ketemu = 0;
        while ((del != NULL) &&
               (ketemu == 0)) {
            if (del->goal->container == ctujuan) {
                ketemu = 1;
            } else {
                prev = del;
                del = del->next_lane;
            }
        }
        if (ketemu == 1) {
            if (prev == NULL) {
                /*del lane pertama*/
                begin->arc = del->next_lane;
                del->next_lane = NULL;
            } else {
                if (del->next_lane == NULL) {
                    /*del lane terakhir*/
                    prev->next_lane = NULL;
                } else {
                    /*del lane di tengah*/
                    prev->next_lane = del->next_lane;
                    del->next_lane = NULL;
                }
            }
            free(del);
        } else {
            printf("tidak ada lane dengan node goal\n");
        }
    } else {
        printf("tidak ada lane dengan node goal\n");
    }
}

void delAll(node *begin) {
    lane *point;
    point = begin->arc;
    lane *del;
    while (point != NULL) {
        del = point;
        point = point->next_lane;
        begin->arc = point;
        del->next_lane = NULL;
        free(del);
    }
}

void delNode(char c, graph *G) {
    node *del = (*G).first;
    if (del != NULL) {
        node *prev = NULL;
        /*mencari node yang akan dihapus*/
        int ketemu = 0;
        while ((del != NULL) &&
               (ketemu == 0)) {
            if (del->container == c) {
                ketemu = 1;
            } else {
                prev = del;
                del = del->next;
            }
        }
        if (ketemu == 1) {
            /* jika node yang akan dihapus ada */
            /* del semua lane dari node lain
            yang mengarah pada node yang dihapus */

            node *point;
            point = (*G).first; /* memeriksa semua node dalam graf */
            while (point != NULL) {
                /* jika node yang ditelusuri tidak sama
                dengan yang dihapus */
                if (point != del) {
                    /* del semua lane yang mengarah pada
                    node yang dihapus */
                    delLane(del->container, point);
                }
                point = point->next;
            } /* del semua lane */
            delAll(del);

            if (prev == NULL) {
                /*del node pertama*/
                (*G).first = del->next;
                del->next = NULL;
            } else {
                if (del->next == NULL) {
                    /*del node terakhir*/
                    prev->next = NULL;
                } else {
                    /*del node di tengah*/
                    prev->next = del->next;
                    del->next = NULL;
                }
            }
            free(del);
        } else {
            printf("tidak ada node dengan info karakter masukan\n");
        }
    } else {
        printf("tidak ada node dengan info karakter masukan\n");
    }
}

void printGraph(graph G) {
    node *point = G.first;
    if (point != NULL) {
        while (point != NULL) {
            printf("node : %c\n",
                   point->container);
            lane *point_lane = point->arc;
            while (point_lane != NULL) {
                printf(" - ada lane ke node : %c dengan w: %d\n", point_lane->goal->container, point_lane->container_lane);
                point_lane = point_lane->next_lane;
            }
            point = point->next;
        }
    } else {
        printf("graf kosong\n");
    }
}