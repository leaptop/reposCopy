import javax.swing.*;
import java.awt.*;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

class LagrInter extends Application {


    @Override
    public void start(Stage stage){
       /* int n = 3, z = 50;
        double[] xx = new double[200];//array for counting
        double[] yy = new double[200];//array for counting
        double[] x = new double[z];//array for x-es
        double[] y = new double[z];//array for y-s
        x[0] = 10;
        //double y = 0;
        xx[0] = 5;
        xx[1] = 10;
        xx[2] = 20;
        yy[0] = 12;
        yy[1] = 25;
        yy[2] = 18;
        double chisl;
        double znam;

        for (int m = 0; m < z; m++){
            x[m] += 0.2;
            for (int i = 0; i < n; i++) {// здесь i - номер избегаемой переменной
                chisl = 1;
                znam = 1;
                for (int j = 0; j < n; j++) {
                    if (i != j) {
                        chisl *= (x[m] - xx[j]);
                        znam *= (xx[i]-xx[j]);
                    }
                }
                y[m] += (chisl *= (yy[i])) / znam;
            }
            System.out.println("Если x = " + x + ", то" + " y = " + y);
            //xx[3] = x; yy[3] = y;
        }

*/
        stage.setTitle("Интерполяция по формуле Лагранжа");
        //defining the axes
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        //creating the chart
        final LineChart<Number, Number> lineChart =
                new LineChart<Number, Number>(xAxis, yAxis);

        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        lineChart.setTitle("Title");
        //defining a series
        XYChart.Series series = new XYChart.Series();
        series.setName("01");
        //populating the series with data
       // for(int i = 0; i< z; i++){
       //     series.getData().add(new XYChart.Data(x[i], y[i]));
      //  }

        series.getData().add(new XYChart.Data(1, 23));
        series.getData().add(new XYChart.Data(2, 14));
        series.getData().add(new XYChart.Data(3, 15));
        series.getData().add(new XYChart.Data(4, 24));
        series.getData().add(new XYChart.Data(5, 34));
        series.getData().add(new XYChart.Data(6, 36));
        series.getData().add(new XYChart.Data(7, 22));
        series.getData().add(new XYChart.Data(8, 45));
        series.getData().add(new XYChart.Data(9.5, 43));
        series.getData().add(new XYChart.Data(10, 17));
        series.getData().add(new XYChart.Data(11, 29));
        series.getData().add(new XYChart.Data(12, 50));



        Scene scene = new Scene(lineChart, 800, 600);
        lineChart.getData().add(series);

        stage.setScene(scene);
        stage.show();
    }
    public static void main(String[] args) {

        launch(args);

        //LagrInter lr = new LagrInter();



    }
}
