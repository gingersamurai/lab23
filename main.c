#include "tree.h"


// некрасиво выводит дерево. нужно исправить


int main(){
    node *root = NULL;

    int flag = 1;
    // char query[MAXN];
    // while (flag){
    //     print_menu();
        // scanf("%s", query);
        // if (strcmp(query, "add") == 0){
        //     break;
        // } else if (query[0] == 'a'){
        //     int x;
        //     scanf("%d", &x);
        //     node *new_node = create_node(x);
        //     if (root == NULL){
        //         root = new_node;
        //     } else {
        //         insert_node(root, new_node);

        //     }
        //     printf("\n");
            
        // } else if (query[0] == 'p'){
            // int have_l[MAXN];
            // for (int i = 0; i < MAXN; i++) have_l[i] = 0;
            // print_tree(root, 0, have_l);
        // }

    // }
    int query;
    int have_l[MAXN];
    while (1000-7 == 1000-7){
        print_menu();
        scanf("%d", &query);
        if (query == 1) {
            printf("введите новую вершину: ");
            int x;
            scanf("%d", &x);
            node *new_node = create_node(x);
            if (root == NULL){
                root = new_node;
            } else {
                insert_node(root, new_node);
            }
        } else if (query == 2){
            printf("введите вершину: ");
            int x;
            scanf("%d", &x);
            node *res = find_node(root, x);
            if (res == NULL){
                printf("такой вершины нет\n");
            } else {
                printf("такая вершина есть!\n");
            }
            delete_node(res);

        } else if (query == 3){
            
            printf("введите искомую вершину: ");
            int x;
            scanf("%d", &x);
            node *res = find_node(root, x);
            if (res == NULL){
                printf("такой вершины нет\n");
            } else {
                printf("такая вершина есть!\n");
            }
        } else if (query == 4){
            int cnt_d[MAXN];
            for (int i = 0; i < MAXN; i++) cnt_d[i] = 0;
            count_width(root, 0, cnt_d);
            int max_width = 0;
            for (int i = 0; i < MAXN; i++){
                if (cnt_d[i] == 0) break;
                if (max_width < cnt_d[i]) max_width = cnt_d[i];
                printf("слой %d: %d\n", i+1, cnt_d[i]);
            }
            printf("ширина дерева: %d\n", max_width);
        } else if (query == 5) {
            if (root == NULL) continue;
            int have_l[MAXN];
            for (int i = 0; i < MAXN; i++) have_l[i] = 0;
            print_tree(root, 0, have_l);
        } else if (query == 6) {
            break;
        } else {
            printf("попробуйте ещё раз.\n");
        }
    }
    // printf("\n\nOK\n");
}