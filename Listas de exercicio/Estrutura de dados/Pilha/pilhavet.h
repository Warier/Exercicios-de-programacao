typedef struct pilha pilhaVet;

pilhaVet* cria();

void push(pilhaVet *p1, float v);

float pop(pilhaVet *p1);

void imprimir(pilhaVet *p1);

int testaMaisElementos(pilhaVet *p1, pilhaVet *p2);

void transferirElementos(pilhaVet *p1, pilhaVet *p2, int *flag);

void inverter(pilhaVet *p1);

int iguais(pilhaVet *p1, pilhaVet *p2);

int verifExpressao(char *e);

int verifXCY(char *frase);
