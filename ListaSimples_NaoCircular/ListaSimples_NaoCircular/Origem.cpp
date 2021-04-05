#include <stdio.h>
#include <stdlib.h>

// protótipos das funções
int menu();
void inserirInicio(int num);
void inserirFim(int num);
void inserirMeio(int num, int meio);
int remover(int num);
void mostrar();

// estrutura homogênea de dados
struct Lista {
	
	int dado;
	struct Lista* prox;
} *Head;

int main() {

	int op, num, c, pos, res; // variáveis

	while (1) { // laço infinito que se encerrará somente se o usuário optar por isso.
		
		op = menu();

		switch (op) {

		case 1: // inserir no início da lista
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

			if (res == 1) { // se o número escolhido existir na lista
				printf("Numero removido!\n");
				system("pause");
			}
			else { // se o número escolhido não existir na lista
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

		default: // Não permite o usuário escolher uma opção inválida
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

	if (Head == NULL) { // caso a primeira posição estiver vazia...
		Head = NovoElemento; // ...a primeira posição receberá o numero digitado pelo usuário
		Head->prox = NULL; // o último elemento sempre apontará pra nulo
	}
	else { // se a primeira posição estiver ocupada...
		NovoElemento->prox = Head; // ... a próxima posição receberá o valor de head
		Head = NovoElemento; // e o head vai guardar o novo elemento
	}

}

void inserirFim(int num) {

	struct Lista* NovoElemento;
	NovoElemento = (struct Lista*)malloc(sizeof(struct Lista));
	struct Lista* ElementoVarredura;
	ElementoVarredura = (struct Lista*)malloc(sizeof(struct Lista));

	NovoElemento->dado = num; // a variável dado da estrutura recebe o valor passado por parâmetro

	if (Head == NULL) { // se a lista estiver a vazia insere na primeira posição
		Head = NovoElemento;
		Head->prox = NULL;
	}
	else { // se a lista não estiver vazia...

		ElementoVarredura = Head;

		while (ElementoVarredura->prox != NULL) { // varre todas as posições até achar o elemetno que aponta pra nulo
			ElementoVarredura = ElementoVarredura->prox;
		}

		ElementoVarredura->prox = NovoElemento; // atribui o elemento digitado na última posição
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

	if (pos == 0) { // caso a posição escolhida for 0, o elemetno será atribuido a primeira posição

		Head = NovoElemento;
		Head->prox = NULL;

	}
	else {

		ElementoVarredura = Head;
		for (int i = 0; i < pos - 1; i++) { // procura a posição escolhida e atribui um valor a ela 
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

		if (ElementoVarredura->dado == num) { // se achar o elemento passado por parâmetro

			if (ElementoVarredura == Head) { // se o elemento estiver na primeira posição
				
				Head = ElementoVarredura->prox;
				free(ElementoVarredura); // remove o elemento da lista
				return 1; // encerra a função
			}

			else {

				Anterior->prox = ElementoVarredura->prox;
				free(ElementoVarredura); // remove o elemento da lista
				return 1; // encerra a função

			}

		}
		else { // caso o elemento não exista na lista
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