#ifndef CONNEXIONSERVEUR_H
#define CONNEXIONSERVEUR_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

/**
 * @class ConnexionServeur
 * @brief Singleton gérant la communication réseau TCP/IP avec le serveur d'affichage.
 * * Cette classe encapsule toute la logique de bas niveau de l'API Winsock.
 * Elle assure l'ouverture d'une socket unique, la connexion au serveur Java
 * et la libération des ressources lors de la fermeture de l'application.
 */
class ConnexionServeur {
private:
    SOCKET sock;              /**< Descripteur de la socket Windows. */
    /**< Adresse IP du serveur (localhost par défaut). */
    std::string adresseServeur = "127.0.0.1";
    /**< Port de destination pour le serveur Java. */
    int portServeur = 9111;

    /**
     * @brief Constructeur privé (Singleton).
     * Initialise la bibliothèque Winsock, crée la socket et établit la connexion.
     * @throw std::runtime_error En cas d'échec de l'initialisation ou de la connexion.
     */
    ConnexionServeur() {
        WSADATA wsaData;
        if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
            throw std::runtime_error("WSAStartup failed");
        }

        sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sock == INVALID_SOCKET) {
            WSACleanup();
            throw std::runtime_error("Socket creation failed");
        }

        sockaddr_in sockAddr{};
        sockAddr.sin_family = AF_INET;
        sockAddr.sin_port = htons(portServeur);

        // Conversion moderne de l'adresse string en format binaire réseau
        inet_pton(AF_INET, adresseServeur.c_str(), &sockAddr.sin_addr);

        if (connect(sock, (struct sockaddr*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR) {
            closesocket(sock);
            WSACleanup();
            throw std::runtime_error("Connection impossible");
        }

        std::cout << "Connecté au serveur de dessin" << std::endl;
    }

    /**
     * @brief Destructeur.
     * Ferme la socket et nettoie les ressources Winsock (WSACleanup).
     */
    ~ConnexionServeur() {
        if (sock != INVALID_SOCKET) {
            closesocket(sock);
        }
        WSACleanup();
    }

public:

    /**
     * @brief Récupère l'instance unique de la connexion (Singleton).
     * @return Référence sur l'instance unique de ConnexionServeur.
     */
    static ConnexionServeur& getInstance() {
        static ConnexionServeur instance;
        return instance;
    }

    /** @brief Interdiction du constructeur par copie. */
    ConnexionServeur(ConnexionServeur const&) = delete;
    /** @brief Interdiction de l'opérateur d'affectation. */
    void operator=(const ConnexionServeur&) = delete;

    /**
     * @brief Envoie un message texte (requête) au serveur Java.
     * @param message Chaîne de caractères à envoyer via la socket.
     */
    void envoyerRequete(const std::string& message) const;
};

#endif //CONNEXIONSERVEUR_H