#include<stdio.h>
#include<stdlib.h>
#include<math.h>          

int N;
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int *Partition(int a[N],int l, int r)
{
    int i=0, j=0, k=0, count=0,p;
    int* c =(int*)malloc(sizeof(int)*2);
    p=a[l];
    i=l+1;
    j=r;
    do
    {
        while(a[i]<=p) 
            {
                if((i+1)>r)
                    break;
                i++;
                count++;
            }
        while(a[j]>p)
            {
                j--;
                count++;
            }
        swap(&a[i],&a[j]);
    }while(i<j && i<=r);
    swap(&a[i],&a[j]);
    swap(&a[l],&a[j]);
    c[0]=j;
    c[1]=count;
    return c;
}


int QuickSort(int a[N], int l, int r)
{
    if(r<=l || l<0 || r<0)
        return 0;
    int s,i,c1=0,c2=0,count=0,*c;
    c = Partition(a,l,r);
    s=c[0];
    count = c[1];
    c1 = QuickSort(a,l,s-1);
    c2 = QuickSort(a,s+1,r);
    return count+c1+c2; 
}

int main()
{
    int n,i,ch,x;
    printf("Enter choice: 1.Correctness 2.Complexity - ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        {
            printf("Enter the size of array: ");
            scanf("%d",&n);
            N=n;
            int a[n];
            printf("Enter %d array elements -\n",n);
            for(i=0;i<n;i++)
                scanf("%d",&a[i]);
            x = QuickSort(a,0,n-1);
            printf("Sorted array is:\n");
            for(i=0;i<n;i++)
                printf("%d ",a[i]);
            break;
        }
        case 2:
        {
            int arr[32000],size,i,j,t1,t2,t3;
            float ln;
            printf("Enter size of array for complexity calculation of array of its next 5 multiples: ");
            scanf("%d",&size);
            printf("Size\tAscending\t(n*n)\t\tDescending\t(n*n)\tRandom \t(3nlogn)\n");
            for(i=1;i<=5;i++,size*=2)
            {
                N=size;
                ln=3*size*log(size)/log(2);
                for(j=0;j<size;j++)
                    arr[j]=j;
                t1=QuickSort(arr,0,size-1);
                for(j=0;j<size;j++)
                    arr[j]=size - j;
                t2=QuickSort(arr,0,size-1);
                for(j=0;j<size;j++)
                    arr[j]=rand()%32000;
                t3=QuickSort(arr,0,size-1);
                printf("%d\t%d\t\t%d\t\t%d\t\t%.d\t%d\t%.0f\n",size,t1,size*size,t2,size*size,t3,ln);
                
            }
            break;
        }
        default:
        {
            exit(0);
        }
    }
    return 0;
}