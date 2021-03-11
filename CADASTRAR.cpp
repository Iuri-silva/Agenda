#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <unistd.h>
#include <cstdlib>

typedef struct {
	int codigo;
	char nome[50],telefone[20],email[30],data[15],obs[40];		//ESTRUTURA AGENDA
}agenda;														//------------------

agenda contatos[10];

int valida(int x){												//VALIDANDO O C�DIGO COMO MAIOR DE 0
	if(contatos[x].codigo<=0){									//------------------------------------
		fflush(stdin);											
		printf("\n|O C�DIGO DEVE SER MAIOR QUE 0!!\n");
		printf("|C�DIGO: ");
		scanf("%d",&contatos[x].codigo);
		valida(x);
	}
}

int novoContato(int x){											//VERIFICANDO ESPA�O VAZIO PARA NOVO CONTATO
	while (1>0){												//--------------------------------------------
		if(contatos[x].codigo!=0){
			x++;
		}else{
			return x;
			break;
		}
}
}

int cadastrar(){												//FUN��O PARA CADASTRAR NOVO CONTATO
	system("cls");												//------------------------------------
	int x;
	x=1;
	x=novoContato(x);
	if(x==11){
		system("cls");
		printf(" ___________________________AGENDA CHEIA!____________________________\n");
		printf("|____________________________________________________________________|\n");  //CASO J� TENHA 10 CONTATOS
		printf("|");																		 //---------------------------
		printf("\n|LIMITE DE 10 CONTATOS.");													 
		printf("\n|APAGUE ALGUM CONTATO PARA LIBERAR ESPA�O.\n");
		printf("|\n");
		printf("|____________________________________________________________________\n");
		printf("|____________________________________________________________________|\n");
		system("pause");
		return(3);
	}
	printf(" ____________________________NOVO CONTATO____________________________\n");      
	printf("|____________________________________________________________________|\n");
	printf("|\n");
	printf("|C�DIGO: ");
	scanf("%d",&contatos[x].codigo);
	valida(x);
	fflush(stdin);
	printf("|\n");
	printf("|NOME: ");
	gets(contatos[x].nome);
	printf("|\n");											//PREENCHENDO DADOS DE NOVO CONTATO
	printf("|TELEFONE: ");									//----------------------------------
	gets(contatos[x].telefone);
	printf("|\n");
	printf("|EMAIL: ");
	gets(contatos[x].email);
	printf("|\n");
	printf("|DATA DE NASCIMENTO: ");
	gets(contatos[x].data);
	printf("|\n");
	printf("|OBSERVA��ES: ");
	gets(contatos[x].obs);
	printf(" ____________________________________________________________________");
	printf("\n|____________________________________________________________________|\n");
	printf("                       |CONTATO CADASTRADO!|\n");
	printf("                        -------------------\n\n\n");
	system("pause");
	system("cls");
	
	
}

int exibir(){													//FUN��O PARA EXIBIR A LISTA DE CONTATOS
}
	

int buscar(){													//FUN��O PARA BUSCAR UM CONTATO NA LISTA
}

int alterar(){													//FUN��O PARA ALTERAR UM CONTATO NA LISTA
}

int excluir(){													//FUN��O PARA EXCLUIR UM CONTATO DA LISTA
}
 	
int opcoes(){													//MENU DE OP��ES DA AGENDA	
	int x;														//--------------------------
	system("cls");
	printf(" _____________________A G E N D A_____________________\n");
	printf("|_____________________________________________________|\n");
	printf("|                                                     |\n");
	printf("|OP��ES:                                              |\n");
	printf("|                                                     |\n");
	printf("|1-CADASTRAR UM NOVO CONTATO                          |\n");
	printf("|                                                     |\n");
	printf("|2-EXIBIR A LISTA DE CONTATOS                         |\n");
	printf("|                                                     |\n");
	printf("|3-BUSCAR CONTATO                                     |\n");
	printf("|                                                     |\n");
	printf("|4-ALTERAR CONTATO                                    |\n");
	printf("|                                                     |\n");
	printf("|5-APAGAR CONTATO                                     |\n");
	printf("|                                                     |\n");
	printf("|0-SAIR DA AGENDA                                     |\n");
	printf("|_____________________________________________________|\n");
	
	scanf("%d",&x);	
	switch(x){
		case 1:
			cadastrar();
			break;
		case 2:
			exibir();
			break;
		case 3:
			buscar();								//CADA CASE REDIRECIONA A UMA FUN��O
			break;									//------------------------------------
		case 4:
			alterar();
			break;
		case 5:
			excluir();
			break;
		case 0:
			system("cls");
			printf("\n _____________________FECHANDO AGENDA_____________________\n");
			printf("|_________________________________________________________|");
			sleep(2);					
			system("cls");								//FECHANDO O PROGRAMA (AGENDA)
			exit(0);									//------------------------------
	}
} 	
 	
int main(){
	setlocale(LC_ALL, "Portuguese");
	
	while(1>0){
		opcoes();
	}
	
}
