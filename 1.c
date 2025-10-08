#include <stdio.h>

int main(){
    int a = 6;
    int b = 6;
    int c = a / b;
    for(int i=0; i<5; i++){
        c+=i;
    }
    printf("%d", c);
    return 0;
}
