/*
 Initialisation d'une structure contenant tous les champs généraux du chat:
    - le nombre de clients
    - le nombre de lignes en réception
    - le nombre de lignes en envoie
    - le nombre maximal de clients
 */
struct serv_t {
	unsigned int nb_clients;
	unsigned int nb_lignes_reception;
	unsigned int nb_lignes_envoie;
	unsigned int nb_max_clients;
};

/*
 Initialisation d'une structure contenant tous les champs d'un client:
    - l'id d'un client
    - le nombre de lignes reçues par client
    - le nombre de lignes envoyées par client
 */
struct client_t {
    unsigned int id_client;
    unsigned int nb_lignesRecues_client;
    unsigned int nb_lignesEnvoyees_client;
    unsigned int activite;
};

/*Structure globale statistique*/
struct serv_t statistiques;

/*Fonction permettant d'ajouter un client dans le tableau de statistiques (avec initialisation des différents champs de cette structure*/
void add_client(int);

/*Fonction permettant de supprimer un client dans le tableau de statistiques*/
void del_client(int);

/*Fonction permettant d'incrémenter le nombre de messages reçus, ainsi que le nombre de messages envoyés SI ET SEULEMENT SI le client a envoyé le message*/
void incr_msg_client(int);

/*Fonction permettant d'afficher les statistiques (serveur et client)*/
void display_stat();
