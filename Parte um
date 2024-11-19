#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// ADM
const char cpf_gerente[] = "51616468882";
const char senha_gerente[] = "admin1";

// Estruturas e variáveis de investidores
char cpfs[10][12] = {
    "12345678910",
    "22124085611",
    "52124009312",
    "22124071613"
};

char senhas[10][7] = {
    "123456",
    "234567",
    "345678",
    "456789"
};

char nomes[10][20] = {
    "Analiza Julia",
    "Ana Lima",
    "Elizabeth Kruger",
    "Julia Barreto"
};

// Variáveis de saldo
float reais[10] = {0.00, 0.00, 0.00, 0.00};
float bitcoin[10] = {0.00, 0.00, 0.00, 0.00};
float ethereum[10] = {0.00, 0.00, 0.00, 0.00};
float ripple[10] = {0.00, 0.00, 0.00, 0.00};
int total_investidores = 4;

// Funções de administração
void cadastrar_investidor();
void excluir_investidor();
void menu_gerente();

// Funções principais
void efetuar_login();
void menu_completo(int cliente);

// Cadastar novos investidores
void cadastrar_investidor() {
    if (total_investidores >= 10) {
        printf("Não é possível cadastrar novos investidores.\n");
        return;
    }

    printf("Digite o CPF do novo investidor: ");
    scanf("%s", cpfs[total_investidores]);
    printf("Digite a senha do novo investidor: ");
    scanf("%s", senhas[total_investidores]);
    printf("Digite o nome do novo investidor: ");
    scanf(" %[^\n]%*c", nomes[total_investidores]);

    reais[total_investidores] = 0.0;
    bitcoin[total_investidores] = 0.0;
    ethereum[total_investidores] = 0.0;
    ripple[total_investidores] = 0.0;

    total_investidores++;
    printf("Investidor cadastrado.\n");
}

// Exclusão de investidores
void excluir_investidor() {
    char cpf_excluir[12];
    printf("Digite o CPF do investidor a ser deletado: ");
    scanf("%s", cpf_excluir);

    int encontrado = -1;
    for (int i = 0; i < total_investidores; i++) {
        if (strcmp(cpfs[i], cpf_excluir) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf(" O Investidor não existe.\n");
        return;
    }

    for (int i = encontrado; i < total_investidores - 1; i++) {
        strcpy(cpfs[i], cpfs[i + 1]);
        strcpy(senhas[i], senhas[i + 1]);
        strcpy(nomes[i], nomes[i + 1]);
        reais[i] = reais[i + 1];
        bitcoin[i] = bitcoin[i + 1];
        ethereum[i] = ethereum[i + 1];
        ripple[i] = ripple[i + 1];
    }

    total_investidores--;
    printf("Investidor excluído.\n");
}

// Menu ADM
void menu_gerente() {
    int opcao;
    while (1) {
        printf("== Menu administrador ==\n");
        printf("1. Cadastrar novo investidor\n");
        printf("2. Excluir investidor\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_investidor();
                break;
            case 2:
                excluir_investidor();
                break;
            case 3:
                return;
            default:
                printf("Inválido.\n");
        }
    }
}

// Login
void efetuar_login() {
    char cpf_login[12];
    char senha_login[7];

    printf("Digite seu CPF: ");
    scanf("%s", cpf_login);
    printf("Digite sua senha: ");
    scanf("%s", senha_login);

    if (strcmp(cpf_login, cpf_gerente) == 0 && strcmp(senha_login, senha_gerente) == 0) {
        printf("Gerenciamento\n");
        menu_gerente();
        return;
    }

    for (int i = 0; i < total_investidores; i++) {
        if (strcmp(cpfs[i], cpf_login) == 0 && strcmp(senhas[i], senha_login) == 0) {
            printf("Bem-vindo, %s!\n", nomes[i]);
            menu_completo(i);
            return;
        }
    }

    printf("CPF ou senha inválidos.\n");
}

int main() {
    efetuar_login();
    return 0;
}
