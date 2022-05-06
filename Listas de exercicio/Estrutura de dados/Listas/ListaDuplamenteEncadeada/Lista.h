typedef struct lista2 Lista2;

Lista2* insereFim(Lista2 *L, int v);

void imprimir(Lista2 *L);

int conteListaRecursiva (Lista2* l);

int conteListaIterativa (Lista2* l);

int crescente(Lista2* l); // retorna 1 caso seja verdadeira e 0

int compara(Lista2* l1, Lista2* l2); //retorna 1 se for igual e 0 se for diferente

Lista2* troca(Lista2* l, int a, int b);
