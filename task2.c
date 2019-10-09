#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int** table;
    printf("Enter number of graph elements(<100):\n");
    int n;
    scanf("%d", &n);
    table = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i != n; ++i)
    {
        table[i] = (int*)malloc(sizeof(int) * n);
        memset(table[i], 0, sizeof(int) * n);
    }
    int finished = 0;
    
    while(!finished)
    {
        printf("1.Add connection\n2.Finish\n");
        int in;
        scanf("%d", &in);
        switch(in)
        {
            case 1:
            {
                printf("Type 2 values: ");
                int a, b;
                scanf("%d %d", &a, &b);
                table[a][b] = 1;
                table[b][a] = 1;
                break;
            }
            case 2:
            {
                finished = 1;
                break;
            }
            default:
            {
                printf("incorrect input\n");
                break;
            }
            
        };
    }    
    printf("\n   ");
    
    for(int i = 0; i != n; ++i)
        printf("%2d ", i);
    for(int i = 0; i != n; ++i)
    {
        printf("\n%2d ", i);
        for(int j = 0; j != n; ++j)
        {
           printf("%2d ", table[i][j]); 
            
        }
        
    }
    putchar('\n');
    return 0;
}
