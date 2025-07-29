#include <stdlib.h>
#include <stdio.h>

// Função para imprimir os elementos do array
void printArray(int *p_arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", p_arr[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]){
  int index_max, temp;
  int arr[] = {13, 7, 5, 1, 4};      // Array desordenado
  int size = sizeof(arr) / sizeof(int); // Tamanho do array
  
  // Mostra o array inicial antes da ordenação
  printArray(arr, size);

  // Loop externo: percorre do final até o início do array
  for(int i = size - 1; i > 0; i--){
    index_max = 0; // Assume que o maior elemento é o primeiro da lista

    // Loop interno: busca o índice do maior elemento na parte não ordenada
    for(int j = 0; j <= i; j++){
      if(arr[j] > arr[index_max]){
        index_max = j; // Atualiza a posição do maior elemento encontrado
      }
    }
    
    // Após encontrar o maior elemento, troca com a última posição da parte analisada
    temp = arr[i];
    arr[i] = arr[index_max];
    arr[index_max] = temp;
    
    // Mostra o array após cada troca para visualizar o processo
    printArray(arr, size);
  }
  return 0;
}