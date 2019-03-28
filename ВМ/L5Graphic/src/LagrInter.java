import javax.swing.*;
import java.awt.*;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

public class LagrInter extends Application {
    int n = 4; //, z = 50;// z - кол-во шагов по 0.2 по иксам// n = 3 - по трём точкам считаем
    int nu = 100;// число точек для корня из икс
    int numD = 100;
    double[] xx = new double[200];//array for counting
    double[] yy = new double[200];//array for counting
    double[] x = new double[numD];//array for x-es for sqr
    double[] y = new double[numD];//array for y-s
    double chisl;
    double znam;

    public void initXXYY() {
        xx[0] = 1;
        yy[0] = 1;
        xx[1] = 1.2;
        yy[1] = 1.0954;
        xx[2] = 1.4;
        yy[2] = 1.1832;
        xx[3] = 1.6;
        yy[3] = 1.2649;
        xx[4] = 1.44;
        yy[4] = lagr(xx[4]);
        xx[5] = 5;
        yy[5] = lagr(xx[5]);
    }

    public void init() {

    }

    public void buildLine() {
        for (int i = 0; i < numD; i++) {
            x[i] = 0;
            y[i] = 0;
        }
        double m = (yy[4] - yy[5]) / (xx[4] - xx[5]);
        double b = -(m * xx[4]) + yy[4];
        if (b >= 0) {
            System.out.println("y = " + m + "x=" + b);
        } else {
            System.out.println("y = " + m + "x=" + b);
        }
        x[0] = 0;
        for (int i = 1; i < numD; i++) {
            x[i] = x[i - 1] + 0.1;
            y[i] = m * x[i] + b;
        }

    }

    public void clear() {
        for (int i = 0; i < numD; i++) {
            x[i] = 0;
            y[i] = 0;
        }
    }

    public double lagr(double t) {
        double y = 0;
        for (int i = 0; i < n; i++) {// здесь i - номер избегаемой переменной
            chisl = 1;
            znam = 1;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    chisl *= (t - xx[j]);
                    znam *= (xx[i] - xx[j]);
                }
            }
            y += (chisl *= (yy[i])) / znam;
        }
        System.out.println("Лагранж - если x = " + t + ", то" + " y = " + y);
        // }
        return y;
    }

    public void sqrBuild() {
        x[0] = 0;
        y[0] = 0;
        for (int i = 1; i < numD - 1; i++) {
            x[i] = x[i - 1] + 0.1;
            y[i] = Math.sqrt(x[i]);
        }
    }

    @Override
    public void start(Stage stage) {
        sqrBuild();
        initXXYY();

        stage.setTitle("Интерполяция по формуле Лагранжа");
        //d]объявляю оси
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов
        lineChart.setTitle("Title");

        XYChart.Series series1 = new XYChart.Series();
        for (int i = 1; i < nu; i++) {
            series1.getData().add(new XYChart.Data(x[i], y[i]));
        }

        clear();
        buildLine();
        XYChart.Series series2 = new XYChart.Series();
        for (int i = 1; i < numD; i++) {
            series2.getData().add(new XYChart.Data(x[i], y[i]));
        }

        series2.setName("interp");

       /* x[0] = -5;
        xx[0] = 5;//Заданные точки
        xx[1] = 10;
        xx[2] = 20;
        yy[0] = 12;
        yy[1] = 25;
        yy[2] = 18;//Заданные точки
        XYChart.Series series1 = new XYChart.Series();
        series1.setName("("+xx[0]+", "+yy[0]+") "+"("+xx[1]+", "+yy[1]+")...   ");
        lagr();
        for (int i = 1; i < z; i++) {
            series1.getData().add(new XYChart.Data(x[i], y[i]));
        }
        clear();

        x[0] = -5;
        xx[0] = -1;
        xx[1] = 0;
        xx[2] = 1;
        yy[0] = 1;
        yy[1] = 0;
        yy[2] = 1;
        XYChart.Series series2 = new XYChart.Series();
        series2.setName("("+xx[0]+", "+yy[0]+") "+"("+xx[1]+", "+yy[1]+")...");
        lagr();
        for (int i = 1; i < z; i++) {
            series2.getData().add(new XYChart.Data(x[i], y[i]));
        }
        clear();

        x[0] = -5;
        xx[0] = 0;
        xx[1] = 0.25;
        xx[2] = 0.33;
        yy[0] = 1;
        yy[1] = 0.707;
        yy[2] = 0.5;
        XYChart.Series series3 = new XYChart.Series();
        series3.setName("("+xx[0]+", "+yy[0]+") "+"("+xx[1]+", "+yy[1]+")...");
        lagr();
        for (int i = 1; i < z; i++) {
            series3.getData().add(new XYChart.Data(x[i], y[i]));
        }
        clear();*/

        Scene scene = new Scene(lineChart, 800, 600);
        lineChart.getData().addAll(series1, series2);

        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
