package dessin;

import java.awt.*;
import java.awt.image.BufferStrategy;

public abstract class Dessin {
    Frame frame;
    Graphics graphics;
    BufferStrategy bufferStrategy;

    public Dessin() {}

    public void framesetup() throws InterruptedException {
        frame = new Frame("dessin.Dessin demande");
        frame.setBounds(30,60,400,400);
        frame.setVisible(true);
        frame.setIgnoreRepaint(true);
        frame.createBufferStrategy(3);
        Thread.sleep(150);

        bufferStrategy = frame.getBufferStrategy();
        graphics = bufferStrategy.getDrawGraphics();
    }
    public abstract void dessiner(String forme);
}
