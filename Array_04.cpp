// Chocolate Distribution Problem


class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    //here we have brute force solution 
    //first sort the array and find min differece
    sort(a.begin(),a.end());
    long long mini=INT_MAX,i=0,j=m-1;
    while(j<n){
        long long sub=a[j]-a[i];
        if(mini>sub) mini=sub;
        i++;
        j++;
    }
    return mini;
    //sorry we have forgot to sort first
    }   
};
