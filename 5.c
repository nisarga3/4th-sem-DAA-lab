#include<stdio.h>               
#include<stdlib.h>
#include<math.h>   

int N = 30;

int heapify(int[], int);

int main()
{
    int c,ch,n,a[30],arr[32000],size,i,j,t1,t2,t3;
    float ln;
    printf("1.Correctness,  2.Complexity\nEnter choice: ");
    scanf("%d",&ch);
    while(1)
    {
        switch(ch)
        {
            case 1: 
            {
                printf("Enter the number of elements: ");
                scanf("%d",&n);
                printf("Enter %d elements:\n",n);
                for(i=1; i<=n; i++) 
                    scanf("%d",&a[i]);
                heapify(a,n);
                /*for(j=1;j<=n;j++)
                        printf("%d ",a[j]);
                    printf("\n");*/
                printf("Heapsort order: \n");
                for(i=n; i>1; i--)
                {
                    printf("%d  ",a[1]);
                    a[1]=a[i];
                    heapify(a,i-1);
                }
                printf("%d\n",a[1]);
                break;
            }
            case 2:
            {
                printf("Enter size of array for complexity calculation of array of its next 5 multiples: ");
                scanf("%d",&size);
                printf("Size\tAscending\tcnlog(n)\tDescending\tcnlog(n)\tRandom\tcnlog(n)\n");
                for(i=1;i<=5;i++,size*=2)
                {
                    N=size;
                    t1=t2=t3=0;
                    ln=size*log(size)/log(2);
                    //printf("Entered\n");
                    for(j=1;j<=size;j++)
                        arr[j]=j;
                    t1=heapify(arr,size);
                    for(j=N; j>1; j--)
                    {
                        arr[1]=arr[j];
                        t1+=heapify(arr,j-1);
                    }
                    for(j=1;j<=size;j++)
                        arr[j]=size - j;
                    t2=heapify(arr,size);
                    for(j=N; j>1; j--)
                    {
                        arr[1]=arr[j];
                        t2+=heapify(arr,j-1);
                    }
                    for(j=1;j<=size;j++)
                        arr[j]=rand()%32000;
                    t3=heapify(arr,size);
                    for(j=N; j>1; j--)
                    {
                        arr[1]=arr[j];
                        t3+=heapify(arr,j-1);
                    }
                    printf("%d\t%d\t\t%.0f\t\t%d\t\t%.0f\t\t%d\t%.0f\n",size,t1,ln,t2,ln,t3,ln);
                    
                }
                printf("(Considering c as 1 here)\n");
                break;
            }
            default :
            {
                printf("Exiting . . .\n");
                exit(0);
            }
        }
         printf("1.Correctness,  2.Complexity\nEnter choice: ");
        scanf("%d",&ch);
    }
    return 0;
}

int heapify(int a[30], int n)
{
    int v,j,k,i,flag,count=0;
    for(i=n/2;i>=1;i--)
    {
        k=i;
        v=a[k];
        flag=0;
        while(!flag && 2*k<=n)
        {
            j=2*k;
            if(j<n)
            {
                if(a[j]<a[j+1])
                {
                    j=j+1;
                }
            }
            if(v>=a[j])
                flag=1;
            else
            {
                a[k]=a[j];
                k=j;
                count++;
            }
        }
        a[k]=v;
    }
    return count;
}