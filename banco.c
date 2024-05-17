#include "banco.h"
#include <stdio.h>
#include <string.h>

ERROS NovoCliente(Banco banco[], int *pos) {

  if (*pos == TOTAL) {
    return MAX_CLIENTES;
  }
  printf("Digite o cpf do cliente: ");
  long cpf;
  scanf("%ld", &cpf);
  for (int i = 0; i < *pos; i++) {
    if (banco[i].cpf == cpf) {
      return CLIENTE_EXISTENTE;
    }
  }
  banco[*pos].cpf = cpf;

  banco[*pos].pos_extratos = 0;
  
  printf("Digite o saldo inicial da conta do cliente: \n");
  scanf("%f", &banco[*pos].saldo);

  
  clearBuffer();
  printf("Digite o nome do cliente: ");
  fgets(banco[*pos].nome, NOME_MAX, stdin);
  banco[*pos].nome[strcspn(banco[*pos].nome, "\n")] = '\0';

    printf("Digite a senha da conta do cliente: ");
    fgets(banco[*pos].senha, SENHA_MAX, stdin);
  banco[*pos].senha[strcspn(banco[*pos].senha, "\n")] = '\0';
  
  printf("Digite o tipo da conta do cliente(Comum/Plus): \n");
  fgets(banco[*pos].tipo, TIPO_CONTA_MAX, stdin);
  banco[*pos].tipo[strcspn(banco[*pos].tipo, "\n")] = '\0';

  *pos += 1;
  Salvar(banco, pos);
  return OK;
}
ERROS DeletarCliente(Banco banco[], int *pos) {
  if (*pos == 0) {
    printf("nenhum cliente para apagar\n");
    return SEM_CLIENTES;
  }
  long cpf_deletar;
  int pos_DELETAR = -1;
  printf("entre com o cpf para deletar o cliente\n");
  scanf("%ld", &cpf_deletar);

  for (int i = 0; i < *pos; i++) {
    if (banco[i].cpf == cpf_deletar) {
      pos_DELETAR = i;
      break;
    }
  }
  if (pos_DELETAR == -1) {
    printf("cliente com cpf %ld não encontrado\n", cpf_deletar);
    return NAO_ENCONTRADO;
  }

  for (int i = pos_DELETAR; i < *pos - 1; i++) {
    strcpy(banco[i].nome, banco[i + 1].nome);
    strcpy(banco[i].tipo, banco[i + 1].tipo);
    strcpy(banco[i].senha, banco[i + 1].senha);
    banco[i].cpf = banco[i + 1].cpf;
    banco[i].saldo = banco[i + 1].saldo;
  }

  *pos = *pos - 1;

  Salvar(banco, pos);
  return OK;
}

ERROS ListarClientes(Banco banco[], int *pos) {
  if (*pos == 0) {
    return SEM_CLIENTES;
  }

  for (int i = 0; i < *pos; i++) {
    printf("Posição: %d\n", i + 1);
    printf("Nome: %s\t", banco[i].nome);
    printf("CPF: %ld\n", banco[i].cpf);
    printf("Tipo de Conta: %s\t", banco[i].tipo);
    printf("Saldo: %.2f\n", banco[i].saldo);
  }

  ERROS erro = Salvar(banco, pos);
  if (erro != OK) {
    return erro;
  }
  return OK;
}
ERROS Debito(Banco banco[], int *pos) {
  if (*pos == 0) {
    return SEM_CLIENTES;
  }

  long cpf_debito;
  int pos_DEBITO = -1;
  printf("Digite o CPF do cliente para debitar: ");
  scanf("%ld", &cpf_debito);

  for (int i = 0; i < *pos; i++) {
    if (banco[i].cpf == cpf_debito) {
      pos_DEBITO = i;
      break;
    }
  }

  if (pos_DEBITO == -1) {
    printf("Cliente com CPF %ld não encontrado\n", cpf_debito);
    return NAO_ENCONTRADO;
  }

  clearBuffer();
  char senha_debito[SENHA_MAX];
  printf("Digite a senha da conta do cliente: ");
  fgets(senha_debito, SENHA_MAX, stdin);
  senha_debito[strcspn(senha_debito, "\n")] = '\0';
  
  if(strcmp(senha_debito,banco[pos_DEBITO].senha)){
    return SENHA_ERRADA;
  }
  
  float valor_debitar;
  printf("Digite o valor a ser debitado da conta: ");
  scanf("%f", &valor_debitar);

  if (valor_debitar > banco[pos_DEBITO].saldo) {
    printf("Saldo insuficiente para realizar o débito\n");
    return OK;
  } 

  banco[pos_DEBITO].saldo -= valor_debitar;

  printf("Débito de %.2f realizado com sucesso na conta do cliente %ld\n",
         valor_debitar, banco[pos_DEBITO].cpf);

  ERROS erro = Salvar(banco, pos);
  if (erro != OK) {
    return erro;
  }
  
  SalvarExtrato(banco, pos,  cpf_debito,  1,  valor_debitar);
  return OK;
}

ERROS Deposito(Banco banco[], int *pos) {
   if (*pos == 0) {
    return SEM_CLIENTES;
  }
  long cpf_deposito;
  int pos_DEPOSITO=-1;

  printf("Digite o CPF do cliente para depositar: ");
  scanf("%ld",&cpf_deposito);

  for(int i=0;i<*pos;i++){
    if(banco[i].cpf == cpf_deposito){
      pos_DEPOSITO=i;
      break;
    }
  }

  if(pos_DEPOSITO ==-1){
    printf("cliente com CPF %ld não encontrado\n",cpf_deposito);
    return NAO_ENCONTRADO;
  }

  float Valor_deposito;
  printf("Digite o valor a ser depositado da conta :");
  scanf("%f",&Valor_deposito);

  banco[pos_DEPOSITO].saldo += Valor_deposito;

  printf("Deposito de %.2f realizado com sucesso na conta do cliente %ld\n",
         Valor_deposito, banco[pos_DEPOSITO].cpf);

  ERROS erro = Salvar(banco, pos);
  if (erro != OK) {
    return erro;
  }
  
  SalvarExtrato(banco, pos,  cpf_deposito,  2,  Valor_deposito);

  return OK;
}
ERROS Transferencia(Banco banco[], int *pos) {

  ERROS erro = Salvar(banco, pos);
  if (erro != OK) {
    return erro;
  }
  return OK;
}
ERROS Extrato(Banco banco[], int *pos) {
  if (*pos == 0) {
    return SEM_CLIENTES;
  }

  long cpf_EXTRATO;
  int pos_EXTRATO = -1;
  printf("Digite o CPF do cliente para debitar: ");
  scanf("%ld", &cpf_EXTRATO);

  for (int i = 0; i < *pos; i++) {
    if (banco[i].cpf == cpf_EXTRATO) {
      pos_EXTRATO = i;
      break;
    }
  }

  if (pos_EXTRATO == -1) {
    printf("Cliente com CPF %ld não encontrado\n", cpf_EXTRATO);
    return NAO_ENCONTRADO;
  }

  clearBuffer();
  
  char senha_EXTRATO[SENHA_MAX];
  printf("Digite a senha da conta do cliente: ");
  fgets(senha_EXTRATO, SENHA_MAX, stdin);
  senha_EXTRATO[strcspn(senha_EXTRATO, "\n")] = '\0';

  if(strcmp(senha_EXTRATO,banco[pos_EXTRATO].senha)){
    return SENHA_ERRADA;
  }
   printf("Digite o nome do arquivo de extratos: ");
  char nome[NOME_MAX];
  fgets(nome, NOME_MAX, stdin);
  nome[strcspn(nome, "\n")] = '.';
  strcat(nome,"txt");
  
  FILE *f = fopen(nome, "w");
  if (f == NULL)
    return ABRIR;

  for (int i = 0; i < banco[pos_EXTRATO].pos_extratos; i++) {
    fprintf(f,"Tipo: %s\t", banco[pos_EXTRATO].extrato[i].Tipo);
    fprintf(f,"Valor: %.2f\n", banco[pos_EXTRATO].extrato[i].Valor);
  }

  if (fclose(f))
    return FECHAR;

  return OK;
}
ERROS Salvar(Banco banco[], int *pos) {
  FILE *f = fopen("banco.bin", "wb");
  if (f == NULL)
    return ABRIR;
  int qtd = fwrite(banco, TOTAL, sizeof(Banco), f);
  if (qtd == 0)
    return ESCREVER;

  qtd = fwrite(pos, 1, sizeof(int), f);
  if (qtd == 0)
    return ESCREVER;

  if (fclose(f))
    return FECHAR;

  return OK;
}
ERROS Carregar(Banco banco[], int *pos) {
  FILE *f = fopen("banco.bin", "rb");
  if (f == NULL)
    return ABRIR;

  int qtd = fread(banco, TOTAL, sizeof(Banco), f);
  if (qtd == 0)
    return LER;

  qtd = fread(pos, 1, sizeof(int), f);
  if (qtd == 0)
    return LER;

  if (fclose(f))
    return FECHAR;
  
  return OK;
}

ERROS SalvarExtrato(Banco banco[], int *pos, long CPF, int Tipo, float Valor) {
  
  char nomeTipo[TIPO_EXTRATO_MAX];
  switch(Tipo){
    case 1:
      strcpy(nomeTipo, "DEBITO");
      break;
    case 2:
      strcpy(nomeTipo, "DEPOSITO");
      break;
    case 3:
      strcpy(nomeTipo, "TRANSFERENCIA");
      break;
  }
  
  int pos_salvar_extrato = -1;
  
  for (int i = 0; i < *pos; i++) {
    if (banco[i].cpf == CPF) {
        pos_salvar_extrato = i;
      break;
    }
  }
  
  printf("aqui %d",banco[pos_salvar_extrato].pos_extratos);
  
  if(banco[pos_salvar_extrato].pos_extratos == TOTAL_EXTRATOS){
    banco[pos_salvar_extrato].pos_extratos--;
    for (int i = 0; i < TOTAL_EXTRATOS - 1; i++) {
      banco[pos_salvar_extrato].extrato[i].Valor = banco[pos_salvar_extrato].extrato[i+1].Valor;
      strcpy(banco[pos_salvar_extrato].extrato[i].Tipo,banco[pos_salvar_extrato].extrato[i+1].Tipo);
    }
    banco[pos_salvar_extrato].extrato[banco[pos_salvar_extrato].pos_extratos].Valor = Valor;
    strcpy(banco[pos_salvar_extrato].extrato[banco[pos_salvar_extrato].pos_extratos].Tipo,nomeTipo);
    banco[pos_salvar_extrato].pos_extratos++;
  }else{
    banco[pos_salvar_extrato].extrato[banco[pos_salvar_extrato].pos_extratos].Valor = Valor;
    strcpy(banco[pos_salvar_extrato].extrato[banco[pos_salvar_extrato].pos_extratos].Tipo,nomeTipo);
    banco[pos_salvar_extrato].pos_extratos++;
    printf("aqui %d",banco[pos_salvar_extrato].pos_extratos);
  }
  
  return OK;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}

void printErro(ERROS e) {
  switch (e) {
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
  case 9:
    printf("Senha Errada!\n");
    break;
  default:
    printf("Erro desconhecido!\n");
  }
}