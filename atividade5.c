#include <stdio.h>

/**
 * Função que, dado o ano, retorna 1 se é bissexto e 0 caso não seja.   
 */
int is_bissexto(int ano) { 
  return (((ano % 4 == 0) && (ano % 100 != 0)) || (ano % 400 == 0)) ? 1 : 0;
}

/**
 * Função recursiva que, dado o ano atual e final do século, 
 * imprime os anos bissextos no intervalo.  
 */
void imprime_bissextos(int anoAtual, int anoFinal) {
  if (anoAtual == anoFinal+1) { // Checagem de caso trivial (base)
    return;
  }
  
  if (is_bissexto(anoAtual)) { // Se o ano atual for bissexto, imprime
    printf("%d ", anoAtual); 
  }

  imprime_bissextos(anoAtual+1, anoFinal); // Chamada Recursiva que adiciona 1 ao ano atual
}

int main() {
  int seculo; // Variável de entrada do século

  printf("Digite o século: ");
  scanf("%d", &seculo);

  // Calculo de anos inicial e final do século digitado
  int anoInicial = ((seculo - 1) * 100) + 1;
  int anoFinal = anoInicial + 99;

  // Chamada para a função recursiva de imprimir bissextos
  imprime_bissextos(anoInicial, anoFinal); 

  return 0;
}