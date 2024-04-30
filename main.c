#include <stdio.h>
#include "banco.h"  

int main() {
funcao fs[] = {NovoCliente, DeletarCliente, ListarClientes, Debito, Deposito, Transferencia, Extrato, Salvar, Carregar};
  
int pos , escolha;
Banco banco[TOTAL];
    ERROS erro = fs[8](banco, &pos);
  if(erro != OK){
      printf("Erro ao executar a operação.\n");
      printErro(erro);
      printf("\nSe voce continuar, todos os dados serão sobreescritos.\nDeseja continuar? (1-sim, 2-nao)\n");
      scanf("%d", &escolha);
      if(escolha == 1){
        pos = 0;
      }else{
        return 0;
      }
  }
  
do {

printf("\n===== Menu Principal =====\n");
printf("1. Novo cliente\n");
printf("2. Apagar cliente\n");
printf("3. Listar clientes\n");
printf("4. Débito\n");
printf("5. Depósito\n");
printf("6. Extrato\n");
printf("7. Transferência Entre Contas\n");
printf("0. Sair\n");
printf("===========================\n");


printf("Escolha uma opção: ");
scanf("%d", &escolha);


switch (escolha) {
case 1:
printf("Opção 1 selecionada: Novo cliente\n");
break;
case 2:
printf("Opção 2 selecionada: Apagar cliente\n");
break;
case 3:
printf("Opção 3 selecionada: Listar clientes\n");
break;
case 4:
printf("Opção 4 selecionada: Débito\n");
break;
case 5:
printf("Opção 5 selecionada: Depósito\n");
break;
case 6:
printf("Opção 6 selecionada: Extrato\n");
break;
case 7:
printf("Opção 7 selecionada: Transferência Entre Contas\n");
break;
case 0:
printf("Saindo...\n");
break;
default:
printf("Opção inválida. Por favor, escolha uma opção válida.\n");
break;
}
if(escolha>0 && escolha<8){
  erro = fs[escolha-1](banco, &pos);

    if(erro !=OK){
    printf("Erro ao executar a operação.\n");
    printErro(erro);
  
}
} while (escolha != 0);

  erro = fs[escolha-1](banco, &pos);
  
return 0;

  
}

