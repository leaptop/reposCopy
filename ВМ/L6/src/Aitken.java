import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

import java.lang.*;

public class Aitken extends Application {
    int n = 3, z = 10;// z - кол-во шагов по 0.2 по иксам// n = 3 - по трём точкам считаем
    double[] xg = new double[z];//array for x-es
    double[] yg = new double[z];//array for y-s

    public static void main(String[] argv) {
        launch(argv);
    }

    @Override
    public void start(Stage stage) {
        stage.setTitle("Интерполяция по схеме Эйткена");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        //создаю график
        final LineChart<Number, Number> lineChart =
                new LineChart<Number, Number>(xAxis, yAxis);

        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        lineChart.setTitle("Title");
        XYChart.Series series1 = new XYChart.Series();
        //series1.setName("("+xx[0]+", "+yy[0]+") "+"("+xx[1]+", "+yy[1]+")...   ");
        double[] xx = {1, 1.2, 1.4, 1.6};
        double[] yy = {1, 1.0954, 1.1832, 1.2649};

        double x = 1.44;
       // ait(x, xx, yy);
        x = 1.49;
        ait(x, xx, yy);
      /*  xg[0] = 1;
        yg[0] = 1;
        for (int m = 1; m < z; m++) {

            xg[m] = xg[m - 1] + 0.05;
            yg[m] = ait(xg[m], xx, yy);

            System.out.println("Если x = " + xg[m] + ", то" + " y = " + yg[m]);

        }//can't build a chart, because the function works relatively good only near x = 1.2, to x = 1.49
        for (int i = 1; i < z; i++) {
            series1.getData().add(new XYChart.Data(xg[i], yg[i]));
        }
        Scene scene = new Scene(lineChart, 800, 600);
        lineChart.getData().addAll(series1);

        stage.setScene(scene);
        stage.show();*/
    }


    public double ait(double x, double xx[], double yy[]) {
        System.out.println("ait is starting with x = " + x);
        for (int i = 0; i < xx.length - 1; i++) {
            for (int k = 1; k < xx.length - i; k++) {//после каждого прохода расстояние между иксами должно увеличиваться на 1. Для этого можно использовать i, для этого добавляю i в каждый вызов xx[] ниже
                yy[k - 1] = (yy[k - 1] * (x - xx[k + i]) - yy[k] * (x - xx[k - 1 + i])) / (xx[k - 1 + i] - xx[k + i]);//Последний k при этом не должен использоваться. Поэтому внутренний цикл укорачивается на i каждый раз.
                System.out.println("ait counting yy[k-1] = " + yy[k - 1]);
            }
        }
        System.out.println("ait is over\n");
        return yy[0];
    }
}
