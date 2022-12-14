#include <stdio.h>
#include <stdlib.h>

// Caractere I = Int, F = Float, D = Double
// Para poder imprimir na ordem correta achando a ocorrencia do char no buffer

int main() {
  int opcao, teste, tamanhoBytes = 0, contagemDeValores = 0;
  void *buffer = malloc(sizeof(char)); 
  void *start = buffer; 

  do{
    printf("Deseja digitar um numero?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%d", &teste);
    if (teste == 1) {
      contagemDeValores++;
      printf("Qual tipo de dado sera digitado?\n");
      printf("1 - Int\n");
      printf("2 - float\n");
      printf("3 - double\n");
      scanf("%d", &opcao);
      switch (opcao) {
      case 1:
        start = realloc(start, tamanhoBytes + sizeof(int) + sizeof(char));
        tamanhoBytes += 5;
        buffer = start + tamanhoBytes - 5;

        *(char *)buffer = 'I';
        buffer = buffer + 1;

        printf("Digite o numero: ");
        scanf("%d", (int *)buffer);

        printf("\nEndereco antigo de Buffer %p", buffer);
        buffer = start + tamanhoBytes;
        printf("\nEndereco atual de Buffer %p\n\n", buffer);
        break;

      case 2:
        start = realloc(start, tamanhoBytes + sizeof(float) + sizeof(char));
        tamanhoBytes = tamanhoBytes + 5;
        buffer = start + tamanhoBytes - 5;

        *(char *)buffer = 'F';
        buffer = buffer + 1;

        printf("Digite o numero: ");
        scanf("%f", (float *)buffer);

        printf("\nEndereco antigo de Buffer %p", buffer);
        buffer = start + tamanhoBytes;
        printf("\nEndereco atual de Buffer %p\n\n", buffer);
        break;

      case 3:
        start = realloc(start, tamanhoBytes + sizeof(double) + sizeof(char));
        tamanhoBytes = tamanhoBytes + 9;
        buffer = start + tamanhoBytes - 9;

        *(char *)buffer = 'D';
        buffer = buffer + 1;

        printf("Digite o numero: ");
        scanf("%lf", (double *)buffer);

        printf("\nEndereco antigo de Buffer %p", buffer);
        buffer = start + tamanhoBytes;
        printf("\nEndereco atual de Buffer %p\n\n", buffer);
        break;

      default:
        break;
      }
    }
  }while(teste != 2);

  printf("\n");
  buffer = start;

// Impress??o do buffer de acordo com o que o usu??rio digitou

  for (int i = 0; i < contagemDeValores; i++) {
    switch (*(char *)buffer) {
      case 'I':
        buffer += 1;
        printf("Valor <INT> %d: %d \n", i + 1, *(int *)buffer);
        buffer += 4;
        break;

      case 'F':
        buffer += 1;
        printf("Valor <FLOAT> %d: %f \n", i + 1, *(float *)buffer);
        buffer += 4;
        break;

      case 'D':
        buffer += 1;
        printf("Valor <DOUBLE> %d: %lf \n", i + 1, *(double *)buffer);
        buffer += 8;
        break;
      }
    }

// Impressao organizada do buffer em Inteiro, Float e Double

  printf("Impressao em ordem: Inteiro, Float e Double.\n");
  buffer = start;

  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < contagemDeValores; i++) {
      switch (*(char *)buffer) {
      case 'I':
        buffer += 1;
        if (j == 0)
          printf("Valor <INT> %d: %d \n", i + 1, *(int *)buffer);
        buffer += 4;
        break;

      case 'F':
        buffer += 1;
        if (j == 1)
          printf("Valor <FLOAT> %d: %f \n", i + 1, *(float *)buffer);
        buffer += 4;
        break;

      case 'D':
        buffer += 1;
        if (j == 2)
          printf("Valor <DOUBLE> %d: %lf \n", i + 1, *(double *)buffer);
        buffer += 8;
        break;
      }
    }
    buffer = start;
  }
  free(start);
}