import javafx.application.Application;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class LagrInter extends Application {
    int n = 2; // n - число точек, по которым интерполируем
    int numD = 100;// число точек для корня из икс и остальных графиков
    double sh = 0.1; //шаг приращения икс для графиков
    double start = 0;//точка, с которой начнётся построение графиков
    double sh2 = 0.9;// шаг приращения икс для точек для интерполяции
    double start2 = 1;// точка, с которой начнутся вызовы интерполирующей функции(например lagr())
    double[] xx = new double[n];//массив точек для интерполяции с помощью lagr() и других
    double[] yy = new double[n];//массив точек для интерполяции с помощью lagr() и других
    double[] x = new double[numD];//массив точек для записи координат графиков
    double[] y = new double[numD];//массив точек для записи координат графиков
    double maxY = 0, minY = 0;//вспомогательные переменные для рассчета размеров выделения точек интерполяции

    //заполнение массивов x, y точными значениями, посчитанными по формуле y = sqrt(x);
    //x,y - ссылки; sh - шаг изменения x; n - число точек для заполнения; округление до 4-го знака;
    // здесь можно прописать любую функцию для интерполяции
    public void preciseBuild(double x[], double y[], double start, double sh, int n) {
        x[0] = start;
        y[0] = Math.sqrt(x[0]);//подставить любую функцию
        for (int i = 1; i < n; i++) {
            x[i] = x[i - 1] + sh;
            y[i] = Math.floor(Math.sqrt(x[i]) * 1e4) / 1e4;//подставить любую функцию
            Math.sqrt(x[i]);//округление до 4-го знака

        }
    }

    //заполнение массивов x, y значениями, посчитанными по интерполяционной формуле Лагранжа lagr():
    //start - начальная точка, с которой интерполируем, numD -  количество точек для запуска lagr(), sh - шаг изменеия икс:
    public void interpBuildLagrange(double x[], double y[], double xx[], double yy[], double start, double sh, int numD) {
        x[0] = start;
        y[0] = lagr(x[0], xx, yy);
        for (int i = 1; i < numD; i++) {
            x[i] = x[i - 1] + sh;
            y[i] = lagr(x[i], xx, yy);
            if (y[i] > Math.abs(maxY)) {
                maxY = y[i];
            }
            if (y[i] < minY) {
                minY = y[i];
            }
        }
    }

    //заполнение массивов x, y значениями, посчитанными по интерполяционной схеме Эйткина:
    //start - начальн. т., с которой интерполируем, numD -  количество точек для
    //запуска интерп. ф-ции(в общем для псотроения конечного массива иксов и игреков), sh - шаг изменеия икс:
    public void interpBuildAitk(double x[], double y[], double xx[], double yy[], double start, double sh, int numD) {
        x[0] = start;
        y[0] = aitken(x[0], xx, yy);
        for (int i = 1; i < numD; i++) {
            x[i] = x[i - 1] + sh;
            y[i] = aitken(x[i], xx, yy);
            if (y[i] > Math.abs(maxY)) {
                maxY = y[i];
            }
            if (y[i] < minY) {
                minY = y[i];
            }
        }
    }

    //заполнение массивов x, y значениями, посчитанными по интерполяционной формуле Ньютона:
    //start - начальн. т., с которой интерполируем, n -  количество точек для запуска интерп. ф-ции(в общем
    // для псотроения конечного массива иксов и игреков), sh - шаг изменеия икс, n - число интерп. точек(нужно для передачи
    // объекту L7NewtInter L7N) :
    public void interpBuildNewton(double x[], double y[], double xx[], double yy[],
                                  double start, double sh, int numD, L7NewtInter L7N, int n) {
        x[0] = start;
        y[0] = L7N.mn(x[0], xx, yy, n);
        for (int i = 1; i < numD; i++) {
            x[i] = x[i - 1] + sh;
            y[i] = L7N.mn(x[i], xx, yy, n);
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

    // прописываю 4 вручную заданные для интерполяции точки. В принципе это можно сделать и с пом.preciseBuild():
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
    public double lagr(double t, double xx[], double yy[]) {
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

    //функция интерполирования по схеме Эйткина:
    public double aitken(double x, double[] xi, double[] fi) {
        int n = xi.length - 1;
        double[] ft = fi.clone();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                ft[j] = (x - xi[j]) / (xi[i + j + 1] - xi[j]) * ft[j + 1]
                        + (x - xi[i + j + 1]) / (xi[j] - xi[i + j + 1]) * ft[j];
            }
        }
        System.out.println(" Эйткен - если х = " + x + ", то у = " + ft[0]);
        return ft[0];
    }

    //Функция, реализующая интерполирование по схеме Эйткена:
    public double ait(double x, double xx[], double yy[]) {
        System.out.println("\nait is starting with x = " + x);
        for (int i = 0; i < xx.length - 1; i++) {
            for (int k = 1; k < xx.length - i; k++) {//после каждого прохода расстояние между иксами должно увеличиваться на 1. Для этого можно использовать i,
                yy[k - 1] = (yy[k - 1] * (x - xx[k + i]) - yy[k] * (x - xx[k - 1 + i])) / (xx[k - 1 + i] - xx[k + i]);//для этого добавляю i в каждый вызов xx[] ниже
                System.out.println("ait counting yy[k-1] = " + yy[k - 1]);//Последний k при этом не должен использоваться.
            }//Поэтому внутренний цикл укорачивается на i каждый раз.
        }
        System.out.println("ait is over,   yy[0] = " + yy[0]);
        return yy[0];
    }

    @Override
    public void start(Stage stage) {
        stage.setTitle("Интерполяция по формулам Лагранжа, Ньютона, схеме Эйткена");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        preciseBuild(x, y, start, sh, numD);// запускаю заполнение точными значениями интерполируемой ф-ции
        XYChart.Series seriesPrecise = new XYChart.Series();

        for (int i = 1; i < numD; i++) {
            seriesPrecise.getData().add(new XYChart.Data(x[i], y[i]));
        }
        seriesPrecise.setName("Точный график");

        preciseBuild(xx, yy, start2, sh2, n);//заполняю xx, yy точками, по которым потом буду интерполировать
        interpBuildLagrange(x, y, xx, yy, start, sh, numD);
        XYChart.Series seriesLagr = new XYChart.Series();
        for (int i = 1; i < numD; i++) {
            seriesLagr.getData().add(new XYChart.Data(x[i], y[i]));
        }
        seriesLagr.setName("Лагранж");

        clearXY();
        interpBuildAitk(x, y, xx, yy, start, sh, numD);
        XYChart.Series seriesAitk = new XYChart.Series();
        for (int i = 1; i < numD; i++) {
            seriesAitk.getData().add(new XYChart.Data(x[i], y[i]));
        }
        seriesAitk.setName("Эйткен");
        clearXY();
        L7NewtInter L7N = new L7NewtInter();
        interpBuildNewton(x, y, xx, yy, start, sh, numD, L7N, n);
        //

        XYChart.Series seriesNewt = new XYChart.Series();
        for (int i = 1; i < numD; i++) {
            seriesNewt.getData().add(new XYChart.Data(x[i], y[i]));
        }
        seriesNewt.setName("Ньютон");
//
        printInterpolationDots(xx, yy, lineChart, numD, sh, maxY, minY);
        Scene scene = new Scene(lineChart, 800, 600);
        lineChart.getData().addAll(seriesNewt, seriesAitk, seriesLagr, seriesPrecise);
        stage.setScene(scene);
        stage.show();
    }//Графики на самом деле не совпадают. Это можно проверить, подправив добавляемую координату: y[i]+0.08, sh2 = 0.8

    public static void main(String[] args) {
        launch(args);
    }
}
