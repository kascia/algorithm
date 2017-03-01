#include <cstdio>
#include <cstdlib>

typedef struct _TreeNode{

    int x;
    struct _TreeNode *l;
    struct _TreeNode *r;
}Node;

typedef struct _Tree{
    Node* head;
}Tree;


void add_node(Tree* tree, int x);
int exist(Tree* tree, int x);

int main(){
    int n, m;
    Tree *bst = (Tree*)malloc(sizeof(Tree));

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        add_node(bst, x);
    }
    scanf("%d", &m);
    for(int i=0; i<m; i++){
        int y;
        scanf("%d", &y);
        int ans = exist(bst, y);
        printf("%d\n", ans);
    }
    return 0;
}

void add_node(Tree* tree, int x){
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->x = x;
    new_node->r = NULL;
    new_node->l = NULL;
    if(tree->head == NULL){
        tree->head = new_node;
    }
    else{
        Node* cur_node = tree->head;
        while(true){
            if(x > cur_node->x){
                if(cur_node->r == NULL){
                    cur_node->r = new_node;
                    return;
                }
                cur_node = cur_node->r;
            }
            else{
                if(cur_node->l == NULL){
                    cur_node->l = new_node;
                    return;
                }
                cur_node = cur_node->l;
            }
        }
    }
}


int exist(Tree* tree, int x){
    if(tree->head == NULL){
        return 0;
    }
    else{
        Node* cur_node = tree->head;
        while(cur_node != NULL){
            if(x > cur_node->x){
                cur_node = cur_node->r;
            }
            else if(x < cur_node->x){
                cur_node = cur_node->l;
            }
            else{
                return 1;
            }

        }
    }
    return 0;
}


