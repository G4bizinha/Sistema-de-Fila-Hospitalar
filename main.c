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
int controleMenu = 1;

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

void Cadastrar(Paciente *p){
	char nome[40], prioridade;
	printf("Cadastrar Paciente");
	printf("Qual o nome do paciente que você deseja cadastrar ?");
	printf("Digite o nome do paciente:");
	scanf("%s" , nome);
	printf("Qual a prioridade do paciente que você deseja cadastrar ?");
	printf("Digite a prioridade do paciente:");
	printf("A - Amarelo | V - Verde");
	scanf("%c" , &prioridade);

	switch(prioridade){
		case 'A':
		case 'a':
  	printf(AMARELO"--------- Prioridade Amarela -------- \n"     RESET);
		printf(AMARELO"Prioridade definida como Amarela! \n" RESET);
		printf(AMARELO"-------------------------------------- \n \n \n" RESET);
		break;;
		case 'V':
		case 'v':
  	printf(VERDE"--------- Prioridade Verde -------- \n"     RESET);
		printf(VERDE"Prioridade definida como Verde! \n" RESET);
		printf(VERDE"-------------------------------------- \n \n \n" RESET);
		break;	}//SWITCH	
	}

Paciente *aloca(){
 Paciente *p = (Paciente *) malloc(sizeof(Paciente));
 if(!p){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  Cadastrar(p);
	
  scanf("%s", p->nome);//salvando só o nome
  return p;
 }
}
	
//VOID CADASTRAR
int vazia(Paciente *p){
 if(p->prox == NULL){
	 return 1;
 }else{
	 return 0;
 }
} // Verifica se a fila esta vazia

void inserirFim(Paciente *p , int *tam){
	p = aloca();
	p->prox = NULL;

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
  printf(AZUL"<------------ 🔍Pesquisar pacientes -------> \n" RESET);
	//pesquisar
}
void ExibirFilaCompleta(Paciente *p){
  printf(AZUL"--------- 📋Exibir Fila Completa ---------- \n" RESET);
	// exibir fila completa
}
void VfilaTipoUrgencia(Paciente *p, int tam){
  	printf(AZUL"--------- 📋Visualizar Tipo de Urgência ---------- \n" RESET);
  //Ver Fila por Tipo de Urgência
}
void ConsultarFila(int tam){
  printf(AZUL"--------- 📋Consultar Fila ---------- \n" RESET);
  //consultar fila
}

void Menu(Paciente *p){
	int i , tam;
	//Paciente *p = (Paciente *) malloc(sizeof(Paciente)); 
	do{
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
			switch(i){
      case 1:inserirFim(p, &tam);break;
      case 2:Remover(); break;
      case 3:Pesquisar(p,tam);break;
      case 4:ExibirFilaCompleta(p);break;
      case 5:VfilaTipoUrgencia(p, tam);break;
      case 6:ConsultarFila(tam); break;
      default:Error();
				}
		}while(controleMenu ==1); 
	}

int main(){
Paciente *p = (Paciente *) malloc(sizeof(Paciente)); //gerencia o inicio da fila
int tam;
Menu(p);
}