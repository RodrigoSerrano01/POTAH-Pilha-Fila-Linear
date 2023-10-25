
/***************************************************************************
Este algoritmo  registra "N" elementos em ordem crescente.

Imprime o registro ordenado e a quantidade de elementos.

****************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 35 // Diminui o valor para evitar o line feed na exi��o da lista cheia

typedef struct
{
	int key;
} REG;

typedef struct
{
	REG LL[MAX];
	int nElem;
	int primeiroElem;
} PILHA;

//		Cabe�alho das fun��es do sistema

void inicia(PILHA *);
void exibe(PILHA *);
int busca(PILHA *, int);
bool insere(PILHA *, int);
void exclui(PILHA *);

int main()
{
	char opcao = '1', val;
	PILHA Pilha;
	Pilha.primeiroElem = 0;
	while (opcao != '0')
	{
		system("cls");
		printf("==========>Menu<==========\n");
		printf("__________________________\n");
		printf("      1-->Inserir\n");
		printf("      2-->Buscar\n");
		printf("      3-->Exibir\n");
		printf("      4-->Excluir\n");
		printf("      5-->Inicializar\n");
		printf("      0-->Sair\n");
		printf("__________________________\n");
		printf("\nOpcao: ");
		opcao = getche();
		system("cls");

		switch (opcao)
		{
		case '1':
		{ // inserir
			printf("\nDigite o valor do elemento: ");
			scanf("%d", &val);

			if (insere(&Pilha, val) == false)
				printf("Elemento nao pode ser inserido na Pilha\n");
			else
				printf("Inserido com sucesso\n");

			printf("\n\n\nAperte qualquer tecla para continuar.\n");
			getch();
			break;
		}

		case '2':
		{ // buscar
			int x;
			printf("\nDigite o valor procurado : ");
			scanf("%d", &val);
			x = busca(&Pilha, val);
			if (x == -1)
				printf("Valor %d nao foi encontrado na Pilha\n", val);
			else
				printf("O valor encontra-se na posicao %d\n", x);

			printf("\n\n\nAperte qualquer tecla para continuar.\n");
			getch();
			break;
		}

		case '3':
		{ // exibir
			exibe(&Pilha);

			printf("\n\n\nAperte qualquer tecla para continuar.\n");
			getch();
			break;
		}

		case '4':
		{ // excluir

			/*
				int x;
				printf("\nDigite o valor a ser excluido : ");
				scanf ("%d", &val);
				x = busca(&Fila, val);
				if (x == -1)
					printf("Valor %d nao foi encontrado na lista\n",val);
				else
				{
					exclui(&Fila, x);
					printf("Excluido com sucesso\n");
				}

				printf("\n\n\nAperte qualquer tecla para continuar.\n");
				getch();
				*/
			exclui(&Pilha);
			break;
		}

		case '5':
		{ // inicializar
			inicia(&Pilha);
			printf("Pilha zerada\n");

			printf("\n\n\nAperte qualquer tecla para continuar.\n");
			getch();
			break;
		}
		}
	}
}

void inicia(PILHA *P)
{
	P->nElem = 0;
}

void exibe(PILHA *P)
{
	int i;
	printf("Lista : ");
	for (i = 0; i < P->nElem; i++)
		printf("[%d]", P->LL[i].key);
	printf("\n\nQuantidade de elementos da Pilha %d\n", P->nElem);
}

int busca(PILHA *P, int K)
{
	int i = 0;
	while (i < P->nElem)
		if (K == P->LL[i].key)
			return i;
		else
			i++;
	return -1;
}

/* A fun��o de inser��o � feita de forma ordenada crescente,
cada novo valor � comparado desde o �ltimo, para saber em que
posi��o deve ser inserido. Enquanto n�o � encontrada a posi��o
do novo valor, os valores maiores s�o realocados uma posi��o
acima. */

bool insere(PILHA *P, int K)
{
	/*
	int j;
	j = P->nElem;
	if (j == MAX)
		return false;
	for ( ; j > 0 ; j--)
		if (K > P->LL[j-1].key)
			break;
		else
			P->LL[j].key = P->LL[j-1].key;
	P->LL[j].key = K;
	P->nElem++;
	return true;
	*/

	int j;
	j = P->nElem;
	if (j == MAX)
		return false;
	P->nElem++;
	P->LL[j].key = K;
}

void exclui(PILHA *P)
{
	/*
	int i;
	for (i = j ; i < P->nElem-1 ; i++)
		P->LL[i].key = P->LL[i+1].key;
	P->nElem--;
	*/

	if (P->nElem == 0)
	{
		printf("Fila vazia.\n");
		printf("\n\n\nAperte qualquer tecla para continuar.\n");
		getch();
	}
	else
	{
		int temp = P->LL[P->nElem - 1].key;

		if (P->primeiroElem == P->nElem)
		{
			P->primeiroElem = 0;
		}
		P->nElem--; // um item retirado
		printf("O numero %d foi removido", temp);
		printf("\n\n\nAperte qualquer tecla para continuar.\n");
		getch();
	}
}
