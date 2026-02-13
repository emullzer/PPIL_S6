#ifndef CONNEXIONSERVEUR_H
#define CONNEXIONSERVEUR_H

#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

class ConnexionServeur {
private:
    SOCKET sock = INVALID_SOCKET;
    std::string adresseServeur = "127.0.0.1";
    int portServeur = 9111;

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
        // Modern way to set the address
        inet_pton(AF_INET, adresseServeur.c_str(), &sockAddr.sin_addr);

        if (connect(sock, (struct sockaddr*)&sockAddr, sizeof(sockAddr)) == SOCKET_ERROR) {
            closesocket(sock);
            WSACleanup();
            throw std::runtime_error("Connection impossible");
        }

        std::cout << "Connecté au serveur de dessin" << std::endl;
    }

    ~ConnexionServeur() {
        if (sock != INVALID_SOCKET) {
            closesocket(sock);
        }
        WSACleanup();
    }

public:

    static ConnexionServeur& getInstance() {
        static ConnexionServeur instance;
        return instance;
    }

    ConnexionServeur(ConnexionServeur const&) = delete;
    void operator=(const ConnexionServeur&) = delete;


    void envoyerRequete(const std::string& message) const;
};

#endif //CONNEXIONSERVEUR_H