/*
 *
 *Title: Fixing insertion sort
 * Author: Lei Yan
 *
 */
#include<iostream>
#include<fstream>

using namespace std;

void InsertSort(int x[], int n)
{

    for(int i= 1; i<n; i++)
    {
        if(x[i]>=x[i-1])
            continue;
        int temp = x[i];
        int j;
        temp=x[i];


        for (j = i-1; j >= 0; j--)
        {
            if (x[j] > temp)  //if (x[j] > x[i])
                x[j+1] = x[j];
            else {
                 break;
                 }
        }
        x[j+1] = temp;

    }
}


int main()
{
    ifstream f("C:\\Users\\Lei\\Desktop\\hw3.dat");  //You may change path to read the file.
    if (f)
    {
      int n;
      f >> n;
      int*x  =  new int[n];
      for (int i = 0; i < n; i++)
        f >> x[i];
      InsertSort(x,n);
      for (int i = 0; i < n; i++)
        cout << x[i] << " ";
      delete [] x;
      f.close();
    }
    else
    {
        cerr << "File open failed!" << endl;
    }

}
