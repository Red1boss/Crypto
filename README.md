# Crypto
Défi du BTS SN avec le CNED GRENOBLE

Par équipes de 2 à 5 étudiants, prouvez que vous êtes les maîtres du cryptage !
Vous aurez deux semaines pour mener à bien deux missions.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

MISSION N°1

Vous venez d’être recruté(e) comme agent secret par la fameuse agence Gang qui vous confie
votre première mission : mener une cyber-attaque contre l’agence Charly.
Voici le premier message à transmettre à votre agence :

    Important: We are preparing an attack of Charly’s computer server by a Wardriving
    attack this week.
    We will attempt a passive attack of their network and search the access point. We will
    listen to the radio traffic with a scanner and try to decrypt the WPA key.
    Here is my position:
    latitude forty one degrees seven minutes forty one point four two seconds North,
    longitude one degree fifteen minutes twenty point six seven seconds East.
    Unlimited budget required.

Il ne faut surtout pas que ce message tombe entre les mains de vos ennemis. Vous savez que les
agents de Charly sont prêts à tout.
Vous allez donc chiffrer votre message et faire appel à vos souvenirs de BTS SN…

    Je me souviens … « On dit chiffrer un message et non crypter.
    Crypter est un anglicisme provenant du verbe encrypt.
    Le chiffrement permet de rendre un message non
    compréhensible à toute personne ne possédant pas la clé.
    Déchiffrer est le contraire de chiffrer et permet de retrouver le
    texte d’origine grâce à la clé que l’on possède.
    Le verbe décrypter existe ! Il s’utilise quand quelqu’un essaie
    de retrouver un message sans posséder la clé de chiffrement
    ou déchiffrement. »
   
    Ouais, bon, ça m’fait pas vraiment avancer…
    Comment je vais chiffrer ce message ?
    Ah oui, le code César !

Pour communiquer avec ses généraux, un des procédés de chiffrement
utilisé par César consistait à remplacer chaque lettre du message à
crypter par une autre lettre évidemment différente.
La substitution de la lettre d’origine par une autre se faisait sur la base
d’un décalage circulaire.
César utilisait un décalage de valeur 3, c’est à dire que la lettre “a” était
remplacée par “d”, la lettre “b” par un “e” etc…
L’alphabet d’origine (en bleu) est donc remplacé par celui en vert.
Mais que deviennent les lettres x,y,z ?
Comme le décalage est circulaire ces lettres vont être substituées par
a,b,c comme le montre la figure ci-dessous :
Le code de César fait partie des chiffrements à clé symétrique car la
même clé est utilisée, tant pour chiffrer les données que pour les
déchiffrer.

    Il est maintenant temps de programmer ma solution. L’agence attend mon
    message chiffré !!
    Je vais créer une solution basée sur le langage C++ et utiliser la classe Crypto
    suivante :
    
      Crypto
    +fichier_out : ofstream
    +fichier_in : ifstream
    +fileName : string
    -x : int
    -y : int
    -c : char
    +Crypto()
    +Chiffrer(key :int) : void
    +Dechiffrer(key: int) : void
    +LireMessage(void) : void
    
    Cette classe me permettra d’écrire ou lire un fichier grâce à la bibliothèque
    <fstream> qui contient les classes ofstream et ifstream.
    ofstream représente le flux de fichier de sortie. Cette classe est utilisée pour créer
    des fichiers et pour y écrire des informations.
    ifstream représente le flux de fichier d’entrée et permet de lire le contenu du
    fichier.
    Mon application permettra la lecture, le chiffrement ou déchiffrement d’un fichier
    grâce à une clé secrète comprise entre 1 et 25.
    Ahahah, je suis trop fort !!!!!!!!!
    Allez, c’est parti. Je commence par créer un fichier d’origine « origine.txt » et un
    fichier chiffré « message.txt ».
    
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

MISSION N°2

Votre agence vient d’intercepter un message destiné à l’agence Charly. L’avenir de votre
agence dépend de vous ! C’est une question d’heures. Vite, vous devez le décrypter.


    Swzybdkxd: Go kbo zbozkbsxq kx kddkmu yp Qkxq’c mywzedob cobfob li Noxskv yp Cobfsmo (Nyc).
    Go gsvv boxd zygobpev gol cobfobc gsdr rsqr lkxngsndr dy yfobgrovw drosb cobfob.
    Robo sc wi zycsdsyx:
    vkdsdeno pybdi psfo noqbooc pybdi pyeb wsxedoc drsbdi osqrd zysxd yxo pyeb comyxnc Xybdr,
    vyxqsdeno cofox noqbooc xsxodoox wsxedoc joby yxo zysxd psfo comyxnc Okcd.
    Exvswsdon lenqod boaesbon.

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------

    Je vais réutiliser mon programme de chiffrement avec le code César !
    Je n’ai pas le temps de tester les 25 possibilités, je dois trouver une
    méthode plus rapide…
    Ah oui, l’analyse des fréquences ! La fréquence d’utilisation des
    lettres varie d’une langue à l’autre. Certaines apparaissent davantage
    que d’autres.
    En espagnol, c’est le « e ».
    Je suis sûr que les agents Charly communiquent en anglais. Il faut donc
    que je trouve cette analyse des fréquences pour l’anglais…
    Si j’ai bien compris, si je trouve un pic sur la lettre f, ça voudra dire que
    j’ai un décalage de 1 dans le code César.
    
    Pas de temps à perdre, je vais concevoir un programme qui permet de réaliser une analyse des
    fréquences sur le fichier texte que mon agence a intercepté. J’obtiendrai ainsi
    la clé de chiffrement utilisée que j’insérerai dans mon premier programme de déchiffrement.
    Je suis génial, non ?
    
    J’ai réussi à déchiffrer le message de l’agence Charly, c’est terrible… il
    faut absolument que j’informe l’agence et que j’évite le pire. Je sais
    maintenant où ils se cachent.
    Mais bon la méthode César est trop facile à cracker. Je vais utiliser cette
    fois le chiffre de Vigenère.


Blaise de Vigenère (1523-1596) était un diplomate français et son activité l’amena donc à étudier
la cryptographie.
Le type de chiffrement que Vigenère a mis au point est une amélioration du code de César.
Il consiste à associer à chaque lettre une autre lettre différente sans faire de décalage de tout
l’alphabet.
La clé ne sera plus composée d’un chiffre unique ou d’une seule lettre, mais d’une suite de
plusieurs lettres.
Voyons comment cela fonctionne en prenant par exemple une clé égale à “abcd”:

alphabet |      a b c d e f g h i j k l m n o p q r s t u v w x y z

Clé |           a b c d

Texte chiffré | a c e g

Donnons quelques explications :
  Une clé égale à ”a“ ne produit aucun décalage, donc décalage = 0.
  Une clé égale à ”b“ produit un décalage de 1 position, donc décalage = 1.
  
La lettre ”b“ décalée de 1 rang devient ”c“.

  Pour une clé égale à ”c“, décalage = 2. La lettre ”c“ décalée de 2 rangs devient ”e“.
  
Si ma clé ne fait que 4 lettres, comment faire pour l’appliquer à un texte plus long ?
Il suffit de la répéter pour tout le texte et nous obtenons ainsi pour notre alphabet :

alphabet |      a b c d e f g h i j k l m n o p q r s t u v w x y z

Clé |           a b c d a b c d a b c d a b c d a b c d a b c d a b

Texte chiffré | a c e g e g i k i k m o m o q s q s u w u w y a y a


    Ok, je suis au point. Il est temps de programmer ma solution et d’envoyer à mon
    agence les coordonnées GPS de l’agent Charly et de l’informer de leur terrible plan.
    Je vais compléter la classe Crypto de façon à rajouter 2 méthodes permettant de
    chiffrer ou déchiffrer grâce au chiffrement de Vigenère :
    
    void ChiffrerVigenere(string key )
    void DechiffrerVigenere(string key )
    
    Je vais renommer mes méthodes précédentes en :
    
    void ChiffrerCesar(int key )
    void DechiffrerCesar(int key )
    
      Crypto
    +fichier_out : ofstream
    +fichier_in : ifstream
    +fileName : string
    +key : int
    -x : int
    -c : char
    +Crypto()
    +DechiffrerCesar(key : int) : void
    +ChiffrerCesar(key : int) : void
    +ChiffrerVigenere(key : string) : void
    +DechiffrerVigenere(key : string) : void
    +LireMessage() : void
    
    Ahahah, je suis trop fort !!!!!!!!!
    Allez, c’est parti. Je vais livrer à mon agence un fichier chiffré « message-retour.txt »
    et mon fichier source pour les agents non informaticiens !
    Ils ne nous auront pas !!!!!!!!!!!


