ERROS NovoCliente(){
  
}
ERROS DeletarCliente(){
  
}
ERROS ListarClientes(){
  if (*pos == 0){
    return SEM_CLIENTES;
  }

  for (int i = 0; i < *pos; i++){
    printf("Posição: %d\n", i+1);
    printf("Nome: %s\t", banco[i].nome);
    printf("CPF: %ld\n", banco[i].cpf);
    printf("Tipo de Conta: %s\t", banco[i].tipo);
    printf("Saldo: %s\n\n", banco[i].saldo); 
  }

  return OK;
}
ERROS Debito(){

}
ERROS Deposito(){
  
}
ERROS Transferencia(){
  
}
ERROS Extrato(){
  
}
ERROS Salvar(){
  
}
ERROS Carregar(){
  
}