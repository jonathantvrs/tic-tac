#include <stdio.h>
#include <stdlib.h>

// Define a estrutura que vai armazenar os dados da ação
typedef struct acao {
  char codigo[8];
  char area_atuacao[31];
  char data[11];
  float valor_abertura;
  float valor_fechamento;
  float porcentagem_variacao;
} Acao;

/*
 * Função que calcula a porcentagem de variação da ação.
 * Recebe como parametro dois valores reais (float), que 
 * são o valor de abertura (va) e o valor de fechamento (vf).
 */
float calcula_porcentagem_variacao(float va, float vf);
/*
 * Função que adiciona uma nova ação na carteira.
 * Recebe como parametro o ponteiro que vai modificar 
 * a carteira de ações e a variável k usada para acessar
 * os indices e alocar dinamicamente a memória para a carteira.
 */
void adiciona_acao(Acao *carteira, int k);
/*
 * Função que exibe todas as ações da carteira.
 * Recebe como parametro o ponteiro que vai acessar 
 * a carteira de ações e a variável k usada para acessar
 * os indices e como condição de parada da iteração
 */
void exibe_carteira(Acao *carteira, int k);

int main() {
  Acao *carteira; // Declara Vetor para armazenar ações
  int k = 0; // Declara variável para armazenar o tamanho atual do vetor
  int opcao; // Declara variável para armazenar a opção de menu

  setbuf(stdin, NULL); // Substitui o buffer de entrada por NULL

  // Laço para controlar execução do programa
  do {
    // Menu de opções
    printf("[ 1 ] Adicionar nova ação na carteira\n");
    printf("[ 2 ] Mostrar carteira de ações\n");
    printf("[ 3 ] Sair\n");
    printf("Digite a sua opção: ");
    scanf("%d", &opcao); // Armazena opção digitada

    if (opcao == 1) {
      if (k == 0) {
        carteira = (Acao*) malloc(1 * sizeof(Acao)); // Aloca memória para 1 ação
      } else {
        carteira = (Acao*) realloc(carteira, (k+1) * sizeof(Acao)); // Realoca k+1 memória
      }
      
      adiciona_acao(carteira, k); // Chamada da função de adicionar nova ação

      k++; // Adiciona mais 1 ao terminar de cadastrar nova ação
    } else if (opcao == 2) {
      exibe_carteira(carteira, k); // Chamada da função que exibe as ações
    }
  } while (opcao != 3);
  
  return 0;
}

float calcula_porcentagem_variacao(float va, float vf) {
  return ((vf-va)/va) * 100;
}

void adiciona_acao(Acao *carteira, int k) {
  // Se o valor de k for 6, significa que a carteira está cheia (5 ações)
  if (k < 6) {
    printf("Digite o Código da Ação: \n");
    scanf("%s", carteira[k].codigo);

    printf("Digite a Area de Atuação: \n");
    scanf("%s", carteira[k].area_atuacao);

    printf("Digite a Data (dd/mm/aaaa): \n");
    scanf("%s", carteira[k].data);

    printf("Digite o valor de abertura da Ação: \n");
    scanf("%f", &carteira[k].valor_abertura);

    printf("Digite o valor de fechamento da Ação: \n");
    scanf("%f", &carteira[k].valor_fechamento);

    carteira[k].porcentagem_variacao = calcula_porcentagem_variacao(carteira[k].valor_abertura, carteira[k].valor_fechamento);
  } else {
    printf("Sem espaço"); // Imprime para o usuário que não tem espaço para mais ações
  }
}

void exibe_carteira(Acao *carteira, int k) {
  for (int i = 0; i < k; i++) {
    printf("Ação nº%d:\n", i+1);
    printf("Codigo: %s\n", carteira[i].codigo);
    printf("Área de Atuação: %s\n", carteira[i].area_atuacao);
    printf("Data: %s\n", carteira[i].data);
    
    printf("Valor Abertura: R$%.2f\n", carteira[i].valor_abertura);
    printf("Valor Fechamento: R$%.2f\n", carteira[i].valor_fechamento);
    printf("Variação no dia: %f%%\n", carteira[i].porcentagem_variacao);
    printf("---------------------------------------\n");
  }
}
