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
  Salvar(banco,  pos);
  return OK;
  
}
ERROS DeletarCliente(Banco banco[], int *pos){

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