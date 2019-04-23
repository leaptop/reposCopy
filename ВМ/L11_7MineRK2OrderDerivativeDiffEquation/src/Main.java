import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

import java.text.DecimalFormat;

//Math.pow(x, 4)/12 + C - это интеграл взятый два раза от x^2
public class Main extends Application {
    //решение системы дифференциальных уравнений методом Рунге-Кутты(Runge-Kutta-Nystrom)
    //как здесь применить интегрирование для представления g через z?
    //смогу ли я применить здесь интегрирование из 10-й лабы? Там то определённый интеграл...
    // ответы - это игреки?
    public double fDer(double x, double y) {
        return x + y;
    }
    // int range = (int) ((xn - x0) / h);
    //  double yy[] = new double[range + 1];
    // double xx[] = new double[range];

    int k = 2, numD = 11;
    double x0, xn, y0, y1, z0, z1, h, xx[], yy[];
    double k1, k2, k4, k3;
    double q1, q2, q4, q3;

    public void start(Stage stage) {
        xx = new double[numD];
        yy = new double[numD];
        x0 = 0;
        xn = 1;
        y0 = 0;
        z0 = 0;
        h = 0.1; // шаг
        RK4();
        stage.setTitle("Сравнение методов Рунге-Кутты и Эйлера");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        XYChart.Series seriesb = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesb.getData().add(new XYChart.Data(0, 0));
        }
        seriesb.setName("Runge-Kutta4");

        XYChart.Series seriesRK4 = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesRK4.getData().add(new XYChart.Data(xx[i], yy[i]));
        }
        seriesRK4.setName("Runge-Kutta4");

        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesb, seriesRK4);
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        System.out.println("X\t\t\tY");
        launch(args);
    }

    public double f1(double x, double y, double z) {
        return (Math.cos(3 * x) - 4 * y);
    }

    public double f(double x, double y, double z) {
        double result = x * x * x * x / 12;
        return result;  //return Math.pow(x, 4) / 12;
    }

    public double g(double x, double y, double z) {
        return (z);
    }

    public void Euhler() {
        double yc = y0;
        for (double xc = x0; xc < xn; xc += h){
            y1 = y0 + h * f(xc, yc);
        }
    }

    public void RK4() {
        int i = 0;
        double yc = y0;
        for (double xc = x0; xc < xn; xc += h) {
            xx[i] = xc;
            k1 = h * f(xc, yc, z0);
            q1 = h * g(xc, yc, z0);

            k2 = h * f(xc + h / 2.0, yc + q1 / 2.0, z0 + k1 / 2.0);
            q2 = h * g(xc + h / 2.0, yc + q1 / 2.0, z0 + k1 / 2.0);

            k3 = h * f(xc + h / 2.0, yc + q2 / 2.0, z0 + k2 / 2.0);
            q3 = h * g(xc + h / 2.0, yc + q2 / 2.0, z0 + k2 / 2.0);

            k4 = h * f(xc + h, yc + q3, z0 + k3);
            q4 = h * g(xc + h, yc + q3, z0 + k3);

            z1 = z0 + (k1 + 2.0 * k2 + 2.0 * k3 + k4) / 6.0;
            y1 = yc + (q1 + 2.0 * q2 + 2.0 * q3 + q4) / 6.0;
            //System.out.println("\t" + r(x0 + h, k) + "\t\t" + r(y1 ,k) + "\t\t" + r(z1 ,k));

            String x00 = new DecimalFormat("#0.000000000").format(xc);
            String y11 = new DecimalFormat("#0.000000000").format(y1);
            String z11 = new DecimalFormat("#0.0000000").format(z1);

            System.out.println(x00 + "\t" + y11 + "\t" + z11);
            yc = y1;
            z0 = z1;
            yy[i++] = yc;
        }


    }
}

