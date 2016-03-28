/*
 * Title: KnuthQuickSort
 * Author: Lei Yan
 *
 */

#include<iostream>
#include<fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void KnuthQuickSort(int *A,int p,int r, int k);
int Partition(int *A,int p,int r);
void InsertSort(int *A, int start, int end);


int main()
{
    ofstream ofile;
    ofile.open("C:\\Users\\Lei\\Desktop\\RunningTime.txt");  //import running time into a file

    srand((unsigned) time(NULL));
    int*x  =  new int[1000000];
    for (int i = 0; i < 1000000; i++)
    {
        x[i] = rand()%100000;
    }
    for(int k = 1; k<100; k++)
    {

        clock_t start_time=clock(); //record running time by using system time
        KnuthQuickSort(x,0,999999,k);
        clock_t end_time=clock();
        cout<< "When k = "<<k;
        cout<<" ,running time is: "<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<"ms"<<endl;
        ofile<<static_cast<double>(end_time-start_time)/CLOCKS_PER_SEC*1000<<" ";
    }
    delete [] x;

}

void KnuthQuickSort(int *A, int left, int right, int k)
{
    if(left<right)
    {
        if(right - left<k){
            InsertSort(A, left, right + 1);  //When array size is smaller than k, using insertion sort.
        }
        else{
            int q = Partition(A, left, right);
            KnuthQuickSort(A, left, q - 1, k);
            KnuthQuickSort(A, q + 1, right, k);
        }
     }
}


int Partition(int *A,int p,int r)
{
    int x,i,j,n,temp;
    srand((unsigned) time(NULL));
    n = rand()%(r-p+1)+p;

    x = A[n];
    temp = A[n];
    A[n] = A[r];
    A[r] = temp;
    i = p-1;

    for( j=p; j<=r-1; j++)
    {
        if(A[j]<=x)
        {
            i +=1;
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;

    return i+1;
}

void InsertSort(int *A, int start, int end)
{

    for(int i= start + 1; i<end; i++)
    {
        if(A[i]>=A[i-1])
            continue;
        int temp = A[i];
        int j;
        temp=A[i];


        for (j = i-1; j >= 0; j--)
        {
            if (A[j] > temp)
                A[j+1] = A[j];
            else {
                 break;
                 }
        }
        A[j+1] = temp;

    }
}
