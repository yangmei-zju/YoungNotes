#include <stdio.h>
#include<stdlib.h>
#define N 30
//用链表构建一个树
typedef struct TreeNode *Tree;
struct TreeNode {
    int Element;
    Tree  Left;
    Tree  Right;
};
//用指针和数组构建一个栈
typedef struct{
    Tree element[N+1];
    int top;    
}Stack;

void Push(Stack *S, Tree e){
    S->top++;   
    S->element[S->top] = e;   
}

Tree Pop(Stack *S)
{
    Tree t;
    t = S->element[S->top];
    printf(" %d", t->Element);
    S->top--;   
    return t;
}

Tree CreateTree(int *in,int *post, int n);
/*void Inorder(Tree t);*/
void zigorder(Tree t);

int main()
{
    int n;
    scanf("%d", &n);
    int *in = (int *)malloc(N*(sizeof(int)));
    int *post = (int *)malloc(N*(sizeof(int)));
    Tree t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&in[i]);
    }
    for(int j = 0; j < n; j++)
    {
        scanf("%d",&post[j]);
    }
    t = CreateTree(in, post, n);
    zigorder(t);
    return 0;
}

//由中序遍历和后序遍历还原树
Tree CreateTree(int *in, int *post, int n)
{
    Tree t = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int  i, r;
    if(n <= 0) return(NULL);
    r = post[n - 1]; //postorder数组的最后一个元素为根节点的值
    t->Element = r;
    for(i = 0; i < n; i++)
    {
        if(in[i] == r) break;  //inorder的前半部分为左子树，右半部分为右子树，在对左子树和右子树递归找下一层的节点和子树
    }
    t->Left = CreateTree(in, post, i);
    t->Right = CreateTree(in + i + 1 , post + i, n - i - 1);
    return t;
}
//中序遍历
/*void Inorder(Tree t)
{
    if(t != NULL)
    {
        Inorder(t->Left);
        printf("%d ",t->Element);
        Inorder(t->Right);
    }
}*/
//进行之字遍历
void zigorder(Tree t)
{
    Tree e;
    Stack *s1 =(Stack *)malloc(sizeof(Stack));
    Stack *s2 = (Stack *)malloc(sizeof(Stack));
    s1->top = -1;
    s2->top = -1;
    if(t != NULL) Push(s1,t);
    while(s1->top != -1 || s2->top != -1)
    {
        while (s1->top != -1)
        {
            if(s1->element[s1->top] == t) 
            {
                e = t;
                s1->top--;
                printf("%d", e->Element);

            }
            else
            {
                e = Pop(s1);
            }
            if(e->Right != NULL) Push(s2, e->Right);
            if(e->Left !=NULL) Push(s2, e->Left);
    
        }
        while(s2->top != -1)
        {
            e = Pop(s2);
            if(e->Left != 0) Push(s1,e->Left);
            if(e->Right != 0) Push(s1,e->Right);
        }
    }
}


