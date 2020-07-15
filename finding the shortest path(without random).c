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
   
    printf("\n			~ÇÖZÜM~     \n\n");
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
        //ziyaret etmek güvenli ise hücreyi ziyaret edin
        cozum[x][y] = 1;
        //aþaðý gitme
        if(labirentcozumu(x+1, y))
            return 1;
        //saða gitme
        if(labirentcozumu(x, y+1))
            return 1;
        //yukarý gitme
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
    setlocale(LC_ALL, "Turkish"); //türkçe karakter
    srand(time(NULL)); 
    
   	
	printf("\n			~LABÝRENT~   	\n\n");
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
    
    system("color E4"); //arkaplan ve yazý rengi deðiþimi
    
    if (labirentcozumu(0,0))
    
        cozumyazdir();
    else
        printf("\n	ÇIKIÞA ULAÞILMADI :(    \n");
    return 0;
}
