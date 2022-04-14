#include "tree.h"


// некрасиво выводит дерево. нужно исправить


int main(){
    node *root = NULL;

    int flag = 1;
    char query[MAXN];
    while (flag){
        print_menu();
        scanf("%s", query);
        if (query[0] == 'e'){
            break;
        } else if (query[0] == 'a'){
            int x;
            scanf("%d", &x);
            // fprintf(stderr, "\n-creating node %d-\n", x);
            node *new_node = create_node(x);
            // fprintf(stderr, "\n-node %d created-\n", x);
            // fprintf(stderr, "\nadress: %p\n", new_node);
            if (root == NULL){
                fprintf(stderr, "\n-making root-\n");
                root = new_node;
            } else {
                // fprintf(stderr, "\n-insent %p to %p-\n", new_node, root);
                insert_node(root, new_node);

            }
            // fprintf(stderr, "\n-node added-\n");

            printf("\n");
            
        } else if (query[0] == 'p'){
            int have_l[MAXN];
            for (int i = 0; i < MAXN; i++) have_l[i] = 0;
            print_tree(root, 0, have_l);
        }
    }
    printf("\n\nOK\n");
}