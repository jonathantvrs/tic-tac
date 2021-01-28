#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Registro que representa uma loja
struct Store {
  char name[81];
  char tel[15];
  float tabletPrice;
};

/*
 * Função que adiciona uma loja nova ao vetor
 * de lojas. 
 * Recebe como parâmetros o vetor de lojas e 
 * o índice que vai controlar o número de lojas
 * cadastradas
 */
void addStore(struct Store *s, int *index);
/*
 * Função que remove uma loja do vetor de lojas. 
 * Recebe como parâmetros o vetor de lojas e 
 * o índice da loja que deseja excluir.
 */
void removeStore(struct Store *s, int *index);
/*
 * Função que exibe o nome e o telefone das lojas
 * cadastradas que tem o tablet com preço abaixo 
 * da média. 
 * Recebe como parâmetros o vetor de lojas e 
 * o índice
 */
void bestPrices(struct Store *s, int index);
/*
 * Função auxiliar que move as lojas no vetor
 * para a esquerda quando alguma é excluida
 * Recebe como paramento o vetor de lojas, 
 * o índice da loja que será excluída e o 
 * índice que controla o tamanho de lojas 
 * cadastradas.
 */
void shiftLeft(struct Store *s, int rIndex, int *index);
/*
 * Função auxiliar que retorna a média de preço
 * do Tablet nas lojas cadastradas.
 * Recebe como parametro o vetor de lojas e
 * o índice que controla o tamanho das lojas 
 * cadastradas. 
 */
float avgPrices(struct Store *s, int index);
/*
 * Função que salva as lojas cadastradas no 
 * vetor de lojas em um arquivo CSV
 * Recebe como parametro o vetor de lojas e
 * o índice que controla o tamanho das lojas
 * cadastradas.
 */
void saveDataInCSV(struct Store *s, int index);

int main() {
  struct Store stores[15]; // Declara vetor que vai armazenar as lojas
  int i = 0; // Declara índice que vai controlar o número de lojas cadastradas
  char option; // Declara variável que vai guardar a opção de menu 

  setbuf(stdin, NULL); // Substitui o buffer de entrada por NULL

  do {
    // Menu de Opções para o usuário
    printf("[ I ] Inserir nova loja\n");
    printf("[ E ] Excluir loja cadastrada\n");
    printf("[ P ] Melhores Preços\n");
    printf("[ S ] Salvar\n");
    printf("[ D ] Sair\n");
    printf("Digite sua opção: ");
    scanf(" %c", &option); // Armazena opção digitada

    if (option == 'I') {
      addStore(stores, &i); // Chamada da função de cadastro de nova loja
    } else if (option == 'E') {
      removeStore(stores, &i); // Chamada da função de remoção de loja 
    } else if (option == 'P') {
      bestPrices(stores, i); // Chamada da função que mostra as lojas com preço abaixo da média
    } else if (option == 'S') {
      saveDataInCSV(stores, i); // Chamada da função de salvar registros em arquivo csv
    }

  } while (option != 'D');

  return 0;
}

void addStore(struct Store *s, int *index) { 
  if (*index < 15) {  
    printf("Digite o nome da loja:");
    scanf("%s", s[*index].name);

    printf("Digite o telefone da loja:");
    scanf("%s", s[*index].tel);
    
    printf("Digite o preço do Tablet:");
    scanf("%f", &s[*index].tabletPrice);

    *index = *index + 1;
  } else {
    printf("Já foram cadastradas 15 lojas\n");
  }
}

void removeStore(struct Store *s, int *index) {
  if (*index > 0) {    
    int removeIndex;
    for (int i = 0; i < *index; i++) {
      printf("Loja %d: %s\n", i + 1, s[i].name);
    }
    printf("Digite o número da loja que deseja excluir: ");
    scanf("%d", &removeIndex);

    shiftLeft(s, removeIndex-1, index);
  } else {
    printf("Não há lojas cadastradas!\n");
  }
}

void bestPrices(struct Store *s, int index) {
  for (int i = 0; i < index; i++) {
    if (s[i].tabletPrice < avgPrices(s, index)) {
      printf("Loja %d: %s - Tel: %s\n", i + 1, s[i].name, s[i].tel);
    }
  }
}

void shiftLeft(struct Store *s, int rIndex, int *index) {
  for (int i = rIndex; i < (*index - 1); i++) {
    s[i] = s[i+1];
  } 
  *index = *index - 1;
}

float avgPrices(struct Store *s, int index) {
  float avg = 0;
  for (int i = 0; i < index; i++) {
    avg = s[i].tabletPrice;
  }
  avg = avg / (index - 1);
  return avg;
}

void saveDataInCSV(struct Store *s, int index) {
  FILE *stores;
  stores = fopen("precos.csv", "w");
  if (stores == NULL) {
    printf("Erro na abertura do arquivo");
    return;
  }

  for (int z = 0; z < index; z++) {
    char price[16]; 
    sprintf(price, "%f", s[z].tabletPrice);
    for (int i = 0; s[z].name[i] != '\0'; i++) {
      fputc(s[z].name[i], stores);
    }
    fputc(';', stores);
    for (int i = 0; s[z].tel[i] != '\0'; i++) {
      fputc(s[z].tel[i], stores);
    }
    fputc(';', stores);
    for (int i = 0; price[i] != '\0'; i++) {
      fputc(price[i], stores);
    }
    fputc('\n', stores);
  }

  fclose(stores);
}