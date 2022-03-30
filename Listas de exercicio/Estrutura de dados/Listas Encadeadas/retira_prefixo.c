lista* retira_prefixo(lista* l, int n){
    lista *p = l;
    int i = 0;
    while(p->prox != NULL && i < n){
        p = p->prox;
        i++;
    }
    l->info = p->info;
    l->prox = p->prox;
    return l;
}