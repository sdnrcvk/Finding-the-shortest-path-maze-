#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>

#define N 6
#define M 6

int labirent[N][M]={{1,0,0,0,0,0},
					{1,0,0,0,0,0},
					{1,1,1,0,1,1},
					{0,0,1,0,1,1},
					{0,0,1,1,1,1},
					{0,0,0,0,0,1}};
					


int cozum[N][M];

void cozumyazdir()
{
    int i,j;
   
    printf("\n			~��Z�M~     \n\n");
    printf("*******************************************************************************************\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            printf("%4d",cozum[i][j]);
        }
        printf("\n");
    }
    printf("*******************************************************************************************\n");
}


int labirentcozumu(int x, int y)
{
    if((x==N-1) && (y==M-1))
    {
        cozum[x][y] = 1;
        return 1;
    }

    if(x>=0 && y>=0 && x<N && y<M && cozum[x][y] == 0 && labirent[x][y] == 1)
    {
        //ziyaret etmek g�venli ise h�creyi ziyaret edin
        cozum[x][y] = 1;
        //a�a�� gitme
        if(labirentcozumu(x+1, y))
            return 1;
        //sa�a gitme
        if(labirentcozumu(x, y+1))
            return 1;
        //yukar� gitme
        if(labirentcozumu(x-1, y))
            return 1;
        //sola gitme
        if(labirentcozumu(x, y-1))
            return 1;
        //backtracking(geri izleme)
        cozum[x][y] = 0;
        return 0;
    }
    return 0;

}

int main()
{
    int i,j;
    setlocale(LC_ALL, "Turkish"); //t�rk�e karakter
    srand(time(NULL)); 
    
   	
	printf("\n			~LAB�RENT~   	\n\n");
	printf("*******************************************************************************************\n");
	for( i=0;i<N;i++){
		for(j=0;j<M;j++){
				
			printf("%4d", labirent[i][j]);
		}
		printf("\n");		
	}
	printf("*******************************************************************************************\n");
	
    printf("\n\n");
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            cozum[i][j] = 0;
        }
    }
    
    system("color E4"); //arkaplan ve yaz� rengi de�i�imi
    
    if (labirentcozumu(0,0))
    
        cozumyazdir();
    else
        printf("\n	�IKI�A ULA�ILMADI :(    \n");
    return 0;
}
