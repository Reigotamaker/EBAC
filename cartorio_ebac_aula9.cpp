#include <stdio.h> //Biblioteca de comunicação ao usuário!
#include <stdlib.h> //Biblioteca de alocação de espaço em memória!
#include <locale.h> //Biblioteca de alocações de texto por região!
#include <string.h> //Biblioteca que chama as Strings.

int registro() //Função responsável pelo registro de usuários!
{
	printf("Você escolheu o registro de novos nomes, preencha os campos corretamente!\n\n\n\n");
	
	
	char arquivo[50];
	char cpf[40];
	char nome[40];
	char sobrenome [50];
	char endereco [100];
	char telefone [20];
	char cargo [40];
	//Final da criação de variáveis.
	
	printf("Digite o CPF a ser cadastrado:\n\t\t");
	scanf("%s", cpf);
	strcpy(arquivo, cpf);//Responsável por copiar os valores das strings!
	
	FILE *file; //Cria novo arquivo, na pasta do sistema!
	file = fopen(arquivo, "w");	//Cria novo arquivo, na pasta do sistema!
	fprintf(file,"CPF:\t");//Salva o valor da variável!
	fprintf(file,cpf); //Escreve o no arquivo.
	fclose(file);//Fecha o arquivo!	


	file = fopen(arquivo, "a"); //Separador
	fprintf(file,".\n");
	fclose(file);
	
	printf("Nome:\n\t\t"); //Salva o nome do colaborador!
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//Abre o arquivo e "a" atualiza.
	fprintf(file,"Nome completo:\t");
	fprintf(file,nome);//Escreve o no arquivo.
	fclose(file);
	file = fopen(arquivo, "a");//Separador
	fprintf(file," ");
	fclose(file);
	
	printf("Sobrenome:\n\t\t"); //Salva o sobrenome do colaborador.
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //Não imprime no documento campo sobrenome.
	fprintf(file,sobrenome);//Escreve o no arquivo.
	fclose(file);
	file = fopen(arquivo, "a"); //Separador
	fprintf(file,".\n");
	fclose(file);
	
	printf("Endereço:\n\t\t"); //Salva o endereço do colaborador.
	scanf("%s", endereco);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Endereço:\t");
	fprintf(file, endereco);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file,".\n");
	fclose(file);
	
	printf("Telefone:\n\t\t"); //Salva o contato do colaborador!
	scanf("%s",telefone);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Telefone:\t");
	fprintf(file,telefone);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file,".\n");
	fclose(file);
	
	printf("Cargo:\n\t\t");  //Salva cargo do colaborador!
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo:\t");
	fprintf(file,cargo);
	fclose(file);
	file = fopen(arquivo, "a");
	fprintf(file,".\n");
	fclose(file);
}



int consulta() //função de consulta de usuários já cadastrados!
{
			printf("Busque pelo ID/CPF do usuário!\n\n\n\n");//Explicação da página de consulta de usuários.
		setlocale(LC_ALL, "Portuguese"); //Seleção de linguagem Português-BR.
	
		char cpf [40]; 
		char conteudo[200];
	
			printf("Busca de CPF/ID:\t");
		scanf("%s",cpf);
	
		FILE*file;
		file = fopen(cpf,"r"); //Leitura "r" read. 
	
		if(file == NULL)

		{
			printf("Não localizado, por favor confira e tente novamente!");
		}	

			while (fgets(conteudo, 200, file) != NULL);
		{
			printf("Essas são as informações localizadas:\n\n");
			printf("%s", conteudo);
			printf("\n\n");
		}
	system("pause");
}

int deletar()//Abre a função deletar nomes/usuários.
{
	printf("Você está em deletar usuários, tenha certeza, pois é irreversível!n\n\n\n\n");
	
	char cpf[40];
	
	printf("Digite o CPF/ID a ser deletado!");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE*file;
	file= fopen(cpf, "r");
	
	if(file == NULL)
	
    {
		printf("O usuário não se encontra no sistema!\n\n Por favor confira e tente novamente!");
		system("pause");
	}	



}


int main()
{
	int opcao=0;
	int laco=1;
	
	char senhadigitada[]="a";
	int comparacao;
	
	for(laco=1;laco=1;)
	{
		system("cls");	
		setlocale(LC_ALL, "Portuguese"); //Seleção de linguagem Português-BR.
	
	
			printf("\t\t\t\t\t\t###Cartório da EBAC###\n\n\n"); //Inicio do menu!
			printf("Login de administrador!\n\n Digite a sua senha:");
			scanf("%s", senhadigitada);
			
			comparacao = strcmp(senhadigitada, "adimin1234");
			
			if(comparacao == 0);
			
			
			system ("cls");
				
				
			}
			
			
			
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registro de nomes:\n"); //Chama o registro de nomes.
			printf("\t2 - Consultar nomes:\n"); //Chama a consulta de nomes.
			printf("\t3 - Apagar nomes:\n"); //Deleta nomes dos registros de nome.//Final do menu!
			printf("Opção:");//Lacuna para digitação!
	
				scanf("%d",&opcao);//Definindo as variaveis!

			system("cls");//Limpar a tela após a seleção de menu.
	
	
		switch(opcao)//Conjunto de opções.
		{
			case 1: //Opção registro!
			registro();
	 		break;
		
			case 2: //Opção consultar!
			consulta();
			break;
			
			case 3: //Opção deletar!
			deletar();
			break;
			
			default: //Avisa que a opção não existe!
				printf("Essa opção não está disponível\n\n\n\n\n!!!");
			break;
		}//Fim switch.
	}
}
