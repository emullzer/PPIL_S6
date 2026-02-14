package dessin;

import java.awt.*;
import java.awt.image.BufferStrategy;

public abstract class Dessin {
    static Frame frame;
    static Graphics graphics;
    static BufferStrategy bufferStrategy;

    public Dessin() {}

    public static Frame getInstanceFrame() throws InterruptedException {
        if (frame == null) {
            frame = new Frame("Fenêtre de dessin");
            frame.setBounds(30,60,400,400);
            frame.setVisible(true);
            frame.setIgnoreRepaint(true);
            frame.createBufferStrategy(3);
            Thread.sleep(150);

            bufferStrategy = frame.getBufferStrategy();
            graphics = bufferStrategy.getDrawGraphics();
        }
        return frame;
    }
    public static Graphics getGraphics() {
        return graphics;
    }

    public void afficherDessin(){
        if (graphics!=null) {
            graphics.dispose();
        }
        if (bufferStrategy !=null)
        {
            bufferStrategy.show();
        }
    }

    public abstract void dessiner(String forme,Graphics g);
}
