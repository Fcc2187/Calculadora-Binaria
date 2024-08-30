#include <stdio.h>
#include <stdint.h>
#include <string.h>

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
  int negativo = 0;
  if(x<0){
    negativo = 1;
    x = -x;
  }
  //calculo do numero em octal 
  while (x > 8) {
    octal[i] = x % 8; 
    x = x / 8;     
    i++;
  }
   octal[i] = x;
   printf("\nNúmero em octal: ");
  if(negativo == 1){
    printf("-");
  }
  for (int j = i; j >= 0; j--) {
    printf("%d", octal[j]);
  }
  printf("\n");
}


void base_16(int x){
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
void complementoa2(int x) {
  unsigned short int resultado;
  if (x >= 0) {
    resultado = x;
  } else {
    resultado = (1 << 16) + x;
  }

  printf("\nNúmero em complemento a 2 (16 bits): ");
  for (int i = 15; i >= 0; i--) {
    printf("%d", (resultado >> i) & 1);
  }
  printf("\n");
}

void transformarfloat(float valor) {
    //biblioteca importada para garantir que a largura seja exatamente de 32 bits, obedecendo os requisitos
    uint32_t representacao;
    memcpy(&representacao, &valor, sizeof(representacao));

    // Extrair sinal, expoente e fração (mantissa)
    uint32_t sinal_float = representacao >> 31;
    uint32_t expoente_com_vies = (representacao >> 23) & 0xFF;
    uint32_t fracao = representacao & 0x7FFFFF;

    printf("\nNúmero em float (32 bits):\n");
    printf("Sinal: %u\n", sinal_float);
    printf("Expoente (com viés): %u\n", expoente_com_vies);
    printf("Fração (mantissa): %u\n", fracao);

    printf("\nBits em IEEE 754:\n");
    printf("%u ", sinal_float);

    // Mostrar os bits do expoente
    for (int j = 0; j < 8; j++) {
        printf("%u", (expoente_com_vies >> (7 - j)) & 1);
    }
    printf(" ");

    // Mostrar os bits da fração (mantissa)
    for (int k = 0; k < 23; k++) {
        printf("%u", (fracao >> (22 - k)) & 1);
    }
    printf("\n");
}

int main() {
  int numero;
  int choice;
while(1){
  printf("\nEscolha uma opção:\n0: sair\n1: calcular numero\n");
  scanf("%d", &choice);
  if(choice == 0){
    break;
  }
else{
  printf("Digite um número inteiro: ");
  scanf("%d",&numero);
  binario(numero);
  octal(numero);
  base_16(numero);
  BCD(numero);
  complementoa2(numero);
  transformarfloat(numero);
}
}
  return 0;
}
