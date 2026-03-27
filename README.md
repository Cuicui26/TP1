# TP1 – File par tableau circulaire
## Contexte
L’objectif de ce sujet est de concevoir une librairie nommée MessStacker
permettant de gérer une file (une pile FIFO) de messages. Des producteurs (les
expéditeurs) alimentent la file en « postant » des messages. Et des
consommateurs (les receveurs) analysent le contenu de ces messages un par un,
puis demandent de passer au message suivant. Cette librairie expose pour cela
un ensemble de fonction qui vont permettre la gestion du stockage des messages
reçus, en attendant qu’ils soient consultés puis retirés du stock. 

Les messages considérés ici sont constitués d’un bloc d’octet data, associé à
une commande cmd (un nombre). Pour garantir l’intégrité de l’information, le
message sera associé à un checksum (code de contrôle) qui sera calculé sur
l’ensemble cmd+data. Ce checksum pourra ainsi être utilisé à tout moment pour
vérifier que le message n’a pas été altéré au cours de la chaine de transmission
(en particulier s’il est amené à transiter sur le réseau).
La particularité de l’implémentation que nous allons réaliser dans ce sujet,
est que la file de message est matérialisée par un tableau circulaire

## Arborescence 
- bin : Contient les fichiers exécutables

- build : Contient les .o

- src : Contient le code source du projet (les .c et .h)

- test : zone d'essais durant la phase de développement

## Dépôt distant
Il existe pour ce projet un dépôt distant disponible sur github à cet url : https://github.com/Cuicui26/TP1.git

## API de la librairie
- haveMessage : vérifie si il y a un message dans la file

- curMessageCmd, curMessageSize, et curMessageChecksum : ces 3
fonctions ne prennent pas d’arguments et retourne un entier non signé
sur 8 bits.

- curMessageData : cette fonction prend un tableau d’octet buff en
argument, un entier lengthMax, et retourne une valeur booléenne.

- checksumMessage : cette fonction attend 3 arguments : cmd, data et
size, tous de types identiques à ceux de la fonction sendMessage, et
elle retourne un entier non signé sur 8 bits.