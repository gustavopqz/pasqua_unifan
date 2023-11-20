#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define max 5

int verCheia();
int verVazia();
void inserir(int);
void remover();
void listar();
void verTopo();
void buscar(int);
void menu();
void inicializar();

int pilha[max];
int topo;
int elemento, num;
char resp = 's';


int main(){
	setlocale(LC_ALL,"");
	inicializar();
	
	while(resp != 'n'){
		system("cls");
		menu();
	}	
}
	void menu(){
		int escolha;
		
		printf("MENU:\n");
		printf("Escolha uma opção:\n");
		printf(" 1. INSERIR\n 2. REMOVER\n 3. VER TOPO\n 4. LISTAR\n 5. BUSCAR\n 6. VER CHEIA\n 7. VER VAZIA\n 8. SAIR\n");
		scanf("%d",&escolha);
		switch(escolha) {
		case 1:
			if (verCheia()==1){
				printf("Impossível inserir. PILHA CHEIA!\n");
				break;
			}else{
				printf("Informe o elemento a ser inserido: \n");
				scanf("%d",&elemento);
				
				inserir(elemento);
			}	
			break; 
			
		case 2:
			if(verVazia() == 1){
				printf("Impossível remover. PILHA VAZIA!\n");
			}else{
				remover();
			}
			break;
			
		
		case 3:
			if(verVazia()==1){
				printf("Impossível ver topo. PILHA VAZIA!\n");
			}else{
				verTopo();
			}
			break;
			
		case 4:
			if(verVazia() == 1){
				printf("Impossível listar. PILHA VAZIA!\n");
			}else{
				listar();
			}
			break;
		case 5:
			int num5;
			if(verVazia() == 1){
				printf("Impossível buscar. PILHA VAZIA!\n");
			} else {
				printf("Informe o elemento que deseja buscar:\n");
				fflush(stdin);
				scanf("%d",&num5);
				buscar(num5);
			}
			break;
		case 6:
			if(verCheia() == 1){
				printf("A pilha está cheia\n");
			} else {
				printf("A pilha não está cheia. EXISTE ESPAÇOS VAZIOS\n");
			}
			break;
		case 7:
			if(verVazia() == 1){
				printf("A pilha está vazia\n");
			} else {
				printf("A pilha não está vazia. EXISTEM ELEMENTOS NA PILHA\n");
			}	
			break;
		case 8:
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
		if(topo == max-1){
			x = 1;
		}else {
			x = 0;
		}
	return(x);
	system("pause");	
}
int verVazia(){
	int x;
		if( topo == -1){
			x = 1;
		} else {
			x = 0;
		}	
	return(x);
	system("pause");
}

void inserir(int k ){
		topo++;
 		pilha[topo] = k;
		printf("O elemento %d foi inserido com sucesso, na posição %d ", pilha[topo], topo);
		system("pause");		
}

void remover(){
	printf(" O elemento %d foi removido do topo.\n", pilha[topo]);
	topo--;
	system("pause");
}

void listar(){
	int i;
	for(i = topo; i >= 0; i--){
		printf("%d\n", pilha[i]);
	} 
	system("pause");
}
void inicializar(){
	topo = -1;
}

void buscar(int x){
	int achei = 0,i;
	for( i = topo; i>=0; i--){
		if(pilha[i]==x){
			achei = 1;
			printf("Elemento %d foi encontrado com sucesso na pilha posição %d\n ",pilha[topo], i);
		}
	}
	if(achei == 0){
			printf("O elemento não foi encontrado.\n");
		}
		system("pause");
}
void verTopo(){
	printf("O número %d esta no topo da pilha, na posicao %d", pilha[topo], topo);
	system("pause");
}


