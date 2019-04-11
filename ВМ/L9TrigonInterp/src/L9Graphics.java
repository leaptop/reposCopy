import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class L9Graphics extends Application {
    int n = 4; // n - число точек, по которым интерполируем
    int numD = 100;// число точек для точного графика( для корня из икс и остальных )
    //int n = 30;//количество разбиений единичного отрезка
    double[] xx = new double[n];//точки по которым интерполируем
    double[] yy = new double[n];//точки по которым интерполируем
    double[] xc = new double[numD];//массив точек для записи координат графиков
    double[] yc = new double[numD];//массив точек для записи координат графиков
    double h;
    double pi = 3.1415926;
    double a[];

    double AA(int j) {
        double S = 0;
        double ii = 1;
        for (int k = 0; k < n - 1; k++) {

            S = S + yy[k] *
                    Math.exp(-2 * pi * ii * (double) k *
                            (double) j / (double) n);
        }
        return S / (double) n;
    }
    double Interpolate2(double x) {
        double S = 0;
        double ii = 1;
        int c = 0, j = 0;
        while (x > xx[j + 1]) j++;// ищу нужный j
        h = 1 / (double) numD;// считаю шаг
       // if (j == 0) j = 1;
        for (double t = (double) n / 2; t > (double) -n / 2; t--) {// пытаюсь реализовать цикл от n/2 до -n/2
            //наверное число в скобках(степень экспоненты д.б. отрицательным)
            S = S + a[j] * Math.exp(2 * pi * ii * t * (double) j * (x - xx[j]) / ((double) n * h));
        }
        return S;
    }

    public void countAll() {
        {
            a = new double[n];
            System.out.println(" A :");
            for (int j = 0; j < n; j++) {
                a[j] = AA(j);
                System.out.println("a["+j+"] = " + a[j]);
            }

            for (int jj = 0; jj < numD; jj++) {
                int j = 0;
                //if (j == 0) { xc[0] = xx[0]; } else
                // xc[j] = xc[j - 1] + ((xx[n - 1] - xx[0]) / numD);
                xc[jj] =
                        xx[0] +
                                (xx[n - 1] -
                                        xx[0]) / numD * jj;
                // System.out.println("X: "+xc[j]);
                yc[jj] = Interpolate2(xc[jj]);
            }
        }
    }

    //инициализация интерполяционных точек//sin{x):
    public void initXXYY() {
        xx[0] = -4;
        yy[0] = 0.7;
        xx[1] = 0.87;
        yy[1] = 0.76;
        xx[2] = 2.96;
        yy[2] = 0.17;
        xx[3] = 5.86;
        yy[3] = -0.4;

    }// 5 2
    //инициализация интерполяционных точек//ДОМАШКА:
    public void initXXYYе() {
        xx[0] = 2;
        yy[0] = 1;
        xx[1] = 4;
        yy[1] = 0;
        xx[2] = 6;
        yy[2] = 1;
        xx[3] = 8;
        yy[3] = 4;
    }// 5 2

    public void initXXYYT() {//инициализация интерполяционных точек
        xx[0] = 1;
        yy[0] = 2;
        xx[1] = 3;
        yy[1] = 6;
        xx[2] = 5;
        yy[2] = 2;
        xx[3] = 7;
        yy[3] = -2;
        xx[4] = 9;
        yy[4] = 2;
    }// 5 2

    @Override
    public void start(Stage stage) {

        stage.setTitle("Тригонометрическая интерполяция");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        initXXYY();
        XYChart.Series seriesInt = new XYChart.Series();
        for (int i = 0; i < n; i++) {
            seriesInt.getData().add(new XYChart.Data(xx[i], yy[i]));
        }
        seriesInt.setName("Точки интерполяции");


        countAll();
        XYChart.Series seriesTrig = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesTrig.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        seriesTrig.setName("Тригонометрическая интерполяция");

        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesInt, seriesTrig);
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        stage.setScene(scene);
        stage.show();
        System.out.println("Int2(-2.7): " + Interpolate2(-2.7) + ", must be -0.4266");
        System.out.println("Int2(-1): " + Interpolate2(-1) + ", must be -0.844");
        System.out.println("Int2(2): " + Interpolate2(2) + ", must be 0.9");
    }

    public static void main(String[] args) {
        launch(args);

    }
}

 /* int nn = 20;

        dbx[0]=-3.14159;
        dbx[1] = -2.51327;
        dbx[2] = -1.88496;
        dbx[3] = -1.25664;
        dbx[4] = -0.628319;
        dbx[5] = 0;
        dbx[6] = 0.628319;
        dbx[7] = 1.25664;
        dbx[8] = 1.88496;
        dbx[9] = 2.51327;
        dbx[10] = 3.14159;
        dbx[11] = 3.76991;
        dbx[12] = 4.39823;
        dbx[13] = 5.02655;
        dbx[14] = 5.65487;
        dbx[15] = 6.28319;
        dbx[16] = 6.9115;
        dbx[17] = 7.53982;
        dbx[18] = 8.16814;
        dbx[19] = 8.79646;
        dby[0]=-0.663224;
        dby[1] = 0.20168;
        dby[2] = -0.168674;
        dby[3] = -0.0683768;
        dby[4] = 0.0467905;
        dby[5] = -0.02415;
        dby[6] = -0.0117098;
        dby[7] = 0.0779424;
        dby[8] = 0.259817;
        dby[9] = -0.224096;
        dby[10] = 0.669775;
        dby[11] = 1.53468;
        dby[12] = 1.16433;
        dby[13] = 0.764623;
        dby[14] = 0.879791;
        dby[15] = 0.80885;
        dby[16] = 0.82129;
        dby[17] = 0.910942;
        dby[18] = 0.259818;
        dby[19] = -0.224096;*/