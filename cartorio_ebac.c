#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de mem�ria 
#include <locale.h> //Biblioteca de localiza��o do texto por regi�o lingu�stica
#include <string.h> //Biblioteca respons�vel por cuidar das strings

//Fun��es
int registrar()
{
	//Vari�veis:
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	
	//Leitura e armazenamento do dado "CPF":
	printf("Digite o n�mero do CPF: ");
	scanf("%s", cpf);
	
	//Copia o valor da string "cpf" para a string "arquivo":
	strcpy(arquivo, cpf);
	
	//Chama FILE e cria um arquivo vazio dentro dele: 	
	FILE*file; 
	
	//Abre o arquivo criado no FILE e armazena a vari�vel "arquivo". "w"= write:
	file = fopen(arquivo, "w");
	
	//Escreve a vari�vel "cpf" dentro do arquivo vazio:
	fprintf(file, cpf);
	
	//Fecha o arquivo do banco de dados:
	fclose(file);
	
	//Abre o arquivo do banco de dados:
	file = fopen(arquivo, "a");
	
	//Acrescenta uma v�rgula para separar as informa��es:
	fprintf(file, ", ");
	
	//Fecha o arquivo do banco de dados:
	fclose(file);
	
	
	//Leitura e armazenamento do dado "Nome":
	printf("Digite o primeiro nome: ");
	scanf("%s", nome);	
	
	//Armazena a vari�vel "nome" no Banco de Dados:
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	//Acrescenta uma v�rgula para separar as informa��es:
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	
	//Leitura e armazenamento do dado "Sobrenome":
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	//Armazena a vari�vel "sobrenome" no Banco de Dados:
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	//Acrescenta uma v�rgula para separar as informa��es:
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	
	//Leitura e armazenamento do dado "Cargo":
	printf("Digite o cargo a ser registrado: ");
	scanf("%s", cargo);
	
	//Armazena a vari�vel "cargo" no Banco de Dados:
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("cls");
	printf("Registro realizado com sucesso!\n\n");
	system("pause");
}

int consultar()
{
	//Chamada da biblioteca de localiza��o de regi�o lingu�stica:
	setlocale (LC_ALL, "Portuguese");
	
	//Vari�veis:
	char cpf[40];
	char conteudo[200];
	
	//Leitura de qual dado deve ser consultado pelo sistema:
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	//Consulta do CPF informado no Banco de Dados:
	FILE*file;
	file=fopen(cpf, "r");
	
	//Condicional de verifica��o de arquivo:
	if (file == NULL)
	{
		printf("\nRegistro n�o encontrado!.\n\n");
		system("pause");	
	}
	
	//Sa�da de dados das informa��es do usu�rio:
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar ()
{
	//Vari�veis:
	char cpf[40];
	
	//Leitura do CPF a ser deletado:
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s", cpf);
	
	//Deleta o registro desejado:
	remove(cpf);
	system("pause");
	
	//Caso o usu�rio digite um registro que n�o existe:
	FILE*file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf("Esse usu�rio n�o existe!\n\n");
		system("pause");	
	}
}



//Inicio do Programa:
int main()
{ 
	
	//Vari�veis:
	int opcao = 0; 
	int laco = 1;
	
	//La�o de repeti��o
	for (laco = 1; laco = 1;)
	{
		
		//Limpa a tela:
		system("cls");

		//Chamada da biblioteca de localiza��o de regi�o lingu�stica:
		setlocale (LC_ALL, "Portuguese");
	
		//Boas vindas:
		printf("======== Cart�rio EBAC ========\n\n"); 
	
		//Estrutura do Menu:
		printf("Escolha a op��o desejada:\n\n"); 
		printf("\t 1 - Registrar usu�rio\n"); 
		printf("\t 2 - Consultar usu�rio\n"); 
		printf("\t 3 - Deletar usu�rio\n\n"); 
		printf("\t 4 - Sair do sistema\n\n");
	
		//Leitura de dados:
		printf("Op��o: ");
		scanf("%d", &opcao); 
	
		//Limpa a tela:
		system("cls");	
		
		
		//Switch case do Menu:
		switch (opcao)
		{
			case 1:
				registrar();
				break;
				
			case 2:
				consultar();
				break;
			
			case 3:
				deletar();
				break;
		
			case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
				
			default:
				printf("Op��o n�o dispon�vel.\n\n");
				system("pause");
		}
	}


} //Fim da execu��o do Programa
