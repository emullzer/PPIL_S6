#ifndef CONNEXIONSERVEUR_H
#define CONNEXIONSERVEUR_H

#include <winsock2.h>
#include <ws2tcpip.h> // For modern IP conversion functions
#include <iostream>
#include <string>

// Link with Ws2_32.lib
#pragma comment(lib, "Ws2_32.lib")

class ConnexionServeur {
private:
    SOCKET sock = INVALID_SOCKET;
    std::string adresseServeur = "127.0.0.1";
    int portServeur = 9111;

public:
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
            throw std::runtime_error("Connection to server failed");
        }
        
        std::cout << "Connected to server successfully!" << std::endl;
    }

    ~ConnexionServeur() {
        if (sock != INVALID_SOCKET) {
            closesocket(sock);
        }
        WSACleanup();
    }

    void envoyerRequete(const std::string& message) const {
        int bytesSent = send(sock, message.c_str(), static_cast<int>(message.length()), 0);
        if (bytesSent == SOCKET_ERROR) {
            std::cerr << "Send failed: " << WSAGetLastError() << std::endl;
        }
    }
};

#endif //CONNEXIONSERVEUR_H