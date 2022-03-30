lista* separa(lista* l, int v){
    lista *p = l, *aux;
    while(p!=NULL && p->info != v){
        p = p->prox;
    }
    if (p == NULL){
        return NULL;
    }
    aux = p->prox;
    p->prox = NULL;
    return aux;
}