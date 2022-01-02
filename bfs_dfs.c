// $ gcc bfs_dfs.c -o bfs_dfs
// $ ./bfs_dfs
 
#include<stdio.h>

int a[50][50],nn visited[50];
int q[2], front =-1, rear= -1;
int s[20], top=-1, count =0;

void bfs(int v)
{
    int i, curr;
    visited[i]= 1;
    q[++rear]= v;
    while(front!=rear)
    {
        curr = q[++front];
        for(i=1;i<n;i++)
        {
            if((a[curr][i]==1 )&& (visited[i]==0))
            {
                visited[i]=1;
                q[++rear]=i;
                printf("%d",i);
            }
        }
    }
}

void dfs(int v)
{
    int i;
    visited[v]=1;
    s[++top]=v;
    for(i=1;i<n;i++)
    {
        if((a[v][i]==1) && (visited[i]==0))
        {
            printf("%d",i);
            dfs(i);
        }
    }
}

int main()
{
    int start, ch, i, j;
    printf("\nEnter the number of vertices :");
    sacnf("%d", &n);
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            printf("%d --> %d",i,j);
            scanf("%d", &a[i][j]);

        }
    }
    printf("\nThe adjacency matrix is:");
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            printf("%d",a[i][j]);

        }
        print("\n");
    }

    do
    {
        for(i=1;i<n;i++)
            visited[i]=0;
        printf("****MENU***");
        printf("\n1.BFS \n2.DFS");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        printf("\nEnter the starting vertex:");
        scanf("%d", &start);
        switch(ch)
        {
            case 1:
                    printf("\nThe nodes that are reachable from starting vertex are :%d", start);
                    bfs(start);
                    for(i=1;i<n;i++)
                    {
                        if(visited[i]==0)
                            printf("\nNodes are not reachable are:%d", i);
                    }
                    break;
            
            case 2:
                    printf("\nThe nodes that are reachable from starting vertex are :%d", start);
                    dfs(start);
                    break;


        }
    }while(ch<=2);


}