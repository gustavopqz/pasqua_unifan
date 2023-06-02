#include <stdio.h>

void questao1(){
	int vetor[10], i;
    
    for(i = 0; i < 10; i++){
    	printf("Digite o %do numero: ", i + 1);
    	scanf("%d", &vetor[i]);
	}
	
	printf("Imprimindo vetor seguindo a ordem inversa: \n");
	
	for(i = 9; i >= 0; i--){
		printf("O numero na posicao %d: %d\n", i, vetor[i]);
	}
}

void questao2(){
	int vetor[10], i, somaPares = 0, somaImpares = 0;
    
    // Insert de dados
    for(i = 0; i < 10; i++){
    	printf("Digite o %do numero: ", i + 1);
    	scanf("%d", &vetor[i]);
	}
	
	// Lendo o vetor
	for(i = 0; i < 10; i++){
    	// Verificando numero e somando aos pares se for par ou aos impares se for impar
    	if(vetor[i] % 2 == 0){
    		somaPares += vetor[i];
		}else{
			somaImpares += vetor[i];
		}
	}
	
	printf("Imprimindo a soma dos valores pares: %d\n", somaPares);
	printf("Imprimindo a soma dos valores impares: %d\n", somaImpares);
}

void questao3(){
	int vetor[10], i, j, numero;
	bool repetido;
	
	// Insert de dados
    for(i = 0; i < 10; i++){
    	printf("Digite o %do numero: ", i + 1);
    	scanf("%d", &numero);
    	repetido = false;
    	for(j = 0; j < i + 1; j++){
    		if(numero == vetor[j]){
    			repetido = true;
			}
		}
		
		if(!repetido){
			vetor[i] = numero;
		}else{
			printf("Valor digitado ja existe no vetor, nao adicionado ao vetor!\n");
			i--;
		}
	}
	
	// Mostrando vetor
	printf("[");
	for(i = 0; i < 10; i++){
		if(i > 0){
			printf(", ");
		}
		printf("%d", vetor[i]);
	}
	printf("]");
}

void questao4(){
	int A[5], B[8], i, j;
	
	// Valores vetor A
	for(i = 0; i < 5; i++){
		printf("Digite o %do numero do vetor A: ", i + 1);
    	scanf("%d", &A[i]);
	}
	
	// Valores vetor B
	for(i = 0; i < 8; i++){
		printf("Digite o %do numero do vetor B: ", i + 1);
    	scanf("%d", &B[i]);
	}
	
	// Valores em comum
	printf("Valores em comum entre o vetor A e vetor B: \n");
	for(i = 0; i < 8; i++){
		for(j = 0; j < 5; j++){
			if(B[i] == A[j]){
				printf("%d\n", B[i]);
			}
		}
	}
}

void questao5(){
	int vetor1[5], vetor2[5], vetor3[10], contador = 0, i, j = 0;
	
	// Valores vetor 1
	for(i = 0; i < 5; i++){
		printf("Digite o %do numero do vetor 1: ", i + 1);
    	scanf("%d", &vetor1[i]);
	}
	
	// Valores vetor 2
	for(i = 0; i < 5; i++){
		printf("Digite o %do numero do vetor 2: ", i + 1);
    	scanf("%d", &vetor2[i]);
	}
	
	// Valores vetor 3 intercalados de 1 e 2
	for(i = 0; i < 10; i++){
		if(contador % 2 == 0){
			vetor3[i] = vetor1[j];
		}else{
			vetor3[i] = vetor2[j];
			j++;
		}		
		contador++;
	}
	
	// Printar vetor 1
	printf("Vetor 1:\n[");
	for(i = 0; i < 5; i++){
		if(i > 0){
			printf(", ");
		}
		printf("%d", vetor1[i]);
	}
	printf("]\n");
	
	// Printar vetor 2
	printf("Vetor 2:\n[");
	for(i = 0; i < 5; i++){
		if(i > 0){
			printf(", ");
		}
		printf("%d", vetor2[i]);
	}
	printf("]\n");
	
	// Printar vetor 3
	printf("Vetor 3:\n[");
	for(i = 0; i < 10; i++){
		if(i > 0){
			printf(", ");
		}
		printf("%d", vetor3[i]);
	}
	printf("]");
} 

int main(){
    // questao1();
	
	// questao2();
	
	// questao3();
	
	// questao4();
	
	// questao5();
	
	
	return 0;
}
