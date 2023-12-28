// Ceil The Floor


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
    int floor=INT_MIN,ceil=INT_MAX;
    sort(arr,arr+n);
    if(x < arr[0]) floor = -1;
    if(x > arr[n-1]) ceil = -1;
    for(int i=0;i<n;i++){
        if(arr[i] <= x) floor = max(floor,arr[i]);
        if(arr[i] >= x) ceil = min(ceil,arr[i]);
    }
    return {floor,ceil};
}
