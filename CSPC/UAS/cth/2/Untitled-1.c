#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

// Struktur data untuk menyimpan graf berarah
struct Graph {
    int vertices;
    int edges;
    int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];
};

// Fungsi untuk memeriksa apakah graf berarah memiliki jalur path node memutar
int hasCycle(struct Graph* graph) {
    int i, j;

    // Periksa apakah ada jalur path node memutar dengan menggunakan algoritma DFS
    for (i = 0; i < graph->vertices; i++) {
        for (j = 0; j < graph->vertices; j++) {
            if (graph->adjacency_matrix[i][j] == 1) {
                // Melakukan DFS pada setiap node yang terhubung
                int visited[graph->vertices];
                int stack[graph->vertices];
                int top = -1;

                // Menandai semua node sebagai belum dikunjungi
                int k;
                for (k = 0; k < graph->vertices; k++) {
                    visited[k] = 0;
                }

                // Memasukkan node yang sedang dikunjungi ke dalam stack
                stack[++top] = i;
                visited[i] = 1;

                // Selama stack tidak kosong
                while (top >= 0) {
                    // Mengambil node teratas dari stack
                    int current_node = stack[top--];

                    // Menelusuri setiap node yang terhubung dengan node yang sedang dikunjungi
                    for (k = 0; k < graph->vertices; k++) {
                        if (graph->adjacency_matrix[current_node][k] == 1 && visited[k] == 1) {
                            // Apabila node yang terhubung sudah pernah dikunjungi sebelumnya, maka graf berarah memiliki jalur path node memutar
                            return 1;
                        }
                        if (graph->adjacency_matrix[current_node][k] == 1 && visited[k] == 0) {
                            // Memasukkan node yang terhubung ke dalam stack dan menandainya sebagai sudah dikunjungi
                            stack[++top] = k;
                            visited[k] = 1;
                        }
                    }
                }
            }
        }
    }

    // Apabila tidak ditemukan jalur path node memutar, maka graf berarah tidak memiliki jalur path node memutar
    return 0;
}