#include <stdio.h>
#include<stdlib.h>
void BST(int *tree, int *arr, int p, int *k)
{
    if(p < 1 || p > tree[0] || (*k) == tree[0]) return;
    else{
    BST(tree, arr, p*2, k);
    tree[p] = arr[(*k)++];
    BST(tree, arr, p*2+1, k);
    }
}
int main()
{
    int N;
    /*int arr[100];
    int tree[101];*/
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    int *tree = (int *)malloc((N + 1)*sizeof(int));
    
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < N; i++)
    { 
        int t;
        for(int j = 0; j < N; j++)
        {
            if(arr[j] > arr[j+1])
            {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
    tree[0] = N;
    int p = 1, k = 0;
    BST(tree, arr, p,&k);
    printf("%d", tree[1]);
    for(int i = 2; i <= N; i++)
    {
        printf(" %d" ,tree[i]);
    }
    free(arr);
    free(tree);
    return 0;
}