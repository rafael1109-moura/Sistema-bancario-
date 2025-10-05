#ifndef CONTABANCARIA_H
#define CONTABANCARIA_H

#include "Cliente.h"
#include <iostream>

using namespace std;

class ContaBancaria {
    
private:
    int numero;
    double saldo;
    Cliente titular;
    
    // Método auxiliar para saque interno (usado por sacar e transferir)
    bool sacarInterno(double valor);

public:  
    // construtor com Saldo Opcional (s = 0)
    ContaBancaria (int n, Cliente t, double s = 0);

    int getNumero() const;
    
    // método para depositar um valor na conta.
    void depositar(double valor);
    
    // método para sacar um valor da conta (verifique se há saldo suficiente).
    void sacar(double valor);
    
    // SOBRECARGA 1: Transferência para UM destino 
    void transferir (double valor, ContaBancaria &destino);
    
    // SOBRECARGA 2: Transferência para DOIS destinos 
    void transferir (double valor, ContaBancaria &destino1, ContaBancaria &destino2);

    void exibirSaldo() const;

    void exibirInformacoes() const;
};

#endif // CONTABANCARIA_H