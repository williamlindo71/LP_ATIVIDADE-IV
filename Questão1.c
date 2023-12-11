#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define TAM 3

struct contatos
{
    char nome[500];
    char numeroTelefone[500];
    char email[500];
};

void nomeBuscado(struct contatos contato[], char *opcao)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        if (strcmp(contato[i].nome, nomeBuscado) == 0)
        {
            printf("\nTelefone de %s: %s", contato[i].nome, contato[i].numeroTelefone);
            break;
        }
    }
    printf("\nContato não encontrado.");
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct contatos contato[TAM];
    int i;
    char opcao[500];

    for (i = 0; i < TAM; i++)
    {
        printf("Digite o nome do contato :\n");
        gets(contato[i].nome);
        printf("Digite o numero de telefone:\n");
        gets(contato[i].numeroTelefone);
        printf("Digite o Email:");
        gets(contato[i].email);
    }

    fflush(stdin);
    printf("\nDigite o nome do contato que deseja buscar:");
    gets(opcao);

    nomeBuscado(contato, opcao);
    return 0;
}
