#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int table[1000];

void shift_table(char *p)
{
    int m,j,i=0;
    m = strlen(p);
    for(int i=0;i<1000;i++)
    {
        table[i] = m;
    }
    for(int j=0;j<m-1;j++)
    {
        table[p[j]] = m-1-j;
    }
   
}

int horspool(char *p,char *t)
{
   
    int k,i,m,n;
    shift_table(p);
    n = strlen(t);
    m=strlen(p);
   
    i = m-1;
    while(i <= n - 1)
    {
        k = 0;
        while(k <= m-1 && t[i-k] == p[m-1-k])
        {
            k++;
        }
        if(k == m)
         return i-m+1;
        else
         i = i + table[t[i]];
    }
    return -1;
}


int main()
{
    char p[1000];
    char t[1000];
    printf("\nHorspool's String Matching Algorithm\n");
    printf("Enter the pattern: ");
    scanf("%s",p);
    printf("\nEnter the text: ");
    scanf("%s",t);
   
    int res = horspool(p,t);
   
    if(res>=0)
    {
        printf("\n%s is present in the text at position = %d",p,res);
    }
    else
        printf("\n%s is not present in the text",p);
   

    return 0;
}