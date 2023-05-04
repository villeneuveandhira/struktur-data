/*
Saya Villeneuve Andhira Suwandhi NIM 2108067 mengerjakan evaluasi Tugas Masa Depan dalam mata kuliah
Struktur Data untuk keberkahanNya maka saya tidak melakukan kecurangan
seperti yang telah dispesifikasikan. Aamiin.
*/

/*lib*/
#include "header.h"

// global variable
int max[201];

/*tree initialization*/
void makeTree(char name[], char num[], char parent[], int value, int idx, int flag, char comp[][201], tree *T) {
    // init
    node *point;
    point = (node *)malloc(sizeof(node));
    // copy variable into data
    strcpy(point->container.name, name);
    strcpy(point->container.parent, parent);
    strcpy(point->container.num, num);
    point->container.value = value;
    point->container.idx = idx;
    point->container.flag = flag;
    for (int i = 0; i < idx; i++) {
        strcpy(point->container.component[i], comp[i]);
    }
    // create sibling & child pointer
    point->sibling = NULL;
    point->child = NULL;
    (*T).root = point;
}

/*add child*/
void addChild(char name[], char num[], char parent[], int value, int idx, int flag, char comp[][201], node *root) {
    // as long the node isn't NULL
    if (root != NULL) {
        // init
        node *new;
        new = (node *)malloc(sizeof(node));
        // copy variable into data
        strcpy(new->container.name, name);
        strcpy(new->container.parent, parent);
        strcpy(new->container.num, num);
        new->container.value = value;
        new->container.idx = idx;
        new->container.flag = flag;
        for (int i = 0; i < idx; i++) {
            strcpy(new->container.component[i], comp[i]);
        }
        new->child = NULL;
        // if the root node has no child nodes then the new node becomes the first child
        if (root->child == NULL) {
            new->sibling = NULL;
            root->child = new;
        } else {
            // if the root node has children that do not yet have siblings, then the new node becomes the second child
            if (root->child->sibling == NULL) {
                new->sibling = root->child;
                root->child->sibling = new;
            }
            // looking for the last child, the last child node is the sibling of the first child node, the last pointer will go to the next node
            else {
                node *last = root->child;
                while (last->sibling != root->child) {
                    last = last->sibling;
                }
                new->sibling = root->child;
                last->sibling = new;
            }
        }
    }
}

/*delete all*/
void delAll(node *root) {
    if (root != NULL) {
        if (root->child != NULL) {
            // if it has only one child node
            if (root->child->sibling == NULL) {
                delAll(root->child);
            }
            // if it has more than one child node
            else {
                node *point;
                node *process;
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

/*delete child*/
void delChild(char str[], node *root) {
    if (root != NULL) {
        node *point = root->child;
        if (point != NULL) {
            // if it has only one child node
            if (point->sibling == NULL) {
                if (strcmp(root->child->container.name, str) == 0) {
                    delAll(root->child);
                    root->child = NULL;
                }
            }
            // if it has more than one child node
            else {
                node *prev = NULL;
                int found = 0;
                while ((point->sibling != root->child) && (found == 0)) {
                    if (strcmp(point->container.name, str) == 0) {
                        found = 1;
                    } else {
                        prev = point;
                        point = point->sibling;
                    }
                }
                if ((found == 0) && (strcmp(point->container.name, str) == 0)) {
                    found = 1;
                }
                if (found == 1) {
                    node *last = root->child;
                    // checks if the last child was deleted
                    while (last->sibling != root->child) {
                        last = last->sibling;
                    }
                    if (prev == NULL) {
                        // if the first child is removed
                        if ((point->sibling == last) && (last->sibling == root->child->sibling)) {
                            root->child = last;
                            last->sibling = NULL;
                        }
                        // if it has more than two child nodes
                        else {
                            root->child = point->sibling;
                            last->sibling = root->child;
                        }
                    } else {
                        // if there are only two child nodes and what is deleted is the second child node
                        if ((prev == root->child) && (last->sibling == root->child->sibling)) {
                            root->child->sibling = NULL;
                        }
                        // if what is removed is not the first child node and the root node has more than two child nodes
                        else {
                            prev->sibling = point->sibling;
                            point->sibling = NULL;
                        }
                    }
                    delAll(point);
                }
            }
        }
    }
}

/*find node in tree*/
node *findNode(char str[], node *root) {
    // variable to be returned
    node *result = NULL;
    if (root != NULL) {
        if (strcmp(root->container.name, str) == 0) {
            result = root;
        } else {
            node *point = root->child;
            if (point != NULL) {
                // if it has one child node
                if (point->sibling == NULL) {
                    if (strcmp(point->container.name, str) == 0) {
                        result = point;
                    } else {
                        result = findNode(str, point);
                    }
                }
                // if it has many child nodes
                else {
                    int found = 0;
                    while ((point->sibling != root->child) && (found == 0)) {
                        if (strcmp(point->container.name, str) == 0) {
                            result = point;
                            found = 1;
                        } else {
                            result = findNode(str, point);
                            point = point->sibling;
                            if (result != NULL) {
                                found = 1;
                            }
                        }
                    }
                    if (found == 0) {
                        if (strcmp(point->container.name, str) == 0) {
                            result = point;
                        } else {
                            result = findNode(str, point);
                        }
                    }
                }
            }
        }
    }
    return result;
}

/*print space*/
void distance(int total) {
    for (int i = 0; i < total; i++) {
        printf(" ");
    }
}

/*print tree (PreOrder)*/
void printTreePreOrder(node *root, int count, int lvl) {
    if (root != NULL) {
        // if it's not the first node in tree then give a new line spacing
        if (count != 0) {
            printf("\n");
        }
        // print the data
        distance(count);
        printf("|%s - %d\n", root->container.name, root->container.value);
        // print the components
        for (int j = 0; j < root->container.idx; j++) {
            distance(count);
            printf(" - %s\n", root->container.component[j]);
        }
        // iteration every level
        count += max[lvl];
        lvl++;
        // recursive
        node *point = root->child;
        if (point != NULL) {
            // if it has one child node
            if (point->sibling == NULL) {
                printTreePreOrder(point, count, lvl);
            }
            // if it has many child nodes
            else {
                // print all the child nodes
                while (point->sibling != root->child) {
                    printTreePreOrder(point, count, lvl);
                    point = point->sibling;
                }
                // last child node
                printTreePreOrder(point, count, lvl);
            }
        }
    }
}

/*split string for input*/
void split(char str[], char cw[], char temp[]) {
    // init
    int idx = 0, cl = 0;
    // copy string before delimiter ('#')
    while (str[idx] != '#') {
        cw[cl] = str[idx];
        cw[cl + 1] = '\0';
        idx++;
        cl++;
    }
    // pass through '#' index + 1, and reset cl (current-length) to zero
    idx += 1;
    cl = 0;
    // copy the remaining string after delimiter ('#')
    while (idx < strlen(str)) {
        temp[cl] = str[idx];
        temp[cl + 1] = '\0';
        idx++;
        cl++;
    }
}

/*converts char value(s) to integer*/
int toInt(char *str) {
    // init
    int number = 0;
    // iteration for every all elements in the parameter
    for (int i = 0; i < strlen(str); i++) {
        // multiplying the result by 10 each time it finds a new element
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + (str[i] - '0');
        } else {
            return -1;
        }
    }
    return number;
}

/*find the depth according to the tree level*/
void depth(int deep, node *root) {
    // init
    int len, temp;
    if (root != NULL) {
        // calculates the length of the node name and node value plus any other space-characters
        len = strlen(root->container.name) + strlen(root->container.num) + 4;
        // calculates the length of the node component plus any other space-characters
        for (int i = 0; i < root->container.idx; i++) {
            if ((strlen(root->container.component[i])) > (strlen(root->container.component[i - 1]))) {
                temp = strlen(root->container.component[i]) + 3;
            }
        }
        // choose the longest one between len or temp (+1 for a gap space)
        if (len > temp) {
            len = len + 1;
            // check if it's longer than the max
            if (len > max[deep]) {
                max[deep] = len;
            }
        } else if (len < temp) {
            temp = temp + 1;
            // check if it's longer than the max
            if (temp > max[deep]) {
                max[deep] = temp;
            }
        }
        // iteration (as the level of tree)
        deep++;
        // recursive
        node *point = root->child;
        if (point != NULL) {
            if (point->sibling == NULL) {
                depth(deep, point);
            } else {
                while (point->sibling != root->child) {
                    depth(deep, point);
                    point = point->sibling;
                }
                depth(deep, point);
            }
        }
    }
}

/*find and delete nodes whose value is less than the minimum*/
void mark(int value, node *root) {
    if (root != NULL) {
        // if the value is below than the min, set flag to 1 (means it has to be removed later)
        if (root->container.value < value) {
            root->container.flag = 1;
        }
        // recursive
        node *point = root->child;
        if (point != NULL) {
            if (point->sibling == NULL) {
                mark(value, point);
            } else {
                while (point->sibling != root->child) {
                    mark(value, point);
                    point = point->sibling;
                }
                mark(value, point);
            }
        }
    }
}

/*remove child nodes whose flag is '1'*/
void delMark(int idx, char list[][201], node *root) {
    for (int i = 0; i < idx; i++) {
        // find the node in tree
        node *find = NULL;
        find = findNode(list[i], root);
        if (find != NULL) {
            // checks if the flag is 1
            if (find->container.flag == 1) {
                // find the parent
                node *parent = NULL;
                parent = findNode(find->container.parent, root);
                if (parent != NULL) {
                    // delete (node, parent)
                    delChild(find->container.name, parent);
                }
            }
        }
    }
}