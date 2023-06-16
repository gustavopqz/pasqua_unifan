//Declarando bibliotecas
//Biblioteca padrao de entrada e saida
#include <stdio.h>
//Biblioteca para tratamento de strings
#include <string.h>
//Biblioteca para coletar data atual
#include <time.h>


//Structs simularcao requisicoes no banco de dados

//Definindo struct para administradores
struct Vendedor{
	char login[20];
	char password[20];
};

//Definindo struct para clientes
struct Cliente{
	char nome[30];
	char cpf[11];
	char telefone[11];
};

//Definindo struct para contratos
struct Contrato{
	char apolice[9];
	int dia, mes, ano;
	float premio_total, premio_liquido;
	char CPF_cliente[11];
};


//Funcao principal
int main(){
	//Declarando variaveis do sistema
	char loginDigitado[20], senhaDigitada[20];
	int numeroVendedores = 2, numeroClientes = 2, numeroContratos = 4;
		
	//Criando instancias dos administradores que irao simular dados trazidos do banco de dados
	struct Vendedor vendedores[100];
	
	//Para Gustavo
	strcpy(vendedores[0].login, "gustavo.pasqua");
	strcpy(vendedores[0].password, "123");
	
	//Para Savio
	strcpy(vendedores[1].login, "savio.guimaraes");
	strcpy(vendedores[1].password, "12345");
	
	//Criando instancias dos contratos que irao simular dados trazidos do banco de dados
	struct Cliente clientes[100];
	//Para cliente1
	strcpy(clientes[0].nome, "Jose Antonio da Silva Pereira");
	strcpy(clientes[0].cpf, "66114368045");
	strcpy(clientes[0].telefone, "75991254878");
	
	strcpy(clientes[1].nome, "Anderson Dantas Soto Junior");
	strcpy(clientes[1].cpf, "85668922081");
	strcpy(clientes[1].telefone, "75999784865");
	
	//Criando instancias dos contratos que irao simular dados trazidos do banco de dados
	struct Contrato contratos[200];
	//Para contrato1
	strcpy(contratos[0].apolice, "123456789");
	contratos[0].dia = 1;
	contratos[0].mes = 04;
	contratos[0].ano = 2023;
	contratos[0].premio_total = 1000;
	contratos[0].premio_liquido = 946;	
	strcpy(contratos[0].CPF_cliente, "85668922081");
	
	//Para contrato2
	strcpy(contratos[1].apolice, "987654321");
	contratos[1].dia = 12;
	contratos[1].mes = 05;
	contratos[1].ano = 2022;
	contratos[1].premio_total = 1500;
	contratos[1].premio_liquido = 1422;
	strcpy(contratos[1].CPF_cliente, "85668922081");
	
	//Para contrato3
	strcpy(contratos[2].apolice, "423535678");
	contratos[2].dia = 20;
	contratos[2].mes = 06;
	contratos[2].ano = 2022;
	contratos[2].premio_total = 1500;
	contratos[2].premio_liquido = 1422;
	strcpy(contratos[2].CPF_cliente, "66114368045");
	
	//Para contrato2
	strcpy(contratos[3].apolice, "675832123");
	contratos[3].dia = 25;
	contratos[3].mes = 06;
	contratos[3].ano = 2022;
	contratos[3].premio_total = 2000;
	contratos[3].premio_liquido = 1899;
	strcpy(contratos[3].CPF_cliente, "66114368045");
	
	
	while(true){
		bool sucesso;
		//Solicitando login do vendedor
		printf("Login: ");
		scanf("%s", loginDigitado);
		printf("Senha: ");
		scanf("%s", senhaDigitada);
		
		//Buscando por login
		for (int i = 0; i < numeroVendedores; i++){
			//Comparar strings - Se a comparacao for igual a 0 as strings sao iguais
			int compararLogin = strcmp(vendedores[i].login, loginDigitado);
			
			//Caso login seja encontrado, comparar senhas
			if(compararLogin == 0){
				int compararSenha = strcmp(vendedores[i].password, senhaDigitada);
				if (compararSenha == 0){
					printf("Login excutado com sucesso!\n\n");
					sucesso = true;
					break;
				}
			}
		}
		
		// Se a variavel sucesso for falsa o login ou senha estao incorretos
		if(sucesso == false){
			printf("Login ou senha incorretos!\n");
		}else{
			break;
		}
	}
	
	//Coletando data autal
	time_t t = time(NULL);
    struct tm *data_atual = localtime(&t);
    printf("Data atual: %02d/%02d/%d\n", data_atual->tm_mday, data_atual->tm_mon + 1, data_atual->tm_year + 1900);
	
	int menu = -1;
	while(menu != 0){
		//Menu para usuario logado
		printf("O que deseja fazer: \n");
		printf("1 - Cadastro de novo vendedor.\n2 - Listar vendedores.\n3 - Cadastro de novo cliente.\n4 - Inserir novo contrato.\n5 - Consulta de contrato pelo numero da apolice.\n6 - Contratos com vencimento no mes atual.\n0 - Sair.\nDigite a opcao desejada: ");
		scanf("%d", &menu);
		switch (menu){
			case 0:
				break;
			case 1:
				char login[50], senha[30];
				printf("\nDigite o login do novo vendedor: ");
				scanf("%s", vendedores[numeroVendedores].login);
				printf("Digite a senha do novo vendedor: ");
				scanf("%s", vendedores[numeroVendedores].password);
				numeroVendedores++;
				printf("Vendedor cadastrado com sucesso!\n\n");
				break;
			case 2:
				printf("\nVendedores cadastrados:\n");
				for(int i = 0; i < numeroVendedores; i++){
					printf("%d - %s\n", i + 1, vendedores[i].login);
				}
				printf("\n");
				break;				
			case 3:
				char nome[50];
				printf("\nDigite o nome do novo cliente: ");
				fgets(nome, sizeof(nome), stdin);
				strcpy(clientes[numeroClientes].nome, nome);
				printf("%s", nome);
				printf("%s", clientes[numeroClientes].nome);
				printf("Digite o cpf do novo cliente: ");
				scanf("%s", clientes[numeroClientes].cpf);
				printf("Digite o telefone do novo cliente: ");
				scanf("%s", clientes[numeroClientes].telefone);
				numeroClientes++;
				printf("Cliente cadastrado com sucesso!\n\n");
				break;
			case 4:
				// Apolice do novo contrato
				printf("\nDigite o numero de apolice do novo contrato (9 digitos): ");
				scanf("%s", contratos[numeroContratos].apolice);
				
				// Inserir CPF do cliente no contrato
				printf("Digite o CPF do cliente contratante: ");
				char cpf_digitado[11];
				scanf("%s", contratos[numeroContratos].CPF_cliente);
				
				// Premio total
				printf("Digite o valor do premio total: ");
				scanf("%f", &contratos[numeroContratos].premio_total);
				// Premio liquido
				contratos[numeroContratos].premio_liquido = contratos[numeroContratos].premio_total * 0.94; // - 6% de imposto (exemplo)
				// Data do contrato
				contratos[numeroContratos].dia = data_atual->tm_mday;
				contratos[numeroContratos].mes = data_atual->tm_mon + 1;
				contratos[numeroContratos].ano = data_atual->tm_year + 1900;
				numeroContratos++;
				printf("Cadastrado com sucesso!\n\n");
				break;
			case 5:
				char consultaApolice[11];
				printf("\nDigite o numero da apolice do contrato que deseja consultar: ");
				scanf("%s", consultaApolice);
				for(int i = 0; i < numeroContratos; i++){
					int compararApolices = strcmp(consultaApolice, contratos[i].apolice);
					if(compararApolices == 0){
						printf("\nNumero da apolice: %s\n", contratos[i].apolice);
						printf("CPF do cliente vinculado a este contrato: %s\n", contratos[i].CPF_cliente);
						printf("Premio total do contrato: %f\n", contratos[i].premio_total);
						printf("Premio liquido do contrato: %f\n", contratos[i].premio_liquido);
						printf("Data de inicio do contrato: %02d/%02d/%d\n", contratos[i].dia, contratos[i].mes, contratos[i].ano);
						printf("Data final do contrato: %02d/%02d/%d\n", contratos[i].dia, contratos[i].mes, contratos[i].ano + 1);
					}
				}
				printf("\n\n");
				break;
			case 6:
				printf("\nContratos que vencem no mes atual: \n");
				for (int i = 0; i < numeroContratos; i++){
					if(contratos[i].mes == data_atual->tm_mon + 1 && contratos[i].ano + 1 == data_atual->tm_year + 1900){
						printf("- Apolice: %s, Cliente: %s, Vencimento: %02d/%02d/%d\n", contratos[i].apolice, contratos[i].CPF_cliente, contratos[i].dia, contratos[i].mes, contratos[i].ano + 1);
					}
				}
				printf("\n");
		}
	}

	
	return 0;
}

