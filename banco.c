#include "banco.h"
#include <stdio.h>
#include <string.h>

ERROS NovoCliente(Banco banco[], int *pos){

  if(*pos==TOTAL){

    return MAX_CLIENTES;
  }
  printf("Digite o cpf do cliente: ");
  long cpf;
  scanf("%ld",&cpf);
  for(int i = 0;i<*pos;i++){
    if(banco[i].cpf==cpf){
      return CLIENTE_EXISTENTE;
    }
  }
  banco[*pos].cpf=cpf;

  clearBuffer();
  
  printf("Digite o nome do cliente: ");
  fgets(banco[*pos].nome, NOME_MAX, stdin);
    banco[*pos].nome[strcspn(banco[*pos].nome, "\n")] = '\0';

  
  printf("Digite o tipo da conta do cliente: ");
  fgets(banco[*pos].tipo, TIPO_CONTA_MAX, stdin);
    banco[*pos].tipo[strcspn(banco[*pos].tipo, "\n")] = '\0';

  printf("Digite o saldo inicial da conta do cliente: ");
  scanf("%f",&banco[*pos].saldo);
  
  clearBuffer();
  printf("Digite a senha da conta do cliente: ");
  fgets(banco[*pos].senha, SENHA_MAX, stdin);
  banco[*pos].senha[strcspn(banco[*pos].senha, "\n")] = '\0';

  *pos+=1;

  return OK;
  
}
ERROS DeletarCliente(Banco banco[], int *pos){
  
}

ERROS ListarClientes(Banco banco[], int *pos){
  if (*pos == 0){
    return SEM_CLIENTES;
  }

  for (int i = 0; i < *pos; i++){
    printf("Posição: %d\n", i+1);
    printf("Nome: %s\t", banco[i].nome);
    printf("CPF: %ld\n", banco[i].cpf);
    printf("Tipo de Conta: %s\t", banco[i].tipo);
    printf("Saldo: %.2f\n\n", banco[i].saldo); 
  }

  return OK;


}
ERROS Debito(Banco banco[], int *pos){

}
ERROS Deposito(Banco banco[], int *pos){

  
}
ERROS Transferencia(Banco banco[], int *pos){
  
}
ERROS Extrato(Banco banco[], int *pos){
  
}
ERROS Salvar(Banco banco[], int *pos){
  
}
ERROS Carregar(Banco banco[], int *pos){
  
}
void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF);
}

void printErro(ERROS e){
  switch(e){
    case 0:
    printf("OK\n");
    break;
      case 1:
    printf("Maximo de clientes atingido!\n");
    break;
        case 2:
    printf("Sem clientes no arquivo!\n");
    break;
          case 3:
    printf("Cliente não encontrado!\n");
    break;
            case 4:
    printf("Erro ao abrir o arquivo!\n");
    break;
              case 5:
    printf("Erro ao fechar o arquivo!\n");
    break;
                case 6:
    printf("Erro ao escrever no arquivo!\n");
    break;
                  case 7:
    printf("Erro ao ler o arquivo!\n");
    break;
                    case 8:
    printf("Cliente já existente!\n");
    break;
    default:
    printf("Erro desconhecido!\n");
  }
}