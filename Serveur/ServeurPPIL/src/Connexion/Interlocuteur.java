package Connexion;

import java.io.*;
import java.net.Socket;
import java.net.SocketException;
import java.util.ArrayList;

import COR.*;
import Forme.Forme;
import dessin.*;

/**
 * Classe instanciée par Serveur et qui est unique à chaque Connexion, permettant un Serveur multi-thread.
 */
public class Interlocuteur extends Thread {

    /**
     * Numéro du client.
     */
    int noConnexion;
    /**
     * Flux pour communiquer avec le client.
     */
    PrintStream fluxSortant;
    /**
     * Flux qui reçoit les commandes du client.
     */
    BufferedReader fluxEntrant;

    /**
     * Instance de la classe Dessin permettant de créer une page et de dessiner les formes envoyées.
     */
    Dessin tableau;
    /**
     * Liste des Formes envoyées.
     */
    ArrayList<Forme> formesADessiner = new ArrayList<>();
    /**
     * Expert pour la Chain of Responsability pour le traitement des commandes reçues.
     */
    Expert chaineCOR = null;

    /**
     * Constructeur d'interlocuteur. Ceci est utilisé dans la classe Serveur dès qu'une nouvelle connexion est réalisée.
     * @param socket Socket qui s'est connectée.
     * @param noConnexion Numéro du client.
     * @throws IOException Si Problème avec l'initialisaton du Dessin.
     */
    public Interlocuteur(Socket socket, int noConnexion) throws IOException {
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        this.noConnexion = noConnexion;
        this.tableau = new Dessin();
    }

    /**
     * Fonction appelée par la classe Serveur et qui permet d'attendre pour des requêtes, puis de les traiter
     * via la COR dès qu'elle en reçoit une.
     */
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

    /**
     * Initialise la Chain of responsability pour toutes les formes.
     */
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
