#define NOME_MAX 70
#define TIPO_CONTA_MAX 10
#define SENHA_MAX 20
#define TOTAL 1000
#define TOTAL_EXTRATOS 100
#define TIPO_EXTRATO_MAX 20

typedef struct Extratos{
char Tipo[TIPO_EXTRATO_MAX];
float Valor;

}Extratos;

typedef struct Banco{

long cpf;
char nome[NOME_MAX];
char tipo[TIPO_CONTA_MAX];
char senha[SENHA_MAX];
float saldo;
Extratos extrato[TOTAL_EXTRATOS];
int pos_extratos;

}Banco;




typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER, CLIENTE_EXISTENTE,SENHA_ERRADA,TIPO_INCORRETO} ERROS;

typedef ERROS (*funcao)();

ERROS NovoCliente(Banco banco[], int *pos);
ERROS DeletarCliente(Banco banco[], int *pos);
ERROS ListarClientes(Banco banco[], int *pos);
ERROS Debito(Banco banco[], int *pos);
ERROS Deposito(Banco banco[], int *pos);
ERROS Transferencia(Banco banco[], int *pos);
ERROS Extrato(Banco banco[], int *pos);
ERROS Salvar(Banco banco[], int *pos);
ERROS Carregar(Banco banco[], int *pos);
ERROS SalvarExtrato(Banco banco[], int *pos, long CPF, int Tipo, float Valor);

void clearBuffer();

void printErro(ERROS e);
