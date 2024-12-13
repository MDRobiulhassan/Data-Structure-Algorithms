#include <bits/stdc++.h>
using namespace std;
bool ls(int arr[],int target,int n)
    {
        for(int i=0;i<n;i++)
        {
            if(arr[i]==target)
                return true;
        }
        return false;
    }
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
      int len=1;
      for(int i=0;i<N;i++)
      {
          int el=arr[i]+1;
          int count=1;
          while(ls(arr,el,N))
          {
              el++;
              count++;
          }
          
          len=max(len,count);
      }
      return len;
    }