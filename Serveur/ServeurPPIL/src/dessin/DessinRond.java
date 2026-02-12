package dessin;

import static java.lang.Integer.parseInt;

public class DessinRond extends Dessin{

    public DessinRond() {super();}
    @Override
    public void dessiner(String forme) {
        String[] valeurs = forme.split(",");
        graphics.drawOval(parseInt(valeurs[0]),parseInt(valeurs[1]),parseInt(valeurs[2]),parseInt(valeurs[2]));
        bufferStrategy.show();
        graphics.dispose();
    }
}
