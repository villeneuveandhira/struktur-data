/* Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Tes Mesin 9
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

void makeTree(data pohon, tree *T) {
    simpul *node;
    node = (simpul *)malloc(sizeof(simpul));
    node->container = pohon;
    node->sibling = NULL;
    node->child = NULL;
    (*T).root = node;
}

void addChild(data pohon, simpul *root) {
    if (root != NULL) {
        simpul *new;
        new = (simpul *)malloc(sizeof(simpul));
        new->container = pohon;
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

void delChild(char nama[], int nilai, simpul *root) {
    if (root != NULL) {
        simpul *hapus = root->child;
        if (hapus != NULL) {
            if (hapus->sibling == NULL) {
                if ((strcmp(root->child->container.nama, nama) == 0) && (root->child->container.nilai == nilai)) {
                    delAll(root->child);
                    root->child = NULL;
                } else {
                    printf("%s tidak ditemukan\n", nama);
                }
            } else {
                simpul *prev = NULL;
                int ketemu = 0;
                while ((hapus->sibling != root->child) && (ketemu == 0)) {
                    if ((strcmp(hapus->container.nama, nama) == 0) && (root->child->container.nilai == nilai)) {
                        ketemu = 1;
                    } else {
                        prev = hapus;
                        hapus = hapus->sibling;
                    }
                }
                if ((ketemu == 0) && ((strcmp(hapus->container.nama, nama) == 0) && (hapus->container.nilai == nilai))) {
                    ketemu = 1;
                }
                if (ketemu == 1) {
                    simpul *last = root->child;
                    while (last->sibling != root->child) {
                        last = last->sibling;
                    }
                    if (prev == NULL) {
                        if ((hapus->sibling == last) && (last->sibling == root->child)) {
                            root->child = last;
                            last->sibling = NULL;
                        } else {
                            root->child = hapus->sibling;
                            last->sibling = root->child;
                        }
                    } else {
                        if ((prev == root->child) && (last->sibling == root->child)) {
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
        if (strcmp(root->container.nama, nama) == 0) {
            result = root;
        } else {
            simpul *point = root->child;
            if (point != NULL) {
                if (point->sibling == NULL) {
                    if (strcmp(point->container.nama, nama) == 0) {
                        result = point;
                    } else {
                        result = findSimpul(nama, point);
                    }
                } else {
                    int ketemu = 0;
                    while ((point->sibling != root->child) && (ketemu == 0)) {
                        if (strcmp(point->container.nama, nama) == 0) {
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
                        if (strcmp(point->container.nama, nama) == 0) {
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

void nNode(simpul *root, int *n) {
    if (root != NULL) {
        *n += 1;
        simpul *point = root->child;
        if (point != NULL) {
            if (point->sibling == NULL) {
                nNode(point, n);
            } else {
                while (point->sibling != root->child) {
                    nNode(point, n);
                    point = point->sibling;
                }
                nNode(point, n);
            }
        }
    }
}

void printTreePreOrder(simpul *root, int *mark, int n) {
    if (root != NULL) {
        *mark += 1;
        printf("%s %d", root->container.nama, root->container.nilai);
        if (*mark != n) {
            printf("-");
        }
        simpul *point = root->child;
        if (point != NULL) {
            if (point->sibling == NULL) {
                printTreePreOrder(point, mark, n);
            } else {
                while (point->sibling != root->child) {
                    printTreePreOrder(point, mark, n);
                    point = point->sibling;
                }
                printTreePreOrder(point, mark, n);
            }
        }
    }
}

void printTreePostOrder(simpul *root, int *mark, int n) {
    if (root != NULL) {
        simpul *point = root->child;
        if (point != NULL) {
            if (point->sibling == NULL) {
                printTreePostOrder(point, mark, n);
            } else {
                while (point->sibling != root->child) {
                    printTreePostOrder(point, mark, n);
                    point = point->sibling;
                }
                printTreePostOrder(point, mark, n);
            }
        }
        *mark += 1;
        printf("%s %d", root->container.nama, root->container.nilai);
        if (*mark != n) {
            printf("-");
        }
    }
}

void copyTree(simpul *root1, simpul **root2) {
    if (root1 != NULL) {
        (*root2) = (simpul *)malloc(sizeof(simpul));
        (*root2)->container = root1->container;
        (*root2)->sibling = NULL;
        (*root2)->child = NULL;
        if (root1->child != NULL) {
            if (root1->child->sibling == NULL) {
                copyTree(root1->child, &(*root2)->child);
            } else {
                simpul *point1 = root1->child;
                simpul *point2 =
                    (*root2)->child;

                while (point1->sibling != root1->child) {
                    copyTree(point1, &point2);
                    point1 = point1->sibling;
                    point2 = point2->sibling;
                }
                copyTree(point1, &point2);
            }
        }
    }
}

int isEqual(simpul *root1, simpul *root2) {
    int result = 1;
    if ((root1 != NULL) && (root2 != NULL)) {
        if ((strcmp(root1->container.nama, root2->container.nama) != 0) && (root1->container.nilai != root2->container.nilai)) {
            result = 0;
        } else {
            if ((root1->child != NULL) && (root2->child != NULL)) {
                if (root1->child->sibling == NULL) {
                    result = isEqual(root1->child, root2->child);
                } else {
                    simpul *point1 = root1->child;
                    simpul *point2 = root2->child;

                    while (point1->sibling != root1->child) {
                        if ((point1 != NULL) && (point2 != NULL)) {
                            result = isEqual(point1, point2);
                            point1 = point1->sibling;
                            point2 = point2->sibling;
                        } else {
                            result = 0;
                            break;
                        }
                    }
                    result = isEqual(point1, point2);
                }
            }
        }
    } else {
        if ((root1 != NULL) || (root2 != NULL)) {
            result = 0;
        }
    }
    return result;
}