#include <stdio.h>

int main(){
    int a = 60;
    int b = 30;
    int c = a / b;
    for(int i=0; i<5; i++){
        c+=i;
    }
    printf("%d", c);
    return 0;
}

