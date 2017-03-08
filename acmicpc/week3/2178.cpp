#include <cstdio>
#include <climits>
#include <iostream>

using namespace std;

int a[101][101];
int ch[101][101];
int n, m;

bool is_wall(int i, int j);
bool is_end(int i, int j);
bool is_checked(int i, int j);
int dfs(int i, int j, int w, int ds);

int main(){

    scanf("%d", &m);
    scanf("%d", &n);
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            int x;
            scanf("%d", &x);
            a[i][j] = x;
        }
    }

    int ans = dfs(1,1,0,0);
    printf("%d", ans);
    return 0;
}


bool is_wall(int i, int j){

    if(a[i][j] == 0)
        return true;
    else
        return false;
}

bool is_end(int i, int j){
    if(i == m && j == n)
        return true;
    else
        return false;
}
bool is_checked(int i, int j){
    if(ch[i][j] == -1)
        return true;
    else
        return false;
}

int dfs(int i, int j, int w, int ds){
    // d = {1,2,3,4} == goto {right, left, up, down}
    printf("%d, %d\t", i, j);
    w += 1;
    if(is_wall(i, j) || is_checked(i,j))
        return INT_MAX;
    if(w > 500){
        ch[i][j] = -1;
        return INT_MAX;
    }
    if(is_end(i, j))
        return w;

    //ch[i][j] = 1;

    int ans = INT_MAX;
    int a = INT_MAX;
    int b = INT_MAX;
    int c = INT_MAX;
    int d = INT_MAX;
    if(!is_checked(i-1, j) && !is_wall(i-1, j) && ds != 2){
        // ch[i-1][j] = -1;
        a = dfs(i-1, j, w, 1);
        ch[i][j] = 0;
    }
    if(!is_checked(i+1, j) && !is_wall(i+1, j) && ds != 1){
        //ch[i+1][j] = -1;
        b = dfs(i+1, j, w, 2);
        ch[i][j] = 0;
    }
    if(!is_checked(i, j-1) && !is_wall(i, j-1) && ds != 4){
        //ch[i][j-1] = -1;
        c = dfs(i, j-1, w, 3);
        ch[i][j] = 0;
    }
    if(!is_checked(i, j+1) && !is_wall(i, j+1) && ds != 3){
        //ch[i][j+1] = -1;
        d = dfs(i, j+1, w, 4);
        ch[i][j] = 0;
    }
    a = min(a,b);
    b = min(c,d);
    c = min(a,b);
    ans = min(ans, c);
    return ans;

}
