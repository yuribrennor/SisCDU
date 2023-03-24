#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registrar() //fun��o responsavel por cadastrar os usu�rios no sistema.
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("### REGISTRAR NOVO USU�RIO ###\n\n\n");
	
	printf("CPF (apenas n�meros): "); //coletando informa��es do usu�rio.
	scanf("%s",cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das string
	
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
	
	printf("### CONSULTAR USU�RIOS ###\n\n\n");
	printf("Digite o CPF do usu�rio a ser consultado (apenas n�meros): ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	if(file == NULL)
	{
		printf("Usu�rio n�o encontrado. \n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rios: \n\n\n\n");
		printf("%s",conteudo);
		printf("\n\n\n\n");
	}
	fclose(file);
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("### DELETAR USU�RIOS ###\n\n");
	printf("Digite o CPF do usu�rio a ser deletado (apenas n�meros): ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### SISTEMA DE CONTROLE DE USU�RIOS DA EBAC ### \n\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu: \n\n");
		printf("\t1 - REGISTRAR USU�RIO\n");
		printf("\t2 - CONSULTAR USU�RIO\n");
		printf("\t3 - DELETAR USU�RIO\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
		system("cls"); //responsavel por limpar a tela
		
		switch(opcao) //inicio da sele��o do menu
		{
			case 1: //inicio da sele��o
			registrar(); //chamada de fun��es
			break;
			
			case 2:
			consultar();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Essa op��o n�o est� disponivel!\n\n");
			system("pause");
			break; //fim da sele��o
		}
	}
}
