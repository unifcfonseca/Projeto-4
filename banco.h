#define NOME_MAX 70
#define TIPO_CONTA_MAX 5
#define SENHA_MAX 20
#define TOTAL 1000

typedef struct Banco{

long cpf;
char nome[NOME_MAX];
char conta[TIPO_CONTA_MAX];
char senha[SENHA_MAX];
float saldo;

}Banco;

typedef struct Extratos{
int Tipo;
int Valor;

}Extratos;


typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERROS;

typedef ERROS (*funcao)();

ERROS NovoCliente();
ERROS DeletarCliente();
ERROS ListarClientes();
ERROS Debito();
ERROS Deposito();
ERROS Transferencia();
ERROS Extrato();
ERROS Salvar();
ERROS Carregar();