package dessin;

import java.awt.*;

import static java.lang.Integer.parseInt;

public class DessinRond extends Dessin{

    public DessinRond() {super();}
    @Override
    public void dessiner(String forme, Graphics g) {
        try {
            getInstanceFrame();
            String[] valeurs = forme.split(",");
            g.fillOval(parseInt(valeurs[0]), parseInt(valeurs[1]), parseInt(valeurs[2]), parseInt(valeurs[2]));
            afficherDessin();
        }catch(InterruptedException e)
        {
            System.out.println(e);
        }
    }
}
