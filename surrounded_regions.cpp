class Solution {
public:
    //hum boundry ke jo O honge unko visitred mein 1 mark krenge aur jo bhi !vis bachte h woh saare O ko X banao
    void dfs(int row, int col, vector<vector<char>>board,vector<vector<int>>&vis,int delrow[],int delcol[]){
        int m=board.size();
        int n=board[0].size();
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,vis,delrow,delcol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int delrow[]={-1,0,1,0};
        int delcol[]={0,1,0,-1};
        //for first and last column
        //m because column number is gonna be fixes either 0 or n-1 but aall the row are gonnbe checked so <m and not n vice versa for rows
        for(int j=0;j<m;j++){
            if(!vis[j][0] && board[j][0]=='O'){
                dfs(j,0,board,vis,delrow,delcol);
            }
            if(!vis[j][n-1] && board[j][n-1]=='O'){
                dfs(j,n-1,board,vis,delrow,delcol);
            }
        }
        //for first and last row
        for(int i=0;i<n;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,board,vis,delrow,delcol);
            }
            if(!vis[m-1][i] && board[m-1][i]=='O'){
                dfs(m-1,i,board,vis,delrow,delcol);
            }
        }
        //change every O except the one marked visted as only boundry connections are marked visited
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }

        
    }
};
