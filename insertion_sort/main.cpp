#include <stdlib.h>
#include <stdio.h>

void imprimir(int *p_arranjo, int tamanho){
  for(int i = 0; i < tamanho; i++){
    printf("%d ", p_arranjo[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[]){
  int i, j;
  int valor, temp;
  int arranjo[] = {13, 7, 5, 1, 4};
  int tamanho = sizeof(arranjo) / sizeof(int);
  
  imprimir(arranjo, tamanho);

  for(i = 1; i < tamanho; i++){
    valor = arranjo[i];
    j = i - 1;

    while(j >= 0 && arranjo[j] > valor){
      temp = arranjo[j + 1];
      arranjo[j + 1] = arranjo[j];
      arranjo[j] = temp;
      j = j - 1;
      imprimir(arranjo, tamanho);
    }
  }
  system("pause");
  return 0;
}