//  Max rectangle


class Solution{
    
    
  public:
  vector<int> nextSmaller ( int* arr,int n){
      stack<int> st;
      st.push(-1);
      vector<int> ans(n);
      for(int i=n-1;i>=0;i--){
          int curr = arr[i];
          while(st.top()!= -1 && arr[st.top()] >= curr){
              st.pop();
          }
          ans[i] = st.top();
          st.push(i);
      }
      return ans;
  }
  vector<int> prevSmaller ( int* arr,int n){
      stack<int> st;
      st.push(-1);
      vector<int> ans(n);
      for(int i=0;i<n;i++){
          int curr = arr[i];
          while(st.top()!= -1 && arr[st.top()] >= curr){
              st.pop();
          }
          ans[i] = st.top();
          st.push(i);
      }
      return ans;
  }
  
  int largestArea(int *height,int n){
      int area = INT_MIN;
      vector<int> next(n);
      next = nextSmaller(height,n);
      vector<int> prev(n);
      prev = prevSmaller(height,n);
      for(int i=0;i<n;i++){
          int l = height[i];
          if(next[i] == -1) next[i] = n;
          int b = next[i] - prev[i] - 1;
          int newArea = l*b;
          area = max(area,newArea);
      }
      return area;
  }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        int area = largestArea(M[0],m);
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(M[i][j] !=0) M[i][j] += M[i-1][j];
                else M[i][j] = 0;
            }
            area = max(area,largestArea(M[i],m));
        }
        return area;
    }
};
