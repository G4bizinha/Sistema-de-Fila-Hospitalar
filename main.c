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

struct Paciente{
  char nome[50];//salva o nome do paciente na fila
	char sobrenome[50];//salvar o sobrenome 
  char prioridade;//salva a prioridade do paciente   V ou A
  int posicaoGeral;//salva a posição do paciente da fila por ordem de chegada.
	int posicaoPrioridade;//salva a posição do paciente pela prioridade Verde
	struct Paciente *prox; //pegar o proximo paciente
};
typedef struct Paciente Paciente;

Paciente *aloca(){
 Paciente *p = (Paciente *) malloc(sizeof(Paciente));
 if(!p){
  printf("Sem memoria disponivel!\n");
  exit(1);
 }else{
  printf("Novo elemento: ");
	
  scanf("%s", p->nome);//salvando só o nome
  return p;
 }
}

int vazia(Paciente *p){
 if(p->prox == NULL){
	 return 1;
 }else{
	 return 0;
 }
} // Verifica se a fila esta vazia

void inserirFim(Paciente *p , int *tam){
	//chama o aloca e passa ele como um novo nó
	//Paciente *p = 
	aloca();
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
      case 4:VfilaCompleta(p);break;
      case 5:VfilaTipoUrgencia(p, tam);break;
      case 6:ConsultarFila(tam); break;
      default:Error();
				}
		}while(controleMenu ==1); 
	}

int main(){
Paciente *p = (Paciente *) malloc(sizeof(Paciente)); //gerencia o inicio da fila
int tam;
inserirFim(p,&tam);
Menu(p);
}