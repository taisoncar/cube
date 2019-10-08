#include <stdio.h>

int ptrsearch(int *array,int element,int n)
{
    int i;
    for(i=0;*(array+i)!=element;++i)              //i deleted the error handling thing as it causes runtime error, and it is not useful at all in this code
        ;                                        //becuz the element that are needed to put in is get out of ptrsmall so the element must be in the array
    return i;
}

int ptrlarge(int *array,int startpoint,int n)
{
    int largest;
    int i;

    largest=*(array+startpoint);

    for(i=1+startpoint;i!=n;++i)
    {
        if (*(array+i)>largest)
            largest = *(array+i);
    }
    return largest;
}

int ptrsmall(int *array,int startpoint, int n)
{
    int smallest;
    int i;

    smallest=*(array+startpoint);

    for(i=1+startpoint;i!=n;++i)
    {
        if (*(array+i)<smallest)
            smallest = *(array+i);
    }
    return smallest;
}

void cswap(int *a, int *b)
{
    int temp;

    temp=*a;
    *a=*b;
    *b=temp;
}

void csort(int *arr,int n)
{
    int i=0;
    int spoint=0;
    int smallest;
    int found;

    while(i!=n)
    {   
        smallest=ptrsmall(arr,spoint,n);
        found=ptrsearch(arr,smallest,n);
        cswap((arr+spoint),(arr+found));
        ++spoint;
        ++i;
    }
}

void arrswap(int *array,int n1,int n2)
{
    int temp=*(array+n1);
    *(array+n1)=*(array+n2);                           //newly added swap for array
    *(array+n2)=temp;
}

void reverse(int *arr,int n)
{
    for(int i=0,j=n-1;i<j;++i,--j)
    {
        cswap(arr+i,arr+j);
    }
}

void printarr(int *arr,int n)
{
    for(int i=0;i<n;++i)
    {
        printf("%d\n",arr[i]);
    }
}


