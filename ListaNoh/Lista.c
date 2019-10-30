#include <stdio.h>
#include <stdlib.h>

struct no {

    int info;
    struct no *prox;
};

struct no * inserirNoInicio(struct no *L, int v){
/*
1º Alocar espaço de memória p/ o novo noh (malloc);
2º Colocar a informação no novo noh (v);
3º Fazer o encadeamento do novo noh no início da lista, ou seja
atribuir ao campo prox do novo noh, o endereço do 1º noh da lista;
4º Fazer a lista apontar para o novo noh que passa a ser o 1º;
*/
    struct no *p;

    //Aloca espaço de memória para o novo noh
    p = (struct no *) malloc(sizeof(struct no));
    p->info = v; //Coloca a informação no novo noh
    p->prox = L; //Faz o encadeamento do novo noh no início da lista
    L = p; //Faz a lista apontar para o novo noh, o qual passa a ser o primeiro
    return L; //Retorna o endereço do novo noh para a atualizar a lista no prog. principal
}//Fim inserirNoInicio()

struct no * inserirNoFim(struct no *L, int v){
/*
1º Alocar espaço na memória
2º Colocar a informação no novo noh (colocar NULL no campo prox)
3º Localizar o último noh da lista
4º Fazer o encadeamento do novo noh no fim da lista
*/
    struct no *p, *n;

    //Aloca espaço de memória para o novo noh
    n = (struct no *) malloc(sizeof(struct no));
    n->info = v; //Coloca a informação no novo noh
    n->prox = NULL; //Como sera o último noh, seu prox é NULL
    if (L==NULL){
        return n; //tratamento de Lista vazia
    }
    //Localizar o último noh da Lista
    p = L; //Aponta p para o primeiro
    while(p->prox != NULL)
        p = p->prox; //Anda o p até o último noh
    p->prox = n; //Faz o encadeamento do último noh com o novo noh
    return L;
}//Fim inserirNoInicio()

void imprimirLista(struct no *L){

    struct no *p;

    if(L==NULL){ //Tratamento de lista vazia
        printf("Lista vazia!");
        system("pause");
        return;
    }
    p = L; //Aponta p para o primeiro noh da lista
    while (p != NULL){
        printf("%i->", p->info);
        p = p->prox;
    }
    system("pause");
}//Fim imprimirLista()

struct no *removerDoInicio(struct no *L, int *v){

    struct no *p;

    p = L; //Aponta p para o primeiro noh, o qual será removido
    *v = p->info; //Coloca em val (através de v) a informação do noh removido
    L = p->prox; //Aponta L para o segundo noh, o qual passa a ser o primeiro
    free(p); //Libera espaço de memória usada pelo noh removido
    return L;
};//Fim removerDoInicio()

struct no *removerDoFim(struct no *L, int *v){

    struct no *p, *q;

    p = L;
    while (p->prox != NULL) //Posicionar o p no último noh
        p = p->prox;

    if (L->prox!=NULL){ //Lista tem mais de 1 noh
        q = L;
        while (q->prox != p) //Posiciona q no noh anterior ao p
            q = q->prox;
        q->prox = NULL; //Finaliza a Lista do penultimo noh
    }else{ //Lista só tem 1 noh
        L = NULL;
    }
    *v = p->info; //Pega a informação no noh que será removido
    free(p); //Libera memoria do noh removido
    return L;
}//Fim removerDoFim()

int comprimentoLista(struct no *L){

    struct no *p;
    int cont=0;

    p = L;
    while (p!=NULL){
        cont++;
        p = p->prox;
    }
    return cont;
}//Fim comprimentoLista()

int existe(struct no *L, int v){

    struct no *p;
    int achou=0;

    p = L;
    while ((p!=NULL)&&(!achou)){
        if (p->info==v) //Encontrou o noh que tem o valor procurado
            achou = 1;
        p = p->prox;
    }
    return achou;
}//Fim existe()

struct no *localizaRemove(struct no *L, int v){

    struct no *p, *q;

    if(!existe(L, v)){
        printf("\nO valor solicitado NAO existe na Lista");
        return L;
    }

    p=L;
    while(p->info!=v) //Posicionar p no noh que contém o valor
        p = p->prox; //Primeira ocorrencia do valor procurado

    if(p==L){ //O noh a ser removido é o primeiro da Lista
        L = p->prox; //Faz l apontar para o segundo noh, que sera o primeiro
    }else{ //O noh a ser removido é do meio ou fim da lista
        q=L;
        while(q->prox!=p) //Posiciona q no noh anterior ao p
            q = q->prox;
        q->prox = p->prox; //Faz o encadeamento
    }
    free(p);
    printf("\nNoh removido com sucesso!");
    return L;
}//Fim localizaRemove

int main() {
struct no *Lista;
int op, val;

Lista = NULL; //Cria a Lista Vazia

do{
    system("cls");
    printf("\n***************************************");
    printf("\n*1) Inserir no Inicio da Lista        *");
    printf("\n*2) Inserir no Fim da Lista           *");
    printf("\n*3) Imprimir a Lista                  *");
    printf("\n*4) Remover do Inicio da Lista        *");
    printf("\n*5) Remover do Fim da Lista           *");
    printf("\n*6) Comprimento da Lista              *");
    printf("\n*7) Localizar valor na Lista          *");
    printf("\n*8) Localizar e remover da Lista      *");
    printf("\n*0) Sair                              *");
    printf("\n*                                     *");
    printf("\n*Opcao->                              *");
    printf("\n***************************************");

    printf("\n\n");
    fflush(stdin); scanf("%i",&op);

    switch(op){

    case 1: //Insere um novo noh no Inicio da Lista
        printf("\nDigite o valor: ");
        fflush(stdin); scanf("%i", &val);
        Lista = inserirNoInicio(Lista, val);
        break;

    case 2: //Insere um novo noh no Fim da Lista
        printf("\nDigite o valor: ");
        fflush(stdin); scanf("%i", &val);
        Lista = inserirNoFim(Lista, val);
        break;

    case 3: //Imprimir os elementos da Lista
        printf("\nLista ->");
        imprimirLista(Lista);
        break;

    case 4: //Remover o noh do início da lista, retornando a informação do noh
        if (Lista==NULL){
            printf("\nLista vazia! Impossivel remover!");
            system("pause");
        }else{
            Lista = removerDoInicio(Lista, &val);
            printf("\nInformacao removida: %i", val);
            system("pause");
        } break;

    case 5: //Remover o noh do início da lista, retornando a informação do noh
        if (Lista==NULL){
            printf("\nLista vazia! Impossivel remover!");
            system("pause");
        }else{
            Lista = removerDoFim(Lista, &val);
            printf("\nInformacao removida: %i", val);
            system("pause");
        } break;

    case 6: //Comprimento da Lista - Nro. de nohs da Lista
        printf("\nComprimento da Lista: %i", comprimentoLista(Lista));
        system("pause");
        break;

    case 7: //Localizar valor na lista
        printf("\nDigite o valor para localizar: ");
        fflush(stdin); scanf("%i", &val);
        if (existe(Lista, val))
            printf("\nO valor %i existe na lista", val);
        else
            printf("\nO valor %i nao existe na lista", val);
        system("pause");
        break;

    case 8: //Remover o noh que contém a primeira ocorrência de uma determinada informação
        printf("\nDigite o valor a ser localizado e removido");
        fflush(stdin); scanf("%i", &val);
        Lista = localizaRemove(Lista, val);
        break;
    }
}while (op!=0);
    return 0;
}//Fim main()
