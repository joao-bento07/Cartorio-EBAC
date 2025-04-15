#include <stdio.h> //bibloteca de comunicação com o usuário 
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função Responsável por cadastrar os usuários no sistema
{
	// início da criação de variáveis/string
	char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // final da criação
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando informções do usuário
    scanf("%s" , cpf);
    
    strcpy(arquivo,cpf); //Responsável por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); //Salva o valor da variável
    fclose(file); //Fecha o arquivo

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: "); //Coletando informações do usuário
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: "); //Coletando informações do usuário
    scanf("%s", sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado:"); //Coletando informações do usuário
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause"); //Comando para pausar a execução do programa até que o usuário pressione a tecla ENTER
    

}

int consulta()
{	
	setlocale (LC_ALL, "Portuguese"); //Definindo a Linguagem
	
   char cpf[40];
   char conteudo[200];
   
   printf("Digite o CPF a ser consultado:"); //Coletando informações do usuário 
   scanf("%s",cpf);
   
   FILE *file;
   file = fopen(cpf, "r");
   
   if(file == NULL)
   {
   	   printf("Não foi possível abrir o arquivo, não localizado!. \n"); //Configurando o sistema de acordo com a resposta
   }
   
   while(fgets(conteudo, 200,file) != NULL)
   {
   	     printf("\nEssas são as informções do usuário: "); //Apresentando as informações do usuário que deseja ser acessado
   	     printf("%s", conteudo);
   	     printf("\n\n");
   }

   system("pause"); //Comando para pausar a execução do programa até que o usuário pressione a tecla ENTER

}

int deletar()
{
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletando informações do usuário
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n"); //Configurando o sistema de acordo com a resposta
		system("pause"); //Comando para pausar a execução do programa até que o usuário pressione a tecla ENTER
	}
		
}

int main() //Função principal
    {
    int opcao=0; //definindo varoáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
    	
    	system("cls"); //Responsável por limpar a tela
    	
    	setlocale (LC_ALL, "Portuguese"); //Definindo a Linguagem
    	
    	printf("### Cartório da EBAC ###\n\n"); //inicio do menu 
    	printf("Escolha a opção desejada do menu\n\n"); //Layout da tela inicial
    	printf("\t1 - Registrar nomes\n"); //Layout da tela inicial
    	printf("\t2 - Consultar nomes\n"); //Layout da tela inicial
    	printf("\t3 - Deletar nomes\n\n"); //Layout da tela inicial
    	printf("\t4 - Sair do Sistema\n\n"); //Layout da tela inicial
    	printf("Opção: ");//fim do menu
    	
    	scanf("%d" , &opcao); //armazenamento a escolha do usuário
    	
    	system("cls"); //Responsável por limpar a tela
    	
    	switch(opcao) //Início da seleção do menu
    	{
    	   case 1:
		   registro(); //chamada de funções 
			break;
			
			case 2: 
			consulta(); //chamada de funções
			break;
			
			case 3:
			deletar(); //chamada de funções
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause"); //Comando para pausar a execução do programa até que o usuário pressione a tecla ENTER
			break; 	
		} //Fim da seleção
    	
		
    	}	
    	
    	
	}
