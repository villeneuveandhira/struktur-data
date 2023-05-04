/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tugas Praktikum 4
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

void makeTree(char pohon[], tree *T) {
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    strcpy(node->container, pohon);
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(char pohon[], simpul *root) {
    if (root != NULL) {
        simpul *new;
        new = (simpul *)malloc(sizeof(simpul));
        strcpy(new->container, pohon);
        new->child = NULL;
        if (root->child == NULL) {
            new->sibling = NULL;
            root->child = new;
        } else {
            if (root->child->sibling == NULL) {
                new->sibling = root->child;
                root->child->sibling = new;
            } else {
                simpul *last = root->child;
                while (last->sibling != root->child) {
                    last = last->sibling;
                }
                new->sibling = root->child;
                last->sibling = new;
            }
        }
    }
}

void delAll(simpul *root) {
    if (root != NULL) {
        if (root->child != NULL) {
            if (root->child->sibling == NULL) {
                delAll(root->child);
            } else {
                simpul *point;
                simpul *process;
                point = root->child;
                while (point->sibling != root->child) {
                    process = point;
                    point = point->sibling;
                    delAll(process);
                }
                delAll(point);
            }
            free(root);
        } else {
            free(root);
        }
    }
}

void delChild(char nama[], simpul *root) {
    if (root != NULL) {
        simpul *hapus = root->child;
        if (hapus != NULL) {
            if (hapus->sibling == NULL) {
                if (strcmp(root->child->container, nama) == 0) {
                    delAll(root->child);
                    root->child = NULL;
                } else {
                    printf("%s tidak ditemukan\n", nama);
                }
            } else {
                simpul *prev = NULL;
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0)) {
                    if (strcmp(hapus->container, nama) == 0) {
                        ketemu = 1;
                    } else {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                if ((ketemu == 0) && (strcmp(hapus->container, nama) == 0)) {
                    ketemu = 1;
                }
                if (ketemu == 1) {
                    simpul *last = root->child;
                    while (last->sibling != root->child) {
                        last = last->sibling;
                    }
                    if (prev == NULL) {
                        if ((hapus->sibling == last) && (last->sibling == root->child->sibling)) {
                            root->child = last;
                            last->sibling = NULL;
                        } else {
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    } else {
                        if ((prev == root->child) && (last->sibling == root->child->sibling)) {
                            root->child->sibling = NULL;
                        } else {
                            prev->sibling = hapus->sibling;
                            hapus->sibling = NULL;
                        }
                    }
                    delAll(hapus);
                } else {
                    printf("%s tidak ditemukan\n", nama);
                }
            }
        }
    }
}

simpul *findSimpul(char nama[], simpul *root) {
    simpul *result = NULL;
    if (root != NULL) {
        if (strcmp(root->container, nama) == 0) {
            result = root;
        } else {
            simpul *point = root->child;
            if (point != NULL) {
                if (point->sibling == NULL) {
                    if (strcmp(point->container, nama) == 0) {
                        result = point;
                    } else {
                        result = findSimpul(nama, point);
                    }
                } else {
                    int ketemu = 0;
                    while ((point->sibling != root->child) && (ketemu == 0)) {
                        if (strcmp(point->container, nama) == 0) {
                            result = point;
                            ketemu = 1;
                        } else {
                            result = findSimpul(nama, point);
                            point = point->sibling;
                            if (result != NULL) {
                                ketemu = 1;
                            }
                        }
                    }
                    if (ketemu == 0) {
                        if (strcmp(point->container, nama) == 0) {
                            result = point;
                        } else {
                            result = findSimpul(nama, point);
                        }
                    }
                }
            }
        }
    }
    return result;
}

void printTreePreOrder(simpul *root, int lvl) {
    for (int i = 0; i < lvl; i++) {
        printf("->");
    }
    if (root != NULL) {
        printf("%s\n", root->container);
        simpul *point = root->child;
        if (point != NULL) {
            if (point->sibling == NULL) {
                lvl += 1;
                printTreePreOrder(point, lvl);
                lvl -= 1;
            } else {
                while (point->sibling != root->child) {
                    lvl += 1;
                    printTreePreOrder(point, lvl);
                    lvl -= 1;
                    point = point->sibling;
                }
                lvl += 1;
                printTreePreOrder(point, lvl);
                lvl -= 1;
            }
        }
    }
}