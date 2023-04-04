///
/// Mission n°2 - Gang 007
///
///
/// main.cpp
/// Le 21/03/2023
///
///
/// Code écrit et édité par
///
/// Redwane TALMANT
///
///

#include "Crypto.h"
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    Crypto code;

    cout << "Bienvenue chez moi !" << endl;
    Sleep(1000);
    cout << "Vous pouvez m'utiliser pour chiffrer ou d" << char(130) << "chiffrer des messages en utilisant des chiffrements c" << char(130) << "l" << char(138) << "bres," << endl;
    Sleep(1000);
    cout << "comme le code C" << char(130) << "sar et le code Vigen" << char(138) << "re !" << endl;
    Sleep(1000);

    char reponse1('A'), reponse2('A');
    int key;

    do
    {
        cout << "Souhaitez-vous chiffrer (C) ou d" << char(130) << "chiffrer (D) un message ?" << endl;
        cin >> reponse1;
        cin.ignore();

        if(reponse1=='D' || reponse1=='d')
        {
            cout << "Choisissez votre code de d" << char(130) << "chiffremment : C" << char(130) << "sar (C) ou Vigenere (V)" << endl;
            cin >> reponse2;
            cin.ignore();

            if(reponse2=='C' || reponse2=='c')
            {
                code.DechiffrerCesar();
            }
            else if(reponse2=='V' || reponse2=='v')
            {
                code.DechiffrerVigenere();
            }
            else
            {
                cout << "D" << char(130) << "sol" << char(130) << ", je ne suis qu'un pauvre programme, et j'ai du mal " << char(133) << " analyser vos r" << char(130) << "ponses lorsqu'elles sont inhabituelles... Recommencez !" << endl;
            }
        }
        else if(reponse1=='C' || reponse1=='c')
        {
            cout << "Choisissez votre code de chiffremment : C" << char(130) << "sar (C) ou Vigenere (V)" << endl;
            cin >> reponse2;
            cin.ignore();

            if(reponse2=='C' || reponse2=='c')
            {
                cout << "Choisissez votre cl" << char(130) << " de chiffrement (comprise entre 1 et 25) : " << endl;
                cin >> key;
                cin.ignore();

                code.ChiffrerCesar(key);
            }
            else if(reponse2=='V' || reponse2=='v')
            {
                code.ChiffrerVigenere();
            }
            else
            {
                cout << "D" << char(130) << "sol" << char(130) << ", je ne suis qu'un pauvre programme, et j'ai du mal " << char(133) << " analyser vos r" << char(130) << "ponses lorsqu'elles sont inhabituelles... Recommencez !" << endl;
            }
        }
        else
        {
            cout << "D" << char(130) << "sol" << char(130) << ", je ne suis qu'un pauvre programme, et j'ai du mal " << char(133) << " analyser vos r" << char(130) << "ponses lorsqu'elles sont inhabituelles... Recommencez !" << endl;
        }
    } while(reponse1!='D' || reponse1!='d' || reponse1!='C' || reponse1!='c');

    return 0;
}

