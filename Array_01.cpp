// Set Matrix Zeroes


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //this is second approach to do the first question

        //first we have traverse first row and col for mark them all for 0
        bool fr=false,fc=false;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    if(i==0)fr= true;
                    if(j==0)fc= true;
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        //we mark zero except first row and col
        //here we make a mistake 
        for(int i=1;i<matrix.size();i++){
            for(int j=1;j<matrix[0].size();j++){
                if(matrix[0][j]==0 || matrix[i][0] == 0)
                matrix[i][j]=0;
            }
        }
        //here we mark first row as zero if it is true
        if(fr){
            for(int j=0;j<matrix[0].size();j++){
                matrix[0][j]=0;
            }
        }
        //here we mark first col as zero if it is true
        if(fc){
            for(int i=0;i<matrix.size();i++){
                matrix[i][0]=0;
            }
        }
    }
};
