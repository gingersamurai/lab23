#ifndef tree_h
#define tree_h

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000


typedef float  dtype;
typedef struct Node node;

struct Node{
    dtype data;
    node *l;
    node *r;
    node *prev;
};


void print_menu();





// создаем новый узел
node *create_node(dtype value);

// добавляем узел в бинарное дерево поиска
void insert_node(node *now_node, node *cur_node);

// удаляем вершину по указателю
void delete_node(node *cur_node);

// находим вершину
node *find_node(node* now_node, dtype value);

// считаем ширину для каждого слоя
void count_width(node *now_node, int depth, int cnt_d[MAXN]);

// визуализируем дерево
void print_tree(node *now_node, int depth, int have_l[MAXN]);

// визуализируем дерево, как хочет этого лабник
void another_print_tree(node *now_node, int depth);






#endif