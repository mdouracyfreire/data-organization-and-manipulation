#include <stdlib.h>
#include <stdio.h>

// Função para imprimir todos os elementos de um array
// Recebe como parâmetro um ponteiro para o array e o seu tamanho
void printArray(int *p_arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", p_arr[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]){
  int i, j;
  int value, temp;
  
  // Array inicial desordenado
  int arr[] = {13, 7, 5, 1, 4};
  
  // Calcula quantos elementos existem no array
  int size = sizeof(arr) / sizeof(int);
  
  // Mostra o estado inicial do array antes de ordenar
  printArray(arr, size);

  // Percorre o array a partir do segundo elemento (índice 1)
  for(i = 1; i < size; i++){
    value = arr[i];     // Pega o elemento atual para comparação
    j = i - 1;          // Começa a comparar com o elemento anterior

    // Enquanto houver elementos maiores à esquerda, faz trocas
    while(j >= 0 && arr[j] > value){
      // Troca o elemento atual com o anterior (movendo para esquerda)
      temp = arr[j + 1];
      arr[j + 1] = arr[j];
      arr[j] = temp;

      // Move o índice para a esquerda para continuar as comparações
      j = j - 1;

      // Mostra o array a cada troca para visualizar o processo
      printArray(arr, size);
    }
  }

  system("pause");
  return 0;
}