///
/// Mission n°2 - Gang 007
///
///
/// Crypto.h
/// Le 21/03/2023
///
///
/// Code écrit et édité par
///
/// Redwane TALMANT
///
///

#ifndef CRYPTO_H
#define CRYPTO_H

#include <string>
#include <fstream>

class Crypto
{
public :
    Crypto();
    ~Crypto();
    std::ofstream fichier_out;
    std::ifstream fichier_in;
    std::string fileName;
    void ChiffrerCesar(int key);
    void DechiffrerCesar();
    int getKey();
    void ChiffrerVigenere();
    void DechiffrerVigenere();

protected :

private :
    int x;
    char c;
};

#endif // CRYPTO_H
