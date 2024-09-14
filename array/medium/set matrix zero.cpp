#include<iostream>
#include<vector>
#include<algorithm>
using namespace  std;

void setMatrix0(vector<vector<int>> &mat,int m,int n){
    //int row[m] = {0};  --> matrix[...][0]
    //int col[n] = {0};  --> matrix[0][...]

    int col0 = mat[0][0];

    for(int i=0; i<m; i++){
       for(int j=0;j<n;j++){
            if (mat[i][j] == 0)
            {
                //mark ith row
                mat[i][0] = 0;

                //mark jth col
                if (j != 0){
                    mat[0][j] = 0;
                }else{
                    col0 = 0;
                }
                
            }
       }
    }


    for(int i=1; i<m; i++){
       for(int j=1;j<n;j++){
            if (mat[i][j] != 0)
            {
                //chack for row & col
                if (mat[i][0] == 0 || mat[0][j] == 0 )
                    mat[i][j] = 0;
                
            }
            
       }
    }

    if (mat[0][0] == 0) for (int j = 1; j < n; j++) mat[0][j] = 0;

    if (col0 == 0) for (int i = 0; i < m; i++) mat[i][0] = 0;

}

int main(){
    int n,m;
    cin>>n; // row
    cin>>m; // col
    vector<vector<int>> mat(n,vector<int>(m));
    for(int i=0; i<m; i++){
       for(int j=0;j<n;j++){
            cin>>mat[i][j];
       }
    }

    cout<<"before setting to Zero"<<endl;
    for(int i=0; i<m; i++){
       for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
       }
       cout<<endl;
    }

    setMatrix0(mat,m,n);

    cout<<"after setting to Zero"<<endl;
    for(int i=0; i<m; i++){
       for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
       }
       cout<<endl;
    }


    return 0;
}
