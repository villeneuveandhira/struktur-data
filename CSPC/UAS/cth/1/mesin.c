/*Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan soal Ulangan Akhir Semester
dalam mata kuliah Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.*/

/*lib*/
#include "header.h"

// to make space in between node
int counter = 0;

/*make tree*/
void makeTree(int num, int div, tree *T) {
    node *newNode;
    newNode = (node *)malloc(sizeof(node));
    newNode->container.num = num;
    newNode->container.div = div;
    newNode->right = NULL;
    newNode->left = NULL;
    (*T).root = newNode;
    newNode = NULL;
}

/*add left*/
void addLeft(int num, int div, node *root) {
    // if sub-tree->left is empty
    if (root->left == NULL) {
        node *newNode;
        newNode = (node *)malloc(sizeof(node));
        newNode->container.num = num;
        newNode->container.div = div;
        newNode->right = NULL;
        newNode->left = NULL;
        root->left = newNode;
    } else {
        printf("sub pohon kiri telah terisi.\n");
    }
}

/*add right*/
void addRight(int num, int div, node *root) {
    // if sub-tree->right is empty
    if (root->right == NULL) {
        node *newNode;
        newNode = (node *)malloc(sizeof(node));
        newNode->container.num = num;
        newNode->container.div = div;
        newNode->right = NULL;
        newNode->left = NULL;
        root->right = newNode;
    } else {
        printf("sub pohon kanan telah terisi.\n");
    }
}

/*dell all*/
void delAll(node *root) {
    if (root != NULL) {
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

/*dell right*/
void delRight(node *root) {
    if (root != NULL) {
        if (root->right != NULL) {
            delAll(root->right);
            root->right = NULL;
        }
    }
}

/*dell left*/
void delLeft(node *root) {
    if (root != NULL) {
        if (root->left != NULL) {
            delAll(root->left);
            root->left = NULL;
        }
    }
}

/*pre order*/
void printTreePreOrder(node *root) {
    if (root != NULL) {
        if ((root->left == NULL)) {
            printf("%d %d ", root->container.num, root->container.div);
        }
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

/*in order*/
void printTreeInOrder(node *root) {
    if (root != NULL) {
        printTreeInOrder(root->left);
        if (counter != 0) {
            printf(" ");
        }
        printf("%d", root->container.num);
        counter++;
        printTreeInOrder(root->right);
    }
}

/*post order*/
void printTreePostOrder(node *root) {
    if (root != NULL) {
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        printf("%d %d ", root->container.num, root->container.div);
    }
}

/*copy tree*/
void copyTree(node *root1, node **root2) {
    if (root1 != NULL) {
        (*root2) = (node *)malloc(sizeof(node));
        (*root2)->container = root1->container;
        if (root1->left != NULL) {
            copyTree(root1->left, &(*root2)->left);
        }
        if (root1->right != NULL) {
            copyTree(root1->right, &(*root2)->right);
        }
    }
}

/*check equal*/
int isEqual(node *root1, node *root2) {
    int result = 1;
    if ((root1 != NULL) && (root2 != NULL)) {
        if ((root1->container.num != root2->container.num) && (root1->container.div != root2->container.div)) {
            result = 0;
        } else {
            isEqual(root1->left,
                    root2->left);
            isEqual(root1->right,
                    root2->right);
        }
    } else {
        if ((root1 != NULL) ||
            (root2 != NULL)) {
            result = 0;
        }
    }
    return result;
}

/*depth*/
int heightTree(node *root) {
    int max = 0;
    if (root != NULL) {
        int leftRoot = heightTree(root->left);
        int rightRoot = heightTree(root->right);
        if (leftRoot > rightRoot) {
            max = leftRoot + 1;
            return max;
        } else {
            max = rightRoot + 1;
            return max;
        }
    }
}

/*level order*/
void printTreeLevelOrder(node *root, int level) {
    if (root != NULL) {
        if (level == 1) {
            printf("%d %d ", root->container.num, root->container.div);
        } else if (level > 1) {
            printTreeLevelOrder(root->left, level - 1);
            printTreeLevelOrder(root->right, level - 1);
        }
    }
}

/*add*/
void addTree(node *root, int *flag) {
    if (root != NULL) {
        int left, right;
        node *new = root;
        left = new->container.num / 2;
        right = new->container.div / 2;
        if ((left >= 1) && (right >= 1)) {
            *flag = 0;
            if (left == 1 || right == 1) {
                *flag = 1;
            }
            addLeft(left, new->container.div, root);
            addRight(new->container.num, right, root);
        }
        if (*flag != 1) {
            addTree(root->left, flag);
            addTree(root->right, flag);
        }
    }
}

void insertTree(node *root) {
    if (root != NULL) {
        int angka, pembagi, result = 0;
        node *newNode = root;
        angka = newNode->container.num;
        pembagi = newNode->container.div;
        result = angka / pembagi;
        if (result > 0) {
            if (result % 2 != 0) {
                addLeft(result, pembagi, root);
            } else if (result % 2 == 0) {
                addRight(result, pembagi, root);
            }
        }
        insertTree(root->left);
        insertTree(root->right);
    }
}