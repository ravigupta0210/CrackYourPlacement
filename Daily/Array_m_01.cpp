class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp = head;
        while(temp->next != NULL){
            int gcd = __gcd(temp->val,temp->next->val);
            ListNode* insertnode = new ListNode(gcd);
            ListNode* extra = temp->next;
            temp->next = insertnode;
            insertnode->next=extra;
            temp = extra;
        }
        return head;
    }
};


// Queries on a Permutation With Key

class Solution {
public:
int findSolve(int key,vector<int> p){
    for(int i=0;i<p.size();i++){
        if(key == p[i]){
            return i;
        }
    }
    return 0;
}
vector<int> refactor(vector<int> p,int key){
    vector<int> temp ;
    temp.push_back(key);
    for(int i=0;i<p.size();i++){
        if(key != p[i])
        temp.push_back(p[i]);
    }
    return temp;
}
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p;
        for(int i=1;i<=m;i++)
        p.push_back(i);

        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int index = findSolve(queries[i],p);
            ans.push_back(index);
            p = refactor(p,queries[i]);
        }
        return ans;
    }
};


// Arithmetic Subarrays

class Solution {
public:
bool check(vector<int> temp){
    sort(temp.begin(),temp.end());
    bool ans = true;
    for(int i=0;i<temp.size()-2;i++){
        if(temp[i+1]-temp[i] != temp[i+2]-temp[i+1])
        ans = false;
    }
    return ans;
}
vector<int> slicing(vector<int>& arr,int X, int Y)
{
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;
    vector<int> result(Y - X + 1);
    copy(start, end, result.begin());
    return result;
}
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int i=0,j=0;
        while(i < l.size() && j< r.size()){
            vector<int> temp = slicing(nums,l[i],r[i]);
            bool res = check(temp);
            ans.push_back(res);
            i++;j++;
        }
        return ans;
    }
};

// Convert an Array Into a 2D Array With Conditions

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int,int> mp;
        for(auto i:nums) mp[i]++;
        int maxi = 0;
        for(auto k:mp){
            maxi = max(maxi,k.second);
        }
        for(int i=0;i<maxi;i++){
            vector<int> temp;
            for(auto k:mp){
                if(k.second != 0){
                    temp.push_back(k.first);
                    mp[k.first] = k.second - 1;
                }
            }
            if(temp.size() != 0) ans.push_back(temp);
        }
        return ans;
    }
};


// Sort the Matrix Diagonally


class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int r = mat.size(),c = mat[0].size();
        int rIndex = 0,cIndex;
        int n = r+c-1;
        for(int i=1;i<=n;i++){
            vector<int> diagonal;
            if(i<=c)
            cIndex = c-i;
            else{
                rIndex++;
                cIndex=0;
            }
            for(int i=rIndex,j=cIndex;i<r && j<c;i++,j++){
                diagonal.push_back(mat[i][j]);
            }
            sort(diagonal.begin(),diagonal.end());
            for(int i=rIndex,j=cIndex,k=0;i<r && j<c;i++,j++,k++ ){
                mat[i][j] = diagonal[k];
            }
        }
        return mat;
    }
};
