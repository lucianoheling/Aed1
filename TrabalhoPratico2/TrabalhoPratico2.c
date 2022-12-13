#include<stdio.h>
#include<stdlib.h>

#define ANTERIOR 1
#define PROXIMO 6
#define SIZEOF_NODE 9

void *teste(void *start, void *contadorDeNodos);
void *testePalindromo(void *start, void *contadorDeNodos);

int main(){
  void *contadorDeNodos = malloc(sizeof(int));
  ((int *)contadorDeNodos)[0] = 0;
  void *start=NULL;

  do{
    start = teste(start, contadorDeNodos);

    void *atual = start;                           

    while (atual != NULL){
      atual = *(void **)(atual + PROXIMO);
    }
    atual = *(void **)(atual - PROXIMO);
  }while (atual != 'x');                  

  testePalindromo(start, contadorDeNodos);
  return 0;
}

void *teste(void *start, void *contadorDeNodos){
  void *nodo=malloc(SIZEOF_NODE);
  printf("Digite o caractere: \n");
  scanf("%c", nodo);

  *(void **)(nodo + ANTERIOR) = NULL;

  *(void **)(nodo + PROXIMO) = NULL;

  if (start == NULL){                  //Primeira inserção na pilha
    start = nodo;
    ((int *)contadorDeNodos)[1]++;
    return start;                      //Se o start não for nulo, insere sempre depois dele ou do ultimo nodo
  }else {                              //e basicamente se torna uma pilha

    void *atual = start;
    void *anterior = start;                           

    while (atual != NULL){
      anterior = atual;
      atual = *(void **)(atual + PROXIMO);
    }

    *(void **)(anterior + PROXIMO) = nodo;
    *(void **)(nodo + PROXIMO) = atual;
    *(void **)(nodo + ANTERIOR) = anterior;

    ((int *)contadorDeNodos)[1]++;
    return start;
  }
}

void *testePalindromo(void *start, void *contadorDeNodos){
  //testaria se é um palindromo indo até o ultimo nodo e comparando com o primeiro
  //após isso daria um pop nesse elemento e seguiria comparando até terminar o teste
  //e imprimiria na tela se é um palindromo
}