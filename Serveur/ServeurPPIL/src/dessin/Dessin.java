package dessin;

import Forme.Forme;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

/**
 * Classe gérant l'affichage des formes sur une Frame.
 * Cette classe est instanciée une fois par chaque interlocuteur.
 */
public  class Dessin {
    /**
     * Frame sur laquelle les formes vont être dessinées.
     */
    private Frame frame;
    /**
     * BufferStrategy de la Frame, permettant d'obtenir les Graphics pour dessiner.
     */
    private BufferStrategy bufferStrategy;

    /**
     * Constructeur par défaut, Initialise automatiquement la frame avec les bons paramètres.
     */
    public Dessin() {
        setupFrame();
    }

    /**
     * Permet d'initialiser une Frame et sa BufferStrategy.
     * Déclare certains paramètres comme setIgnoreRepaint à true et Resizable a false.
     */
    private void setupFrame() {
        try {
            if (frame == null) {
                frame = new Frame("Fenêtre de dessin");

                frame.setSize(800, 600);
                frame.setIgnoreRepaint(true);
                frame.setResizable(false);
                frame.setVisible(true);
                frame.createBufferStrategy(2);
                Thread.sleep(300);

                bufferStrategy = frame.getBufferStrategy();
            }
        }catch (InterruptedException e){
            e.printStackTrace();
        }
    }

    /**
     * Retourne les graphics du BufferStrategy, permettant d'afficher les formes dessus.
     * Usage unique.
     * @return
     */
    public Graphics getGraphics() {
        return bufferStrategy.getDrawGraphics();
    }

    /**
     * Fonction qui affiche les formes données en paramètres.
     * Commence par nettoyer le canvas, puis pour chacune des formes, appelle sa méthode dessiner.
     * @param formeArrayList Liste de formes donnée par l'interlocuteur.
     */
    public void afficherDessin(ArrayList<Forme> formeArrayList){
        Graphics2D g2 = (Graphics2D) getGraphics();

        //permet d'avoir des traits plus lisses avec l'utilisation de Double
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        //récupére la taille des bordures pour ne pas dessiner en dessous du titre de la page de la fenetre de dessin
        Insets insets = frame.getInsets();
        int xOffset = insets.left;
        int yOffset = insets.top;

        // efface tout les anciennes formes pour redessiner
        g2.setColor(Color.WHITE);
        g2.fillRect(0, 0, frame.getWidth(), frame.getHeight());

        //décale le dessin pour éviter de dessiner sous la barre des taches
        g2.translate(xOffset, yOffset);

        for(Forme f : formeArrayList){
            f.dessiner(g2);
        }

        bufferStrategy.show();
        g2.dispose();
    }


}
