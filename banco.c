#include "banco.h"
#include <stdio.h>
#include <string.h>>

ERROS NovoCliente(Banco *banco, int *pos){
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
  
  printf("Digite o nome do cliente: ");
  scanf("%s",banco[*pos].nome);
  fgets(banco[*pos].nome, NOME_MAX, stdin);
    banco[*pos].nome[strcspn(banco[*pos].nome, "\n")] = '\0';
  
  printf("Digite o tipo da conta do cliente: ");
  scanf("%s",banco[*pos].tipo);
  fgets(banco[*pos].tipo, TIPO_CONTA_MAX, stdin);
    banco[*pos].tipo[strcspn(banco[*pos].tipo, "\n")] = '\0';
  
  printf("Digite o saldo inicial da conta do cliente: ");
  scanf("%f",&banco[*pos].saldo);
  
  printf("Digite a senha da conta do cliente: ");
  scanf("%d",&banco[*pos].senha);
  fgets(banco[*pos].senha, SENHA_MAX, stdin);
  banco[*pos].senha[strcspn(banco[*pos].SENHA, "\n")] = '\0';
  
  *pos+=1;

  return OK;
  
}
ERROS DeletarCliente(Banco *banco, int *pos){
  
}
ERROS ListarClientes(Banco *banco, int *pos){
  
}
ERROS Debito(Banco *banco, int *pos){

}
ERROS Deposito(Banco *banco, int *pos){
  
}
ERROS Transferencia(Banco *banco, int *pos){
  
}
ERROS Extrato(Banco *banco, int *pos){
  
}
ERROS Salvar(Banco *banco, int *pos){
  
}
ERROS Carregar(Banco *banco, int *pos){
  
}