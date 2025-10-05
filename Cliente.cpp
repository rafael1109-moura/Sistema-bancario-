#include "Cliente.h"
#include <iostream>

using namespace std;

// construtor
Cliente::Cliente (string n, string c)
    : nome(n), cpf(c) 
{
    cout << "iniciando construtor" << endl;
}

string Cliente::getNome() const {
    return nome;
}

string Cliente::getCpf() const {
    return cpf;
}
