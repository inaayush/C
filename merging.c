#include<stdio.h>

int main()
{
    int index = 0,index_first=0,index_second=0,n1=5,n2=6,a[n1],b[n2],c[n1+n2];

    for(int i=0;i<n1;i++)
    {
        a[i]=n1*n1+i;
    }
    for (int i = 0; i < n2; i++)
    {
        b[i]=n2*2+i;
    }
    printf("\nArray1:");
    for (int i = 0; i < n1; i++)
    {
        printf("[%d]",a[i]);
    }
    printf("\nArray2:");
    for (int i = 0; i < n2; i++)
    {
        printf("[%d]",b[i]);
    }
    
    while(index_first<n1 && index_second<n2)
    {
        if(a[index_first]<b[index_second])
        {
            c[index]=a[index_first];
            index_first++;
        }
        else
        {
            c[index]=b[index_second];
            index_second++;
        }
        index++;
        
    }
    if(index_first==n1)
    {
        while(index_second<n2)
        {
            c[index]=b[index_second];
            index_second++;
            index++;
        }
    }
    else if(index_second==n2)
    {
        while(index_first<n1)
        {
            c[index]=a[index_first];
            index_first++;
            index++;
        }
    }
    printf("\nMerged Output:");
    for (int i = 0; i < n1+n2; i++)
    {
        printf("[%d]",c[i]);
    }
}
