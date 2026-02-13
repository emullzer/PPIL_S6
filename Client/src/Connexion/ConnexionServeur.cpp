//
// Created by mulle1149u on 07/02/2026.
//

#include "ConnexionServeur.h"

void ConnexionServeur::envoyerRequete(const std::string& message) const  {
    int testEnvoi = send(sock, message.c_str(), static_cast<int>(message.length()), 0);
    if (testEnvoi == SOCKET_ERROR) {
        std::cerr << "Send failed: " << WSAGetLastError() << std::endl;
    }
}
