#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

#define MAX_CRIPTOMOEDAS 100
#define MAX_INVESTIDORES 100

// Estrutura para criptomoedas
typedef struct {
    char nome[50];
    float cotacao_inicial;
    float taxa_compra;
    float taxa_venda;
} Criptomoeda;

Criptomoeda criptomoedas[MAX_CRIPTOMOEDAS];
int total_criptomoedas = 0;

// Estrutura para Investidores
typedef struct {
    char cpf[12];
    char nome[50];
    char senha[50];
    float saldo_reais;
    float saldo_bitcoin;
    float saldo_ethereum;
    float saldo_ripple;
} Investidor;

Investidor investidores[MAX_INVESTIDORES];
int total_investidores = 0;

// ADM
const char cpf_gerente[] = "1";
const char senha_gerente[] = "a";

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

// Funções de administração
void cadastrar_investidor();
void excluir_investidor();
void menu_gerente();

// Funções principais
void efetuar_login();
void menu_completo(int cliente);

// Núcleo da lógica de interação
void menu_completo(int cliente) {
    int opcao_menu;

    // Laço infinito até que o cliente decida deslogar
    while (1) {
        printf("==----------------------------==\n");
        printf("Menu: \n");
        printf("1. Consultar saldo\n");
        printf("2. Consultar extrato\n");
        printf("3. Depositar\n");
        printf("4. Sacar\n");
        printf("5. Comprar criptomoedas\n");
        printf("6. Vender criptomoedas\n");
        printf("7. Atualizar cotação\n");
        printf("8. Sair\n");
        printf("==----------------------------==\n");
        printf("Escolha sua opção: ");
        scanf("%d", &opcao_menu);

        // Executa a operação escolhida
        switch (opcao_menu) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                return; // Sai do laço e retorna à função 'efetuar_login'
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    }
}

// CADASTRO DE INVESTIDOR
void cadastrar_investidor() {
    if (total_investidores >= MAX_INVESTIDORES) {
        printf("Não foi possível cadastrar novos investidores.\n");
        return;
    }

    Investidor novo_investidor;

    printf("Digite o nome do novo investidor: ");
    scanf(" %[^\n]%*c", novo_investidor.nome);
    printf("Digite o CPF do novo investidor: ");
    scanf("%s", novo_investidor.cpf);
    printf("Digite a senha do novo investidor: ");
    scanf("%s", novo_investidor.senha);
    
    novo_investidor.saldo_reais = 0.0;
    novo_investidor.saldo_bitcoin = 0.0;
    novo_investidor.saldo_ethereum = 0.0;
    novo_investidor.saldo_ripple = 0.0;

    investidores[total_investidores] = novo_investidor;
    total_investidores++;
    printf("Investidor cadastrado com sucesso.\n");
}

// EXCLUSÃO DE INVESTIDOR
void excluir_investidor() {
    char confirmacao;
    char cpf_excluir[12];
    printf("Digite o CPF do investidor a ser deletado: ");
    scanf("%s", cpf_excluir);

    int encontrado = -1;
    for (int i = 0; i < total_investidores; i++) {
        if (strcmp(investidores[i].cpf, cpf_excluir) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf(" O Investidor não foi encontrado.\n");
        return;
    }

    printf("\nInvestidor encontrado:\n");
    printf("Nome: %s\n", investidores[encontrado].nome);
    printf("CPF: %s\n", investidores[encontrado].cpf);
    printf("Saldo em Reais: %.2f\n", investidores[encontrado].saldo_reais);
    printf("Saldo em Bitcoin: %.4f\n", investidores[encontrado].saldo_bitcoin);
    printf("Saldo em Ethereum: %.4f\n", investidores[encontrado].saldo_ethereum);
    printf("Saldo em Ripple: %.4f\n", investidores[encontrado].saldo_ripple);
    while (getchar() != '\n');
    
    printf("\nDeseja realmente excluir o investidor? (S/N): ");
    scanf("%c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's'){
        for (int i = encontrado; i < total_investidores - 1; i++) {
            investidores[i] = investidores[i + 1];
        }
        total_investidores--;
        printf("Investidor excluído com sucesso.\n");
    } else if (confirmacao == 'N' || confirmacao == 'n'){
        printf("Exclusão cancelada.\n");
    } else {
        printf("Opção inválida.\n");
    }
    
}

// CADASTRO DE CRIPTOMOEDAS
void cadastrar_criptomoedas(){
    if (total_criptomoedas >= MAX_CRIPTOMOEDAS) {
        printf("Limite de cadastro de criptomoedas atingido.\n");
        return;
    }
    
    Criptomoeda nova;
    printf("Digite o nome da nova criptomoeda: ");
    scanf(" %[^\n]", nova.nome);
    printf("Digite a cotação inicial: ");
    scanf("%f", &nova.cotacao_inicial);
    printf("Digite a taxa de compra: ");
    scanf("%f", &nova.taxa_compra);
    printf("Digite a taxa de venda: ");
    scanf("%f", &nova.taxa_venda);

    criptomoedas[total_criptomoedas] = nova;
    total_criptomoedas++;

    printf("Criptomoeda cadastrada com sucesso!\n");  
}

// EXCLUSÃO DE CRIPTOMOEDAS
void excluir_criptomoeda(){
    char nome_excluir[50];
    char confirmacao;

    printf("Digite o nome da criptomoeda a ser excluída: ");
    scanf(" %[^\n]", nome_excluir);

    int encontrado = -1;
    for (int i = 0; i < total_criptomoedas; i++) {
        if (strcmp(criptomoedas[i].nome, nome_excluir) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Criptomoeda não encontrada.\n");
        return;
    }

    printf("\nCriptomoeda encontrada:\n");
    printf("Nome: %s\n", criptomoedas[encontrado].nome);
    printf("Cotação inicial: %.2f\n", criptomoedas[encontrado].cotacao_inicial);
    printf("Taxa de compra: %.2f\n", criptomoedas[encontrado].taxa_compra);
    printf("Taxa de venda: %.2f\n", criptomoedas[encontrado].taxa_venda);

    // Limpa buffer antes de ler confirmação
    while (getchar() != '\n');
    printf("\nDeseja realmente excluir a criptomoeda? (S/N): ");
    scanf("%c", &confirmacao);

    if (confirmacao == 'S' || confirmacao == 's') {
        for (int i = encontrado; i < total_criptomoedas - 1; i++) {
            criptomoedas[i] = criptomoedas[i + 1];
        }
        total_criptomoedas--;
        printf("Criptomoeda excluída com sucesso.\n");
    } else if (confirmacao == 'N' || confirmacao == 'n') {
        printf("Exclusão cancelada.\n");
    } else {
        printf("Opção inválida.\n");
    }
}

// CONSULTA DE SALDO
void consultar_saldo(){
    char cpf_consultar[12];
    printf("Digite o CPF do investidor: ");
    scanf("%s", cpf_consultar);

    int encontrado = -1;
    for (int i = 0; i < total_investidores; i++) {
        if (strcmp(investidores[i].cpf, cpf_consultar) == 0) {
            encontrado = i;
            break;
        }
    }

    if (encontrado == -1) {
        printf("Investidor não encontrado.\n");
        return;
    }

    printf("\nSaldo do Investidor:\n");
    printf("CPF: %s\n", investidores[encontrado].cpf);
    printf("Saldo em Reais: %.2f\n", investidores[encontrado].saldo_reais);
    printf("Saldo em Bitcoin: %.4f\n", investidores[encontrado].saldo_bitcoin);
    printf("Saldo em Ethereum: %.4f\n", investidores[encontrado].saldo_ethereum);
    printf("Saldo em Ripple: %.4f\n", investidores[encontrado].saldo_ripple);
}

void sair_administrador() {
    char escolha;

    printf("Você deseja sair do modo administrador? (S/N): ");
    scanf(" %c", &escolha);

    if (escolha == 'S' || escolha == 's') {
        printf("Saindo do modo administrador...\n");
        efetuar_login();  // Chama a função de login após o administrador sair
    } else if (escolha == 'N' || escolha == 'n') {
        printf("Retornando ao modo administrador...\n");
    } else {
        printf("Opção inválida.\n");
    }
}

// Menu ADM
void menu_gerente() {
    int opcao;
    while (1) {
        printf("\n== Menu administrador ==\n");
        printf("1. Cadastrar novo investidor\n");
        printf("2. Excluir investidor\n");
        printf("3. Cadastrar criptomoedas\n");
        printf("4. Excluir criptomoeda\n");
        printf("5. Consultar saldo\n");
        printf("6. Sair\n");

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
                cadastrar_criptomoedas();
                break;
            case 4:
                excluir_criptomoeda();
                break;
            case 5:
                consultar_saldo();
                break;
            case 6:
                sair_administrador();
                break;
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
        if (strcmp(investidores[i].cpf, cpf_login) == 0 && strcmp(investidores[i].senha, senha_login) == 0) {
            printf("Bem-vindo, %s!\n", investidores[i].nome);
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
