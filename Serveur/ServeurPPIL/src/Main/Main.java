package Main;

import Connexion.Serveur;

/**
 * Classe Main permettant de démarrer le serveur.
 */
public class Main {
    /**
     * Démarre le serveur.
     * @param args arguments éventuels
     * @throws InterruptedException Quand la socket est interrompue.
     */
    public static void main(String[] args) throws InterruptedException {
        Serveur serveur = new Serveur();
        serveur.start();


    }
}