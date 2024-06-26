#include <stdio.h> //biblioteca de comunicação com o usuário
#include <locale.h>  //alocaçoês de texto por regiâo
#include <stdlib.h>  //espaço na memoria
#include <string.h> //biblioteca responsavel pelas Strings


//  \n = pular linha
//  \t = espaço

int adicionar() //Fução para adicionar nomes
{
	
	//Criação de variaveis/Strings
	char arquivo[30];
	char cpf[30];
	char nome[30];
	char sobrenome[30];
	char cargo[30];
	
	printf("Digite o CPF: "); //Pede e salva o cpf do usuário
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Copia o valor da variavel 'cpf' para variavel 'arquivo'
	
	FILE *file; //cria um arquivo no computador
	file = fopen(arquivo, "w"); //Cria o arquivo usando o valor da variavel arquivo 'w' = write
	fprintf(file, cpf); //coloca no arquivo o valor da variavel cpf
	fclose(file);
	
	file = fopen(arquivo, "a"); //Abre um arquivo existente "a"
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o Nome: "); //Pede o nome do usuário e salva na variavel nome
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //abre o arquivo e salva o nome escrito na variavel
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abre o arquivo e adiciona uma virgula
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome: "); //pede o sobrenome do usuário e salva na variavel sobrenome
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //abre o arquivo e salva o sobrenome
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a"); //abre o arquivo e adiciona uma virgula
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar() //Função para consultar nomes
{
	setlocale(LC_ALL, "Portuguese"); //Coloca a Localizão para portugues
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF para consultar: "); //Pede e salva o cpf a ser consultado na variavel cpf
	scanf("%s", cpf); // %s refere-se a Strings
	
	FILE *file;
	file = fopen(cpf, "r"); //Le o arquivo com o nome igual a variavel cpf 'r' = read
	
	if(file == NULL) //Se o valor digitado na variavel cpf não existir faça:
	{
		printf("CPF não encontrado! ");
	}

	while(fgets(conteudo, 200, file) != NULL) //salva as linhas do file na variavel 'conteudo' com no maximo 200 caracteres
	{
		printf("Esses são as informações do usuario: ");
		printf("%s",conteudo); 
		printf("\n\n");
	
	}

	system("pause");

}


int deletar() //função para deletar nomes
{
	setlocale(LC_ALL, "Portuguese"); //Coloca a Localizão para portugues
	
	char cpf[40];
	
	printf("Digite o CPF que deseja deletar: "); //Pede e salva o cpf digitado
	scanf("%s", cpf);
	
	if(remove(cpf) == 0) //apaga o arquivo com o cpf digitado
	{
		printf("arquivo removido com sucesso \n");
		system("pause");
	}
	else
	{
		printf("CPF não foi encontrado \n");
		system("pause");
	
	}
	FILE *file;
	file = fopen(cpf, "r"); //avre o arquivo para ler 'r' = read
	
}


int main() //função principal
{
	int escolha=0; //Variavel escolha
	int x=1;
	
	for(x=1;x=1;) // loop enquanto volta ao menu
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Coloca a Localizão para portugues
	
		printf("-Lista de Alunos- \n\n"); //Inicio do menu
		printf("Escolha entre as opçôes abaixo: \n\n");
		printf("\t 1- Adicionar nome \n");
		printf("\t 2- Consultar nomes \n");
		printf("\t 3- Deletar nome \n \n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &escolha); //Guarda a tecla apertada na variavel 'escolha'
	
		system("cls"); //Limpa a tela anterior
	
		switch(escolha)
		{
			case 1:
			adicionar(); //Chama a funçao de adicionar nomes
			break;
		
			case 2:
			consultar(); //Chama a função de consultar nomes
			break;
		
			case 3:
			deletar();
			break;
		
			default: //Caso qualquer outro número seja digitado que nao esteja entre as opções
			printf("Essa opção não existe. \n");
			system("pause");
			break;
		}
	

	}	

}

