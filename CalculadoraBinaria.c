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
  return 0;
}




int main(void){
  
  return 0;
}