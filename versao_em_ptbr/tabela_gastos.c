#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define uma constante MAX com valor 300
#define MAX 300

// Cria uma estrutura de dados para armazenar os atributos de cada dado e define o novo tipo "Dado"
typedef struct
{
    char data[13];
    int tipo;
    char descricao[MAX];
    char debito[MAX];
} Dado;

/* Este programa recebe 2 argumentos da linha de comando: ./tabela_gastos <nome_do_arquivo>.
   O arquivo precisa ser um .csv com separação por ponto e vírgula ';' e preferencialmente
   com títulos de cabeçalho. O programa irá solicitar o número de entrada de dados que o 
   usuário irá fazer no momento, e então gravará um por um no arquivo .csv de interesse
   linha a linha, depois encerra */
int main(int argc, char *argv[])
{
    /* Verifica se o usuário digitou o número correto de argumentos e encerra com uma 
    mensagem de erro se não */
    if (argc != 2)
    {
        printf("ERRO!\n");
        printf("Uso: ./tabela_gastos <nome_do_arquivo>\n");
        return 1;
    }

    // Abre o arquivo para acrescentar dados e atribui o endereço dele à um ponteiro do tipo FILE
    FILE *tabela = fopen(argv[1], "a");

    // Verifica se o arquivo foi aberto com sucesso e encerra com uma mensagem de erro se não
    if (tabela == NULL)
    {
        printf("ERRO!\n");
        printf("Erro de memoria\n");
        return 2;
    }

    // Cria um array de strings com cada tipo de despesa disponivel para cadastrar
    char *categorias[9] = {"Moradia", "Serviços Essenciais", "Alimentação", "Transporte", "Educação", "Lazer", "Viagens", "Medicamentos", "Plano de Saúde"};
    
    // Declara 2 variaveis, x e y, para armazenar o numero de entrada de dados e o \n, respectivamente
    int x;
    char y;
    printf("\n\t\t\t\t\tBem vindo!\n\nQuantos dados voce quer inserir na tabela? (digite um numero positivo e tecle ENTER): ");
    scanf("%i", &x);
    scanf("%c", &y);

    // Verifica se o usuário digitou um número válido de entradas e encerra com uma mensagem de erro se não
    if (x <= 0)
    {
        printf("ERRO!\nDigite um numero positivo!\n");
        return 3;
    }

    // Faz a entrada dos x dados pelo usuário no arquivo de interesse
    for (int i = 0; i < x; i++)
    {
        // Aloca memória para cada entrada que o usuário fizer
        Dado *dado = malloc(sizeof(Dado));

        // Verifica se a memória foi alocada corretamente e encerra com uma memsagem de erro se não
        if (dado == NULL)
        {
            printf("ERRO!\nErro ao alocar memória\n");
            fclose(tabela);
            return 4;
        }

        // Recebe a data da despesa em um respectivo formato, forçando o usuário a digitar exatamente igual ao modelo
        printf("\nDigite a data do gasto (escreva como no modelo: dd/mm/aaaa) e tecle ENTER: ");
        fgets(dado->data, 13, stdin);

        // Remove o \n do final da string para evitar problemas de impressão
        dado->data[strlen(dado->data) - 1] = '\0';

        // Verifica se a data foi digitada corretamente e encerra com uma mensagem de erro se não
        if (strlen(dado->data) != 10)
        {
            printf("ERRO!\nDigite corretamente\n");
            free(dado);
            fclose(tabela);
            return 5;
        }

        // Recebe o tipo de despesa que o usuário quer cadastrar
        printf("\nDigite o numero correspondente ao tipo de gasto e tecle ENTER:\n\n"
                "1 - Moradia\n"
                "2 - Servicos Essenciais\n"
                "3 - Alimentacao\n"
                "4 - Transporte\n"
                "5 - Educacao\n"
                "6 - Lazer\n"
                "7 - Viagens\n"
                "8 - Medicamentos\n"
                "9 - Plano de Saude\n\n");
        printf("Digite: ");
        scanf("%i", &dado->tipo);

        // Recebe o \n novamente
        scanf("%c", &y);

        // Verifica se foi digitado um número válido para o tipo de despesa e encerra com uma mensagem de erro se não
        if (dado->tipo < 1 || dado->tipo > 9)
        {
            printf("ERRO!\nDigite um numero entre 1 e 9!\n");
            free(dado);
            fclose(tabela);
            return 5;
        }

        // Recebe uma breve descrição da despesa
        printf("\nEscreva uma breve descricao sobre o que voce gastou (maximo de 300 caracteres) e tecle ENTER: ");
        fgets(dado->descricao, MAX, stdin);

        // Remove o \n do final da string para evitar problemas de impressão
        dado->descricao[strlen(dado->descricao) - 1] = '\0';

        // Verifica se a descrição foi digitada corretamente e encerra com uma mensagem de erro se não
        if (strlen(dado->descricao) == 0)
        {
            printf("ERRO!\nDigite corretamente\n");
            free(dado);
            fclose(tabela);
            return 5;
        }
        else if (strlen(dado->descricao) == MAX - 2)
        {
            printf("ERRO!\nDigite menos caracteres\n");
            free(dado);
            fclose(tabela);
            return 6;
        }

        // Recebe o valor da despesa
        printf("\nDigite o quanto voce gastou (um numero positivo) e tecle ENTER: ");
        fgets(dado->debito, MAX, stdin);

        // Remove o \n do final da string para evitar problemas de impressão
        dado->debito[strlen(dado->debito) - 1] = '\0';

        // Verifica se o valor foi digitado corretamente e encerra com uma mensagem de erro se não
        if (strlen(dado->debito) == 0)
        {
            printf("ERRO!\nDigite corretamente\n");
            free(dado);
            fclose(tabela);
            return 5;
        }
        else if (strlen(dado->debito) == MAX - 2)
        {
            printf("ERRO!\nDigite menos caracteres\n");
            free(dado);
            fclose(tabela);
            return 6;
        }

        // Insere a linha de dados no arquivo de interesse
        fprintf(tabela, "%s;%s;%s;%s\n", dado->data, categorias[dado->tipo - 1], dado->descricao, dado->debito);

        // Libera a memória alocada
        free(dado);
    }

    // Fecha o arquivo e retorna 0
    fclose(tabela);
    return 0;
}