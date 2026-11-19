/*
	Name: BogoSort.cpp
	Author: 
	Date: 17/11/26 11:28
	Description: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//secao de prototipação
bool is_sorted(int *a, int ); //esta em ordem
void shuffle(int *, int); /// embaralha
void bogoSort(int *, int);
// variavel global

int tentativas = 0;
main()
{
	int vet[] = {23, 12, 17, -2, 20, 24, 157, 50, 81, 53};
	int i;
	int tam = sizeof(vet)/sizeof(int);
	
	puts("Vetor Original: ");
	for(i=0; i<tam; i++)
	{
		printf("%d|", vet[i]);
	}
	
	bogoSort(vet,tam);
	puts("\n\nVetor ordenado com Bogo Sort: ");
	for(i=0; i<tam; i++)
	{
		printf("%d|", vet[i]);
	}
	
	printf("\nTentativas: %d", tentativas);
}

// função principal bogo Sort
void bogoSort(int *V, int tam)
{
	while(is_sorted(V, tam) == false)
	shuffle(V, tam);
	
}

//Funçao que embaralha os elementos
void shuffle(int *V, int tam)
{
	int i, temp, r;
	for(i=0; i< tam; i++){
		temp = V[i];
		r = rand()%tam;
		V[i] = V[r];
		V[r] = temp;
	}
}

bool is_sorted(int *V, int tam)
{
	while(--tam >= 1)
	{
		tentativas++;
		if(V[tam] < V[tam-1])
		return false;
	
	}
	return true;
}

