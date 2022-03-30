lista* insereFim(lista* l1, int v){
    lista *novo, *p = l1;
    novo = (lista*) malloc(sizeof(lista));
    novo->info = v;
    novo->prox = NULL;
    if(l1 != NULL) {
        while(p->prox != NULL){
            p = p->prox;
        }
        p->prox = novo;
        return l1;
    }else {
        return novo;
    }
}

lista* constroi (int n, int* v){
    lista *l1 = NULL;
    for (int i = 0; i < n; i++){
        l1 = insereFim(l1, v[i]);
    }
    return l1;
}