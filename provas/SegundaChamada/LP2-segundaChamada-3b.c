#include <stdio.h>

void inverter(int val){
    while(val){
        printf("%d", val % 10);
        val /= 10;
    }
}

int main(){
    int val;
    printf("Digite um valor inteiro: ");
    scanf("%d", &val);
    inverter(val);
    return 0;
}