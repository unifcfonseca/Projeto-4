typedef enum {OK, MAX_CLIENTES, SEM_CLIENTES, NAO_ENCONTRADO, ABRIR, FECHAR, ESCREVER, LER, CLIENTE_EXISTENTE} ERROS;

typedef ERROS (*funcao)();

ERROS NovoCliente(Banco *banco, int *pos);
ERROS DeletarCliente(Banco *banco, int *pos);
ERROS ListarClientes(Banco *banco, int *pos);
ERROS Debito(Banco *banco, int *pos);
ERROS Deposito(Banco *banco, int *pos);
ERROS Transferencia(Banco *banco, int *pos);
ERROS Extrato(Banco *banco, int *pos);
ERROS Salvar(Banco *banco, int *pos);
ERROS Carregar(Banco *banco, int *pos);