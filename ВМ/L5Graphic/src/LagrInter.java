import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

public class LagrInter extends Application {
    int n = 7; // n - число точек, по которым интерполируем
    int numD = 100;// число точек для корня из икс и остальных графиков
    double sh = 0.1; //шаг приращения икс для графиков
    double sh2 = 2;// шаг приращения икс для точек для интерполяции
    double start = 0;// точка, с которой начнутся вызовы lagr();
    double[] xx = new double[n];//массив точек для интерполяции с помощью lagr()
    double[] yy = new double[n];//массив точек для интерполяции с помощью lagr()
    double[] x = new double[numD];//массив точек для записи координат графиков
    double[] y = new double[numD];//массив точек для записи координат графиков
    double maxY = 0, minY = 0;//вспомогательные переменные для рассчета размеров выделения точек интерполяции

    //заполнение массивов x, y точными значениями, посчитанными по формуле y = sqrt(x);
    //x,y - ссылки; sh - шаг изменения x; n - число точек для заполнения
    public void sqrBuild(double x[], double y[], double start, double sh, int n) {
        x[0] = start;
        y[0] = Math.sqrt(x[0]);
        for (int i = 1; i < n; i++) {
            x[i] = x[i - 1] + sh;
            y[i] = Math.sqrt(x[i]);

        }
    }

    //заполнение массивов x, y значениями, посчитанными по интерполяционной формуле Лагранжа lagr():
    //start - начальная точка, с которой интерполируем, n -  количество точек для запуска lagr(), sh - шаг изменеия икс:
    public void interpBuild(double x[], double y[], double start, double sh, int n) {
        x[0] = start;
        y[0] = lagr(x[0]);
        for (int i = 1; i < n; i++) {
            x[i] = x[i - 1] + sh;
            y[i] = lagr(x[i]);
            if (y[i] > Math.abs(maxY)) {
                maxY = y[i];
            }
            if (y[i] < minY) {
                minY = y[i];
            }
        }
    }

    public void printInterpolationDots(double x[], double y[], LineChart<Number,
            Number> lineChart, int numD, double sh, double maxY, double minY) {
        double coefficientX = numD * sh / 100;
        //x[0] = 5;        y[0] = 1;
        double coefficientY = (maxY + Math.abs(minY)) / 100;
        for (int i = 0; i < n; i++) {
            XYChart.Series seriesE = new XYChart.Series();
            seriesE.getData().add(new XYChart.Data(x[i], y[i]));// сложно нарисовать...
            seriesE.getData().add(new XYChart.Data(x[i], y[i] - coefficientY));
            seriesE.getData().add(new XYChart.Data(x[i], y[i] + coefficientY));
            seriesE.getData().add(new XYChart.Data(x[i], y[i] - coefficientY / 6));
            seriesE.getData().add(new XYChart.Data(x[i] + coefficientX / 1.7, y[i]));
            seriesE.getData().add(new XYChart.Data(x[i] - coefficientX / 1.7, y[i]));
            lineChart.getData().add(seriesE);
        }
    }

    // прописываю 4 вручную заданные для интерполяции точки. В принципе это можно сделать и с пом.sqrBuild():
    public void initXXYY() {
        xx[0] = 1;
        yy[0] = 1;
        xx[1] = 1.2;
        yy[1] = 1.0954;
        xx[2] = 1.4;
        yy[2] = 1.1832;
        xx[3] = 1.6;
        yy[3] = 1.2649;
    }

    //обнуляю массив точек для графиков(похоже ненужная функция):
    public void clearXY() {
        for (int i = 0; i < numD; i++) {
            x[i] = 0;
            y[i] = 0;
        }
    }

    //Функция интерполирования основанная на полиноме Лагранжа. t - точка, в которой ищем зн-ие ф-ции;
// возвращаемое зн-ие - интерполированное значение функции. Точки берутся из массивов xx[], yy[]:
    public double lagr(double t) {
        double chisl;
        double znam;
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
        return y;
    }

    @Override
    public void start(Stage stage) {
        stage.setTitle("Интерполяция по формуле Лагранжа");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        sqrBuild(x, y, 0, sh, numD);// запускаю заполнение точными значениями корень из икс
        XYChart.Series series1 = new XYChart.Series();

        for (int i = 1; i < numD; i++) {
            series1.getData().add(new XYChart.Data(x[i], y[i]));
        }
        series1.setName("Корень из икс");

        sqrBuild(xx, yy, 1, sh2, n);//заполняю xx, yy точками, по которым потом буду интерполировать
        interpBuild(x, y, start, sh, numD);//заполнение  x, y значениями, посчитанными по интерполяционной формуле Лагранжа lagr():

        XYChart.Series series2 = new XYChart.Series();
        for (int i = 1; i < numD; i++) {
            series2.getData().add(new XYChart.Data(x[i], y[i]));
        }
        series2.setName("Интерполированные");

        printInterpolationDots(xx, yy, lineChart, numD, sh, maxY, minY);
        Scene scene = new Scene(lineChart, 800, 600);
        lineChart.getData().addAll(series1);
        lineChart.getData().add(series2);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
