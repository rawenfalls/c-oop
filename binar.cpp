#include <cstdio>
int main(){
    for(int i = 0; i<8; i++){
        printf("%d\n",0b10010111 & (1<<i));
    }
    return 0 ;
}