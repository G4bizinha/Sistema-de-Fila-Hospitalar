#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>
#include <unistd.h>

  // sistema de cores
  #define VERDE "\x1b[32m"
  #define AMARELO "\x1b[93m"
  #define VERMELHO "\x1b[31m"
  #define AZUL "\x1b[34m"
  #define RESET "\x1b[0m"

//variaveis globais
int controleMenu = 1;
int prioridadeAmarela=1, prioridadeVerde=1 , tam;
int ini, fim;

void Error(){
	printf(VERMELHO"---------- Erro ❗ ---------- \n");
  printf("❌ Opção inválida! 😐 \nTente novamente! \n");
	printf("---------------------------- \n" RESET);
}

struct Paciente{
  char nome[50];//salva o nome do paciente na fila
	char sobrenome[50];//salvar o sobrenome 
  char prioridade;//salva a prioridade do paciente   V ou A
  int posicaoGeral;//salva a posição do paciente da fila por ordem de chegada.
	int posicaoPrioridade;//salva a posição do paciente pela prioridade Verde
	struct Paciente *prox; //pegar o proximo paciente
};
typedef struct Paciente Paciente;
 
void Cadastrar(Paciente *p , int tam){
	char nome[40], sobrenome[50];
	char escolha = ' ';
	printf("-----Cadastrar Paciente----- \n");
	printf("Qual o nome do paciente que você deseja cadastrar ? \n");
	printf("Digite o nome do paciente: \n");
	scanf("%s %s" , nome , sobrenome);
	p->posicaoGeral=tam;
	strcpy(p->nome,nome);
	strcpy(p->sobrenome,sobrenome);
	printf("Qual a prioridade do paciente que você deseja cadastrar ? \n");
	printf("Digite a prioridade do paciente: \n");
	printf("A - Amarelo | V - Verde \n");
	scanf(" %c" , &escolha);

  	switch(escolha){
		case 'a':
		case 'A':
  	printf(AMARELO"--------- 🟡Prioridade Amarela🟡 -------- \n" RESET);
		printf(AMARELO"Prioridade definida como Amarela! \n" RESET);
		printf(AMARELO"-------------------------------------- \n " RESET);
		p->posicaoPrioridade=prioridadeAmarela;
		p->prioridade='A';
		break;
			
		case 'v':
		case 'V':
  	printf(VERDE"--------- 🟢Prioridade Verde🟢 -------- \n" RESET);
		printf(VERDE"Prioridade definida como Verde! \n" RESET);
		printf(VERDE"-------------------------------------- \n " RESET);
		p->posicaoPrioridade=prioridadeVerde;
		p->prioridade='V';
		break;	

		}
		controleMenu=1;
	}

Paciente *aloca(){
 Paciente *p = (Paciente *) malloc(sizeof(Paciente));
 if(!p){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  Cadastrar(p, tam);
  return p;
 }
	controleMenu=1;
}
	
//VOID CADASTRAR
int vazia(Paciente *p){
 if(p->prox == NULL){
	 return 1;
 }else{
	 return 0;
 }
} // Verifica se a fila esta vazia

void inserirFim(Paciente **p , int *tam){
	//p = aloca();
	//p->prox = NULL;

	Paciente *aux ,*novo = malloc(sizeof(Paciente));

	if(novo){
  novo = aloca();
		//novo->nome = nome;
	}

	if(vazia(p)){
		p->prox=p;
	}else{
		Paciente *tmp = p->prox;

		while(tmp->prox !=NULL)
			tmp = tmp->prox;
			tmp->prox = p;
      }
    (*tam)++;
}


void Remover(){
  printf("--------- 🚶Remover Paciente da Fila ---------- \n");
	//remover 
  // criar um ponteiro inicio - p
	//p->prox=
}
void Pesquisar(Paciente *p, int tam){
  int num;
  printf(AZUL"<------------ 🔍Pesquisar pacientes -------> \n" RESET);
	printf("qual a posição geral do paciente que você deseja procurar as informações?");
	printf("digite a posição:");
	scanf("%d", &num);
	//vai pesquisar pelo numero geral do paciente , pois é a unica informação que permanece diferente entre todos os paciente e não se repete
	for(int i=0;i<tam;i++){
		if(p->posicaoGeral == num){
			//posicaoGeral->num = p;
      //posicaoGeral->p = num;
			//vetor[50]

			// prinntf(vetor[30]. nome)
			// p -1 ;
			// 30 - nome
		}
		
	}
	//pesquisar
}
void ExibirFilaCompleta(Paciente *p){
  printf(AZUL"--------- 📋Exibir Fila Completa ---------- \n" RESET);
	
if(vazia(p)){
	printf(AZUL"A Fila está vazia! 🥲 \n" RESET);
}else{
	
	while(p != NULL){
		printf("Nome:");
		printf("%s" , p->nome);
    printf("%s" , p->sobrenome);
		printf("%c", p->prioridade);
		printf("proximo da fila");
		printf("%s" , p->prox->nome);
		}
	}
}
void VfilaTipoUrgencia(Paciente *p, int tam){
  	printf(AZUL"--------- 📋Visualizar Tipo de Urgência ---------- \n" RESET);
  //Ver Fila por Tipo de Urgência
}
void ConsultarFila(int tam){
  printf(AZUL"--------- 📋Consultar Fila ---------- \n" RESET);
  //consultar fila
}

void Rota(Paciente *p, int i){
	switch(i){
      case 1:inserirFim(p, &tam);break;
      case 2:Remover(); break;
      case 3:Pesquisar(p,tam);break;
      case 4:ExibirFilaCompleta(p);break;
      case 5:VfilaTipoUrgencia(p, tam);break;
      case 6:ConsultarFila(tam); break;
      default:Error();
		}
}

void Menu(Paciente *p){
	int i;
		printf(AZUL"------------------ Menu ---------------- \n" RESET);
		printf("1 - 📝Cadastrar Paciente \n");
		printf("2 - 🚶Remover Paciente \n");
		printf("3 - 🔍Pesquisar Paciente por nível de urgência \n");
		printf("4 - 📋Visualizar fila completa \n");
 	 	printf("5 - 📋Visualizar fila por tipo de urgência \n");
  	printf("6 - 📋Consultar situação da fila \n");
		printf("Digite uma Opção: ");
		scanf("%d", &i);
		printf(AZUL"---------------------------------------- \n" RESET);
  	Rota(p, i);
	}

int main(){
Paciente *p = (Paciente *) malloc(sizeof(Paciente)); //gerencia o inicio da fila
do{
	Menu(p);
}while(controleMenu==1);
}