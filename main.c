#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define ERR_NO_NUM -1
#define ERR_NO_MEM -2

int main()
{
	
	int i,j , x = 0, AntiVarjeLag, antalnamn = 0, antallag = 0;
	char *namn[10];

	system("cls");

	printf("Hur manga spelare ska spela? "); scanf("%d", &antalnamn);
	printf("\nHur manga lag? "); scanf("%d", &antallag);
	
	if (fmod(antalnamn, antallag) != 0){
		printf("Ojamnt antal spelare i forhallande till lag. ");
		printf("\nResvarde: %f\n", fmod(antalnamn, antallag));
		system("PAUSE");
		return 0;
	}
		
	printf("\nMata in namn.\n\n");
	for(i = 0; i < antalnamn; i++)
		{
			namn[i] = malloc(100); 
			printf("Spelare nr%d: ", i+1);
			scanf("%s", namn[i]);			
		}
	
		AntiVarjeLag = antalnamn / antallag;	
		//printf("%d", AntiVarjeLag);
		srand (time (NULL));
		x = myRandom (antalnamn);
		for (i=1;i<=antallag;i++)
			{
				printf("\n\nLag nr%d: \n--------\n", i);
				for (j=1;j<=AntiVarjeLag;j++)
				{
					printf ("Spelare: %s\n", namn[x]);
					x = myRandom (-1);
				}
			}
	

system("PAUSE");
return 0;
}



int myRandom (int size) {
    int i, n;
    static int numNums = 0;
    static int *numArr = NULL;


    if (size >= 0) {
        if (numArr != NULL)
            free (numArr);
        if ((numArr = malloc (sizeof(int) * size)) == NULL)
            return ERR_NO_MEM;
        for (i = 0; i  < size; i++)
            numArr[i] = i;
        numNums = size;
    }


    if (numNums == 0)
       return ERR_NO_NUM;


    n = rand() % numNums;
    i = numArr[n];
    numArr[n] = numArr[numNums-1];
    numNums--;
    if (numNums == 0) {
        free (numArr);
        numArr = 0;
    }

    return i;
}

