#include <stdlib.h>
#include <stdio.h>  

// Função para imprimir todos os elementos do array
void printArray(int *p_arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", p_arr[i]);
  }
  printf("\n");
}

// Função de ordenação usando o algoritmo Quick Sort
void quick_sort(int *p_arr, int index_first, int index_end) {
  int temp; 
  int pivot = p_arr[index_first]; // Define o pivô como o primeiro elemento do subarray
  int c_left = index_first;       // Cursor que começa do lado esquerdo
  int c_right = index_end;        // Cursor que começa do lado direito
  
  // Enquanto os dois cursores não se cruzarem
  while (c_left <= c_right) {
    
    // Avança o cursor da esquerda até achar um elemento >= pivô
    while (p_arr[c_left] < pivot) c_left++;
    
    // Move o cursor da direita até achar um elemento <= pivô
    while (p_arr[c_right] > pivot) c_right--;
    
    // Se os cursores ainda não se cruzaram, troca os elementos
    if (c_left <= c_right) {
      temp = p_arr[c_left];
      p_arr[c_left] = p_arr[c_right];
      p_arr[c_right] = temp;
      
      // Move os cursores para continuar a varredura
      c_left++;
      c_right--;
    }
  }
  
  // Verifica se ainda há mais de um elemento em cada lado para continuar a ordenação
  if (index_end - index_first > 1) {
    quick_sort(p_arr, index_first, c_right); // Ordena lado esquerdo
    quick_sort(p_arr, c_left, index_end);    // Ordena lado direito
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {4, 8, 2, -12, -6, 5, 13, 22, 7, 3}; // Array desordenado
  int size = sizeof(arr) / sizeof(int);           // Tamanho do array
  
  // Chama o Quick Sort para ordenar todo o array
  quick_sort(arr, 0, size - 1);
  
  // Imprime o array já ordenado
  printArray(arr, size);
  system("pause");
  return 0;
}