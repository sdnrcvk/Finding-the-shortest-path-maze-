#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<locale.h>

#define N 6
#define M 7

int labirent[N][M];

int cozum[N][M];

void cozumyazdir()
{
    int i,j;
    
    printf("\n		~ÇÖZÜM~     \n\n");
    printf("************************************************************\n");
    for(i=0;i<N;i++)
    {
        for(j=0;j<M;j++)
        {
            printf("%7d",cozum[i][j]);
        }
        printf("\n");
        
    }
	printf("************************************************************\n");
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
    
   
     for(i=0;i<N;i++){
		for(j=0;j<M;j++)
		{
			if(rand() % 3){
				labirent[i][j]=1;
			}else{
				labirent[i][j]=0;
			}
		}
	}	
	labirent[0][0]=1; 
	labirent[N-1][M-1]=1;
       
	printf("\n		~LABÝRENT~   	\n\n");
	printf("************************************************************\n");
	for( i=0;i<N;i++){
		for(j=0;j<M;j++){
				
			printf("%7d", labirent[i][j]);
		}
		printf("\n");					
	}
    printf("************************************************************\n");
    printf("\n\n");

    for(i=0; i<N; i++)
    {
        for(j=0; j<M; j++)
        {
            cozum[i][j] = 0;
        }
    }
    /*
     printf("\n		~YOL~		\n\n");
    for(i=0; i<N; i++){
        for(j=0; j<M; j++)
        {
            printf("%7d", cozum[i][j]);
        }
        printf("\n");
    }
     printf("\n\n"); 
    */
    
    system("color E4"); //arkaplan ve yazý rengi deðiþimi
    
    if (labirentcozumu(0,0))
    
        cozumyazdir();
    else
        printf("\n	ÇIKIÞA ULAÞILMADI :( \n");
    return 0;
}
