package Connexion;

import java.io.*;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;
import java.util.Objects;

import Forme.Forme;
import dessin.*;

public class GestionnaireFormes extends Thread {


    int noConnexion;
    PrintStream fluxSortant;
    BufferedReader fluxEntrant;
    ArrayList<Forme> formeArrayList = new ArrayList<>();

    public GestionnaireFormes(Socket socket, int noConnexion) throws IOException {
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        this.noConnexion = noConnexion;

    }

    public void run(){
        try {
            System.out.println("Enchanté je suis l'interlocuteur n° " + noConnexion + " et je suis à pret et à votre service");

            String requete = this.fluxEntrant.readLine();
            if (requete == null) this.interrupt();
            else
            {

                System.out.println("Le client n° " + this.noConnexion + " à envoyé : " + requete);

                String forme = requete.split("\\[")[0];
                Dessin dessin = new Dessin();


                this.fluxSortant.println("Dessin mis à jour.");
            }


        } catch (SocketException s){
            System.out.println("le client n°" + this.noConnexion+ " a mis fin à la conversation");
        } catch (IOException e) {
            this.fluxSortant.println("Probleme lors de la lecture du message du client.");
        } catch (InterruptedException e) {
            this.fluxSortant.println("Probleme lors de la création de l'interface de dessin.");
        }
    }
}
