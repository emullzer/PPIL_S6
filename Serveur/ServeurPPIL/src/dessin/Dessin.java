package dessin;

import Forme.Forme;

import java.awt.*;
import java.awt.image.BufferStrategy;
import java.util.ArrayList;

public  class Dessin {
    static Frame frame;
    static BufferStrategy bufferStrategy;

    public Dessin() throws InterruptedException {
        setupFrame();
    }

    private static void setupFrame() throws InterruptedException {
        if (frame == null) {
            frame = new Frame("Fenêtre de dessin");
            frame.setBounds(30,60,400,400);
            frame.setVisible(true);
            frame.setIgnoreRepaint(true);
            frame.createBufferStrategy(2);
            Thread.sleep(150);

            bufferStrategy = frame.getBufferStrategy();
        }
    }
    public Graphics getGraphics() {
        return bufferStrategy.getDrawGraphics();
    }

    public void afficherDessin(ArrayList<Forme> formeArrayList){
        Graphics g = getGraphics();
        g.clearRect(0,0,frame.getWidth(),frame.getHeight());

        for(Forme f : formeArrayList){
            f.dessiner(g);
        }

        g.dispose();
        bufferStrategy.show();
    }
}
