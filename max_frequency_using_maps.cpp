#include<map>
#include<unordered_map>
int maximumFrequency(vector<int> &arr, int n)
{
    
    int maxfreq=0;
    int ans=0;
    unordered_map<int,int>m;
    for(int i=0;i<arr.size();i++)
    {
        m[arr[i]]++;
        maxfreq=max(maxfreq,m[arr[i]]);
    }

   for(int i=0;i<arr.size();i++)
   {
       if(maxfreq==m[arr[i]])
       {
           ans=arr[i];
           break;
       }
   }
   return ans;
}
