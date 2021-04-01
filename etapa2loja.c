#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

//Declaração das Estruturas a serem utilizadas
typedef struct enderecoStruct
{
char rua[40];
char bairro[30];
char numero[6];
char cep[8];
char cidade[20];
char estado[20];
} Endereco;

typedef struct CadastroPessoaStruct
{
char nome[40];
char reg[12];
char rg[10];
char telefone[11];
Endereco end;
} Pessoa;

//Declaração das variáveis
int input = 0;
int qtdClientes;
int tamClientes;
Pessoa *clientes;
FILE *arquivo;
char clientes_dir[] = "Clientes.bin";

//Declaração dos Procedimentos e Funções a serem utilizados
void menuPrincipal();
void menuClientes();
void consoles();
void removerQuebraLinha();
Pessoa receberCliente();
Endereco receberEndereco();
void inserirCliente();
void SONY();
void MICROSOFT();

//Início do main
int main(int argc, char** argv)
{
    menuPrincipal();
    return 0;
}

void sucesso()
{
    system("cls");
    printf ("Operacao concluida com sucesso!");
}

void menuPrincipal()
{
    do
    {
        printf("\n");
        printf ("\t\t\t\t  Riguete GAMES!\n");
        printf ("\t\t\t===============================\n");
        printf ("\t\t\t|\t                      |\n");
        printf("\t\t\t|\t 1 - Cliente          |\n");
        printf("\t\t\t|\t 2 - Consoles         |\n");
        printf("\t\t\t|\t 0 - Sair             |\n");
        printf ("\t\t\t|\t                      |\n");
        printf ("\t\t\t===============================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input)
        {
        case 1:
            menuClientes();
            break;
        case 2:
            consoles();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}


void menuClientes()
{
    do
    {
        printf("\n");
        printf ("\t\t\t\t  Riguete GAMES!\n");
        printf ("\t\t\t===============================\n");
        printf ("\t\t\t|\t                      |\n");
        printf("\t\t\t|    1 - Fazer Cadastro    |\n");
        printf("\t\t\t|    2 - Menu Principal       |\n");
        printf("\t\t\t|    0 - Sair                 |\n");
        printf ("\t\t\t|                             |\n");
        printf ("\t\t\t===============================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input)
        {
        case 1:
            fflush(stdin);
            inserirCliente(receberCliente());
            break;
        case 2:
            menuPrincipal();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}



void removerQuebraLinha(char *string)
{
    if(string != NULL && strlen(string) > 0)
    {
        short tamanho = strlen(string);
        if(string[tamanho-1] == '\n')
        {
            string[tamanho-1] = '\0';
        }
    }
}

void receberString(char *string_destino, int quantidade_caracteres)
{
    fgets(string_destino, quantidade_caracteres, stdin);
    removerQuebraLinha(string_destino);
}

Pessoa receberCliente()
{
    Pessoa p;

    printf("Nome: ");
    receberString(p.nome, 39);
    printf ("CPF: ");
    receberString(p.reg, 13);
    fflush(stdin);
    printf ("RG: ");
    receberString(p.rg, 11);
    fflush(stdin);
    printf ("Telefone: ");
    receberString(p.telefone, 12);
    fflush(stdin);

    p.end = receberEndereco();

    sucesso();
    return p;
}

Endereco receberEndereco()
{
    Endereco e;

    printf ("Rua: ");
    receberString(e.rua, 39);
    fflush(stdin);
    printf ("Numero: ");
    receberString(e.numero, 5);
    fflush(stdin);
    printf ("CEP: ");
    receberString(e.cep, 9);
    fflush(stdin);
    printf ("Bairro: ");
    receberString(e.bairro, 29);
    printf ("Cidade: ");
    receberString(e.cidade, 20);
    printf ("Estado: ");
    receberString(e.estado, 20);

    sucesso();
    return e;
}

void inserirCliente(Pessoa p)
{
    if(qtdClientes == tamClientes)
    {
        tamClientes *= 1.5;
        clientes = realloc(clientes, tamClientes*sizeof(Pessoa));
    }
    clientes[qtdClientes] = p;
    qtdClientes++;
}

void consoles()
{
    do
    {
        printf("\n");
        printf ("Riguete GAMES!");
        printf ("===============================\n");
        printf ("\t\t\t|\t                          |\n");
        printf("\t\t\t|    1 - SONY                     |\n");
        printf("\t\t\t|    2 - MICROSOFT                |\n");
        printf("\t\t\t|    3 - Menu Principal           |\n");
        printf("\t\t\t|    0 - Sair                     |\n");
       printf ("\t\t\t|                                 |\n");
        printf ("\t\t\t===============================\n");
        printf ("\n\n");
        printf("\t\t\tPor favor, selecione uma opcao: ");
        fflush(stdin);
        scanf("%d", &input);
        system("cls");
        switch(input)
        {
        case 1:
            SONY();
            break;
        case 2:
            MICROSOFT();
            break;
        case 3:
            menuPrincipal();
            break;
        case 0:
            exit(EXIT_SUCCESS);
        default:
            printf ("\n\t\t\tOpcao invalida!\n\n");
            fflush(stdin);
        }
    }
    while(input != 0);
    system("cls");
}


void SONY()
{
    char sony;
float controle,n2;
float valorfat=1900, valorslim=2100, valorpro=2300;
float valorcontroleadd=200;
int preco;
printf("Escolha o console:\n1-PS4 FAT\n2-PS4 SLIM\n3-PS4 PRO\n\n");
 scanf(" %c", &sony);

switch (sony)
{

case '1':
    printf("PRODUTO DISPONIVEL\nDigite 1 para adicionar um controle extra ou 0 para pular\n");
            scanf("%f",&controle);

   if (controle==1 )
{
    preco = valorfat + valorcontroleadd;
printf("O PS4 FAT COM DOIS CONTROLES custa R$%i", preco);
}


   else if (controle==0)
    {
        preco = valorfat + 0;
        printf("O PS4 FAT COM UM CONTROLE custa R$%i\n", preco);
    }

break;

case '2':
    printf("PRODUTO DISPONIVEL\nDigite 1 para adicionar um controle extra ou 0 para pular\n");
            scanf("%f",&controle);

     if (controle == 1)
    {
        preco = valorslim + valorcontroleadd;
        printf("O PS4 SLIM COM DOIS CONTROLES custa R$%i\n", preco);
    }
    else if (controle == 0)
    {
        preco = valorslim + 0;
        printf("O PS4 SLIM COM UM CONTROLE custa R$%i\n", preco);
    }

break;

case '3':
    printf("PRODUTO INDISPONIVEL\n");

break;

return 0;
}
}

void MICROSOFT()
{

printf("\n\nOS CONSOLES DA MICROSOFT ESTAO FORA DE ESTOQUE, ESCOLHA OUTRA OPCAO\n\n");

}






