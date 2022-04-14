#include "tree.h"

void print_menu(){
    printf("------------------------------\n");
    printf("|добавить в дерево вершину x:|\n");
    printf("|add                         |\n");
    printf("|x                           |\n");
    printf("|визуализировать дерево:     |\n");
    printf("|print                       |\n");
    printf("|завершить работу программы: |\n");
    printf("|exit                        |\n");
    printf("------------------------------\n");
    printf("введите запрос: ");
}



node *create_node(dtype value){
    node *res_node = (node *) malloc(sizeof(node));
    res_node->data = value;
    res_node->l = NULL;
    res_node->r = NULL;

    return res_node;
}

void insert_node(node *now_node, node *cur_node){
    // fprintf(stderr, "\n(%d)\n", now_node->data);
    if (cur_node->data < now_node->data){
        if (now_node->l == NULL){
            now_node->l = cur_node;
        } else {
            insert_node(now_node->l, cur_node);
        }
    } else {
        if (now_node->r == NULL ){
            now_node->r = cur_node;
        } else {
            insert_node(now_node->r, cur_node);
        }
    }
}

void print_tree(node *now_node, int depth, int have_l[MAXN]){
    printf("%d", now_node->data);
    if (now_node->l != NULL){
        have_l[depth] = 1;
    }
    if (now_node->r == NULL){
        printf("\n");
    } else {
        printf("───");
        print_tree(now_node->r, depth+1, have_l);
    }

    if (now_node->l != NULL){
        for (int i = 0; i < depth; i++) {
            if (have_l[i] == 1){
                printf("│   ");
            } else {
                printf("    ");
            }
            
        }
        printf("└───");
        have_l[depth] = 0;
        print_tree(now_node->l, depth+1, have_l);
    }

}
