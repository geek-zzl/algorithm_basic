#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vector{
    int *data;
    int length, size;
} Vector;

Vector * init(int n){
    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->data = (int *)malloc(sizeof(int) * n);
    vec->length = 0;
    vec->size = n;
    return vec;
}

int expend(Vector * vec){

    int new_size = vec->size * 2;
    int *p = (int *)realloc(vec->data, new_size);
    

    if (p == NULL) return 0;
    vec->data = p;
    vec->size = new_size;
    return 1;
}

int insert(Vector *vec, int ind, int val){

    if (vec == NULL) return 0;
    if (vec->length == vec->size){
        if(!expend(vec)) return 0;
        printf("expend vector size to %d\n", vec->size);
    }
    if (ind < 0 || ind > vec->length) return 0;

    for (int i = vec->length; i > ind; i--){
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 1;

}

int erase(Vector *vec, int ind){

    if (vec == NULL) return 0;
    if (vec->length == 0) return 0;
    if (ind < 0 || ind >= vec->length)  return 0;

    for (int i = ind; i < vec->length; i++){
        vec->data[i] = vec->data[i+1];
    }
    
    vec->length -= 1;
    return 1;

}

void output(Vector * vec){
    printf("Vector[%d] = {", vec->length);
    for (int i = 0; i < vec->length; i++){
        if(i)  printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("}\n");
}

void clear(Vector *vec){
    if (vec == NULL) return ;
    free(vec->data);
    free(vec);
    return ;
}


int main(){
    // 随机化测试过程
    srand(time(0));
    #define MAX_OP 20
    Vector *vec = init(1);

    int op, ind ,val;
    
    for (int i = 0; i < MAX_OP; i++){
        op = rand() % 4;
        ind = rand() % (vec->length + 2);
        val = rand() % 100;
        switch (op){
            case 0:
            case 1:
            case 2:{
                printf("insert %d at %d to vector = %d\n", \
                val, ind, insert(vec, ind, val));
                
            }break;
            case 3:{
                printf("erase item at %d from vector = %d\n", ind, erase(vec, ind));
            }   
            break;
        }
        output(vec);
        printf("\n");
    }
    

    return 0;
}