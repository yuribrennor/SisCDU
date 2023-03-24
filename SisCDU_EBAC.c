#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registrar() //função responsavel por cadastrar os usuários no sistema.
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("### REGISTRAR NOVO USUÁRIO ###\n\n\n");
	
	printf("CPF (apenas números): "); //coletando informações do usuário.
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,"CPF: "); 
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,cpf);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, " | NOME: ");
	fclose(file);
	
	printf("NOME: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("SOBRENOME: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," | CARGO: ");
	fclose(file);
	
	printf("CARGO: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	printf("\n\n");
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("### CONSULTAR USUÁRIOS ###\n\n\n");
	printf("Digite o CPF do usuário a ser consultado (apenas números): ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL)
	{
		printf("Usuário não encontrado. \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuários: \n\n\n\n");
		printf("%s",conteudo);
		printf("\n\n\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("### DELETAR USUÁRIOS ###\n\n");
	printf("Digite o CPF do usuário a ser deletado (apenas números): ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### SISTEMA DE CONTROLE DE USUÁRIOS DA EBAC ### \n\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu: \n\n");
		printf("\t1 - REGISTRAR USUÁRIO\n");
		printf("\t2 - CONSULTAR USUÁRIO\n");
		printf("\t3 - DELETAR USUÁRIO\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usuário
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da seleção do menu
		{
			case 1: //inicio da seleção
			registrar(); //chamada de funções
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa opção não está disponivel!\n\n");
			system("pause");
			break; //fim da seleção
		}
	}
}
