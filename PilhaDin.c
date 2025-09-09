#include <stdio.h>
#include <stdlib.h>
#include "PilhaDin.h" //inclui os Prot�tipos

//Defini��o do tipo Pilha
struct elemento
{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Pilha* cria_Pilha()
{
    Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
    if(pi != NULL)
        *pi = NULL;
    return pi;
}

void libera_Pilha(Pilha* pi)
{
    if(pi != NULL)
    {
        Elem* no;
        while((*pi) != NULL)
        {
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }
        free(pi);
    }
}

int consulta_topo_Pilha(Pilha* pi, struct aluno *al)
{
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    *al = (*pi)->dados;
    return 1;
}

int insere_Pilha(Pilha* pi, struct aluno al)
{
    if(pi == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*pi);
    *pi = no;
    return 1;
}

int remove_Pilha(Pilha* pi)
{
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->prox;
    free(no);
    return 1;
}

int tamanho_Pilha(Pilha* pi)
{
    if(pi == NULL)
        return 0;
    int cont = 0;
    Elem* no = *pi;
    while(no != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int Pilha_cheia(Pilha* pi)
{
    return 0;
}

int Pilha_vazia(Pilha* pi)
{
    if(pi == NULL)
        return 1;
    if(*pi == NULL)
        return 1;
    return 0;
}

void imprime_Pilha(Pilha* pi)
{
    if(pi == NULL)
        return;
    Elem* no = *pi;
    while(no != NULL)
    {
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n",
               no->dados.n1,
               no->dados.n2,
               no->dados.n3);
        printf("-------------------------------\n");
        no = no->prox;
    }
}


/*
1) Fa�a um programa que tenha uma nova fun��o chamada pop2() para
desempilhar dois elementos da pilha e uma outra fun��o chamada
push2() para empilhar 2 elementos a partir do topo da pilha. N�o devem
ser utilizadas as fun��es de push e pop j� existentes.
*/

void pop_2(Pilha *pi)
{
    for(int i = 0; i < 2; i++)
    {
        Elem *no;

        no = *pi;
        *pi = no->prox;

        free(no);
    }
}

void push_2(Pilha *pi,struct aluno al[])
{

    for(int i = 0; i < 2; i++)
    {
        Elem *no1 = (Elem*)malloc(sizeof(Elem));
        if(!no1)
        {
            printf("Erro na Alocacao");
            return;
        }


        no1->dados = al[i];
        no1->prox = *pi;
        *pi = no1;
    }

}

/*
2) Fa�a um programa que tenha uma nova fun��o chamada popN() para
desempilhar n elementos a partir do topo da pilha. N�o devem ser
utilizadas as fun��es de push e pop j� existentes.
*/

void pop_n(Pilha *pi,int n_desempilhar)
{
    for(int i = 0; i <= n_desempilhar; i++)
    {

        Elem *no;

        no = *pi;
        *pi = no->prox;

        free(no);
    }
}

/*
3) Fa�a um programa que utilizando apenas as fun��es desenvolvidas
para a pilha, implemente uma fun��o que receba uma pilha como
par�metro e retorna como resultado uma c�pia dessa pilha. Essa fun��o
deve obedecer ao prot�tipo:
Pilha *pilha_copia (Pilha* p);
Obs.: Ao final da fun��o copia_pilha, a pilha p recebida como par�metro
deve estar no mesmo estado em que ela come�ou a fun��o.
*/

Pilha *pi_clone(Pilha *pi)
{

    Pilha *pi_clone = cria_Pilha();
    Pilha *pi_aux = cria_Pilha();
    Elem *no = *pi;
    if(!no)
        return;

    while(no != NULL)
    {
        insere_Pilha(pi_aux, no->dados);
        no = no->prox;
    }

    no = *pi_aux;
    while(no != NULL)
    {
        insere_Pilha(pi_clone, no->dados);
        no = no->prox;
    }

    libera_Pilha(pi_aux);
    return pi_clone;
}

/*
4) Dado uma pilha que armazene n�meros, escreva uma fun��o que
forne�a o maior, o menor e a m�dia aritm�tica dos elementos da pilha.

*/

int avarage_pi(Pilha *pi)
{
    Elem *no = *pi;
    float media, maior, menor;

    while(no != NULL)
    {
        media = (no->dados.n1 + no->dados.n2 + no->dados.n3) / 3;
        printf("Aluno: %s\n", no->dados.nome);
        printf("Media %.2f\n", media);

        if (no->dados.n1 >= no->dados.n2 && no->dados.n1 >= no->dados.n3)
        {
            maior = no->dados.n1;
        }
        else if (no->dados.n2 >= no->dados.n1 && no->dados.n2 >= no->dados.n3)
        {
            maior = no->dados.n2;
        }
        else
        {
            maior = no->dados.n3;
        }

        if (no->dados.n1 <= no->dados.n2 && no->dados.n1 <= no->dados.n3)
        {
            menor = no->dados.n1;
        }
        else if (no->dados.n2 <= no->dados.n1 && no->dados.n2 <= no->dados.n3)
        {
            menor = no->dados.n2;
        }
        else
        {
            menor = no->dados.n3;
        }

        printf("Maior nota: %.2f\n", maior);
        printf("Menor nota: %.2f\n\n", menor);


        no = no->prox;
    }


}

/*
5) Fa�a um programa que utilizando apenas as fun��es desenvolvidas
para a pilha, implemente uma fun��o que teste se duas pilhas s�o iguais
ou n�o.
*/

void comparador_pi(Pilha *pi, Pilha *pi_two)
{
    Elem *no = *pi;
    Elem *no_two = *pi_two;

    while(no != NULL && no_two != NULL)
    {
        if(no->dados.matricula != no_two->dados.matricula)
        {
            printf("As pilhas s�o diferentes\n");
            return;
        }
        no = no->prox;
        no_two = no_two->prox;
    }

    printf("As pilhas sao iguais\n");
}

/*
6) Escreva um programa solicite ao usu�rio uma sequ�ncia de caracteres
sem limite de tamanho m�ximo e realize as seguintes opera��es usando
uma pilha:
a) Imprimir o texto na ordem inversa;
b) Verificar se o texto � um pal�ndromo, ou seja, se o texto � escrito da
mesma maneira de frente para tr�s e de tr�s para frente. Ignore espa�os
e pontos.
*/

void imprimir_ex6(Palavra *palindromo)
{
    Palavra *no = palindromo;
    while (no != NULL)
    {
        printf("%c ", no->letra);
        no = no->prox;
    }
    printf("\n");
}

Palavra *push_ex6(Palavra *p, char c)
{
    Palavra *no = (Palavra*) malloc(sizeof(Palavra));
    if (no == NULL) return p;

    no->letra = c;
    no->prox = p;
    return no;
}

void palindromo(char *string)
{
    Palavra *palindromo_main = NULL;
    Palavra *palindromo_aux = NULL;
    Palavra *no;


    for (int i = 0; i < strlen(string); i++)
    {
        no = (Palavra*) malloc(sizeof(Palavra));
        if (no == NULL) return;

        no->letra = string[i];
        no->prox = palindromo_main;
        palindromo_main = no;
    }


    no = palindromo_main;
    while (no != NULL)
    {
        palindromo_aux = push_ex6(palindromo_aux, no->letra);
        no = no->prox;
    }

    printf("Pilha principal:\n");
    imprimir_ex6(palindromo_main);

    printf("Pilha auxiliar:\n");
    imprimir_ex6(palindromo_aux);

    // compara��o das duas pilhas
    Palavra *n1 = palindromo_main;
    Palavra *n2 = palindromo_aux;

    int cont = 0, tam = strlen(string);

    while (n1 != NULL && n2 != NULL)
    {
        if (n1->letra == n2->letra)
        {
            cont++;
        }
        n1 = n1->prox;
        n2 = n2->prox;
    }

    if (cont == tam)
    {
        printf("'%s' eh palindromo!\n", string);
    }
    else
    {
        printf("'%s' nao eh palindromo!\n", string);
    }
}

/*
7) Fa�a uma fun��o para retornar o n�mero de elementos da pilha que
possuem valor par e o n�mero de elementos com valor �mpar.
*/

void numeros_pares_impares(Pilha *pi)
{
    Elem *no = *pi;
    int impares = 0;
    int pares = 0;

    while(no != NULL)
    {
        if(no->dados.matricula % 2 == 0)
            pares++;
        else
            impares++;

        no = no->prox;
    }

    printf("Numeros pares: %d\n", pares);
    printf("Numeros impares: %d\n", impares);
}

/*
8) Fa�a um programa para determinar se uma cadeia de caracteres (string)
� da forma:
x C y
onde x e y s�o cadeias de caracteres compostas por letras �A� e/ou �B�, e y �
o inverso de x. Isto �, se x = �ABABBA�, y deve equivaler a �BABAAB�. Em
cada ponto, voc� s� poder� ler o pr�ximo caractere da cadeia.
*/

void imprimir_ex8(cadeia *cad)
{
    cadeia *no = cad;
    while(no != NULL)
    {
        printf("%c", no->c);

        no = no->prox;
    }
}

void cadeia_shape(char *string)
{
    cadeia *cad_y = NULL;
    cadeia *cad = NULL;
    cadeia *no;

    int tam = strlen(string);
    char vet[tam + 1];

    for(int i = 0; i < tam; i++)
    {
        vet[i] = toupper(string[i]);
    }
    vet[tam] = '\0';

    for(int i = tam - 1; i >= 0; i--)
    {
        cadeia *no = (cadeia*)malloc(sizeof(cadeia));
        if(!no)
            return NULL;

        no->c = vet[i];
        no->prox = cad;
        cad = no;
    }

    for (int i = tam - 1; i >= 0; i--)
    {
        cadeia *no_y = (cadeia*)malloc(sizeof(cadeia));
        if (!no_y) return NULL;

        if (vet[i] == 'A')
            vet[i] = 'B';
        else
            vet[i] = 'A';


        no_y->c = vet[i];
        no_y->prox = cad_y;
        cad_y = no_y;
    }

    imprimir_ex8(cad);
    printf("\n");
    imprimir_ex8(cad_y);
    printf("\n");

    cadeia *n1,*n2;
    int count = 0;

    n1 = cad;
    n2 = cad_y;
    while(n1 != NULL && n2 != NULL)
    {
        if(n1->c != n2->c)
            count++;

        n1 = n1->prox;
        n2 = n2->prox;
    }

    if(count == tam)
        printf("a cadeia de string eh da forma x C y\n");
    else
        printf("a cadeia de string nao eh da forma x C y\n");
}

/*
9) Fa�a um programa que apresente um menu cont�nuo com as seguintes
op��es e execute de acordo com a escolha do usu�rio.
void menu()
{
 printf("1-Inicializa pilha.\n");
 printf("2-Verifica se a pilha e vazia.\n");
 printf("3-Verifica se a pilha e cheia.\n");
 printf("4-Empilha o elemento na pilha.\n");
 printf("5-Desempilha elemento da pilha.\n");
 printf("6-Le topo de um pilha.\n");
 printf("7-Converte um numero decimal em binario.\n");
 printf("8-Sair.\n");
}
*/

void menu()
{
    printf("1 - Inicializa pilha.\n");
    printf("2 - Verifica se a pilha e vazia.\n");
    printf("3 - Verifica se a pilha e cheia.\n");
    printf("4 - Empilha o elemento na pilha.\n");
    printf("5 - Desempilha elemento da pilha.\n");
    printf("6 - Le topo de uma pilha.\n");
    printf("7 - Converte um numero decimal em binario.\n");
    printf("8 - Sair.\n");
    printf("9 - Imprimir Pilha.\n");
}


void decimal_para_binario(int num)
{
    if (num == 0)
    {
        printf("Binario: 0\n");
        return;
    }

    int temp = num;
    int tamanho = 0;
    while (temp > 0)
    {
        temp /= 2;
        tamanho++;
    }

    char bin[tamanho + 1];
    bin[tamanho] = '\0';

    for (int i = tamanho - 1; i >= 0; i--)
    {
        bin[i] = (num % 2) + '0';
        num /= 2;
    }

    printf("Binario: %s\n", bin);
}

