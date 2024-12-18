
typedef struct TNodoA{
 int info;
 struct TNodoA *esq;
 struct TNodoA *dir;
} pNodoA;



pNodoA* InsereArvore(pNodoA *a, int ch);

int PreFixado(pNodoA *a);

int Count(pNodoA *a, int *c);

void ShowLevels(pNodoA *a, int n);
