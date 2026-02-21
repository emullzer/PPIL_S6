package Connexion;

import java.io.*;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;

import COR.Expert;
import COR.ExpertCroix;
import COR.ExpertRond;
import COR.ExpertTriangle;
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
                    System.out.println("Le client n° " + this.noConnexion + " à envoyé : " + requete);

                    String reponse = chaineCOR.afficher(requete);
                    if (reponse ==null)
                    {
                        this.fluxSortant.println("Aucun expert n'a compris votre requete.");
                    }
                    else {

                        this.fluxSortant.println(requete);
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
        chaineCOR = new ExpertRond(formesADessiner,chaineCOR);
        chaineCOR = new ExpertCroix(formesADessiner,chaineCOR);
        chaineCOR = new ExpertTriangle(formesADessiner,chaineCOR);
    }
}
