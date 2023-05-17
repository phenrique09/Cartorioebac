#include <stdio.h> //biblioteca de comunica�ao com o usuario
#include <stdlib.h> //biblioteca de aloca�ao de espa�o em memorias
#include <locale.h> //biblioteca de aloca�oes de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()    //Fun�ao
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
	
	file = fopen(arquivo, "a"); //atualiza as informa�oes do arquivo
	fprintf(file,","); //coloca virgula para nao ficar tudo junto
	fclose(file);   //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //comentario
	scanf("%s",nome); //salva dentro de uma string
	
	file = fopen(arquivo, "a"); //atualiza as informa�oes do arquivo
	fprintf(file,nome); //salva o valor da variavel
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza as informa�oes do arquivo
	fprintf(file,",");   //coloca virgula para nao ficar tudo junto
	fclose(file);  //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); //comentario
	scanf("%s",sobrenome); //salva dentro de uma string
	
	file = fopen(arquivo, "a"); //atualiza as informa�oes do arquivo
	fprintf(file,sobrenome); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza as informa�oes do arquivo
	fprintf(file,","); //coloca virgula para nao ficar tudo junto
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: "); //comentario
	scanf("%s",cargo); //salva dentro de uma string
	
	file = fopen(arquivo, "a"); //atualiza as informa�oes do arquivo
	fprintf(file,cargo); //salva o valor da variavel
	fclose(file); //fecha o arquivo
	
	system("pause"); //o sitema pausa a tela, ate o usuario sair dela
	
}

int consultar()  //fun�ao
{
	setlocale(LC_ALL, "Portuguese"); //linguagem em portugu�s
	char cpf[40]; //string
	char conteudo[200]; //string
	
	printf("Digite o CPF a ser consultado: "); //comentario
	scanf("%s", cpf); //salva dentro de uma string
	
	FILE *file; // Cria o arquivo
	file = fopen(cpf,"r"); // Cria o arquivo na variavel ler
	
	if(file == NULL) //usuario nao existe
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado! \n"); //comentario
	}
	
	while(fgets(conteudo, 200, file) != NULL) //busca o usuario no arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: "); //comentario
		printf("%s", conteudo); //salva dentro de uma string
		printf("\n\n"); //pular linha
	}
	
	system("pause"); //sistema pausa a tela
}

int deletar()  //fun�ao
{
	char cpf[40]; //string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //comentario
	scanf("%s",cpf); //salva dentro de uma string
	
	remove(cpf);  //deleta o arquivo escolhido
	
	FILE *file; //acessa o arquivo
	file = fopen(cpf,"r"); // arquivo na variavel ler
	
	if(file == NULL) //nao achar o arquivo
	{
		printf("O usu�rio n�o se encontra no sistema!\n"); //comentario
		system("pause"); //pausa a tela
	}
	
}

int main() //fun�ao
{
	int opcao=0;  //definindo as variaveis
	int x=1;  //enquanto o valor for 1, vai estar em funcionamento
	
	for (x=1;x=1;) //repetindo a fun�ao
    {
	   system("cls");  //sistema limpa a tela
	   
	   setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	   printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu
	   printf("Escolha a op��o desejada do menu:\n\n"); //comentario
	   printf("\t1 - Registrar nomes\n"); //op�ao 1
	   printf("\t2 - Consultar nomes\n"); //op�ao 2
	   printf("\t3 - Deletar nomes\n\n"); //op�ao 3
	   printf("Op�ao: "); //fim do menu
	
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
	   	    
	   	    default:   //se nao for nenhuma op�ao
	   	    printf("Essa op��o n�o est� disponivel!\n"); //comentario
		    system("pause"); //sistema pausa a tela
	   		break;  //fecha chave
	   	
	   	
	   }
	
    }     
}
