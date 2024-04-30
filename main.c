#include <stdio.h>

int main() {
int escolha;

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

} while (escolha != 0);

return 0;
}