#include <stdio.h> //biblioteca de comunicaçao com o usuario
#include <stdlib.h> //biblioteca de alocaçao de espaço em memorias
#include <locale.h> //biblioteca de alocaçoes de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()    //Funçao
{
	char arquivo[40]; //string
	char cpf[40];    //string
	char nome[40];   //string
	char sobrenome[40];  //string
	char cargo[40];  //string
	
	printf("Digite o CPF a ser cadastrado: "); //comentario
	scanf("%s", cpf);  //salva dentro de uma string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file;           // Cria o arquivo
	file = fopen(arquivo, "w");  //Cria o arquivo na variavel escrever
	fprintf(file,cpf);       //salva o valor da variavel
	fclose(file);            // fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza as informaçoes do arquivo
	fprintf(file,","); //coloca virgula para nao ficar tudo junto
	fclose(file);   //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //comentario
	scanf("%s",nome); //salva dentro de uma string
	
	file = fopen(arquivo, "a"); //atualiza as informaçoes do arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza as informaçoes do arquivo
	fprintf(file,",");   //coloca virgula para nao ficar tudo junto
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //comentario
	scanf("%s",sobrenome); //salva dentro de uma string
	
	file = fopen(arquivo, "a"); //atualiza as informaçoes do arquivo
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza as informaçoes do arquivo
	fprintf(file,","); //coloca virgula para nao ficar tudo junto
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //comentario
	scanf("%s",cargo); //salva dentro de uma string
	
	file = fopen(arquivo, "a"); //atualiza as informaçoes do arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //o sitema pausa a tela, ate o usuario sair dela
	
}

int consultar()  //funçao
{
	setlocale(LC_ALL, "Portuguese"); //linguagem em português
	char cpf[40]; //string
	char conteudo[200]; //string
	
	printf("Digite o CPF a ser consultado: "); //comentario
	scanf("%s", cpf); //salva dentro de uma string
	
	FILE *file; // Cria o arquivo
	file = fopen(cpf,"r"); // Cria o arquivo na variavel ler
	
	if(file == NULL) //usuario nao existe
	{
		printf("Não foi possivel abrir o arquivo, não localizado! \n"); //comentario
	}
	
	while(fgets(conteudo, 200, file) != NULL) //busca o usuario no arquivo
	{
		printf("\nEssas são as informações do usuário: "); //comentario
		printf("%s", conteudo); //salva dentro de uma string
		printf("\n\n"); //pular linha
	}
	
	system("pause"); //sistema pausa a tela
}

int deletar()  //funçao
{
	char cpf[40]; //string
	
	printf("Digite o CPF do usuário a ser deletado: "); //comentario
	scanf("%s",cpf); //salva dentro de uma string
	
	remove(cpf);  //deleta o arquivo escolhido
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); // arquivo na variavel ler
	
	if(file == NULL) //nao achar o arquivo
	{
		printf("O usuário não se encontra no sistema!\n"); //comentario
		system("pause"); //pausa a tela
	}
	
}

int main() //funçao
{
	int opcao=0;  //definindo as variaveis
	int x=1;  //enquanto o valor for 1, vai estar em funcionamento
	
	for (x=1;x=1;) //repetindo a funçao
    {
	   system("cls");  //sistema limpa a tela
	   
	   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	   printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	   printf("Escolha a opção desejada do menu:\n\n"); //comentario
	   printf("\t1 - Registrar nomes\n"); //opçao 1
	   printf("\t2 - Consultar nomes\n"); //opçao 2
	   printf("\t3 - Deletar nomes\n\n"); //opçao 3
	   printf("Opçao: "); //fim do menu
	
	   scanf("%d", &opcao); //armazenando a escolha do usuario
	
	   system("cls");  //sistema limpa a tela
	   
	   switch(opcao) //testa igualdades
	   {
	   	    case 1: //caso for 1
	   	    registro();
	   		break; //fecha chave
	   	    
	   	    case 2: //caso for 2
	   		consultar();
	   	    break; //fecha chave
	   	    
	   	    case 3: //caso for 3
	   		deletar();
	   	    break; //fecha chave
	   	    
	   	    default:   //se nao for nenhuma opçao
	   	    printf("Essa opção não está disponivel!\n"); //comentario
		    system("pause"); //sistema pausa a tela
	   		break;  //fecha chave
	   	
	   	
	   }
	
    }     
}
