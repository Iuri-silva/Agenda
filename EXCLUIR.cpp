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

int comparacao(int x){      									//VERIFICANDO SE H� UM CONTATO NO ESPA�O PARA EXIBIR NA LISTA
		while (1>0){											//------------------------------------------------------------
			if(contatos[x].codigo==0){
				x++;
			}else{
				break;
			}
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
	system("cls");												//---------------------------------------
	int cont;
	cont=0;
	int x;
	x=1;													
	printf(" _____________________________CONTATOS________________________________\n");
	printf("|_____________________________________________________________________|\n");
	for(int x=1;x<11;x++){							
		if(contatos[x].codigo==0){
			cont++;		
		}else{
		printf("|\n");
		printf("|C�DIGO: %d\n",contatos[x].codigo);
		printf("|\n");
		printf("|NOME: %s\n",contatos[x].nome);
		printf("|\n");
		printf("|TELEFONE: %s\n",contatos[x].telefone);					//EXIBINDO
		printf("|\n");													//----------
		printf("|EMAIL: %s\n",contatos[x].email);
		printf("|\n");
		printf("|DATA DE NASCIMENTO: %s\n",contatos[x].data);
		printf("|\n");
		printf("|OBSERVA��ES: %s\n",contatos[x].obs);
		printf("|_____________________________________________________________________|\n");
		printf("|_____________________________________________________________________|\n");
		}
		}
		if(cont==10){
			printf("|\n");
			printf("|\n");										//CASO N�O HAJA CONTATOS
			printf("|SUA AGENDA EST� VAZIA");					//------------------------
			printf("\n|\n");									
			printf("|_____________________________________________________________________\n");
			printf("|_____________________________________________________________________|\n");
	}
		system("pause");
	}
	

int buscar(){													//FUN��O PARA BUSCAR UM CONTATO NA LISTA
	system("cls");												//----------------------------------------
	int cont=0;
	int x;
	int busca;
	fflush(stdin);
	printf(" _____________________________PESQUISAR_____________________________\n");
	printf("|___________________________________________________________________|\n");
	printf("|\n");
	printf("|C�DIGO DO CONTATO DESEJADO: ");
	scanf("%d",&busca);
	if(busca<=0){
		printf("|");
		printf("\n|O C�DIGO DEVE SER MAIOR QUE 0!\n");
		printf("|\n");
		printf("|___________________________________________________________________\n");
		printf("|___________________________________________________________________|\n");
		system("pause");
		return(3);
	}
	
	
	for(int x=1;x<11;x++){
		if(busca==contatos[x].codigo){
			system("cls");
			printf(" ______________________________CONTATO______________________________\n");
			printf("|___________________________________________________________________|\n");
			printf("|\n");
			printf("|C�DIGO: %d\n",contatos[x].codigo);
			printf("|\n");
			printf("|NOME: %s\n",contatos[x].nome);
			printf("|\n");
			printf("|TELEFONE: %s\n",contatos[x].telefone);						//EXIBINDO O CONTATO DESEJADO
			printf("|\n");														//----------------------------
			printf("|EMAIL: %s\n",contatos[x].email);
			printf("|\n");
			printf("|DATA DE NASCIMENTO: %s\n",contatos[x].data);
			printf("|\n");
			printf("|OBSERVA��ES: %s\n",contatos[x].obs);
			printf("|_____________________________________________________________________\n");
			printf("|_____________________________________________________________________|\n");
			system("pause");
		}else{
			cont++;
		}
	}
	if(cont==10){
		system("cls");
		printf(" _____________________________PESQUISAR_____________________________\n");
		printf("|___________________________________________________________________|\n");
		printf("|\n");
		printf("|\n");
		printf("|CONTATO N�O ENCONTRADO!");							//CASO CONTATO N�O EXISTA
		printf("\n|\n");											//------------------------
		printf("|___________________________________________________________________\n");
		printf("|___________________________________________________________________|\n");
		system("pause");
	}
}

int alterar(){													//FUN��O PARA ALTERAR UM CONTATO NA LISTA
	system("cls");												//-----------------------------------------
	int cont=0;
	int busca;
	int escolha;
	fflush(stdin);
	printf(" ______________________________ALTERAR______________________________\n");
	printf("|___________________________________________________________________|\n");
	printf("|\n");
	printf("|C�DIGO DO CONTATO QUE DESEJA ALTERAR: ");
	scanf("%d",&busca);
	if(busca<=0){
		printf("|");
		printf("\n|O C�DIGO DEVE SER MAIOR QUE 0!\n");
		printf("|\n");
		printf("|___________________________________________________________________\n");
		printf("|___________________________________________________________________|\n");
		system("pause");
		return(3);
	}
	
	for(int x=1;x<11;x++){
		if(busca==contatos[x].codigo){
			system("cls");
			printf(" ______________________________CONTATO______________________________\n");
			printf("|___________________________________________________________________|\n");
			printf("|\n");
			printf("|1 --- C�DIGO: %d\n",contatos[x].codigo);
			printf("|\n");
			printf("|2 --- NOME: %s\n",contatos[x].nome);
			printf("|\n");
			printf("|3 --- TELEFONE: %s\n",contatos[x].telefone);				//EXIBINDO O CONTATO DESEJADO
			printf("|\n");														//-----------------------------
			printf("|4 --- EMAIL: %s\n",contatos[x].email);
			printf("|\n");
			printf("|5 --- DATA DE NASCIMENTO: %s\n",contatos[x].data);
			printf("|\n");
			printf("|6 --- OBSERVA��ES: %s\n",contatos[x].obs);
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|\n");
			printf("|0 --- CANCELAR\n");
			printf("|_____________________________________________________________________");
			printf("\n|_____________________________________________________________________|\n");
			printf("|\n");
			printf("|DADO QUE DESEJA ALTERAR: ");
			
			scanf("%d",&escolha);
			system("cls");
			printf(" ______________________________ALTERAR______________________________\n");
			printf("|___________________________________________________________________|\n");
			printf("|\n");
			switch(escolha){								
				case 1:
					fflush(stdin);
					printf("|C�DIGO: %d\n",contatos[x].codigo);			//SWITCH CASE PARA ESCOLHER O DADO QUE DESEJA ALTERAR ALTERAR
					printf("|NOVO: ");									//------------------------------------------------------------
					scanf("%d",&contatos[x].codigo);
					valida(x);
					printf("|\n");
					printf("|DADOS ALTERADOS COM SUCESSO!\n");			//CODIGO
					printf("|---------------------------");				//-------
					printf("\n|\n");
					printf("|___________________________________________________________________|\n");
					printf("|___________________________________________________________________|\n");
					system("pause");
					break;
				case 2:
					fflush(stdin);
					printf("|NOME: %s\n",contatos[x].nome);
					printf("|NOVO: ");		
					gets(contatos[x].nome);								//NOME	
					printf("|\n");										//-----
					printf("|DADOS ALTERADOS COM SUCESSO!\n");				
					printf("|---------------------------");
					printf("\n|\n");
					printf("|___________________________________________________________________|\n");
					printf("|___________________________________________________________________|\n");
					system("pause");
					break;
				case 3:
					fflush(stdin);
					printf("|TELEFONE: %s\n",contatos[x].telefone);
					printf("|NOVO: ");
					gets(contatos[x].telefone);							//TELEFONE
					printf("|\n");										//---------
					printf("|DADOS ALTERADOS COM SUCESSO!\n");
					printf("|---------------------------");
					printf("\n|\n");
					printf("|___________________________________________________________________|\n");
					printf("|___________________________________________________________________|\n");
					system("pause");
					break;
				case 4:
					fflush(stdin);
					printf("|EMAIL: %s\n",contatos[x].email);
					printf("|NOVO: ");
					gets(contatos[x].email);							//EMAIL
					printf("|\n");										//------
					printf("|DADOS ALTERADOS COM SUCESSO!\n");
					printf("|---------------------------");
					printf("\n|\n");
					printf("|___________________________________________________________________|\n");
					printf("|___________________________________________________________________|\n");
					system("pause");
					break;
				case 5:
					fflush(stdin);
					printf("|DATA DE NASCIMENTO: %s\n",contatos[x].data);
					printf("|NOVO: ");
					gets(contatos[x].data);									//DATA
					printf("|\n");											//-----
					printf("|DADOS ALTERADOS COM SUCESSO!\n");
					printf("|---------------------------");
					printf("\n|\n");
					printf("|___________________________________________________________________|\n");
					printf("|___________________________________________________________________|\n");
					system("pause");
					break;
				case 6:
					fflush(stdin);
					printf("|OBSERVA��O: %s\n",contatos[x].obs);
					printf("|NOVO: ");
					gets(contatos[x].obs);									//OBSERVA��O
					printf("|\n");											//------------
					printf("|DADOS ALTERADOS COM SUCESSO!\n");
					printf("|---------------------------");
					printf("\n|\n");
					printf("|___________________________________________________________________|\n");
					printf("|___________________________________________________________________|\n");
					system("pause");
					break;
				case 0:
					return(3);
			}
			
		}else{
			cont++;
		}
	}
	if(cont==10){
		system("cls");
		printf(" _____________________________PESQUISAR_____________________________\n");
		printf("|___________________________________________________________________|\n");
		printf("|\n");
		printf("|\n");
		printf("|CONTATO N�O ENCONTRADO!");								//CASO O CONTATO N�O EXISTA
		printf("\n|\n");												//--------------------------
		printf("|___________________________________________________________________\n");
		printf("|___________________________________________________________________|\n");
		system("pause");
	}
}

int excluir(){													//FUN��O PARA EXCLUIR UM CONTATO DA LISTA
	system("cls");												//-----------------------------------------
	
	int cont=0;	
	int busca;
	int confirma;
	
	fflush(stdin);
	printf(" ___________________________APAGAR CONTATO___________________________\n");
	printf("|____________________________________________________________________|\n");
	printf("|\n");
	printf("|C�DIGO DO CONTATO DESEJADO: ");
	scanf("%d",&busca);
	if(busca<=0){
		printf("|");
		printf("\n|O C�DIGO DEVE SER MAIOR QUE 0!\n");
		printf("|\n");
		printf("|____________________________________________________________________\n");
		printf("|____________________________________________________________________|\n");
		system("pause");
		return(3);
	}
	
	for(int x=1;x<11;x++){
		if(busca==contatos[x].codigo){
			system("cls");
			printf(" ___________________________APAGAR CONTATO___________________________\n");
			printf("|____________________________________________________________________|\n");
			printf("|\n");
			printf("|C�DIGO: %d\n",contatos[x].codigo);
			printf("|\n");
			printf("|NOME: %s\n",contatos[x].nome);
			printf("|\n");
			printf("|TELEFONE: %s\n",contatos[x].telefone);						//EXIBINDO O CONTATO DESEJADO
			printf("|\n");														//----------------------------
			printf("|EMAIL: %s\n",contatos[x].email);
			printf("|\n");
			printf("|DATA DE NASCIMENTO: %s\n",contatos[x].data);
			printf("|\n");
			printf("|OBSERVA��ES: %s\n",contatos[x].obs);
			printf("|_____________________________________________________________________\n");
			printf("|_____________________________________________________________________|\n");
			printf("|\n");
			printf("|DESEJA APAGAR ESSE CONTATO?");
			printf("\n|---------------------------\n");
			printf("|\n");
			printf("|1 - SIM\n");
			printf("|2 - N�O\n");
			
			scanf("%d",&confirma);
			
			switch(confirma){
				case 1:
					contatos[x].codigo=0;
					contatos[x].nome[0]= '\0' ;
					contatos[x].telefone[0]= '\0';					//APAGANDO TODOS OS DADOS DO CONTATO
					contatos[x].email[0]= '\0';						//-----------------------------------
					contatos[x].data[0]= '\0';		
					contatos[x].obs[0]= '\0';
					system("cls");
					printf(" ___________________________APAGAR CONTATO___________________________\n");
					printf("|____________________________________________________________________|\n");
					printf("|\n");
					printf("|CONTATO APAGADO COM SUCESSO!");			
					printf("\n|\n");
					printf("|____________________________________________________________________\n");
					printf("|____________________________________________________________________|\n");
					system("pause");
					break;
				case 2:
					break;
			}
			
		}else{
			cont++;
		}
	}
	if(cont==10){
		system("cls");
		printf(" ___________________________APAGAR CONTATO___________________________\n");
		printf("|____________________________________________________________________|\n");
		printf("|\n");
		printf("|\n");											//CASO O CONTATO N�O EXISTA
		printf("|CONTATO N�O ENCONTRADO!");						//---------------------------
		printf("\n|\n");
		printf("|____________________________________________________________________|\n");
		printf("|____________________________________________________________________|\n");
		system("pause");
	}
	
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
