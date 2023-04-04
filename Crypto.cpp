///
/// Mission n°2 - Gang 007
///
///
/// Crypto.cpp
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
#include <cctype>
#include <windows.h>

using namespace std;

Crypto::Crypto() : fileName("message_intercepte.txt"){
    //ctor
}

Crypto::~Crypto(){
    //dtor
}

//chiffrage type
void Crypto::ChiffrerCesar(int key){

    string fileNameBis("origine_message_intercepte.txt");
    ifstream fichier_in(fileNameBis.c_str());

    if(!fichier_in)
    {
        cout << "IMPOSSIBLE D'OUVRIR LE FICHIER" << endl;
    }
    else
    {
        long pos = fichier_in.tellg();
        fichier_in.seekg(0, ios_base::end);
        long size = fichier_in.tellg();
        fichier_in.seekg(pos, ios_base::beg);
        char message[size];

        fichier_in.read(&message[0], size);
        fichier_in.close();

        if(key<0)
        {
            key = 0;
        }
        else if(key>25)
        {
            key = 25;
        }

        ofstream fichier_out(fileName.c_str());

        if(!fichier_out)
        {
            cout << "IMPOSSIBLE D'OUVRIR LE FICHIER" << endl;
        }
        else
        {
            for(unsigned int i=0; i<sizeof(message); i++)
            {
                if(isupper(message[i]))
                {
                    message[i]+=key;

                    //au cas ou après chiffrage, mon caractère n'est plus une majuscule
                    if(!isupper(message[i]))
                    {
                        message[i]-=26;
                    }
                }
                else if(islower(message[i]))
                {
                    message[i]+=key;

                    //au cas ou après chiffrage, mon caractère n'est plus une minuscule
                    if(!islower(message[i]))
                    {
                        message[i]-=26;
                    }
                }

                cout << message[i];
                fichier_out << message[i];
            }

            fichier_out.close();
        }
    }
}

void Crypto::DechiffrerCesar(){

    ifstream fichier_in(fileName.c_str());

    if(!fichier_in)
    {
        cout << "IMPOSSIBLE D'OUVRIR LE FICHIER" << endl;
    }
    else
    {
        long pos = fichier_in.tellg();
        fichier_in.seekg(0, ios_base::end);
        long size = fichier_in.tellg();
        fichier_in.seekg(pos, ios_base::beg);
        char message[size];

        fichier_in.read(&message[0], size);
        fichier_in.close();

        int key = Crypto::getKey();

        string fileNameBis("origine_message_intercepte.txt");
        ofstream fichier_out(fileNameBis.c_str());

        if(!fichier_out)
        {
            cout << "IMPOSSIBLE D'OUVRIR LE FICHIER" << endl;
        }
        else
        {
            for(unsigned int i=0; i<sizeof(message); i++)
            {
                if(isupper(message[i]))
                {
                    message[i]-=key;

                    //au cas ou après chiffrage, mon caractère n'est plus une majuscule
                    if(!isupper(message[i]))
                    {
                        message[i]+=26;
                    }
                }
                else if(islower(message[i]))
                {
                    message[i]-=key;

                    //au cas ou après chiffrage, mon caractère n'est plus une minuscule
                    if(!islower(message[i]))
                    {
                        message[i]+=26;
                    }
                }

                cout << message[i];
                fichier_out << message[i];
            }

            fichier_out.close();
        }
    }
}

int Crypto::getKey(){

    ifstream fichier_in(fileName.c_str());

    if(!fichier_in)
    {
        cout << "IMPOSSIBLE D'OUVRIR LE FICHIER" << endl;
        return 0;
    }
    else
    {
        long pos = fichier_in.tellg();
        fichier_in.seekg(0, ios_base::end);
        long size = fichier_in.tellg();
        fichier_in.seekg(pos, ios_base::beg);
        char message[size];

        fichier_in.read(&message[0], size);
        fichier_in.close();

        char lettre;
        int occurrence;
        int nbOccurrence(0);
        char equivalentE;

        //chercher la lettre ayant le plus d'occurrences
        for(unsigned int i=0; i<sizeof(message); i++)
        {
            //initialisation à 0 à chaque tour
            occurrence=0;
            lettre = message[i];

            if(isalpha(message[i]))
            {
                for(unsigned int j=0; j<sizeof(message); j++)
                {
                    //en lisant le fichier, on compare à lettre
                    if(message[j]==lettre || message[j]==lettre-32 || message[j]==lettre+32)
                    {
                        //à chaque fois que lettre est trouvée, on implémente
                        occurrence++;
                    }
                }

                //si le nombre d'occurences max est plus petit que l'occurence de la lettre regardée
                if(nbOccurrence<occurrence)
                {
                    //la lettre trouvée est stockée dans la variable equivalente à E
                    equivalentE = lettre;
                }
            }
        }

        int cle;

        //calcul de la clé
        if(isupper(equivalentE))
        {
            cle = equivalentE - 69;
        }
        else if(islower(equivalentE))
        {
            cle = equivalentE - 101;
        }

        return cle;
    }
}

void Crypto::ChiffrerVigenere(){

    string fileNameBis("origine_message_retour.txt");
    ifstream fichier_in(fileNameBis.c_str());

    if(!fichier_in)
    {
        cout << "IMPOSSIBLE D'OUVRIR LE FICHIER" << endl;
    }
    else
    {
        long pos = fichier_in.tellg();
        fichier_in.seekg(0, ios_base::end);
        long size = fichier_in.tellg();
        fichier_in.seekg(pos, ios_base::beg);
        char message[size];

        fichier_in.read(&message[0], size);
        fichier_in.close();

        enum
        {
            a, b, c, d
        };

        for(unsigned int i=0; i<sizeof(message); i++)
        {
            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] += a;

                    if(!isupper(message[i]))
                    {
                        message[i] -= 26;
                    }
                }

                if(islower(message[i]))
                {
                    message[i] += a;

                    if(!islower(message[i]))
                    {
                        message[i] -= 26;
                    }
                }
            }
            i++;

            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] += b;

                    if(!isupper(message[i]))
                    {
                        message[i] -= 26;
                    }
                }

                if(islower(message[i]))
                {
                    message[i] += b;

                    if(!islower(message[i]))
                    {
                        message[i] -= 26;
                    }
                }
            }
            i++;
            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] += c;

                    if(!isupper(message[i]))
                    {
                        message[i] -= 26;
                    }
                }

                if(islower(message[i]))
                {
                    message[i] += c;

                    if(!islower(message[i]))
                    {
                        message[i] -= 26;
                    }
                }
            }
            i++;
            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] += d;

                    if(!isupper(message[i]))
                    {
                        message[i] -= 26;
                    }
                }

                if(islower(message[i]))
                {
                    message[i] += d;

                    if(!islower(message[i]))
                    {
                        message[i] -= 26;
                    }
                }
            }
        }

        string fileNameTris("message-retour.txt");
        ofstream fichier_out(fileNameTris.c_str());

        for(unsigned int i=0; i<sizeof(message)-12; i++)
        {
            cout << message[i];
            fichier_out << message[i];
        }

        fichier_out.close();
    }
}

void Crypto::DechiffrerVigenere(){

    string fileNameBis("message-retour.txt");
    ifstream fichier_in(fileNameBis.c_str());

    if(!fichier_in)
    {
        cout << "IMPOSSIBLE D'OUVRIR LE FICHIER" << endl;
    }
    else
    {
        long pos = fichier_in.tellg();
        fichier_in.seekg(0, ios_base::end);
        long size = fichier_in.tellg();
        fichier_in.seekg(pos, ios_base::beg);
        char message[size];

        fichier_in.read(&message[0], size);
        fichier_in.close();

        typedef enum
        {
            a, b, c, d
        }cleVigenere;

        for(unsigned int i=0; i<sizeof(message); i++)
        {
            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] -= a;

                    if(!isupper(message[i]))
                    {
                        message[i] += 26;
                    }
                }

                if(islower(message[i]))
                {
                    message[i] -= a;

                    if(!islower(message[i]))
                    {
                        message[i] += 26;
                    }
                }
            }
            i++;

            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] -= b;

                    if(!isupper(message[i]))
                    {
                        message[i] += 26;
                    }
                }

                if(islower(message[i]))
                {
                    message[i] -= b;

                    if(!islower(message[i]))
                    {
                        message[i] += 26;
                    }
                }
            }
            i++;
            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] -= c;

                    if(!isupper(message[i]))
                    {
                        message[i] += 26;
                    }
                }

                if(islower(message[i]))
                {
                    message[i] -= c;

                    if(!islower(message[i]))
                    {
                        message[i] += 26;
                    }
                }
            }
            i++;
            if(isalpha(message[i]))
            {
                if(isupper(message[i]))
                {
                    message[i] -= d;

                    if(!isupper(message[i]))
                    {
                        message[i] += 26;
                    }
                }

                if(islower(message[i]))
                {
                    message[i] -= d;

                    if(!islower(message[i]))
                    {
                        message[i] += 26;
                    }
                }
            }
        }

        string fileNameTris("origine_message_retour.txt");
        ofstream fichier_out(fileNameTris.c_str());

        for(unsigned int i=0; i<sizeof(message)-12; i++)
        {
            cout << message[i];
            fichier_out << message[i];
        }

        fichier_out.close();
    }
}


