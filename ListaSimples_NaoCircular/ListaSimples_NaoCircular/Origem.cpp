#include <stdio.h>
#include <stdlib.h>

// prot�tipos das fun��es
int menu();
void inserirInicio(int num);
void inserirFim(int num);
void inserirMeio(int num, int meio);
int remover(int num);
void mostrar();

// estrutura homog�nea de dados
struct Lista {
	
	int dado;
	struct Lista* prox;
} *Head;

int main() {

	int op, num, c, pos, res; // vari�veis

	while (1) { // la�o infinito que se encerrar� somente se o usu�rio optar por isso.
		
		op = menu();

		switch (op) {

		case 1: // inserir no in�cio da lista
			printf("Digite o numero a ser inserido: ");
			scanf_s("%d", &num);
			while((c= getchar()) != '\n' && c != EOF) {} // limpa o buffer do teclado

			inserirInicio(num);
			break;

		case 2: // inserir no fim da lista
			printf("Digite o numero a ser inserido: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpa o buffer do teclado

			inserirFim(num);
			break;

		case 3: // inserir no meio da lista
			printf("Digite o numero a ser inserido: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpa o buffer do teclado
			printf("Digite a posicao onde sera inserido o valor: ");
			scanf_s("%d", &pos);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpa o buffer do teclado

			inserirMeio(num, pos);
			break;

		case 4: // remover da lista
			printf("Digite o numero a ser removido: ");
			scanf_s("%d", &num);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpa o buffer do teclado

			res = remover(num);

			if (res == 1) { // se o n�mero escolhido existir na lista
				printf("Numero removido!\n");
				system("pause");
			}
			else { // se o n�mero escolhido n�o existir na lista
				printf("Numero nao encontrado!\n");
				system("pause");
			}

			break;

		case 5: // exibir a lista 
			mostrar();
			break;

		case 6: // sair
			exit(0);
			break;

		default: // N�o permite o usu�rio escolher uma op��o inv�lida
			printf("Opcao invalida!");
			system("pause");
			break;
		}
	}

	return 0;
}

int menu() {

	int op;

	system("cls");

	printf("1.Inserir no inicio da lista.\n");
	printf("2.Inserir no fim da lista.\n");
	printf("3.Inserir no meio da lista.\n");
	printf("4.Remover da lista.\n");
	printf("5.Mostrar lista\n");
	printf("6.Sair.\n");

	printf("Escolha uma opcao: ");
	scanf_s("%d", &op);

	system("cls");

	return op;
}

void inserirInicio(int num) {

	struct Lista* NovoElemento;
	NovoElemento = (struct Lista*)malloc(sizeof(struct Lista));
	
	NovoElemento->dado = num;

	if (Head == NULL) { // caso a primeira posi��o estiver vazia...
		Head = NovoElemento; // ...a primeira posi��o receber� o numero digitado pelo usu�rio
		Head->prox = NULL; // o �ltimo elemento sempre apontar� pra nulo
	}
	else { // se a primeira posi��o estiver ocupada...
		NovoElemento->prox = Head; // ... a pr�xima posi��o receber� o valor de head
		Head = NovoElemento; // e o head vai guardar o novo elemento
	}

}

void inserirFim(int num) {

	struct Lista* NovoElemento;
	NovoElemento = (struct Lista*)malloc(sizeof(struct Lista));
	struct Lista* ElementoVarredura;
	ElementoVarredura = (struct Lista*)malloc(sizeof(struct Lista));

	NovoElemento->dado = num; // a vari�vel dado da estrutura recebe o valor passado por par�metro

	if (Head == NULL) { // se a lista estiver a vazia insere na primeira posi��o
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else { // se a lista n�o estiver vazia...

		ElementoVarredura = Head;

		while (ElementoVarredura->prox != NULL) { // varre todas as posi��es at� achar o elemetno que aponta pra nulo
			ElementoVarredura = ElementoVarredura->prox;
		}

		ElementoVarredura->prox = NovoElemento; // atribui o elemento digitado na �ltima posi��o
		NovoElemento->prox = NULL; // e o novo elemento aponta para nulo

	}

}

void inserirMeio(int num, int pos) {

	struct Lista* NovoElemento;
	NovoElemento = (struct Lista*)malloc(sizeof(struct Lista));
	struct Lista* ElementoVarredura;
	ElementoVarredura = (struct Lista*)malloc(sizeof(struct Lista));
	struct Lista* ElementoAuxiliar;
	ElementoAuxiliar = (struct Lista*)malloc(sizeof(struct Lista));

	NovoElemento->dado = num;

	if (pos == 0) { // caso a posi��o escolhida for 0, o elemetno ser� atribuido a primeira posi��o

		Head = NovoElemento;
		Head->prox = NULL;

	}
	else {

		ElementoVarredura = Head;
		for (int i = 0; i < pos - 1; i++) { // procura a posi��o escolhida e atribui um valor a ela 
			ElementoVarredura = ElementoVarredura->prox;
		}

		ElementoAuxiliar = ElementoVarredura->prox;
		ElementoVarredura->prox = NovoElemento;
		NovoElemento->prox = ElementoAuxiliar;

	}

}

int remover(int num) {

	struct Lista* ElementoVarredura;
	ElementoVarredura = (struct Lista*)malloc(sizeof(struct Lista));
	struct Lista* Anterior;
	Anterior = (struct Lista*)malloc(sizeof(struct Lista));

	ElementoVarredura = Head;

	while (ElementoVarredura != NULL) {

		if (ElementoVarredura->dado == num) { // se achar o elemento passado por par�metro

			if (ElementoVarredura == Head) { // se o elemento estiver na primeira posi��o
				
				Head = ElementoVarredura->prox;
				free(ElementoVarredura); // remove o elemento da lista
				return 1; // encerra a fun��o
			}

			else {

				Anterior->prox = ElementoVarredura->prox;
				free(ElementoVarredura); // remove o elemento da lista
				return 1; // encerra a fun��o

			}

		}
		else { // caso o elemento n�o exista na lista
			Anterior = ElementoVarredura;
			ElementoVarredura = ElementoVarredura->prox;
		}
	}

	return 0;
}

void mostrar() {

	struct Lista* ElementoVarredura;
	ElementoVarredura = (struct Lista*)malloc(sizeof(struct Lista));

	ElementoVarredura = Head;
	
	if (ElementoVarredura == NULL) { // se a lista estiver vazia

		printf("Lista Vazia!\n");
		system("pause");
		return;

	}
	while(ElementoVarredura != NULL) { 

		printf("%d -> ", ElementoVarredura->dado); // imprime todos os dados armazenados
		ElementoVarredura = ElementoVarredura->prox;

	}

	printf("\n");
	system("pause");
}