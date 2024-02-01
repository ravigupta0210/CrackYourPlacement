// Nearest Smaller Element


vector<int> Solution::prevSmaller(vector<int> &A) {
    int n=A.size();
    vector<int> ans(n,-1);
    stack<int> st;
    st.push(A[0]);
    for(int i=1;i<n;i++){
        if(A[i]>st.top()){
            ans[i]=st.top();
            st.push(A[i]);
        }
        else{
            while(!st.empty() && st.top()>=A[i])
            st.pop();
        
        if(!st.empty())
        ans[i]=st.top();
        st.push(A[i]);
    }
}
    return ans;
}
