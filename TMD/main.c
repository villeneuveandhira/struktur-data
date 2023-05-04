/*
Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/

/*lib*/
#include "header.h"

/*program*/
int main() {
    /*description(INA):
    T               : Pohon
    n, m, i, j      : iterator (banyak inputan, minimum value, i, j)
    value, comp     : nilai_jual & jumlah_komponen (converted)
    que             : string input
    temp, temp2     : input sementara setelah dipisah
    child, parent   : data container tree
    data            ;
    1. name         = nama_simpul
    2. value        = nilai_jual
    3. parent       = nama_simpul_orangtua
    4. idx          = jumlah komponen
    5. flag         = penanda (penjualannya lebih rendah dari minimum masukan)
    6. component    = isi komponen sesusai jumlah komponen*/
    // init
    tree T;
    int n, m, i, j, value, comp;
    char que[201], temp[201], temp2[201];
    data child, parent;

    // sum of all tree nodes
    scanf("%d", &n);
    // list names of the input (child.name)
    char list[n][201];
    for (i = 0; i < n; i++) {
        // string input with '#'
        scanf("%s", &que);
        // separates the '#' from the input string
        split(que, child.name, temp);
        split(temp, parent.name, temp2);
        split(temp2, child.num, parent.num);
        /*for example (que, temp, temp2):
        original        : mie_goreng#null#8000#2
        after 1st split : null#8000#2
        2nd split       : 8000#2
        last split      : 2*/
        // convert string to integer
        value = toInt(child.num);
        comp = toInt(parent.num);
        // insert to list
        strcpy(list[i], child.name);
        // components
        for (j = 0; j < comp; j++) {
            scanf("%s", &child.component[j]);
        }
        // if the input is the first string whose condition has no parent name or 'NULL'
        if ((strcmp(parent.name, "null") == 0) || (strcmp(parent.name, "NULL") == 0)) {
            makeTree(child.name, child.num, parent.name, value, comp, 0, child.component, &T);
        }
        // add to tree
        else {
            node *find = NULL;
            find = findNode(parent.name, T.root);
            if (find != NULL) {
                addChild(child.name, child.num, parent.name, value, comp, 0, child.component, find);
            }
        }
    }
    // minimum value
    scanf("%d", &m);

    // first output (completed tree)
    for (i = 0; i < n; i++) {
        max[i] = 0;
    }
    depth(0, T.root);
    printTreePreOrder(T.root, 0, 0);

    // delete nodes whose value is below minimum:
    /*first of all,
    mark the node that is less than the minimum value (mark it with a flag).*/
    mark(m, T.root);
    /*after that find the node whose flag is 1 (meaning less than the value) and delete the node.*/
    delMark(n, list, T.root);

    // second output (after deleted)
    printf("\n");
    printTreePreOrder(T.root, 0, 0);

    return 0;
}