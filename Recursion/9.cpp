// All Possible Full Binary Trees


class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2 == 0) return {};
        vector<TreeNode*> list; 
        if(n==1){
            list.push_back(new TreeNode(0));
        }
        else{
            for(int i=1;i<=n-1;i+=2){
                vector<TreeNode*> leftAns = allPossibleFBT(i);
                vector<TreeNode*> rightAns = allPossibleFBT(n-i-1);

                for(auto l:leftAns){
                    for(auto r: rightAns){
                        list.push_back(new TreeNode(0,l,r));
                    }
                }
            }
    
        
        }
        return list;
    }
};
