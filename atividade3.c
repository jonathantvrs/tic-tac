#include <stdio.h>

int main() {
  int numeros[5]; // Declara o vetor de entrada dos números 
  
  // Armazena os 5 valores no vetor 
  for (int i = 0; i < 5; i++) {
    printf("Digite o %dº inteiro: ", i + 1);
    scanf("%d", &numeros[i]);
  }

  /* 
   * Declara dois ponteiros que recebem a primeira posição do vetor, e os ordena 
   * utilizando bubble sort
   */ 
  int *ptr1 = numeros, *ptr2 = numeros;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < (4 - i); j++) {
      if (*(ptr1+j) > *(ptr2+j+1)) {
        int aux = *(ptr1+j);
        *(ptr1+j) = *(ptr2+j+1);
        *(ptr2+j+1) = aux;
      }
    }
  }

  // Exibe o vetor ordenado
  for (int i = 0; i < 5; i++) {
    printf("%d ", numeros[i]);
  }
  
  return 0;
}