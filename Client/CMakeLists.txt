cmake_minimum_required(VERSION 3.29)
project(PPIL_EXO)

set(CMAKE_CXX_STANDARD 20)

add_executable(PPIL_EXO
        src/Formes/Forme.cpp
        src/Formes/Forme.h
        src/Formes/Croix.cpp
        src/Formes/Croix.h
        src/Formes/Rond.cpp
        src/Formes/Rond.h
        src/Connexion/ConnexionServeur.cpp
        src/Connexion/ConnexionServeur.h
        src/Tests/TestClient.cpp
        src/Tests/TestClient.h
        src/Formes/Vecteur2D.h
        src/Formes/Triangle.cpp
        src/main.cpp
        src/Formes/Groupe.h
        src/Formes/Groupe.cpp)
target_link_libraries(PPIL_EXO ws2_32)
