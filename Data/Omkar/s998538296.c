#include <stdio.h>

int main(){
    int rodadas, somado, numero = 1;
    scanf("%d", &rodadas);
    scanf("%d", &somado);
    for (int i = 0; i < rodadas; i++){
        if (2*numero <= numero+somado)
            numero = 2*numero;
        else
            numero =  numero + somado;
    }
    printf("%d\n", numero);
    return 0;
}
