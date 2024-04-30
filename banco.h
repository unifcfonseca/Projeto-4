typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER} ERROS;

typedef ERROS (*funcao)();

ERROS NovoCliente();
ERROS DeletarCliente();
ERROS ListarClientes();
ERROS Deposito();
ERROS Transferencia();
ERROS Extrato();
ERROS Debito();
ERROS Salvar();
ERROS Carregar();