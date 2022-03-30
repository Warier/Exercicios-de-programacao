lista* concatena(lista*l, lista* l2){
    lista *p = l;
    while(p->prox!=NULL){
        p = p->prox;
    }
    p->prox = l2;
    return l;
}