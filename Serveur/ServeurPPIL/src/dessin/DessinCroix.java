package dessin;

import java.awt.*;

import static java.lang.Integer.parseInt;

public class DessinCroix extends Dessin {

    public DessinCroix() {
        super();
    }

    @Override
    public void dessiner(String forme, Graphics g) {
        try {
            getInstanceFrame();
            String valeurs[] = forme.split(",");
            g.drawLine(parseInt(valeurs[0]), parseInt(valeurs[1]), parseInt(valeurs[2]), parseInt(valeurs[3]));
            g.drawLine(parseInt(valeurs[0]), parseInt(valeurs[3]), parseInt(valeurs[2]), parseInt(valeurs[1]));
            afficherDessin();
        }catch(InterruptedException e)
        {
            System.out.println(e);
        }
    }
}
