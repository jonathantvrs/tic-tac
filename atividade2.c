#include <stdio.h>

struct Store {
  char name[81];
  char tel[15];
  float tabletPrice;
};

void addStore(struct Store *s, int *index);
void removeStore(struct Store *s, int index);
void bestPrices(struct Store *s);

int main() {
  struct Store stores[15];
  int i = 0;
  char option;

  do {
    printf("[ I ] Inserir nova loja\n");
    printf("[ E ] Excluir loja cadastrada\n");
    printf("[ P ] Melhores Preços\n");
    printf("[ S ] Sair\n");
    printf("Type your Option: ");
    scanf("%c", &option);

    if (option == 'I') {
      addStore(stores, &i);
    }
  } while (option != 'S');

  printf("Name: %s\n", stores[0].name);
  printf("Tel: %s\n", stores[0].tel);
  printf("Tablet Price: %.2f", stores[0].tabletPrice); 

  return 0;
}

void addStore(struct Store *s, int *index) {
  fflush(stdin);

  printf("Type Store name:");
  fgets(s[*index].name, sizeof(s[*index].name), stdin);

  printf("Type Store tel:");
  fgets(s[*index].tel, sizeof(s[*index].tel), stdin);
  
  printf("Type tablet price:");
  scanf("%f", s[*index].tabletPrice);

  *index++;
}

