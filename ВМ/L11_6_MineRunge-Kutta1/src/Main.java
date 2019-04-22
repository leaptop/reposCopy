import javafx.application.Application;
import javafx.stage.Stage;
// метод Эйлера с пересчетом - то же, что метод Рунге-Кутта 2-го порядка
public class Main extends Application {
    //взято с http://www.simumath.net/library/book.html?code=Dif_Ur_example
    //Вычислить методом Рунге-Кутта интеграл дифференциального уравнения y' = x + y при начальном
    // условии y(0) = 1  на отрезке [0, 0.5] с шагом интегрирования h = 0.1
    //производная первого порядка:
    public double fDer(double x, double y) {
        return x + y;
    }

    double h = 0.1;
    double x0 = 0.0;
    double xn = 0.5;
    double y0 = 1, y1;
    double k1, k2, k3, k4, delta_y0;

    int range = (int) ((xn - x0) / h);
    double yy[] = new double[range + 1];

    double xx[] = new double[range];

    public double integrateRK4OrderClassical()  {
        System.out.println("range = " + range);
        yy[0] = y0;
        xx[0] = x0;
        for (int i = 0; i < range; i++) {
            if (i > 0) xx[i] = xx[i - 1] + h;
            System.out.println("yy[" + i + "] = " + yy[i]);
            k1 = fDer(xx[i], yy[i]);
            System.out.println("k1 = " + k1);
            k2 = fDer(xx[i] + h / 2, yy[i] + h / 2 * k1);
            System.out.println("k2 = " + k2);
            k3 = fDer(xx[i] + h / 2, yy[i] + h / 2 * k2);
            System.out.println("k3 = " + k3);
            k4 = fDer(xx[i] + h, yy[i] + h * k3);
            System.out.println("k4 = " + k4);
            delta_y0 = h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
            System.out.println("deltay0 = " + delta_y0);
            yy[i + 1] = yy[i] + delta_y0;

        }
        System.out.println("yy[" + range + "] = y("+(xx[range-1]+h)+") = " + yy[range]);
        return yy[range];
    }

    public void start(Stage stage) {
        //Вычислим y1. Для этого сначала последовательно вычисляем kj:
        /*k1 = x0 + y0;
        k2 = x0 + h / 2 + y0 + h * k1 / 2;
        k3 = x0 + h / 2 + y0 + h * k2 / 2;
        k4 = x0 + h + y0 + h * k3;

        delta_y0 = h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
        y1 = y0 + delta_y0;*/
        integrateRK4OrderClassical();


    }

    public static void main(String[] args) {
        launch(args);
    }

}

