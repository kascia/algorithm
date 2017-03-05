#include <cstdio>
#include <cstdlib>


int x[10000];
int N = 1;
int **G;

void check_prime();

bool is_prime(int a);

bool is_connected(int a, int b);

void make_graph();

int dfs(int a, int b);

int main(){

    int t;
    make_graph()
    scanf("%d", &t);
    for(int i=0; i<t; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        dfs(a, b);
    }

    return 0;
}

void check_prime(){
    for(int i=1000; i<10000; i++){
        if(is_prime(i)){
            x[i] = 1;
            N += 1
        }
        else{
            x[i] = -1;
        }
    }
}

bool is_prime(int a){

    return;
}

bool is_connected(int a, int b){

    return;
}
void make_graph(){
    check_prime();
}

int dfs(int a, int b){

    return num_way
}


