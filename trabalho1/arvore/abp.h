#define N_DATA 36*1024*1024/4 //36MB to overflow cache L3

typedef struct TNodoA {
    int info;
    struct TNodoA* esq;
    struct TNodoA* dir;
} pNodoA;



pNodoA* InsereArvore(pNodoA* a, int ch);
int search(pNodoA* a, int data);