#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_IDADE 11
#define KEY_TELEFONE 15
#define PROXIMO 23
#define ANTERIOR 19
#define SIZEOF_NODE 27
#define SIZEOF_PBUFFER 19
#define NOMETEMP 11

void *inserirCadastro(void *start, void *pBuffer);
void *excluirCadastro(void *start, void *pBuffer);
void buscarCadastro(void *start, void *pBuffer);
void listarAgenda(void *start, void *pBuffer);

int main(){
  void *pBuffer = malloc(SIZEOF_PBUFFER);

  ((int *)pBuffer)[0] = 0;              // Variáveis auxiliares, switch e while
  ((int *)pBuffer)[1] = 0;              // Contador de cadastros na agenda

  void *start = NULL;

  do{
    printf("\n");
    printf("1) Inserir cadastro\n");
    printf("2) Excluir cadastro\n");
    printf("3) Buscar cadastro\n");
    printf("4) Listar\n");
    printf("5) Sair\n");
    scanf("%d", &((int *)pBuffer)[0]);

    switch (((int *)pBuffer)[0])
    {

    case 1:
      start = inserirCadastro(start, pBuffer);
      break;

    case 2:
      start = excluirCadastro(start, pBuffer);
      break;

    case 3:
      buscarCadastro(start, pBuffer);
      break;

    case 4:
      listarAgenda(start, pBuffer);
      break;

    case 5:
      printf("Saindo...\n");
      break;

    default:
      printf("Opcao invalida!\n");
      break;
    }

  } while (*(int *)pBuffer != 5);

  free(pBuffer);
  free(start);
  return 0;
}

void *inserirCadastro(void *start, void *pBuffer){
  void *nodo = malloc(SIZEOF_NODE);

  printf("\nInsira o nome: ");
  scanf("%s", (char *)nodo);

  printf("Insira a idade: ");
  scanf("%d", ((int *)(nodo + KEY_IDADE)));

  printf("Insira o telefone: ");
  scanf("%d", ((int *)(nodo + KEY_TELEFONE)));

  *(void **)(nodo + ANTERIOR) = NULL;

  *(void **)(nodo + PROXIMO) = NULL;

  
  if (start == NULL){                         // Teste para a fila vazia
    start = nodo;
    ((int *)pBuffer)[1]++;
    return start;
  }

  if ((strcmp((char *)start, (char *)nodo)) >= 0){
    *(void **)(nodo + PROXIMO) = start;
    *(void **)(start + ANTERIOR) = nodo;            // Inserção no começo da fila
    start = nodo;
    ((int *)pBuffer)[1]++;
    return start;
  }

  void *atual = start;
  void *anterior = start;                           // Inserção no meio ou final da fila

  while (atual != NULL && (strcmp((char *)atual, (char *)nodo) <= 0)){
    anterior = atual;
    atual = *(void **)(atual + PROXIMO);
  }

  *(void **)(anterior + PROXIMO) = nodo;
  *(void **)(nodo + PROXIMO) = atual;
  *(void **)(nodo + ANTERIOR) = anterior;

  ((int *)pBuffer)[1]++;
  return start;
}

void *excluirCadastro(void *start, void *pBuffer){

  if (((int *)pBuffer)[1] == 0){
    printf("\nA agenda esta vazia.\n");             // Teste para a fila vazia
    return start;
  }

  void *segundo_nodo = *(void **)(start + PROXIMO); // Exclusão caso a fila tenha só um elemento
  free(start);

  if (segundo_nodo == NULL){
    ((int *)pBuffer)[1]--;
    printf("\nRemovido! Agora a agenda esta vazia.\n");
    return segundo_nodo;
  }

  start = segundo_nodo;
  *(void **)(start + ANTERIOR) = NULL;               // Excluindo normalmente
  ((int *)pBuffer)[1]--;
  printf("\nRemovido! Resta(m) %d cadastro(s)\n", ((int *)pBuffer)[1]);

  return start;
}

void buscarCadastro(void *start, void *pBuffer){

  if (start == NULL){
    printf("\nA agenda esta vazia.\n");
    return;
  }
  else{
    printf("\nDigite o nome a ser buscado na agenda: ");
    scanf("%s", (char *)(pBuffer + NOMETEMP));

    ((int *)pBuffer)[1] = 1;
    void *atual = start;

    while (atual != NULL && (strcmp((char *)atual, (char *)(pBuffer + NOMETEMP)) != 0)){
      atual = *(void **)(atual + PROXIMO);
      ((int *)pBuffer)[1]++;
    }

    if (atual == NULL){
      printf("\nNome nao encontrado!\n");
      return;
    }
    else{
      printf("\nNome: %s", (char *)atual);
      printf("\nIdade: %d", *(int *)(atual + KEY_IDADE));
      printf("\nTelefone: %d\n", *(int *)(atual + KEY_TELEFONE));
    }
  }
}

void listarAgenda(void *start, void *pBuffer){

  if (start == NULL){
    printf("\nA agenda esta vazia.\n");
    return;
  }

  void *atual = start;

  while (atual != NULL){

    printf("\nNome: %s", (char *)atual);
    printf("\nIdade: %d", *(int *)(atual + KEY_IDADE));
    printf("\nTelefone: %d\n", *(int *)(atual + KEY_TELEFONE));

    atual = *(void **)(atual + PROXIMO);
  }
}