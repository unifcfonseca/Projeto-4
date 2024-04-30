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

  
  printf("Digite o tipo da conta do cliente: \n");
  fgets(banco[*pos].tipo, TIPO_CONTA_MAX, stdin);
    banco[*pos].tipo[strcspn(banco[*pos].tipo, "\n")] = '\0';

  printf("Digite o saldo inicial da conta do cliente: \n");
  scanf("%f",&banco[*pos].saldo);
  
  clearBuffer();
  printf("Digite a senha da conta do cliente: ");
  fgets(banco[*pos].senha, SENHA_MAX, stdin);
  banco[*pos].senha[strcspn(banco[*pos].senha, "\n")] = '\0';

  *pos+=1;
  Salvar(banco,  pos);
  return OK;
  
}
ERROS DeletarCliente(Banco banco[], int *pos){
  if(*pos==0){
    printf("nenhum cliente para apagar\n");
      return SEM_CLIENTES;  
  }
  long cpf_deletar;
  int pos_DELETAR=-1;
  printf("entre com o cliente para deletar\n");
  scanf("%ld", &cpf_deletar);

  for(int i = 0; i < *pos; i++){
    if(banco[i].cpf == cpf_deletar){
      pos_DELETAR = i;
      break;
    }
  }
  if(pos_DELETAR == -1){
    printf("cliente com cpf %ld não encontrado\n", cpf_deletar);
    return NAO_ENCONTRADO;
  }

  for(int i = pos_DELETAR; i < *pos - 1; i++){
    strcpy(banco[i].nome, banco[i + 1].nome);
    strcpy(banco[i].tipo, banco[i + 1].tipo);
    strcpy(banco[i].senha, banco[i + 1].senha);
    banco[i].cpf = banco[i + 1].cpf;
    banco[i].saldo = banco[i + 1].saldo;
  }

  *pos = *pos - 1;

  
  Salvar(banco,  pos);
  return OK;

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


  ERROS erro = Salvar(banco,  pos);
  if(erro != OK){
    return erro;
  }
  return OK;
}
ERROS Debito(Banco banco[], int *pos){

  ERROS erro = Salvar(banco,  pos);
  if(erro != OK){
    return erro;
  }
  return OK;
}
ERROS Deposito(Banco banco[], int *pos){

  ERROS erro = Salvar(banco,  pos);
  if(erro != OK){
    return erro;
  }
  return OK;
}
ERROS Transferencia(Banco banco[], int *pos){

  ERROS erro = Salvar(banco,  pos);
  if(erro != OK){
    return erro;
  }
  return OK;
}
ERROS Extrato(Banco banco[], int *pos){

  ERROS erro = Salvar(banco,  pos);
  if(erro != OK){
    return erro;
  }
  return OK;
}
ERROS Salvar(Banco banco[], int *pos){
  FILE *f = fopen("banco.bin", "wb");
  if(f == NULL)
      return ABRIR;
  int qtd = fwrite(banco, TOTAL, sizeof(Banco), f);
  if(qtd == 0)
      return ESCREVER;

  qtd = fwrite(pos, 1, sizeof(int), f);
  if(qtd == 0)
      return ESCREVER;

  if(fclose(f))
      return FECHAR;


  return OK;
}
ERROS Carregar(Banco banco[], int *pos){
  FILE *f = fopen("banco.bin", "rb");
  if(f == NULL)
      return ABRIR;

  int qtd = fread(banco, TOTAL, sizeof(Banco), f);
  if(qtd == 0)
      return LER;

  qtd = fread(pos, 1, sizeof(int), f);
  if(qtd == 0)
      return LER;

  if(fclose(f))
      return FECHAR;
  return OK;
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