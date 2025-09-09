#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h"

//Aluno:Guilherme de Sousa Brito ra:2576627

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

    // ============================
    // Menu contínuo (exercício 9)
    // ============================
    int opcao;
    struct aluno al;
    printf("\n\nPressione qualquer tecla para iniciar o menu do ex9...\n");
    getchar(); // aguarda entrada
    system("cls || clear"); // limpa console

    do
    {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // limpa buffer do teclado

        switch (opcao)
        {
        case 1:
            printf("Inicializando pilha...\n");
            Pilha *pi_ex9 = cria_Pilha();
            if(pi_ex9) printf("Pilha inicializada!\n");
            else printf("Erro ao inicializar pilha!\n");
            break;

        case 2:
            if(Pilha_vazia(pi_ex9)) printf("Pilha vazia!\n");
            else printf("Pilha nao esta vazia!\n");
            break;

        case 3:
            printf("Pilha dinamica o limite da pilha depende do seu computador!\n");
            break;

        case 4:
            printf("Empilhando elemento...\n");
            printf("Digite a matricula: ");
            scanf("%d", &al.matricula);
            getchar();
            printf("Digite o nome: ");
            fgets(al.nome, 30, stdin);
            al.nome[strcspn(al.nome, "\n")] = '\0'; // remove '\n'
            if(insere_Pilha(pi_ex9, al)) printf("Elemento empilhado!\n");
            else printf("Erro ao empilhar!\n");
            break;

        case 5:
            if(remove_Pilha(pi_ex9)) printf("Elemento desempilhado!\n");
            else printf("Erro ao desempilhar ou pilha vazia!\n");
            break;

        case 6:
            if(consulta_topo_Pilha(pi_ex9, &al))
                printf("Topo - Matricula: %d, Nome: %s\n", al.matricula, al.nome);
            else
                printf("Pilha vazia!\n");
            break;

        case 7:
            printf("Convertendo a matricula do ultimo aluno digitado...\n");
            decimal_para_binario(al.matricula);
            break;

        case 8:
            printf("Saindo do menu...\n");
            libera_Pilha(pi_ex9);
            break;
        case 9:
            printf("Imprimir Pilha");
            imprime_Pilha(pi_ex9);
            break;

        default:
            printf("Opcao invalida!\n");
        }

        // Aguarda o usuário pressionar Enter antes de limpar a tela
        printf("\nPressione Enter para continuar...");
        getchar();
        system("cls || clear"); // limpa a tela após o Enter

    }
    while (opcao != 8);

    return 0;

}

