#include <stdio.h>
#include <string.h>

#define MAX 100

struct Contato {
    char nome[50];
    char telefone[20];
    char email[50];
};

int totalContatos = 0;

void adicionarContato(struct Contato agenda[]) {
    if (totalContatos >= MAX) {
        printf("Agenda cheia!\n");
        return;
    }

    printf("\nNome: ");
    scanf(" %[^\n]", agenda[totalContatos].nome);

    printf("Telefone: ");
    scanf(" %[^\n]", agenda[totalContatos].telefone);

    printf("Email: ");
    scanf(" %[^\n]", agenda[totalContatos].email);

    totalContatos++;
    printf("Contato adicionado com sucesso!\n");
}

void listarContatos(struct Contato agenda[]) {
    int i;

    if (totalContatos == 0) {
        printf("Nenhum contato cadastrado.\n");
        return;
    }

    printf("\n=== Lista de Contatos ===\n");

    for (i = 0; i < totalContatos; i++) {
        printf("\nContato %d\n", i + 1);
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("Email: %s\n", agenda[i].email);
    }
}

void buscarContato(struct Contato agenda[]) {
    char nomeBusca[50];
    int i;
    int encontrado = 0;

    printf("\nDigite o nome para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    for (i = 0; i < totalContatos; i++) {
        if (strcmp(agenda[i].nome, nomeBusca) == 0) {
            printf("\nContato encontrado!\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato nao encontrado.\n");
    }
}

void removerContato(struct Contato agenda[]) {
    char nomeBusca[50];
    int i, j;
    int encontrado = 0;

    printf("\nDigite o nome para remover: ");
    scanf(" %[^\n]", nomeBusca);

    for (i = 0; i < totalContatos; i++) {
        if (strcmp(agenda[i].nome, nomeBusca) == 0) {
            for (j = i; j < totalContatos - 1; j++) {
                agenda[j] = agenda[j + 1];
            }
            totalContatos--;
            encontrado = 1;
            printf("Contato removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Contato nao encontrado.\n");
    }
}

int main() {
    struct Contato agenda[MAX];
    int opcao;

    do {
        printf("\n=== AGENDA ===\n");
        printf("1 - Adicionar contato\n");
        printf("2 - Listar contatos\n");
        printf("3 - Buscar contato\n");
        printf("4 - Remover contato\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarContato(agenda);
                break;
            case 2:
                listarContatos(agenda);
                break;
            case 3:
                buscarContato(agenda);
                break;
            case 4:
                removerContato(agenda);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
