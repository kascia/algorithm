#include <stdio.h>


int mh[100000 + 100];
int size = 0;


int get_parent_index(int cur_index){
    int parent_index = (cur_index-1)/2;
    return parent_index;
}

int get_left_child_index(int cur_index){
    int left_child_index= cur_index*2 + 1;
    return left_child_index;
}

int get_right_child_index(int cur_index){
    int right_child_index = cur_index*2 + 2;
    return right_child_index;
}


void swap(int* a, int* b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


void push(int val){
    mh[size] = val;
    int cur_index = size;
    if(cur_index == 0){
        size++;
        return;
    }
    int parent_index = get_parent_index(cur_index);
    while(cur_index > 0 && mh[parent_index] < val){
        swap(&mh[parent_index], &mh[cur_index]);
        cur_index = parent_index;
        parent_index = get_parent_index(cur_index);
    }
    size++;
}


void pop(){
    if(size == 0){
        printf("0\n");
        return;
    }
    printf("%d\n", mh[0]);
    swap(&mh[size-1], &mh[0]);
    int current_index = 0;
    mh[--size] = 0;
    while(current_index < size) {
        int left_child_index = get_left_child_index(current_index);
        int right_child_index = get_right_child_index(current_index);
        if(left_child_index >= size) {
            break;
        }else if(right_child_index >= size) {
            if(mh[left_child_index] > mh[current_index]) {
                swap(&mh[left_child_index], &mh[current_index]);
                break;
            }else {
                break;
            }
        }else {
            if(mh[current_index] < mh[left_child_index] && mh[current_index] < mh[right_child_index]) {
                if(mh[left_child_index] > mh[right_child_index]){
                    swap(&mh[left_child_index], &mh[current_index]);
                    current_index = left_child_index;
                }
                else{
                    swap(&mh[right_child_index], &mh[current_index]);
                    current_index = right_child_index;
                }
            }
            else if(mh[current_index] < mh[left_child_index]){
                swap(&mh[left_child_index], &mh[current_index]);
                current_index = left_child_index;
            }
            else if(mh[current_index] < mh[right_child_index]){
                swap(&mh[right_child_index], &mh[current_index]);
                current_index = right_child_index;
            }
            else{
                break;
            }
        }
    }
}


void print_mh(){
    int i = 0;
    for(i=0; i<size; i++){
        printf("%d th : %d ", i, mh[i]);
    }
    printf("\n");
}


int main(){

    int n;
    int input;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        // print_mh();
        scanf("%d", &input);
        if(input == 0) {
            pop();
        }else {
            push(input);
        }
    }
    return 0;
}
