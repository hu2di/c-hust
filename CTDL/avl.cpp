#include <stdio.h>
#include <algorithm>
using namespace std;

struct node {
    int value;
    node *ll, *rr, *pp;
    node(int x=0){ ll=rr=pp=0; value=x; }
};

node * root;

int height(node* a){
    if (a==0) return 0;
    return max(
        height(a->ll)+1,
        height(a->rr)+1
    );
}

int abs(int a, int b){ return a>b?a-b:b-a; }

int absdelta(node* a){
    if (a==0) return 0;
    return abs(height(a->ll), height(a->rr));
}

void lljoin(node* a, node* b){
    if (a) a->pp=b;
    if (b) b->ll=a;
    else root=a;
}

void rrjoin(node* a, node* b){
    if (a) a->pp=b;
    if (b) b->rr=a;
    else root=a;
}

void doInsert(node* a, node* b){
    if (b==0) { rrjoin(a, b); return ; }
    if (a==0) { puts("Fatal\n"); return ; }
    if (a->value == b->value) { return ; }
    if (a->value < b->value)
        if (b->ll) doInsert(a, b->ll);
        else lljoin(a, b);
    if (a->value > b->value)
        if (b->rr) doInsert(a, b->rr);
        else rrjoin(a, b);
}

void show(node *a){
    if (a==0) return ;
    printf("(");
    show(a->ll);
    printf(" %d ", a->value);
    show(a->rr);
    printf(")");
}

main(){
    int z;
    while (scanf("%d", &z) > 0){
        doInsert(new node(z), root);
        show(root); printf("\n");
    }
}
