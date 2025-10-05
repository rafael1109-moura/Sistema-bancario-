#include <iostream>
// Inclui apenas os headers das classes
#include "Cliente.h"
#include "ContaBancaria.h"

using namespace std;

int main() {
    // Criação dos clientes
    Cliente cliente1("Ana", "111.111.111-11");
    Cliente cliente2("Bruno", "222.222.222-22");
    Cliente cliente3("Carla", "333.333.333-33");

    // Criação das contas bancárias com saldos iniciais
    ContaBancaria conta1(1001, cliente1, 1000.0);
    ContaBancaria conta2(1002, cliente2); // Saldo opcional (0.0)
    ContaBancaria conta3(1003, cliente3); // Saldo opcional (0.0)

    // Exibe o saldo inicial da conta de Ana
    conta1.exibirSaldo();

    cout << "\n--- Operações ---\n";

    // Ana transfere R$200 para Bruno
    conta1.transferir(200.0, conta2);

    // Ana transfere R$300 divididos entre Bruno e Carla (Sobrecarga 2)
    conta1.transferir(300.0, conta2, conta3);

    // Teste de saque
    conta1.sacar(100.0);
    
    // Teste de saque com saldo insuficiente (Teste de validação)
    conta1.sacar(1000.0);

    cout << "\n--- Saldos Finais ---\n";
    conta1.exibirInformacoes();
    conta2.exibirInformacoes();
    conta3.exibirInformacoes();

    return 0;
}