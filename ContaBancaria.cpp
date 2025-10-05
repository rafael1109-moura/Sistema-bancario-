#include "ContaBancaria.h"

using namespace std;

// Construtor: Inicialização de Membros Corrigida
ContaBancaria::ContaBancaria (int n, Cliente t, double s)
    : numero(n), titular(t), saldo(s) {}

int ContaBancaria::getNumero() const {
    return numero;
}

// Implementação do método auxiliar privado para a LÓGICA da transação
bool ContaBancaria::sacarInterno(double valor) {
    if (valor <= 0) {
        cout << "ERRO: O valor deve ser positivo." << endl;
        return false;
    }
    if (saldo >= valor) {
        saldo -= valor;
        return true;
    } else {
        cout << "ERRO: Saldo insuficiente na conta " << numero << " para sacar R$ " << valor << "." << endl;
        return false;
    }
}

// método para depositar um valor na conta.
void ContaBancaria::depositar(double valor){
    if (valor > 0){
        saldo = saldo + valor;
        cout << "Depositado: R$ " << valor << " na conta " << numero << endl;
    }
    else {
        cout << "ERRO: Valor de depósito deve ser positivo." << endl;
    }
}

// método para sacar um valor da conta (usa o sacarInterno)
void ContaBancaria::sacar(double valor){
    if (sacarInterno(valor)){
        // Se deu certo, a subtração já foi feita pelo sacarInterno
        cout << "Saque efetuado com sucesso, no valor de: R$ " << valor << " da conta " << numero << endl;
    }
    // Se falhou, o sacarInterno já exibiu a mensagem de erro
}

// SOBRECARGA 1: Transferência para UM destino 
void ContaBancaria::transferir (double valor, ContaBancaria &destino){
    if (sacarInterno(valor)) { // Valida e saca desta conta
        destino.depositar(valor);
        cout << "Transferido: R$ " << valor 
             << " da conta " << numero 
             << " para a conta " << destino.getNumero()
             << "." << endl;
    }
}

// SOBRECARGA 2: Transferência para DOIS destinos 
void ContaBancaria::transferir (double valor, ContaBancaria &destino1, ContaBancaria &destino2){
    if (sacarInterno(valor)) { // Valida e saca desta conta
        double valorDividido = valor / 2.0;
        
        destino1.depositar(valorDividido);
        destino2.depositar(valorDividido);

        cout << "Transferido: R$ " << valorDividido << " para cada conta (" 
             << destino1.getNumero() << " e " << destino2.getNumero() 
             << ") da conta " << numero << "." << endl;
    }
}

void ContaBancaria::exibirSaldo() const {
    cout << "Saldo atual da conta " << numero << ": R$ " << saldo << endl;
}

void ContaBancaria::exibirInformacoes() const {
    cout << "Titular: " << titular.getNome() << ", CPF: " << titular.getCpf() 
         << " | Conta: " << numero << ", Saldo: R$ " << saldo << endl;
}