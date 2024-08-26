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

int main() {
  return 0;
}
