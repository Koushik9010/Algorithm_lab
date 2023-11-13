#include<stdio.h>
#include<stdbool.h>
#include <string.h>

int i, j, n;

void prims(int array[n][n])
{
    int selected[n], edge = 0, x, y;
    memset(selected, false, sizeof(selected));
    selected[0] = true;

    while(edge < n - 1)
    {
        int min = 100000;
        x = 0;
        y = 0;

        for(i = 0; i < n; i++)
        {
            if(selected[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!selected[j] && array[i][j])
                    {
                        if(min > array[i][j])
                        {
                            min = array[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
        printf("%d -> %d : %d\n", x, y, array[x][y]);
        selected[y] = true;
        edge++;
    }
}

int main()
{
    printf("Enter the number of vertices: \n");
    scanf("%d", &n);

    int array[n][n];

    printf("Enter the adjacency matrix: \n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
    prims(array);
    return 0;
}