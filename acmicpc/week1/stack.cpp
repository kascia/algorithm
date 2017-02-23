
#include <iostream>
#include <cstring>

using namespace std;
int s[10000 + 100];
int size = 0;

void push(int x);
int get_top();
int pop();
int is_empty();


int main(){
    iostream::sync_with_stdio(false);
    int n;
    char cmd[100];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> cmd;
        if(strcmp(cmd, "push")==0){
            int x;
            cin >> x;
            push(x);
        }
        else if(strcmp(cmd, "top")==0){
            int t = get_top();
            cout << t<< endl;
        }
        else if(strcmp(cmd, "pop")==0){
            int p = pop();
            cout << p << endl;
        }
        else if(strcmp(cmd, "empty")==0){
            int e = is_empty();
            cout << e << endl;
        }
        else if(strcmp(cmd, "size")==0){
            cout << size << endl;
        }
    }
    return 0;
}


void push(int x){
    s[size] = x;
    size += 1;
}

int get_top(){
    if(size==0){
        return -1;
    }
    return s[size-1];
}

int pop(){
    if(size==0){
        return -1;
    }
    int ret =s[size-1];
    s[size-1] = 0;
    size--;
    return ret;
}

int is_empty(){
    if(size==0){
        return 1;
    }
    return 0;
}

