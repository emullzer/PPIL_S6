cmake_minimum_required(VERSION 3.29)
project(PPIL_EXO)

set(CMAKE_CXX_STANDARD 20)

add_executable(PPIL_EXO
        src/Forme.cpp
        src/Forme.h
        src/Croix.cpp
        src/Croix.h
        src/Rond.cpp
        src/Rond.h
        src/Connexion/ConnexionServeur.cpp
        src/Connexion/ConnexionServeur.h
        src/TestClient.cpp
        src/TestClient.h)
target_link_libraries(PPIL_EXO ws2_32)
