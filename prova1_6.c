#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct estado {
    char nome[50];
    char telefone[20];
    struct estado *anterior;
} Estado;

typedef struct contato {
    char nome[50];
    char telefone[20];
    Estado *historico;
    struct contato *proximo;
} Contato;

typedef struct {
    Contato *cabeca;
    Contato *cauda;
} Agenda;

Agenda *criar() {
    Agenda *agenda = malloc(sizeof(Agenda));
    agenda->cabeca = NULL;
    agenda->cauda = NULL;
    return agenda;
}

int vazia(Agenda *agenda) {
    return agenda->cabeca == NULL && agenda->cauda == NULL;
}

void incluirContato(Agenda *agenda, char *nome, char *telefone) {
    Contato *contato = malloc(sizeof(Contato));
    strcpy(contato->nome, nome);
    strcpy(contato->telefone, telefone);
    contato->historico = NULL;
    contato->proximo = NULL;

    if (vazia(agenda)) {
        agenda->cabeca = contato;
    }
    else {
        agenda->cauda->proximo = contato;
    }

    agenda->cauda = contato;
}

Contato *buscarContato(Agenda *agenda, char *nome) {
    Contato *contato = agenda->cabeca;

    while (contato != NULL)
    {
        if (strcmp(contato->nome, nome) == 0)
        {
            return contato;
        }
        contato = contato->proximo;
    }

    return NULL;
}

void empilharEstado(Contato *contato) {
    Estado *estado = malloc(sizeof(Estado));
    strcpy(estado->nome, contato->nome);
    strcpy(estado->telefone, contato->telefone);
    estado->anterior = contato->historico;
    contato->historico = estado;
}

int editarContato(Agenda *agenda, char *nomeAtual, char *novoNome, char *novoTelefone) {
    Contato *contato = buscarContato(agenda, nomeAtual);

    if (contato == NULL)
    {
        printf("Contato nao encontrado\n");
        return 0;
    }

    empilharEstado(contato);

    strcpy(contato->nome, novoNome);
    strcpy(contato->telefone, novoTelefone);

    return 1;
}

int desfazerEdicao(Agenda *agenda, char *nome)
{
    Contato *contato = buscarContato(agenda, nome);

    if (contato == NULL || contato->historico == NULL)
    {
        printf("Nao ha edicoes para desfazer\n");
        return 0;
    }

    Estado *estado = contato->historico;

    strcpy(contato->nome, estado->nome);
    strcpy(contato->telefone, estado->telefone);

    contato->historico = estado->anterior;
    free(estado);

    return 1;
}

int main()
{
    Agenda *agenda = criar();
    int opcao;
    char nome[50], novoNome[50], telefone[20];

    do
    {
        printf("\n1. Incluir contato\n");
        printf("2. Editar contato\n");
        printf("3. Desfazer ultima edicao\n");
        printf("4. Listar contatos\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Nome: ");
            scanf(" %[^\n]", nome);
            printf("Telefone: ");
            scanf(" %[^\n]", telefone);
            incluirContato(agenda, nome, telefone);
            break;
        case 2:
            printf("Nome do contato a editar: ");
            scanf(" %[^\n]", nome);
            printf("Novo nome: ");
            scanf(" %[^\n]", novoNome);
            printf("Novo telefone: ");
            scanf(" %[^\n]", telefone);
            editarContato(agenda, nome, novoNome, telefone);
            break;
        case 3:
            printf("Nome do contato: ");
            scanf(" %[^\n]", nome);
            desfazerEdicao(agenda, nome);
            break;
        case 4:
            Contato *contato = agenda->cabeca;

            while (contato != NULL)
            {
                printf(contato->nome);
                printf("\n");
                printf(contato->telefone);
                printf("\n");
                contato = contato->proximo;
            }
            break;
        case 0:
            printf("Cabou\n");
            break;
        default:
            printf("Opcao invalida\n");
        }
    } while (opcao != 0);
    return 0;
}

