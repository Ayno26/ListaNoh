#include <stdio.h>
#include <stdlib.h>

struct no {

    int info;
    struct no *prox;
};

struct no * inserirNoInicio(struct no *L, int v){
/*
1� Alocar espa�o de mem�ria p/ o novo noh (malloc);
2� Colocar a informa��o no novo noh (v);
3� Fazer o encadeamento do novo noh no in�cio da lista, ou seja
atribuir ao campo prox do novo noh, o endere�o do 1� noh da lista;
4� Fazer a lista apontar para o novo noh que passa a ser o 1�;
*/
    struct no *p;

    //Aloca espa�o de mem�ria para o novo noh
    p = (struct no *) malloc(sizeof(struct no));
    p->info = v; //Coloca a informa��o no novo noh
    p->prox = L; //Faz o encadeamento do novo noh no in�cio da lista
    L = p; //Faz a lista apontar para o novo noh, o qual passa a ser o primeiro
    return L; //Retorna o endere�o do novo noh para a atualizar a lista no prog. principal

}//Fim inserirNoInicio()

struct no * inserirNoFim(struct no *L, int v){
/*
1� Alocar espa�o na mem�ria
2� Colocar a informa��o no novo noh (colocar NULL no campo prox)
3� Localizar o �ltimo noh da lista
4� Fazer o encadeamento do novo noh no fim da lista
*/
    struct no *p, *n;

    //Aloca espa�o de mem�ria para o novo noh
    n = (struct no *) malloc(sizeof(struct no));
    n->info = v; //Coloca a informa��o no novo noh
    n->prox = NULL; //Como sera o �ltimo noh, seu prox � NULL
    if (L==NULL){
        return n; //tratamento de Lista vazia
    }
    //Localizar o �ltimo noh da Lista
    p = L; //Aponta p para o primeiro
    while(p->prox != NULL)
        p = p->prox; //Anda o p at� o �ltimo noh
    p->prox = n; //Faz o encadeamento do �ltimo noh com o novo noh
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
}//Fim imprimir lista()

struct no *removerDoInicio(struct no *L, int *v){

    struct no *p;

    p = L; //Aponta p para o primeiro noh, o qual ser� removido
    *v = p->info; //Coloca em val (atrav�s de v) a informa��o do noh removido
    L = p->prox; //Aponta L para o segundo noh, o qual passa a ser o primeiro
    free(p); //Libera espa�o de mem�ria usada pelo noh removido
    return L;

};//Fim removerDoInicio()

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

    case 4: //Remover o noh do in�cio da lista, retornando a informa��o do noh
        if (Lista==NULL){
            printf("\nLista vazia! Impossivel remover!");
            system("pause");
        }else{
            Lista = removerDoInicio(Lista, &val);
            printf("\nInformacao removida: %i", val);
            system("pause");
            break;
        }
    }
}while (op!=0);
    return 0;
}//Fim main()
