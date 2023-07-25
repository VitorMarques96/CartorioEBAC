#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de memória 
#include <locale.h> //Biblioteca de localização do texto por região linguística
#include <string.h> //Biblioteca responsável por cuidar das strings

//Funções
int registrar()
{
	//Variáveis:
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	
	
	//Leitura e armazenamento do dado "CPF":
	printf("Digite o número do CPF: ");
	scanf("%s", cpf);
	
	//Copia o valor da string "cpf" para a string "arquivo":
	strcpy(arquivo, cpf);
	
	//Chama FILE e cria um arquivo vazio dentro dele: 	
	FILE*file; 
	
	//Abre o arquivo criado no FILE e armazena a variável "arquivo". "w"= write:
	file = fopen(arquivo, "w");
	
	//Escreve a variável "cpf" dentro do arquivo vazio:
	fprintf(file, cpf);
	
	//Fecha o arquivo do banco de dados:
	fclose(file);
	
	//Abre o arquivo do banco de dados:
	file = fopen(arquivo, "a");
	
	//Acrescenta uma vírgula para separar as informações:
	fprintf(file, ", ");
	
	//Fecha o arquivo do banco de dados:
	fclose(file);
	
	
	//Leitura e armazenamento do dado "Nome":
	printf("Digite o primeiro nome: ");
	scanf("%s", nome);	
	
	//Armazena a variável "nome" no Banco de Dados:
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	//Acrescenta uma vírgula para separar as informações:
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	
	//Leitura e armazenamento do dado "Sobrenome":
	printf("Digite o sobrenome: ");
	scanf("%s", sobrenome);
	
	//Armazena a variável "sobrenome" no Banco de Dados:
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	//Acrescenta uma vírgula para separar as informações:
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	
	//Leitura e armazenamento do dado "Cargo":
	printf("Digite o cargo a ser registrado: ");
	scanf("%s", cargo);
	
	//Armazena a variável "cargo" no Banco de Dados:
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("cls");
	printf("Registro realizado com sucesso!\n\n");
	system("pause");
}

int consultar()
{
	//Chamada da biblioteca de localização de região linguística:
	setlocale (LC_ALL, "Portuguese");
	
	//Variáveis:
	char cpf[40];
	char conteudo[200];
	
	//Leitura de qual dado deve ser consultado pelo sistema:
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	//Consulta do CPF informado no Banco de Dados:
	FILE*file;
	file=fopen(cpf, "r");
	
	//Condicional de verificação de arquivo:
	if (file == NULL)
	{
		printf("\nRegistro não encontrado!.\n\n");
		system("pause");	
	}
	
	//Saída de dados das informações do usuário:
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	system("pause");
}

int deletar ()
{
	//Variáveis:
	char cpf[40];
	
	//Leitura do CPF a ser deletado:
	printf("Digite o CPF que deseja deletar: ");
	scanf("%s", cpf);
	
	//Deleta o registro desejado:
	remove(cpf);
	system("pause");
	
	//Caso o usuário digite um registro que não existe:
	FILE*file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf("Esse usuário não existe!\n\n");
		system("pause");	
	}
}



//Inicio do Programa:
int main()
{ 
	
	//Variáveis:
	int opcao = 0; 
	int laco = 1;
	
	//Laço de repetição
	for (laco = 1; laco = 1;)
	{
		
		//Limpa a tela:
		system("cls");

		//Chamada da biblioteca de localização de região linguística:
		setlocale (LC_ALL, "Portuguese");
	
		//Boas vindas:
		printf("======== Cartório EBAC ========\n\n"); 
	
		//Estrutura do Menu:
		printf("Escolha a opção desejada:\n\n"); 
		printf("\t 1 - Registrar usuário\n"); 
		printf("\t 2 - Consultar usuário\n"); 
		printf("\t 3 - Deletar usuário\n\n"); 
		printf("\t 4 - Sair do sistema\n\n");
	
		//Leitura de dados:
		printf("Opção: ");
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
				printf("Opção não disponível.\n\n");
				system("pause");
		}
	}


} //Fim da execução do Programa
