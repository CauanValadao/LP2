#include <stdio.h>

void inverter(int val){
    if(val){
        printf("%d", val % 10);
        inverter(val / 10);
    }
}

int main(){
    int val;
    printf("Digite um valor inteiro: ");
    scanf("%d", &val);
    inverter(val);
    return 0;
}