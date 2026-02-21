package Connexion;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;

public class Serveur extends Thread {
    //private boolean running = false;
    final private int port = 9111;

    public Serveur() {}

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
