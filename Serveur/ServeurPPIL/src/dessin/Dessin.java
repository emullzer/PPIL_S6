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

                Canvas canvas = new Canvas();
                canvas.setSize(800, 600);
                frame.add(canvas);
                frame.setIgnoreRepaint(true);
                frame.setResizable(false);
                frame.pack();
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

        // Antialiasing pour trait propre
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);

        g2.clearRect(0,0,frame.getWidth(),frame.getHeight());

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
