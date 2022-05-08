typedef struct no no;

typedef struct pilhaL pilhaList;

pilhaList* criaL(pilhaList *p1);

pilhaList* pushL(pilhaList* p1, float v);

float popL(pilhaList *p1);

void imprimirL(pilhaList *p1);

void limpa(pilhaList *p1);

int testaMaisElementosL(pilhaList *p1, pilhaList *p2);

void inverterL(pilhaList *p1);

void transferirElementosL(pilhaList *p1, pilhaList *p2, int *flag);

int iguaisL(pilhaList *p1, pilhaList *p2);

int verifExpressaoL(char *e);

int verifXCYL(char *frase);
