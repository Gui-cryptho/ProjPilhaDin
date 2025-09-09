//Arquivo PilhaDin.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, struct aluno *al);
int insere_Pilha(Pilha* pi, struct aluno al);
int remove_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);

//ex1
void push_2(Pilha *pi,struct aluno al[]);
void pop_2(Pilha *pi);

//ex2
void pop_n(Pilha *pi,int n_desempilhar);

//ex3
Pilha *pi_clone(Pilha *pi);

//ex4
int avarage_pi(Pilha *pi);

//ex5
void comparador_pi(Pilha *pi, Pilha *pi_two);

//ex6
struct elemento_ex6 {
    char letra;
    struct elemento_ex6 *prox;
};

typedef struct elemento_ex6 Palavra;

void imprimir_ex6(Palavra *palindromo);
Palavra *push_ex6(Palavra *p, char c);
void palindromo(char *string);

//ex7
void numeros_pares_impares(Pilha *pi);

//ex8
struct elemento_ex8
{
    char c;
    struct elemento_ex8 *prox;
};

typedef struct elemento_ex8 cadeia;

void imprimir_ex8(cadeia *cad);
void cadeia_shape(char *string);

//ex9
struct elemento_ex9{
char num;
struct elemento_ex9 *prox;
};

typedef struct elemento_ex9 binomo;

void menu();
