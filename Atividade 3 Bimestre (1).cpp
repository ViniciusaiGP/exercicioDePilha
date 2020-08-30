#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Node{
 int num;
 struct Node *prox;
};
typedef struct Node node;

int tam;

int menu(void);
void inicia(node *PILHA);
void opcao(node *PILHA, int op);
void exibe(node *PILHA);
void libera(node *PILHA);
void push(node *PILHA);
void localizar(node *PILHA);
void exibirTopo(node *PILHA);
node *pop(node *PILHA);



int main(void)
{
	setlocale(LC_ALL, "Portuguese");			
 	node *PILHA = (node *) malloc(sizeof(node));
 	if(!PILHA){
  		printf("Sem memoria disponivel!\n");
  		exit(1);
 	}else{
 		inicia(PILHA);
 		int opt;
 		do{
  			opt=menu();
  			opcao(PILHA,opt);
 		}while(opt);
 		
 		free(PILHA);
 		return 0;
 	}
}	

void inicia(node *PILHA)
{
	PILHA->prox = NULL;
	tam=0;
}

int menu(void)
{
	int opt;
	
	printf("Escolha a opcao\n");
	printf("0. Sair\n");
	printf("1. Zerar PILHA\n");
	printf("2. Exibir PILHA\n");
	printf("3. Empilhar\n");
	printf("4. Desempilhar\n");
	printf("5. Localizar Elemento\n");
	printf("6. Exibir primeiro elemento\n");
	printf("Opcao: "); scanf("%d", &opt);
	
	return opt;
}

void opcao(node *PILHA, int op)
{
	node *tmp;
	switch(op){
	case 0:
		libera(PILHA);
   		break;

	case 1:
		libera(PILHA);
		inicia(PILHA);
   		break;

	case 2:
		exibe(PILHA);
		break;

	case 3:
		push(PILHA);
   		break;

	case 4:
		tmp= pop(PILHA);
		if(tmp != NULL){			
   			printf("Retirado: %3d\n\n", tmp->num);
		}
   		break;
   
	case 5:
  		localizar(PILHA);  	
  		break;

  	case 6:
  		exibirTopo(PILHA);
  		break;
  	
  	default:
   		printf("Comando invalido\n\n");
 }
}

int vazia(node *PILHA)
{
	if(PILHA->prox == NULL){		
  		return 1;
	}
 	else{
 		return 0;
	}
  		
}

node *aloca()
{
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
  		printf("Sem memoria disponivel!\n");
  		exit(1);
 	}else{
  		printf("Novo elemento: "); scanf("%d", &novo->num);
  		return novo;
 	}
}


void exibe(node *PILHA)
{
	if(vazia(PILHA)){
  		printf("PILHA vazia!\n\n");
  		return ;
 	}

	node *tmp;
 	tmp = PILHA->prox;
 	printf("PILHA:");
 	while( tmp != NULL){
  		printf("%5d", tmp->num);
  		tmp = tmp->prox;
 	}
 	printf("\n        ");
 	int count;
 	
	for(count=0 ; count < tam ; count++){ 		
  		printf("  ^  ");
 		printf("\nOrdem:");
	}
 	for(count=0 ; count < tam ; count++){
 		printf("%5d", count+1);
	}
 		 
 printf("\n\n");
}

void libera(node *PILHA)
{
	if(!vazia(PILHA)){
  		node *proxNode,
     	*atual;
  		atual = PILHA->prox;
  		while(atual != NULL){
   			proxNode = atual->prox;
   			free(atual);
   			atual = proxNode;
  		}
 	}
}

void push(node *PILHA)
{
	node *novo=aloca();
 	novo->prox = NULL;

 	if(vazia(PILHA)){
 		PILHA->prox=novo;
	}else{
  		node *tmp = PILHA->prox;
  		
  		while(tmp->prox != NULL){
  			tmp = tmp->prox;	
  		}
  		tmp->prox = novo;
 	}
 	tam++;
}


node *pop(node *PILHA)
{
 if(PILHA->prox == NULL){
  printf("PILHA ja vazia\n\n");
  return NULL;
 }else{
  node *ultimo = PILHA->prox,
              *penultimo = PILHA;

  while(ultimo->prox != NULL){
   penultimo = ultimo;
   ultimo = ultimo->prox;
  }

  penultimo->prox = NULL;
  tam--;
  return ultimo;
 }
}

void localizar(node *PILHA)
{
	int localizarItem, ordemCache = 0;	
	bool itemExiste = false, valorItem = false;
	if(vazia(PILHA)){
	printf("Pilha está vazia!\n\n");
	return ;
	}

	printf("Qual elemento da Pilha para localizar: ");
	scanf("%i", &localizarItem);	
	
	node *tmp;
	tmp = PILHA->prox;
	while( tmp != NULL){
		if(valorItem == false){
			ordemCache++;
		}
		
		if(tmp->num == localizarItem){
			printf("O item (%d).", tmp->num);
			itemExiste = true;
			valorItem = true;
		}				
	  	tmp = tmp->prox;		
	}
	if(itemExiste == true){
		int count, valorAtual;
				
		for(count=0 ; count < tam ; count++){			
			valorAtual = (count + 1);				
			if(valorAtual == ordemCache){	
				printf("Está localizado no elemento (%d) da pilha. \n", count+1);
			}
			valorAtual = 0;
		}
	}else{
		printf("\nItem não localizado na pilha.\n");
	}

}

void exibirTopo(node *PILHA)
{
	int localizarItem, ordemCache = 0;	
	bool itemExiste = false;
	if(vazia(PILHA)){
	printf("Pilha está vazia!\n\n");
	return ;
	}
	node *tmp;
	tmp = PILHA->prox;
	printf("O item (%d).\n", tmp->num);

}
