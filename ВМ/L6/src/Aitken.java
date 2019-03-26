import javafx.application.Application;
import javafx.stage.Stage;

import java.lang.*;

public class Aitken extends Application {

    double[] xi = {1, 1.2, 1.4, 1.6};
    double[] fi = {1, 1.0954, 1.1832, 1.2649};



    //double f = aitken(x, xi, fi);
    public static void main(String[] argv) {
        launch(argv);
    }

    @Override
    public void start(Stage stage) {
        ait();
    }
    double[] xx = {1, 1.2, 1.4, 1.6};
    double[] yy = {1, 1.0954, 1.1832, 1.2649};

    double x = 1.44;

    public void ait() {
        for (int i = 0; i < xx.length - 1; i++) {
            for (int k = 1; k < xx.length; k++) {
                yy[k-1] = (yy[k-1] * (x - xx[k]) - yy[k] * (x - xx[k-1])) / (xx[k-1] - xx[k]);
                System.out.println(yy[k-1]);
            }
        }

    }
}
