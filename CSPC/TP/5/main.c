/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 5
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

int main() {
    // init
    int n, i, distance, visited[26];
    char beginPath, endPath;
    graph G;
    createEmpty(&G);

    // input
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        // add node
        scanf(" %c %c", &beginPath, &endPath);
        if (findNode(beginPath, G) == NULL) {
            addNode(beginPath, &G);
        }
        if (findNode(endPath, G) == NULL) {
            addNode(endPath, &G);
        }
        // add path
        scanf("%d", &distance);
        addLane(findNode(beginPath, G), findNode(endPath, G), distance);
    }
    // node 'Techi & Ibu'
    scanf(" %c %c", &beginPath, &endPath);

    // init for path and distance
    char path[n + 100];
    int range = 0;
    // set all as not visited
    for (i = 0; i < 26; i++) {
        visited[i] = 0;
    }
    // set the beginning of the path
    node *begin = findNode(beginPath, G);
    // findpath
    findPath(G, begin, path, 0, visited, endPath, range);

    return 0;
}