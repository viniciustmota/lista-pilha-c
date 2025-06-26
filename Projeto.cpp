#include <stdio.h>
#include <stdlib.h>

#define tam 10

typedef struct
{
	int topo;
	int info[tam];
}PILHA;

void Inicializa(PILHA *p)
{
	p->topo = -1;
}

int Vazia(PILHA *p)
{
	return p->topo==-1;
}

int Cheia(PILHA *p)
{
	return p->topo==tam-1;
}

int Push(PILHA *p, int val)
{
	if(Cheia(p))
		return 0;    // Pilha cheia
	p->info[++p->topo] = val;
	return 1;
}

int Pop(PILHA *p, int *val)
{
	if(Vazia(p))
		return 0;
	*val = p->info[p->topo--];
	return 1;
}

void Imprime(PILHA p)
{
	int i;
	for (i=p.topo; i>=0; i--)
		printf("[ %d ]\n", p.info[i]);
}

int Converte(PILHA *p, int val)
{
	int b = 0, v;
	while(val > 0)
	{
		Push(p, val%2);
		val /= 2;
	}
	
	while(!Vazia(p))
	{
		Pop(p, &v);
		b = b*10 + v;
	}
	return b;
}

main()
{
	PILHA S;
	int op, val, bin;
	
	Inicializa(&S);
	
	do
	{
		system("cls");
		printf("\n1 - Inserir na Pilha");
		printf("\n2 - Remover da Pilha");
		printf("\n3 - Imprimir a Pilha");
		printf("\n4 - Converter Decimal para Binario");
		printf("\n0 - Sair do programa");
		
		printf("\nDigite a opcao: ");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1: printf("\nDigite o valor a inserir: \n");
					scanf("%d", &val);
					if(Push(&S, val))
						printf("\nInsercao com sucesso!\n");
					else
						printf("\nPilha Cheia!\n");
					system("pause");
					break;
			
			case 2: if(Pop(&S, &val))
						printf("\nValor removido: %d\n", val);
					else
						printf("\nPilha Vazia!\n");
					system("pause");
					break;
					
			case 3: if(Vazia(&S))
						printf("\nPilha Vazia!\n");
					else
					{
						printf("\nPILHA:\n");
						Imprime(S);
					}
					system("pause");
					break;
					
			case 4:	printf("\nDigite um numero em decimal: ");
					scanf("%d", &val);
					
					bin = Converte(&S, val);
					
					printf("\nO valor %d em binario = %d\n", val, bin);					
					system("pause");
					break;
		}
	}while (op!=0);
}
