#include "tree.h"

void print_menu(){
    printf("┌────────────────────────────┐\n");
    printf("│1.добавить в дерево вершину │\n");
    printf("│2.удалить из дерева вершину │\n");
    printf("│3.найти вершину в дереве    │\n");
    printf("│4.найти ширину дерева       │\n");
    printf("│5.визуализировать дерево    │\n");
    printf("│6.завершить работу программы│\n");
    printf("└────────────────────────────┘\n");
    printf("введите запрос: ");
}



node *create_node(dtype value){
    node *res_node = (node *) malloc(sizeof(node));
    res_node->data = value;
    res_node->l = NULL;
    res_node->r = NULL;
    res_node->prev = NULL;

    return res_node;
}

void insert_node(node *now_node, node *cur_node){
    // fprintf(stderr, "\n(%d)\n", now_node->data);
    if (cur_node->data < now_node->data){
        if (now_node->l == NULL){
            now_node->l = cur_node;
            cur_node->prev = now_node;
        } else {
            insert_node(now_node->l, cur_node);
        }
    } else {
        if (now_node->r == NULL ){
            now_node->r = cur_node;
            cur_node->prev = now_node;
        } else {
            insert_node(now_node->r, cur_node);
        }
    }
}

void print_tree(node *now_node, int depth, int have_l[MAXN]){
    printf("%f", now_node->data);
    if (now_node->l != NULL){
        have_l[depth] = 1;
    }
    if (now_node->r == NULL){
        printf("\n");
    } else {
        if (now_node->data > -1 && now_node->data < 10){
            printf("───────");
        } else if (now_node->data > -10 && now_node->data < 100){
            printf("──────");
        } else {
            printf("─────");
        }  
        
        print_tree(now_node->r, depth+1, have_l);
    }

    if (now_node->l != NULL){
        for (int i = 0; i < depth; i++) {
            if (have_l[i] == 1){
                printf("│              ");
            } else {
                printf("               ");
            }
            
        }
        printf("└──────────────");
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
        if (cur_node == cur_node->prev->l) cur_node->prev->l = NULL;
        else cur_node->prev->r = NULL;
        free(cur_node);
    } else if (cur_node->l == NULL && cur_node->r != NULL){
        node *new_cur = cur_node->r;
        node *old_prev = cur_node->prev;
        if (old_prev->r == cur_node){
            free(cur_node);
            old_prev->r = new_cur;
        } else {
            free(cur_node);
            old_prev->l = new_cur;
        }
        
        // cur_node = buff;
    } else if (cur_node->l != NULL && cur_node->r == NULL){
        node *new_cur = cur_node->l;
        node *old_prev = cur_node->prev;
        if (old_prev->r == cur_node){
            free(cur_node);
            old_prev->r = new_cur;
        } else {
            free(cur_node);
            old_prev->l = new_cur;
        }
    } else {
        node *min_node = cur_node->r;
        while (min_node->l != NULL) min_node = min_node->l;
        cur_node->data = min_node->data;
        delete_node(min_node);
    }
}

void another_print_tree(node *now_node, int depth){
    
    if (now_node->r != NULL) another_print_tree(now_node->r, depth+1);
    for(int i = 0; i < depth; i++) printf("            ");
    printf("%f\n\n", now_node->data);
    if (now_node->l != NULL) another_print_tree(now_node->l, depth+1);
}


void count_width(node *now_node, int depth, int cnt_d[MAXN]){
    if (now_node == NULL) return;
    cnt_d[depth]++;
    count_width(now_node->l, depth+1, cnt_d);
    count_width(now_node->r, depth+1, cnt_d);
}

