package dessin;

import Forme.Forme;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

public  class Dessin {
    private Frame frame;
    private BufferStrategy bufferStrategy;

    public Dessin() {
        setupFrame();
    }

    private void setupFrame() {
        try {
            if (frame == null) {
                frame = new Frame("Fenêtre de dessin");

                frame.setSize(800, 600);
                frame.setIgnoreRepaint(true);
                frame.setResizable(false);
                frame.setVisible(true);
                frame.createBufferStrategy(2);
                Thread.sleep(150);

                bufferStrategy = frame.getBufferStrategy();
            }
        }catch (InterruptedException e){
            e.printStackTrace();
        }
    }
    public Graphics getGraphics() {
        return bufferStrategy.getDrawGraphics();
    }

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

    public void changerTailleCanvas(int longueur, int hauteur)
    {

    }
}
