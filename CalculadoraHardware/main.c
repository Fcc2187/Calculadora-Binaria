#include<stdio.h>

void binario(int x){
  //deixando 32 como padrão oara todas operações
  int binario[32]; 
  int i = 0;
  if(x==0){
    printf("\nNúmero em binário: \n0\n");
  }
  //calcular o complemento a 2 para o valor negativo de x;
  if (x < 0) {
    x = (1 << 8) + x;
  }
  //calculo do numero em binario 
  while (x > 0) {
    binario[i] = x % 2; 
    x = x / 2;     
    i++;
  }
  printf("\nNúmero em binário: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binario[j]);
  }
  printf("\n");
}

void octal(int x){
  //deixando 32 como padrão oara todas operações
  int octal[32]; 
  int i = 0;

  if(x<=7){
    if(x<0){
      printf("Número em octal: \n-%d\n",x);
    }
    printf("\nNúmero em octal: %d \n", x);
  }
  //calculo do numero em octal 
  while (x > 8) {
    octal[i] = x % 8; 
    x = x / 8;     
    i++;
  }
  if(x<0){
    printf("\nNúmero em octal: -");
  }
  else{
    printf("\nNúmero em octal: ");
  }
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", octal[j]);
  }
  printf("\n");
}


void base_16(int x) {
    char hexadecimal[32];
    int i = 0;
    unsigned int valorConvertido; // Usamos unsigned int para representar o número corretamente

    if (x == 0) {
        printf("\nNúmero em Hexadecimal: 0\n");
        return;
    }

    // Trata números negativos com complemento a 2
    valorConvertido = (x < 0) ? ((unsigned int)x) : (unsigned int)x;

    while (valorConvertido > 0) {
        int resto = valorConvertido % 16;
        if (resto < 10) {
            hexadecimal[i] = resto + '0'; 
        } else {
            hexadecimal[i] = resto - 10 + 'A';
        }
        valorConvertido /= 16;
        i++;
    }

    if (x < 0) {
        printf("\nNúmero em Hexadecimal: -");
    } else {
        printf("\nNúmero em Hexadecimal: ");
    }


    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal[j]);
    }
    printf("\n");
}

void BCD(int x) {
    // Declara um array para armazenar os dígitos em BCD
    int BCD[32 * 4] = {0};
    // Array para armazenar os dígitos decimais individuais
    int algarismos[32] = {0};
    int i = 0;
    int o = 0; 

    if (x == 0) {
        printf("\nNúmero em BCD: 0000\n");
        return;
    }
    while (x != 0) {
        algarismos[o] = x % 10; 
        x = x / 10;            
        o++;
    }

   
    for (int h = o - 1; h >= 0; h--) {
        int n = algarismos[h];
        for (int k = 3; k >= 0; k--) {
            BCD[i] = (n >> k) & 1;
            i++;
        }
    }
  int r=0;
    printf("\nNúmero em BCD: ");
    for (int j = 0; j < i; j++) {
        printf("%d", BCD[j]);
        r++;
        if (r == 4) { 
            printf(" ");
            r = 0; 
        }
    }
    printf("\n");
}
int main() {
  int numero;
  printf("Digite um número inteiro: ");
  scanf("%d",&numero);
  binario(numero);
  octal(numero);
  base_16(numero);
  BCD(numero);
  return 0;
}
