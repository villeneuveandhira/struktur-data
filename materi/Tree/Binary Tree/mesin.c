#include "header.h"

void makeTree(char c, tree *T) {
    node *new;
    new = (node *)malloc(sizeof(node));
    new->container = c;
    new->right = NULL;
    new->left = NULL;
    (*T).root = new;
    new = NULL;
}

void addRight(char c, node *root) {
    if (root->right == NULL) {
        node *new;
        new = (node *)malloc(sizeof(node));
        new->container = c;
        new->right = NULL;
        new->left = NULL;
        root->right = new;
    } else {
        printf("sub pohon kanan telah terisi.\n");
    }
}

void addLeft(char c, node *root) {
    if (root->left == NULL) {
        node *new;
        new = (node *)malloc(sizeof(node));
        new->container = c;
        new->right = NULL;
        new->left = NULL;
        root->left = new;
    } else {
        printf("sub pohon kiri telah terisi.\n");
    }
}

void delAll(node *root) {
    if (root != NULL) {
        delAll(root->left);
        delAll(root->right);
        free(root);
    }
}

void delRight(node *root) {
    if (root != NULL) {
        if (root->right != NULL) {
            delAll(root->right);
            root->right = NULL;
        }
    }
}

void delLeft(node *root) {
    if (root != NULL) {
        if (root->left != NULL) {
            delAll(root->left);
            root->left = NULL;
        }
    }
}

void printTreePreOrder(node *root) {
    if (root != NULL) {
        printf(" %c ", root->container);
        printTreePreOrder(root->left);
        printTreePreOrder(root->right);
    }
}

void printTreeInOrder(node *root) {
    if (root != NULL) {
        printTreeInOrder(root->left);
        printf(" %c ", root->container);
        printTreeInOrder(root->right);
    }
}

void printTreePostOrder(node *root) {
    if (root != NULL) {
        printTreePostOrder(root->left);
        printTreePostOrder(root->right);
        printf(" %c ", root->container);
    }
}

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

int isEqual(node *root1, node *root2) {
    int result = 1;
    if ((root1 != NULL) && (root2 != NULL)) {
        if (root1->container != root2->container) {
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

void printTreeLevelOrder(node *root, int level) {
    if (root != NULL) {
        if (level == 1) {
            printf(" %c ", root->container);
        } else if (level > 1) {
            printTreeLevelOrder(root->left, level - 1);
            printTreeLevelOrder(root->right, level - 1);
        }
    }
}