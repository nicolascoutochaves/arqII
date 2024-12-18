#define N_DATA 10000000

typedef struct TNodoA {
    int info;
    struct TNodoA* esq;
    struct TNodoA* dir;
} pNodoA;



pNodoA* InsereArvore(pNodoA* a, int ch);
int search(pNodoA* a, int data);