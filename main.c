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
        } else if (query == 2) {
            if (root == NULL) continue;
            int have_l[MAXN];
            for (int i = 0; i < MAXN; i++) have_l[i] = 0;
            print_tree(root, 0, have_l);
        } else if (query == 3) {
            break;
        } else {
            printf("попробуйте ещё раз.\n");
        }
    }
    // printf("\n\nOK\n");
}