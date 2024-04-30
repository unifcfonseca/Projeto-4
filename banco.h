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