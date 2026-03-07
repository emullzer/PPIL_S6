cmake_minimum_required(VERSION 3.29)
project(PPIL_CLIENT)

set(CMAKE_CXX_STANDARD 20)

add_executable(PPIL_CLIENT
        src/Formes/Forme.cpp
        src/Formes/Forme.h
        src/Formes/Segment.cpp
        src/Formes/Segment.h
        src/Formes/Rond.cpp
        src/Formes/Rond.h
        src/Formes/Rectangle.cpp
        src/Formes/Rectangle.h
        src/Connexion/ConnexionServeur.cpp
        src/Connexion/ConnexionServeur.h
        src/Tests/TestClient.cpp
        src/Calculs/Vecteur2D.h
        src/Calculs/Vecteur2D.cpp
        src/Calculs/Matrice22.h
        src/Calculs/Plan.h
        src/Calculs/Plan.cpp
        src/Formes/Triangle.cpp
        src/main.cpp
        src/Formes/Groupe.h
        src/Formes/Groupe.cpp
        src/Formes/Polygone.cpp
        src/Formes/Polygone.h
        src/Calculs/Plan.h
        src/Calculs/Plan.h
        src/Calculs/Matrice22.h
        src/Calculs/FormesManager.h
        src/Calculs/FormesManager.cpp
        src/Visiteur/VisiteurDessin.h
        src/Visiteur/VisiteurDessin.cpp
        src/Visiteur/VisiteurDessinJava.h
        src/Visiteur/VisiteurDessinJava.cpp
        src/Visiteur/VisiteurSauvegarde.h
        src/Visiteur/VisiteurSauvegarde.cpp
        src/COR/Expert.h
        src/COR/ExpertCharger.h
        src/COR/ExpertCharger.cpp

)
target_link_libraries(PPIL_CLIENT ws2_32)
