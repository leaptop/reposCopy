import javafx.application.Application;
import javafx.stage.Stage;

import java.text.DecimalFormat;

public class Main extends Application {

    double x0, xn, y0, y1, z0, z1, h, H, xx[], yy[], YY[], k1, k2, k4, k3, k11, k22, k44, k33;
    double x0F = 0, y0F = 1, z0F = 1, xnF = 1, hF = 0.1, eps = 10E-8;

    public void start(Stage stage) {
        System.out.println("X\t\t\t\tY\t\t\t\tY'");
        x0 = x0F;//зн-ие аргумента// F means first
        xn = xnF;
        y0 = y0F;//зн-ие ф-ции в точке x0
        z0 = z0F;
        h = hF; // шаг
        H = 2 * h;
        int range;
        int RANGE;
        do {
            RANGE = (int) ((xn - x0) / h);
            range = (int) ((xn - x0) / H);
            xx = new double[range];
            YY = new double[range];
            System.out.println("RK4 launch with H = " + H);
            RK4(H, range, YY);
            xx = new double[RANGE];
            yy = new double[RANGE];
            y0 = y0F;
            z0 = z0F;
            System.out.println("RK4 launch with h = " + h);
            RK4(h, RANGE, yy);
            System.out.println();
            h *= 0.5;
            H = 2 * h;
            y0 = y0F;
            z0 = z0F;
        } while (Math.abs(yy[RANGE - 1] - YY[range - 1]) > eps);
    }

    public static void main(String[] args) {
        launch(args);
    }

    public double f(double x, double y, double z) {
        double result = (Math.exp(x) + y) / 2;
        return result;  //return Math.pow(x, 4) / 7;
    }

    public double g(double x, double y, double z) {
        return (z);
    }

    public void RK4(double h, int range, double[] yy) {
        double yc = y0;
        double xc = x0;
        double zc = z0;
        for (int i = 0; i < range; i++) {
            k1 = h * f(xc, yc, zc);
            k11 = h * g(xc, yc, zc);
            k2 = h * f(xc + h / 2.0, yc + k11 / 2.0, zc + k1 / 2.0);
            k22 = h * g(xc + h / 2.0, yc + k11 / 2.0, zc + k1 / 2.0);
            k3 = h * f(xc + h / 2.0, yc + k22 / 2.0, zc + k2 / 2.0);
            k33 = h * g(xc + h / 2.0, yc + k22 / 2.0, zc + k2 / 2.0);
            k4 = h * f(xc + h, yc + k33, zc + k3);
            k44 = h * g(xc + h, yc + k33, zc + k3);
            z1 = zc + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
            yy[i] = y1 = yc + (k11 + 2.0 * k22 + 2.0 * k33 + k44) / 6.0;
            yc = y1;
            xc += h;
            zc = z1;
        }
        String x00 = new DecimalFormat("#0.0000000000000").format(xc);
        String y11 = new DecimalFormat("#0.0000000000000").format(y1);
        String z11 = new DecimalFormat("#0.0000000000000").format(zc);
        System.out.println(x00 + "\t" + y11 + "\t" + z11);
    }
}