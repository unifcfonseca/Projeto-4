

#define NOME_MAX 70
#define TIPO_CONTA_MAX 5
#define SENHA_MAX 20
#define TOTAL 1000

typedef struct Banco{

long cpf;
char nome[NOME_MAX];
char tipo[TIPO_CONTA_MAX];
char senha[SENHA_MAX];
float saldo;

}Banco;

typedef struct Extratos{
int Tipo;
int Valor;

}Extratos;


typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER, CLIENTE_EXISTENTE} ERROS;



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

void clearBuffer();

void printErro(ERROS e);
