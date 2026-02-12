package Connexion;

import java.io.*;
import java.net.Socket;
import java.util.Objects;

import dessin.*;

public class Interlocuteur extends Thread {


    int noConnexion;
    PrintStream fluxSortant;
    BufferedReader fluxEntrant;

    public Interlocuteur(Socket socket, int noConnexion) throws IOException {
        this.fluxSortant = new PrintStream(socket.getOutputStream());
        this.fluxEntrant = new BufferedReader(new InputStreamReader(socket.getInputStream()));

        this.noConnexion = noConnexion;
        // PAS DE CATCH ICI SINON C4EST QUE RIEN COMPRIS
        //ici on sait pas reparer juste elle renvoie l'exception
    }

    public void run(){
        try {
            System.out.println("Enchanté je suis l'interlocuteur n° " + noConnexion + " et je suis à pret et à votre service");

            while (!this.isInterrupted()) {
                String requete = this.fluxEntrant.readLine();

                if (requete == null) this.interrupt();
                else {

                    System.out.println("Le client n° " + this.noConnexion + " à envoyé : " + requete);

                    String forme = requete.split("\\[")[0];
                    Dessin dessin;
                    if (Objects.equals(forme, "Rond"))
                    {
                        dessin = new DessinRond();
                    }
                    else {
                        dessin = new DessinCroix();
                    }
                        dessin.framesetup();
                        String coordonnees = requete.split("\\[")[1];
                        coordonnees = coordonnees.substring(0,coordonnees.length()-1);
                        dessin.dessiner(coordonnees);


                    this.fluxSortant.println("dessin.Dessin effectue");
                }
            }
            System.out.println("le client n°" + this.noConnexion+ " a mis fin à la conversation");

        }catch (IOException e) {
            e.printStackTrace();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }
    }
}
