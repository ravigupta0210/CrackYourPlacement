// Different Ways to Add Parentheses


class Solution {
public:
bool isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*');
}
vector<int> solve(int i,int j,string& expression){
    int len = j-i+1;
     if(len <= 2){
         return {stoi(expression.substr(i,len))};
     }
     vector<int> res;
     for(int index = i;index <= j ;index++){
         if(isOperator(expression[index])){
             char op = expression[index];

             vector<int> left = solve(i,index-1,expression);
             vector<int> right = solve(index+1,j,expression);
             for(auto l:left){
                 for(auto r:right){
                     if(op == '+'){
                         res.push_back(l+r);
                     }
                     else if(op == '-')
                     res.push_back(l-r);

                     else if( op == '*')res.push_back(l*r);
                 }
             }
         }
     }
     return res;
}
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();

        return solve(0,n-1,expression);
    }
};
