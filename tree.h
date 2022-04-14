#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000


typedef int dtype;
typedef struct Node node;

struct Node{
    dtype data;
    node *l;
    node *r;
};


void print_menu();





// создаем новый узел
node *create_node(dtype value);

// добавляем узел в бинарное дерево поиска
void insert_node(node *now_node, node *cur_node);

// визуализируем дерево
void print_tree(node *now_node, int depth, int have_l[MAXN]);








#endif