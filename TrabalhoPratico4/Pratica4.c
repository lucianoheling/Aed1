//Luciano Ludwig Heling
//Matrícula - 20201961 - Aed1 - Turma M1

/*Dado um vetor nums contendo n número inteiros positivos e únicos encontre o número
faltante na sequência. Assuma que somente um número está faltando para completar a
sequência numérica.*/

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *vetor, int tam){
  int i, j, menor, troca;
  for (i = 0; i < tam; i++){
    menor = i;
    for (j = i + 1; j < tam; j++){ 
      if (vetor[j] < vetor[menor]){
        menor = j;
      }
    }
    if (i != menor){
      troca = vetor[i];        
      vetor[i] = vetor[menor]; 
      vetor[menor] = troca;    
    }                            
  }
}

int main(){
  int tam=9, faltou, *nums;
  nums = (int *)malloc(tam * sizeof(int));
 
  ((int*)nums)[0] = 9;
  ((int*)nums)[1] = 6;
  ((int*)nums)[2] = 4;
  ((int*)nums)[3] = 2;
  ((int*)nums)[4] = 3;       //faltando o 4
  ((int*)nums)[5] = 5;
  ((int*)nums)[6] = 7;
  ((int*)nums)[7] = 0;
  ((int*)nums)[8] = 1;
  
  
  selectionSort(nums, tam);
  printf("Vetor Ordenado:\n\n");
  for(int i=0; i<tam; i++){
    printf("Vetor[%d]=%d\n", i, nums[i]);
  }

  for(int i=0; i<tam; i++){
    if(nums[i+1] != nums[i]+1){
      faltou=nums[i]+1;
      printf("\nFaltando: %d\n\n", faltou);
      free(nums);
      return 0;
    }
  }
}