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


// Matrix Median

int Solution::findMedian(vector<vector<int> > &A) {
    int row=A.size(),col=A[0].size();
    int mini = INT_MAX,maxi=INT_MIN;
    for(int i=0;i<row;i++){
        mini=min(mini,A[i][0]);
        maxi=max(maxi,A[i][col-1]);
    }
    int desired = (row*col+1)/2;
    while(mini<maxi){
        int mid=(maxi+mini)/2;
        int place=0;
        for(int i=0;i<row;i++)
        place+=upper_bound(A[i].begin(),A[i].end(),mid)-A[i].begin();
        if(place<desired)
        mini=mid+1;
        else maxi=mid;
        
    }
    return mini;
}


// Single Element in a Sorted Array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<right){
            int mid=(left+right)/2;
            if(mid%2 == 1)
            mid--;
            if(nums[mid]!=nums[mid+1])
            right=mid;
            else left=mid+2;
        }
        return nums[left];
    }

// Search in Rotated Sorted Array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[low]){
                if(target >= nums[low] && target<=nums[mid])
                high=mid-1;
                else low=mid+1;
            }
            else{
                if(target >= nums[mid] && target <= nums[high])
                low=mid+1;
                else high=mid-1;
            }
        }
        return -1;
    }
};
};


// Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> v;
       v=nums1;
       double ans;
       for(auto i:nums2)
       v.push_back(i);
        sort(v.begin(),v.end());
        int n=v.size();
        if(n%2==0){
            ans=(v[n/2]+v[(n-1)/2])/2.0;
        }
        else ans=v[n/2];
        return ans;
    }
};


// K-th element of two Arrays


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int arr[n+m];
        int i=0,t=0,j=0;
        while(i<n)
        arr[t++]=arr1[i++];
        while(j<m)
        arr[t++]=arr2[j++];
        
        sort(arr,arr+n+m);
        return arr[k-1];
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}


// Allocate Books


bool possible(vector<int> &a, int n,int b,int mid){
    int count=1,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(a[i]>mid) return false;
        if(sum>mid){
            count++;
            sum=a[i];
        }
    }
    return b>=count;
}
int Solution::books(vector<int> &A, int B) {
    int start=0,end=0,ans=-1;
    if(B>A.size()) return ans;
    for(auto i:A)
    end+=i;
    while(start<=end){
        int mid=(start+end)/2;
        if(possible(A,A.size(),B,mid)){
            ans=mid;
            end=mid-1;
        }
        else start=mid+1;
    }
    return ans;
}

// } Driver Code Ends



// Aggressive Cows



//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool check(vector<int> &arr,int mid,int k){
        int count=1,last=arr[0];
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last >= mid)
            {
                count++;
                last=arr[i];
            }
            if(count==k)
            return true;
        }
        return false;
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        int low=0,high=stalls[n-1]-stalls[0];
        while(low<high){
            int mid=(low+high+1)/2;
            if(check(stalls,mid,k))
            low=mid;
            else
            high=mid-1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
