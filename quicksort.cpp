/*
 * QuickSort
 * Author: Lei Yan
 *
 */

#include<iostream>
#include<fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void QuickSort(int *A,int p,int r);
int Partition(int *A,int p,int r);

int main()
{
    ifstream f("hw3.dat");  //You may add path to read the file.
    if (f)
    {
      int n;
      f >> n;
      int*x  =  new int[n];
      for (int i = 0; i < n; i++)
        f >> x[i];
      QuickSort(x,0,n-1);
      for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
      f.close();
    }
    else
    {
        cerr << "File open failed!" << endl;
    }

}


void QuickSort(int *A,int p,int r)
{
    int q;
    if(p<r)
    {
        q = Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
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

