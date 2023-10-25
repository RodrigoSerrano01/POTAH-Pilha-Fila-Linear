
/***************************************************************************
Este algoritmo  registra "N" elementos em ordem crescente.

Imprime o registro ordenado e a quantidade de elementos.

****************************************************************************/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define MAX 35		// Diminui o valor para evitar o line feed na exi��o da lista cheia

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

void inicia(PILHA*);
void exibe(PILHA*);
int busca(PILHA*, int);
bool insere(PILHA*, int);
void exclui(PILHA*);

int main ()
{
	char opcao = '1', val;
	PILHA Fila;
	while(opcao!='0')
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

		switch(opcao)
		{
			case '1':{			// inserir
				    printf("\nDigite o valor do elemento: ");
				    scanf ("%d", &val);

				    if (insere(&Fila, val) == false)
						printf("Elemento nao pode ser inserido na Fila\n");
					else
						printf("Inserido com sucesso\n");

					printf("\n\n\nAperte qualquer tecla para continuar.\n");
					getch();
				    break;
                   }

            case '2':{ 			// buscar
            		int x;
                    printf("\nDigite o valor procurado : ");
                    scanf ("%d", &val);
                    x = busca(&Fila, val);
                    if (x == -1)
						printf("Valor %d nao foi encontrado na Pilha\n",val);
					else
						printf("O valor encontra-se na posicao %d\n", x);

					printf("\n\n\nAperte qualquer tecla para continuar.\n");
					getch();
                    break;
                   }

			case '3':{			// exibir
                    exibe(&Fila);

					printf("\n\n\nAperte qualquer tecla para continuar.\n");
					getch();
                    break;
                   }

            case '4':{ 			// excluir
					exclui(&Fila);
                    break;
                   }

            case '5':{ 			// inicializar
					inicia(&Fila);
					printf("Fila zerada\n");

					printf("\n\n\nAperte qualquer tecla para continuar.\n");
					getch();
                    break;
                   }
		}
	}
}

void inicia(PILHA* F)
{
	F->nElem = 0;
	F->primeiroElem = 0;
}

void exibe(PILHA* F)
{
	int i=F->primeiroElem;
	printf("Fila : ");

	while (i <F->nElem){
		printf("[%d]",F->LL[i].key);
		i++;
		}
    printf("\n\nQuantidade de elementos da Fila %d\n",F->nElem);
}

int busca(PILHA* F, int K)
{
	int i = F->primeiroElem;
	while (i < F->nElem)
		if (K == F->LL[i].key)
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

bool insere(PILHA* F, int K)
{
    if (F->nElem == MAX) {
        return false;  // Fila cheia, não é possível adicionar mais elementos
    }

    F->LL[(F->primeiroElem + F->nElem) % MAX].key = K;
    F->nElem++;

    return true;
}


void exclui(PILHA* F)
{	
	if (F->nElem == 0) {
		printf("Fila vazia.\n");
		printf("\n\n\nAperte qualquer tecla para continuar.\n");
		getch();
	}else{
	    int temp = F->LL[F->primeiroElem].key;
	for (int i = F->primeiroElem ; i < F->nElem-1 ; i++){
		F->LL[i].key = F->LL[i+1].key;
		
		}
		F->nElem--;
        printf("O numero %d foi removido", temp);
        printf("\n\n\nAperte qualquer tecla para continuar.\n");
        getch();
		}
}


