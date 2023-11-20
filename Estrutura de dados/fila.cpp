#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 4

int verCheia();
int verVazia();
void inserir(int);
void remover();
void listar();
void verInicio();
void verFinal();
void buscar(int);
void menu();

int fila[max];
int comeco = 0, final = 0;
int elemento, num;
char resp = 's';

int main(){
	setlocale(LC_ALL,"");
	
	while(resp != 'n'){
		system("cls");
		menu();
	}	
}

void menu() {
  	int escolha;

  	printf("MENU:\n");
  	printf("Escolha uma opção:\n");
  	printf(" 1. INSERIR\n 2. REMOVER\n 3. VER INÍCIO \n 4. VER FINAL \n 5. VER CHEIA\n 6. VER VAZIA\n 7. LISTAR\n 8. BUSCAR ELEMENTO\n 9. SAIR\n Sua escolha: ");
  	scanf("%d", &escolha);
  	
  	switch(escolha){
	
	case 1:
		if(verCheia() == 1){
			printf("Impossível inserir. FILA CHEIA\n");
		}else{
			printf("Digite o elemento a ser inserido: ");
			scanf("%d", &elemento);
			inserir(elemento);
			printf("Elemento inserido com sucesso!\n");
		}
		
		system("pause");
		break;
	
	case 2:
		if(verVazia() == 1){
			printf("Impossível remover. FILA VAZIA\n");
		}else{
			remover();
		}

		system("pause");
		break;
	
	case 3:
		if(verVazia() == 1){
			printf("A fila está vazia.\n");
		}else{
			verInicio();	
		}
		
		system("pause");
		break;
		
	case 4:
		if(verVazia() == 1){
			printf("A fila está vazia.\n");
		}else{
			verFinal();	
		}
		
		system("pause");
		break;
	
	case 5:
		if(verCheia() == 1){
			printf("Fila cheia.\n");
		}else{
			printf("Fila NÂO cheia.\n");
		}
		
		system("pause");	
		break;
		
	case 6:
		if(verVazia() == 1){
			printf("Fila vazia.\n");
		}else{
			printf("Fila NÂO vazia.\n");
		}
		
		system("pause");	
		break;

	case 7:
		if(verVazia() == 1){
			printf("A fila está vazia.\n");
		}else{
			listar();
		}
		
		system("pause");
		break;
		
	case 8:
		if(verVazia() == 1){
			printf("A fila está vazia.\n");
		}else{
			printf("Digite um elemento para buscar: ");
			scanf("%d", &elemento);
			buscar(elemento);
		}
		
		system("pause");
		break;
		
  
 	case 9:
	    printf("Obrigado por usar nosso sistema :D\n\n");
	    resp = 'n';
	    break;

	default:
	    printf("Você escolheu uma opção errada...");
	    printf("FINALIZANDO O SISTEMA :( ");
	}
}

int verCheia(){
	int x;
		if(final == max){
			x = 1;
		}else {
			x = 0;
		}
	return(x);	
}

int verVazia(){
	int x;
		if( comeco == final){
			x = 1;
		} else {
			x = 0;
		}	
	return(x);
}

void inserir(int k){
 	fila[final] = k;
	final++;
}

void remover(){
	printf("O elemento %d foi removido do início da posicão %d.\n", fila[comeco], comeco);
	comeco++;
}

void listar(){
	int i;
	printf("Listando fila:\n");
	for(i = comeco; i < final; i++){
		printf("%d\n", fila[i]);
	}
	printf("Fim da listagem.");
}

void verInicio(){
	printf("O elemento do início da fila é: %d\n", fila[comeco]);
}

void verFinal(){
	printf("O elemento do final da fila é: %d\n", fila[final - 1]);
}

void buscar(int x){
	int achei = 0,i;
	for( i = comeco; i<final; i++){
		if(fila[i]==x){
			achei = 1;
			printf("Elemento %d foi encontrado com sucesso na pilha posição %d\n ",fila[i], i);
			
		}
	}
	if(achei == 0){
			printf("O elemento não foi encontrado.\n");
		}
} 
