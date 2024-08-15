class Solution {
public:
    bool isValid(vector<vector<int>>& image,int target,int i,int j, int n, int m){
        if(i>=0 && i<n && j>=0 && j<m && image[i][j]==target) return true;
        return false;
    }
    void DFS(vector<vector<int>>& image,int target,int i,int j, int n, int m, int color){
        image[i][j] = color;

        if(isValid(image,target,i+1,j,n,m)) DFS(image,target,i+1,j,n,m,color);
        if(isValid(image,target,i-1,j,n,m)) DFS(image,target,i-1,j,n,m,color);
        if(isValid(image,target,i,j-1,n,m)) DFS(image,target,i,j-1,n,m,color);
        if(isValid(image,target,i,j+1,n,m)) DFS(image,target,i,j+1,n,m,color);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int target = image[sr][sc];
        if(target != color)
            DFS(image,target,sr,sc,n,m,color);
        return image;
    }
};