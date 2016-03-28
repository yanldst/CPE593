/*
 * BinarySearch
 * Lei Yan
 *
 */
#include <iostream>
#include <fstream>

using namespace std;

bool BinarySearch(int* a, int len, int goal, int& count)
    {
        int low = 0;
        int high = len - 1;
        int iteration=0;
        while(low <= high)
        {
            int mid = (low + high+1)/2;
            if(a[mid] > goal)
            {
                high = mid - 1;
                iteration++;
            }
            else
                if(a[mid]<goal)
                  {
                    low = mid + 1;
                    iteration++;
                   }
                 else
                 {
                    iteration++;
                    count = iteration;
                    return true;
                 }
         }
        iteration++;
        count = iteration;
        return false;
    }

int main()
{
    ifstream f("HW3.txt"); //You may add path to test my code.
    if (f)
    {
      int g;
      int len, goal;
      int i,j;
      string garbage;
      f>>garbage;
      f>>g;
      for(i = 0; i < g; i++)
      {
          f>>len;
          int*a  =  new int[len];
          for(j=0;j<len;j++)
          f >> a[j];
          f>>goal;
          int count;
          BinarySearch(a, len, goal,count);
          bool k;
          k = BinarySearch(a, len, goal,count);
          if (!k)
          {
              cout<<"NOT FOUND ";
              cout<<count<<endl;
          }
          else
          {
              cout<<goal<<" ";
              cout<<count<<endl;
          }
          delete [] a;
      }



    }
    else
    {
        cerr << "File open failed!" << endl;
    }


}
