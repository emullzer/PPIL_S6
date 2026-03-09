package Connexion;

import java.io.*;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;

import COR.*;
import Forme.Forme;
import dessin.*;

public class Interlocuteur extends Thread {


    int noConnexion;
    PrintStream fluxSortant;
    BufferedReader fluxEntrant;

    Dessin tableau;
    ArrayList<Forme> formesADessiner = new ArrayList<>();
    Expert chaineCOR = null;

    public Interlocuteur(Socket socket, int noConnexion) throws IOException {
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        this.noConnexion = noConnexion;
        this.tableau = new Dessin();
    }

    public void run(){
        try {
            System.out.println("Enchanté je suis l'interlocuteur n° " + noConnexion + " et je suis à pret et à votre service");
            setupCOR();

            while(!this.isInterrupted()){
                String requete = this.fluxEntrant.readLine();
                if (requete == null) this.interrupt();
                else
                {
                   //System.out.println("Le client n° " + this.noConnexion + " à envoyé : " + requete);

                    Forme forme = chaineCOR.afficher(requete);
                    if (forme ==null)
                    {
                        this.fluxSortant.println("Aucun expert n'a compris votre requete.");
                    }
                    else {
                        formesADessiner.add(forme);
                        tableau.afficherDessin(formesADessiner);
                    }
                }
            }


        } catch (SocketException s){
            System.out.println("le client n°" + this.noConnexion+ " a mis fin à la conversation");
        } catch (IOException e) {
            this.fluxSortant.println("Probleme lors de la lecture du message du client.");
        }
    }

    private void setupCOR(){
        chaineCOR = new ExpertRond(chaineCOR);
        chaineCOR = new ExpertSegment(chaineCOR);
        chaineCOR = new ExpertTriangle(chaineCOR);
        chaineCOR = new ExpertNettoyage(formesADessiner,chaineCOR);
        chaineCOR = new ExpertRectangle(chaineCOR);
        chaineCOR = new ExpertPolygone(chaineCOR);
        chaineCOR = new ExpertGroupe(chaineCOR,chaineCOR);
    }
}
