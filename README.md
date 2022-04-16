# Отчет по лабораторной работе N 23 по курсу
# "Фундаментальная информатика"

**студент группы:** М8О-110Б-21, Малышев Назим Бахтиярович\
**Контакты:** nazimmalyshev47@gmail.com\
**работа выполнена:** 14.04.2022\
**Преподаватель:** Никулин Сергей Петрович

## 1. Тема
Динамические структуры данных.

## 2. Цель работы
составить программу на Си построения и обработки дерева

## 3. Задание
Найти ширину бинарного дерева поиска

## 4. Оборудование 
**CPU:** Intel® Core™ i7-8550U\
**RAM:** 8 GB\
**SSD:** 256 GB\
**MONITOR:** 2560 x 1440

## 5. Программное обеспечивание 
**Операционная система семейства:** ubuntu, **версия** 20.04 LTS\
**Интерпретатор команд:** bash, **версия** 5.0.17(1)-release.\
**Система программирования**: --, **версия**-- \
**Редактор текстов:** vs code, **версия** 1.66.1\
**Утилиты операционной системы:** --\
**Прикладные системы и программы:** --

## 6. Идея, метод, алгоритм
1. Составить структуру узлов, в которых есть:
    + номер узла
    + ссылка на левого сына
    + ссылка на правого сына
    + ссылка на родителя
2. реализовать базовый функции:
    + создние узла
    + добавление узла в дерево
    + поиск узла в дереве по значению
    + удаление узла из дерева
    + визуализация дерева
3. реализация основной функции
4. настройка интерфейса взаимодействия с пользователем

# 7. Сценарий выполнения работы
1. реализация дерева
2. настройка makefile
3. отладка
4. создание протокола

# 8. Распечатка протокола
**tree.c**
```cpp
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

void count_width(node *now_node, int depth, int cnt_d[MAXN]){
    if (now_node == NULL) return;
    cnt_d[depth]++;
    count_width(now_node->l, depth+1, cnt_d);
    count_width(now_node->r, depth+1, cnt_d);
}


```
**tree.h**
```
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








#endif
```
**main.c**
```
#include "tree.h"




int main(){
    node *root = NULL;

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
}
```
**Makefile**
```
run : main
	./main

main : tree.o main.o
	gcc main.o tree.o -o main

tree.o : tree.c
	gcc -c tree.c -o tree.o

main.o : main.c
	gcc -c main.c -o main.o
```

пример работы:
```
gingersamurai@LY530:~/lab/lab23$ make
gcc -c main.c -o main.o
gcc main.o tree.o -o main
./main
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 1
введите новую вершину: 4
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 1
введите новую вершину: 6
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 1
введите новую вершину: 3
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 1
введите новую вершину: 5
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 1
введите новую вершину: 3
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 4
слой 1: 1
слой 2: 2
слой 3: 2
ширина дерева: 2
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 5
4───6
│   └───5
└───3───3
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 2
введите вершину: 6
такая вершина есть!
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 4
слой 1: 1
слой 2: 2
слой 3: 1
ширина дерева: 2
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 5
4───5
└───3───3
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 3
введите искомую вершину: 4
такая вершина есть!
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: 3
введите искомую вершину: 7
такой вершины нет
┌────────────────────────────┐
│1.добавить в дерево вершину │
│2.удалить из дерева вершину │
│3.найти вершину в дереве    │
│4.найти ширину дерева       │
│5.визуализировать дерево    │
│6.завершить работу программы│
└────────────────────────────┘
введите запрос: ^Cmake: *** [makefile:2: run] Прерывание

```
## 9. Дневник отладки
--

## 10. Замечания автора
--
# 11. Выводы
Мной была изучена такая структура, как бинарное дерево.\
Составлена программа реализации такого дерева.\
Бинарное дерево – очень полезная структура,
которая может решать различные задачи