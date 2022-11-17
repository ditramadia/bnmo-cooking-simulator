#include<stdio.h>
#include "wordmachine.c"
#include "tree.c"


int main(){
    STARTWORD();
    int length;
    length = wordToInteger();
    // printf("%d\n",x);
    // ADVWORD();
    // x = wordToInteger();
    // printf("%d\n",x);
    int arr[length+5][100];
    
    ADVWORD();
    int mode = 0, x = 0;
    while(retval != EOF){
        // printf("mode = %d\n", mode);
        if(mode == 0){
            mode = 1;
            int temp = wordToInteger();
            // printf("temp = %d\n", temp);
            arr[x/3][0] = temp;
            ADVWORD();
        }
        else if(mode == 1){
            mode = 2;
            int temp = wordToInteger();
            // printf("temp = %d\n", temp);
            arr[x/3][1] = temp;
            ADVWORD();
        }
        else if(mode == 2){
            mode = 0;
            for(int i=2;i<2+arr[x/3][1]; i++){
                int temp = wordToInteger();
                arr[x/3][i] = temp;
                // printf("temp = %d\n", temp);
                ADVWORD();
            }
        }
        x++;
    }
    List treeResep[length][100];
    createTree(&treeResep);
    tree(arr,treeResep,length);

    printf("%d",INFO(NEXT(FIRST(treeResep[1][0]))));
}