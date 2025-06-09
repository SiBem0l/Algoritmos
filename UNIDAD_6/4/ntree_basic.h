#ifndef NTREE_BASIC_H
#define NTREE_BASIC_H

#define NTREE_ELEMENT int

typedef struct _ntn ntn;

typedef struct _ntlist{
    ntn* node;
    struct _ntlist* next;
}ntlist;

typedef struct _ntn{
    NTREE_ELEMENT value;
    ntlist* child;
}ntn;


ntn* ntn_new(NTREE_ELEMENT data);
ntlist* ntlist_new(ntn* node);
ntlist* nt_new(NTREE_ELEMENT data);
void ntn_addSon(ntn* father, ntn* son);

void print_depth(ntn* node);
void print_depth2(ntn* node);
void print_amplitud(ntn* node);

int ntree_size(ntn* node);

int ntree_degree(ntn* node);
int max(int a, int b);
int ntn_degree(ntn* node);

int ntree_sameDegree(ntn* node, int root_degree);

int ntree_height(ntn* node);

ntn* ntree_search(ntn* node, NTREE_ELEMENT data);

#endif