#include <stdio.h>
#include <stdlib.h>

typedef int dtype;
typedef struct Node node;

struct Node{
    dtype data;
    node *l;
    node *r;
};


int main(){
    node *res_node = (node *)malloc(sizeof(node));
    

}