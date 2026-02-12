package dessin;

import static java.lang.Integer.parseInt;

public class DessinCroix extends Dessin {

    public DessinCroix() {
        super();
    }

    @Override
    public void dessiner(String forme) {
        String valeurs[] = forme.split(",");
        graphics.drawLine(parseInt(valeurs[0]), parseInt(valeurs[1]), parseInt(valeurs[2]), parseInt(valeurs[3]));
        graphics.drawLine(parseInt(valeurs[0]), parseInt(valeurs[3]), parseInt(valeurs[2]), parseInt(valeurs[1]));
        bufferStrategy.show();
        graphics.dispose();
    }
}
