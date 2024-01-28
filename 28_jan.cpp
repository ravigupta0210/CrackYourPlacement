// Allocate minimum number of pages


//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    bool isPossible(int n,int m,int a[], int mid){
        int count=1,sum=0;
        for(int i=0;i<n;i++){
            
            sum+=a[i];
            if(a[i]>mid) return false;
            if(sum>mid){
                sum=a[i];
                count++;
            }
            
        }
        return m>=count;
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        if(M>N)
        return -1;
        int start=0,sum=0,ans=-1;
        for(int i=0;i<N;i++)
            sum+=A[i];
        int end=sum;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(N,M,A,mid)){
                ans=mid;
                end=mid-1;
            }
            else start=mid+1;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends


//  Find Nth Root Of M

#include<bits/stdc++.h>
int NthRoot(int n, int m) {
  int low=1;int high=m;
  while(low<=high){
    long long mid=(low+high)/2;
    if(pow(mid,n)==m)
    return mid;
    if(pow(mid,n)>m) high=mid-1;
    else low=mid+1;
  }
  return -1;
   
}
