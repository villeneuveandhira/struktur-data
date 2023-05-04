#include "header.h"

int main() {
    graph G;
    createEmpty(&G);
    addNode('A', &G);
    addNode('B', &G);
    addNode('C', &G);
    addNode('D', &G);
    addNode('E', &G);
    addNode('F', &G);

    node *begin = findNode('A', G);
    node *end = findNode('B', G);
    if ((begin != NULL) &&
        (end != NULL)) {
        addLane(begin, end, 3);
    }
    begin = findNode('B', G);
    end = findNode('D', G);
    if ((begin != NULL) &&
        (end != NULL)) {
        addLane(begin, end, 3);
    }

    end = findNode('E', G);
    if ((begin != NULL) &&
        (end != NULL)) {
        addLane(begin, end, 7);
    }
    begin = findNode('C', G);
    end = findNode('A', G);
    if ((begin != NULL) &&
        (end != NULL)) {
        addLane(begin, end, 3);
    }
    begin = findNode('D', G);
    if ((begin != NULL) &&
        (end != NULL)) {
        addLane(begin, end, 8);
    }
    end = findNode('C', G);
    if ((begin != NULL) &&
        (end != NULL)) {
        addLane(begin, end, 3);
    }
    begin = findNode('E', G);
    end = findNode('D', G);
    if ((begin != NULL) &&
        (end != NULL)) {
        addLane(begin, end, 4);
    }
    end = findNode('F', G);
    if ((begin != NULL) &&
        (end != NULL)) {
        addLane(begin, end, 4);
    }

    begin = findNode('F', G);
    end = findNode('D', G);
    if ((begin != NULL) &&
        (end != NULL)) {
        addLane(begin, end, 2);
    }

    printf("=================\n");
    printGraph(G);
    printf("\n=================\n");
    begin = findNode('A', G);
    if (begin != NULL) {
        delLane('B', begin);
    }

    printf("=================\n");
    printf("setelah dihapus\n");
    printGraph(G);
    printf("\n=================\n");

    return 0;
}