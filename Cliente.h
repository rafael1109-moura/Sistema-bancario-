#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente {

private:
    string nome;
    string cpf;
    
public:  
    // construtor
    Cliente (string n, string c);

    string getNome() const;
    
    string getCpf() const;
};

#endif // CLIENTE_H