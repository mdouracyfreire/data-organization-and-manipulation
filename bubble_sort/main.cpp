#include <stdlib.h>
#include <stdio.h>

// Função para imprimir todos os elementos do array
void printArray(int *p_arr, int size){
  for(int i = 0; i < size; i++){
    printf("%d ", p_arr[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]){
  int temp; 
  int arr[] = {10, 9, 7, 13, 5};   // Array desordenado
  int size = sizeof(arr) / sizeof(int); // Tamanho do array
  
  // Mostra o estado inicial do array
  printArray(arr, size);

  // Loop externo: controla quantas passadas serão feitas
  for(int i = size - 1; i >= 0; i--){
    printf("\n");  // Apenas para separar visualmente cada rodada
    
    // Loop interno: compara elementos vizinhos e faz a troca se necessário
    for(int j = 0; j <= i - 1; j++){
      
      // Se o elemento atual for maior que o próximo, troca de posição
      if(arr[j] > arr[j + 1]){
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp; 
        
        // Mostra o array a cada troca para visualizar o processo
        printArray(arr, size);
      }
    }
  }
  
  system("pause");
  return 0;
}