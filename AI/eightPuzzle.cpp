#include <bits/stdc++.h>
using namespace std;


char finalState[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','.'}};

int heuristic(char matrix[][3]){
    int count =0 ;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(matrix[i][j] != finalState[i][j]){
                count++;
            }
        }
    }
    return count;
}

pair<int,int> findPos(char board[][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] =='.'){
                return {i,j}; 
            }
        }
    }
    return {-1,-1};
}

void bfs(char board[][3],vector<int>& ans){
    queue<pair<int,pair<int,int>>> q;
    //<heuristic<row,col>>;
    int h = heuristic(board);
    pair<int,int> emptyPos = findPos(board);
    q.push({h,emptyPos});
    int delRow[] = {0,1,0,-1};
    int delCol[] = {1,0,-1,0};
    
    while(!q.empty()){
        int currRow = q.front().second.first;
        int currCol = q.front().second.second;
        
        int nRow,nCol;
        for(int i=0;i<4;i++){
            nRow = currRow + delRow[i];
            nCol = currCol + delCol[i];
            
            if(checkValid(board,nRow,nCol)){
                
            }
        }
        
    }
}

int main(){
    char board[3][3];
    cout<<"Enter 9 position values : ";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<"row :  " << i << "Col : " << j<<" : ";
            cin>>board[i][j];
        }
    }
    vector<int> ans;
    bfs(board,ans);
    
    return 0;
}
