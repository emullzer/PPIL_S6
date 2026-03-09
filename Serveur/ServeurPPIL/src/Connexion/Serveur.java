package Connexion;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * Classe qui sert de Serveur, qui capte les connexions et envoie un interlocuteur pour chacune d'elles.
 */
public class Serveur extends Thread {
    /**
     * Port du serveur.
     */
    final private int port = 9111;

    /**
     * Constructeur par défaut.Ici, le port est déjà initialisé donc ne fait rien.
     */
    public Serveur() {}

    /**
     * Fonction appelée par la fonction Main.Main.
     * Dès qu'une connexion est réalisée, crée un interlocuteur unique pour celle-ci.
     */
    @Override
    public void run() {
        try {
            ServerSocket server = new ServerSocket(port);
            System.out.println("Serveur en route.");
            int nConnection = 0;

            while(true){
                System.out.println("Serveur En attente de la prochaine connexion");
                Socket socket = server.accept();
                nConnection++;
                System.out.println("Connexion n'"+nConnection);

                Interlocuteur interlocuteur = new Interlocuteur(socket,nConnection);
                interlocuteur.start();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
