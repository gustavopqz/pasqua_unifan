#include <stdio.h>
#include <stdlib.h>

#define MAX 4

int pilha[MAX], topo = 0;
char resp = 's';

void menu();
void inserir();
void remover();
void verTopo();
void listaPilha();
void buscar();
int verCheia();
int verVazia();

main(){	
	while(resp == 's'){
		system("cls");
		menu();
	}
}

void menu(){
	int escolha;
	
	printf("Bem-vindo ao codigo de pilha\n");
	
	printf("1 - Inserir\n");
	printf("2 - Remover\n");
	printf("3 - Ver topo\n");
	printf("4 - Listar pilha\n");
	printf("5 - Buscar\n");
	printf("6 - Ver cheia\n");
	printf("7 - Ver vazia\n");
	printf("8 - Sair\n");
	
	printf("Digite um numero do menu: ");
	scanf("%d", &escolha);
	if(escolha == 1){
		inserir();
	}
	else if(escolha == 3){
		verTopo();
	}
	else if(escolha == 4){
		listaPilha();
	}
	else if(escolha == 8){
		resp = 'n';
	}
}

void inserir(){
	int valor;
	printf("Digite um valor inteiro para adicionar à pilha: ");
	scanf("%d", &valor);
	pilha[topo] = valor;
	topo++;
}

void verTopo(){
	printf("%d\n", topo);
	system("pause");
}

void listaPilha(){
	int i;
	if(topo == 0){
		printf("Lista vazia!\n\n");
		system("pause");
		return;
	}
	for(i = topo-1; i >= 0; i--){
		printf("%d    ", pilha[topo]);
	}
	printf("\n\n");
	system("pause");
}



