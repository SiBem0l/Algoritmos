#include <stdio.h>
#include <stdlib.h>
#include "ntree_basic.h"
#include "stack.h"
#include "queue.h"

//Crea solo un nodo
ntn* ntn_new(NTREE_ELEMENT data){
    ntn* new_node = (ntn*)malloc(sizeof(ntn));
    new_node->value = data;
    new_node->child = NULL;
}
//Crea una ntlist que apunta al nodo que se paso
ntlist* ntlist_new(ntn* node){
    ntlist* new_ntlist = (ntlist*)malloc(sizeof(ntlist));
    new_ntlist->node = node;
    new_ntlist->next = NULL;
    return new_ntlist;
}
//Crea el nodo y crea una lista que apunta a el
ntlist* nt_new(NTREE_ELEMENT data){
    return ntlist_new(ntn_new(data));
}

//Agregar como hijo a otro nodo
void ntn_addSon(ntn* father, ntn* son){
    ntlist* son_list = ntlist_new(son);
    ntlist** list_add = &(father->child);
    while(*list_add != NULL){
        list_add = &((*list_add)->next);
    }
    *list_add = son_list;
}

//Recorrer en profundidad (iterativo)
void print_depth(ntn* node){
    stack* s = stack_new(100);
    stack_push(s, node);

    while(stack_isEmpty(s) == 0){
        node = stack_pop(s);
        ntlist* list_son = node->child;
        while(list_son != NULL){
            stack_push(s, list_son->node);
            list_son = list_son->next;
        }
        printf("%d ", node->value);
    }
    printf("\n");
    stack_free(&s);
}
//Recorrer en profundidad (recursivo - iterativo)
void print_depth2(ntn* node){
    if(node == NULL) return;
    printf("%d ", node->value);
    ntlist* curr_ntlist = node->child;
    while(curr_ntlist != NULL){
        print_depth2(curr_ntlist->node);
        curr_ntlist = curr_ntlist->next;
    }
}

//Imprime el arbol por (iterativo)
void print_amplitud(ntn* node){
    if(node == NULL) return;
    queue* q = queue_new(100);
    queue_enqueue(q, node);

    while(queue_isEmpty(q) == 0){
        node = queue_dequeue(q);
        ntlist* list_son = node->child;
        while(list_son != NULL){
            queue_enqueue(q, list_son->node);
            list_son = list_son->next;
        }
        printf("%d ", node->value);
    }
    printf("\n");
    queue_free(&q);
}

//Contar cantidad de nodos
int ntree_size(ntn* node){
    if(node == NULL) return 0;
    int size = 1; 
    ntlist* curr_ntlist = node->child;
    while(curr_ntlist != NULL){
        size += ntree_size(curr_ntlist->node);
        curr_ntlist = curr_ntlist->next;
    }
    return size;
}

//Devuelve el grado maximo de un ntree
int ntree_degree(ntn* node){
    if(node == NULL) return 0;
    int max_degree = ntn_degree(node); //grado del primer nodo
    ntlist* curr_ntlist = node->child;
    while(curr_ntlist != NULL){
        max_degree = max(max_degree, ntree_degree(curr_ntlist->node));
        curr_ntlist = curr_ntlist->next;
    }
    return max_degree;
}
//Devuelve el maximo entre dos valores
int max(int a, int b){
    int ans = 0;
    if(a < b){
        ans = b;
    }else{
        ans = a;
    }
    return ans;
}
//Devuelve el grado de un nodo
int ntn_degree(ntn* node){
    int degree = 0;
    ntlist* curr_ntlist = node->child;
    while(curr_ntlist != NULL){
        degree++;
        curr_ntlist = curr_ntlist->next;
    }
    return degree;
}

//Fijarse si todo el arbol tiene el mismo grado exepto por las hojas
int ntree_sameDegree(ntn* node, int root_degree){
    if(node == NULL) return 1;
    int flag = 1;
    int node_degree = ntn_degree(node);
    if(root_degree != node_degree && node_degree != 0){
        flag = 0;
    }
    ntlist* curr_ntlist = node->child;
    while(curr_ntlist != NULL && flag == 1){
        flag = ntree_sameDegree(curr_ntlist->node, root_degree);
        curr_ntlist = curr_ntlist->next;
    }
    return flag;
}

//Altura de un arbol
int ntree_height(ntn* node){
    if(node == NULL) return -1;
    int son_height = -1;
    ntlist* curr_ntlist = node->child;
    while(curr_ntlist != NULL){
        son_height = max(son_height, ntree_height(curr_ntlist->node));
        curr_ntlist = curr_ntlist->next;
    }
    return son_height + 1;
}
  
//Busca el puntero al dato deseado
ntn* ntree_search(ntn* node, NTREE_ELEMENT data){
    if(node == NULL) return NULL;
    ntn* ans = NULL;
    if(node->value == data){
        ans = node;
    }else{
        ntlist* curr_ntlist = node->child;
        while(curr_ntlist != NULL && ans == NULL){
            ans = ntree_search(curr_ntlist->node, data);
            curr_ntlist = curr_ntlist->next;
        }
    }
    return ans;
} 