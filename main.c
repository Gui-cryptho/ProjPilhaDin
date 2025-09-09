#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"
int main()
{
    struct aluno a[4] = {{2,"Andre",9.5,7.8,8.5},
        {4,"Ricardo",7.5,8.7,6.8},
        {1,"Bianca",9.7,6.7,8.4},
        {3,"Ana",5.7,6.1,7.4}

    };

    struct aluno a2[2] =
    {
        {9,"Davi",8.0,7.3,6,5},
        {11,"Gustavo", 8.6,7.8,7.2}
    };

    Pilha* pi = cria_Pilha();
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));
    int i;
    for(i=0; i < 4; i++)
        insere_Pilha(pi,a[i]);

    imprime_Pilha(pi);
    printf("Tamanho: %d\n\n\n\n",tamanho_Pilha(pi));



    printf("Depois do push_2:\n\n");
    push_2(pi, a2);

    imprime_Pilha(pi);

    printf("\n\n\n\n\n\n");
    pop_n(pi, 3);
    imprime_Pilha(pi);
    printf("Tamanho apos pop_n(5): %d\n", tamanho_Pilha(pi));

    printf("\n\n");
    comparador_pi(pi, pi);

    printf("\n\n");
    numeros_pares_impares(pi);

    printf("\n\n");
    avarage_pi(pi);

    printf("\n\n\n");
    Pilha *pi_two = pi_clone(pi);
    imprime_Pilha(pi_two);

    imprime_Pilha(pi);

    printf("\n\n\n");
    palindromo("osso");
    printf("\n");
    palindromo("Guilherme");

    printf("\n\n\n");
    cadeia_shape("ABABBA");

    system("pause");
    return 0;
}

