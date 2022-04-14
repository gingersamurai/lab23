#include "tree.h"

void print_menu(){
    printf("┌────────────────────────────┐\n");
    printf("│1.добавить в дерево вершину │\n");
    printf("│2.удалить из дерева вершину │\n");
    printf("│3.найти вершину в дереве    │\n");
    printf("│4.визуализировать дерево    │\n");
    printf("│5.завершить работу программы│\n");
    printf("└────────────────────────────┘\n");
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
        if (now_node->data > -1 && now_node->data < 10){
            printf("───");
        } else if (now_node->data > -10 && now_node->data < 100){
            printf("──");
        } else {
            printf("─");
        }  
        
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

node *find_node(node* now_node, dtype value){
    if (now_node == NULL){
        return NULL;
    } else if (now_node->data == value){
        return now_node;
    } else if (now_node->data > value){
        return find_node(now_node->l, value);
    } else if (now_node->data < value){
        return find_node(now_node->r, value);
    }
}

void delete_node(node *cur_node){
    if (cur_node == NULL) return;
    if (cur_node->l == NULL && cur_node->r == NULL){
        fprintf(stderr, "list\n");
        free(cur_node);
    } else if (cur_node->l == NULL && cur_node->r != NULL){
        fprintf(stderr, "r\n");
        node *buff;
        buff->l = cur_node->r->l;
        buff->r = cur_node->r->r;
        buff->data = cur_node->r->data;
        free(cur_node->r);
        cur_node = buff;
    } else if (cur_node->l != NULL && cur_node->r == NULL){
        fprintf(stderr, "l\n");
        node *buff;
        buff->l = cur_node->l->l;
        buff->r = cur_node->l->r;
        buff->data = cur_node->l->data;
        free(cur_node->l);
        cur_node = buff;
    }
}