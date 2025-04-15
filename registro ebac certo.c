#include <stdio.h> //bibloteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o Respons�vel por cadastrar os usu�rios no sistema
{
	// in�cio da cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da cria��o
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando inform��es do usu�rio
    scanf("%s" , cpf);
    
    strcpy(arquivo,cpf); //Respons�vel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //Salva o valor da vari�vel
    fclose(file); //Fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: "); //Coletando informa��es do usu�rio
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //Coletando informa��es do usu�rio
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:"); //Coletando informa��es do usu�rio
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause"); //Comando para pausar a execu��o do programa at� que o usu�rio pressione a tecla ENTER
    

}

int consulta()
{	
	setlocale (LC_ALL, "Portuguese"); //Definindo a Linguagem
	
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado:"); //Coletando informa��es do usu�rio 
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL)
   {
   	   printf("N�o foi poss�vel abrir o arquivo, n�o localizado!. \n"); //Configurando o sistema de acordo com a resposta
   }
   
   while(fgets(conteudo, 200,file) != NULL)
   {
   	     printf("\nEssas s�o as inform��es do usu�rio: "); //Apresentando as informa��es do usu�rio que deseja ser acessado
   	     printf("%s", conteudo);
   	     printf("\n\n");
   }

   system("pause"); //Comando para pausar a execu��o do programa at� que o usu�rio pressione a tecla ENTER

}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n"); //Configurando o sistema de acordo com a resposta
		system("pause"); //Comando para pausar a execu��o do programa at� que o usu�rio pressione a tecla ENTER
	}
		
}

int main() //Fun��o principal
    {
    int opcao=0; //definindo varo�veis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
    	
    	system("cls"); //Respons�vel por limpar a tela
    	
    	setlocale (LC_ALL, "Portuguese"); //Definindo a Linguagem
    	
    	printf("### Cart�rio da EBAC ###\n\n"); //inicio do menu 
    	printf("Escolha a op��o desejada do menu\n\n"); //Layout da tela inicial
    	printf("\t1 - Registrar nomes\n"); //Layout da tela inicial
    	printf("\t2 - Consultar nomes\n"); //Layout da tela inicial
    	printf("\t3 - Deletar nomes\n\n"); //Layout da tela inicial
    	printf("\t4 - Sair do Sistema\n\n"); //Layout da tela inicial
    	printf("Op��o: ");//fim do menu
    	
    	scanf("%d" , &opcao); //armazenamento a escolha do usu�rio
    	
    	system("cls"); //Respons�vel por limpar a tela
    	
    	switch(opcao) //In�cio da sele��o do menu
    	{
    	   case 1:
		   registro(); //chamada de fun��es 
			break;
			
			case 2: 
			consulta(); //chamada de fun��es
			break;
			
			case 3:
			deletar(); //chamada de fun��es
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause"); //Comando para pausar a execu��o do programa at� que o usu�rio pressione a tecla ENTER
			break; 	
		} //Fim da sele��o
    	
		
    	}	
    	
    	
	}
