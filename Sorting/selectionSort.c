#include <stdio.h>

int main(){

    int arr[] = {4,3,6,8,9,5,2,1,0,7};

    int length = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i<length-1; i++){
        int min_pos = i;
        for(int j = i+1; j<length; j++){
            if(arr[j] < arr[min_pos]){
                min_pos = j;
            }
        }
        if(min_pos != i){
            int temp = arr[i];
            arr[i] = arr[min_pos];
            arr[min_pos] = temp;
        }
    }
    for(int i=0; i<10; i++){
        printf("%d\t", arr[i]);
    }

    return 0;

}
