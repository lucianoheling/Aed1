// Luciano Ludwig Heling
// Matrícula: 20201961 - Aed1 - M1

// Inserir dados em uma árvore enquanto o usuário desejar 
// e após isso revelar se a arvore é AVL.

#include<stdio.h>
#include<stdlib.h>

struct Nodo{
  int conteudo;
  struct Nodo *esquerda;
  struct Nodo *direita;
  int altura;
};
 
int max(int a, int b);
 
int altura(struct Nodo *N){
  if (N == NULL){
    return 0;
  }
  return N->altura;           //Retorna a altura do nó
}
 
int max(int a, int b){
  return (a > b)? a : b;      //Retorna o maior entra A e B
}

struct Nodo* novoNodo(int valor){
  struct Nodo* nodo = (struct Nodo*)malloc(sizeof(struct Nodo));
  nodo->conteudo = valor;
  nodo->esquerda = NULL;
  nodo->direita = NULL;
  nodo->altura = 1;
  return(nodo);
}
 
int Balanceamento(struct Nodo *N){
  if (N == NULL){
    return 0;
  }
  return altura(N->esquerda) - altura(N->direita);  //Retorna o fator de balanceamento da árvore
}
 
struct Nodo* inserirNaArvore(struct Nodo* nodo, int valor){
  if (nodo == NULL){
    return(novoNodo(valor));
  }
  if (valor < nodo->conteudo){
    nodo->esquerda  = inserirNaArvore(nodo->esquerda, valor);
  }
  else if (valor > nodo->conteudo){
    nodo->direita = inserirNaArvore(nodo->direita, valor);
  }
  else{
    return nodo;
  }
  
  nodo->altura = 1+max(altura(nodo->esquerda), altura(nodo->direita));
  return nodo;
}

int ehAVL(struct Nodo* raiz){
  int fb;
  fb = Balanceamento(raiz);

  if((fb>1) || (fb < -1)){
    return 0;
  }else{
    return 1;
  }
}

void limparNos(struct Nodo *nodo){
  if(nodo != NULL){
    limparNos(nodo->esquerda);
    limparNos(nodo->direita);
    free(nodo);
  }
}

void limparArvore(struct Nodo *raiz){
  if(raiz != NULL){
    limparNos(raiz);
  }
}

int main (){
  int opcao, valor, teste;
  struct Nodo *raiz = NULL;
  
  do{
    printf("\n-----Menu-----\n");
    printf("1)Inserir dado na arvore\n");
    printf("2)Sair\n");
    printf("-----Menu-----\n\n");
    scanf("%d", &opcao);

    switch (opcao){
      case 1:
        printf("\nDigite o numero que deseja adicionar: ");
        scanf("%d", &valor);
        raiz = inserirNaArvore(raiz, valor);
        break;

      case 2:
        teste = ehAVL(raiz);
        if(teste ==  1){
          printf("A arvore eh AVL\n");
        }
        else{
          printf("A arvore nao eh AVL\n");
        }
        break; 
      
      default:
        printf("\nValor Invalido!\n");
        break;
    }
  }while(opcao!=2);
  limparArvore(raiz);
}