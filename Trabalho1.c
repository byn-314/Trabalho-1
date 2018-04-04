#include <stdio.h>
#include <stdlib.h>

typedef struct elemento_int{
  int num;
  struct elemento_int * proximo;
}t_elemento_int;

typedef struct elemento_char{
  char simb;
  struct elemento_char * depois;
}t_elemento;

typedef struct lista_int{
  t_elemento_int * inicio;
  t_elemento_int * fim;
}t_lista_int;

typedef struct lista_char{
  t_elemento_char * comeco;
  t_elemento_char * final;
}t_lista_char;

typedef struct pilha_int{
  t_lista_int * l;
}t_pilha_int;

typedef struct pilha_char{
  t_lista_char * l;
}t_pilha_char;

int lista_int_Vazia(t_lista_int * l)
{
  if(l->inicio == NULL)
  {
    return 1;
  }
  return 0;
}

int lista_char_Vazia(t_lista_char * l)
{
  if(l->comeco == NULL)
  {
    return 1;
  }
  return 0;
}

t_lista_int *criaListaInt()
{
  t_lista_int *l = (t_lista_int *)malloc(sizeof(t_lista_int));
  l->inicio = NULL;
  l->fim = NULL;
  return l;
}

t_lista_char *criaListaChar()
{
  t_lista_char *l = (t_lista_char *)malloc(sizeof(t_lista_char));
  l->comeco = NULL;
  l->final = NULL;
  return l;
}

void insereInicioInt(int n, t_lista_int * l)
{
  t_elemento_int *novo = (t_elemento_int *)malloc(sizeof(t_elemento_int));
  novo->num = n;
  novo->proximo = l->inicio;
  l->inicio = novo;
  if(l->fim == NULL)
  {
    l->fim = novo;
  }
}

void insereInicioChar(int num, t_lista_char * l)
{
  t_elemento_char *novo = (t_elemento_char *)malloc(sizeof(t_elemento_char));
  novo->simb = num;
  novo->depois = l->comeco;
  l->comeco = novo;
  if(l->final == NULL)
  {
    l->final = novo;
  }
}

int retiraInicioInt(t_lista_int * l)
{
  if(lista_int_Vazia(l))
  {
    return -1;
  }
  int n = l->inicio->num;
  t_elemento_int *remove = l->inicio;
  l->inicio = l->inicio->proximo;
  free(remove);
  if(l->inicio == NULL)
  {
    l->fim = NULL;
  }
  return n;
}

char retiraInicioChar(t_lista_char * l)
{
  if(lista_char_Vazia(l))
  {
    return -1;
  }
  char c = l->comeco->simb;
  t_elemento_char *remove = l->comeco;
  l->comeco = l->comeco->depois;
  free(remove);
  if(l->comeco == NULL)
  {
    l->final = NULL;
  }
  return c;
}

int pilha_int_Vazia(t_pilha_char * p)
{
  return lista_int_Vazia(p->l);
}

int pilha_char_Vazia(t_pilha_char * p)
{
  return lista_char_Vazia(p->l);
}

t_pilha *criaPilhaInt()
{
  t_pilha_int *p = (t_pilha_int *)malloc(sizeof(t_pilha_int));
  p->l = criaListaInt();
  return p;
}

t_pilha *criaPilhaChar()
{
  t_pilha_char *p = (t_pilha_char *)malloc(sizeof(t_pilha_char));
  p->l = criaListaChar();
  return p;
}

void empilhaInt(int n, t_pilha * p)
{
  insereInicioInt(n, p->l);
}

void empilhaChar(char c, t_pilha * p)
{
  insereInicioChar(c, p->l);
}

int desempilhaInt(t_pilha_int * p)
{
  return retiraInicioInt(p->l);
}

char desempilhaChar(t_pilha_char * p)
{
  return retiraInicioChar(p->l);
}

void limpar_tela()
{
  system("cls || clear");
}

int main(int argc, char const *argv[])
{
  t_pilha *p = criaPilha();
  return 0;
}