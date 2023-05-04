/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 5
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

/*create empty graph*/
void createEmpty(graph *G) {
    (*G).first = NULL;
}

/*find node*/
node *findNode(char c, graph G) {
    // init
    node *result = NULL;
    node *point = G.first;
    int ketemu = 0;

    // process
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

/*add node*/
void addNode(char c, graph *G) {
    // init
    node *new;

    // process
    new = (node *)malloc(sizeof(node));
    new->container = c;
    new->next = NULL;
    new->arc = NULL;
    // if the graph is empty
    if ((*G).first == NULL) {
        (*G).first = new;
    }
    // add a new node at the end graph
    else {
        node *last = (*G).first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = new;
    }
}

/*add lane or path*/
void addLane(node *begin, node *goal, int w) {
    // init
    lane *new;

    // process
    new = (lane *)malloc(sizeof(lane));
    new->container_lane = w;
    new->next_lane = NULL;
    new->goal = goal;
    // if the lane list is empty
    if (begin->arc == NULL) {
        begin->arc = new;
    }
    // add a new lane to the end of the list lane
    else {
        lane *last = begin->arc;
        while (last->next_lane != NULL) {
            last = last->next_lane;
        }
        last->next_lane = new;
    }
}

/*find path*/
void findPath(graph G, node *begin, char path[], int index, int visited[], char endPath, int range) {
    visited[begin->container - 'A' - 1] = 1;
    // set into array
    path[index] = begin->container;
    index++;
    // if reached the goal
    if (begin->container == endPath) {
        // output
        for (int i = 0; i < index; i++) {
            printf("%c ", path[i]);
        }
        printf("%d", range);
        printf("\n");
    }
    // if it's not the goal
    else {
        // loop until finds the goal
        lane *point = begin->arc;
        while (point != NULL) {
            // if not visited yet
            if (visited[point->goal->container - 'A' - 1] == 0) {
                // recursive to change the beginning of each path(s)
                int sum = range + point->container_lane;
                node *next = findNode(point->goal->container, G);
                findPath(G, next, path, index, visited, endPath, sum);
            }
            // next path
            point = point->next_lane;
        }
    }
    index--;
    visited[begin->container - 'A' - 1] = 0;
}