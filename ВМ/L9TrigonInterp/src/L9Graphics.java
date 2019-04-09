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
    double[] xx = new double[n];//точки по которым интерполируем
    double[] yy = new double[n];//точки по которым интерполируем
    double[] hh = new double[n];//расстояния между иксами (только по икс)
    double[] l = new double[n];// l[k] = (y[k] - y[k-1])/h[k]
    double[] delta = new double[n];//прогоночные коэффициенты
    double[] lambda = new double[n];//прогоночные коэффициенты
    double[] c = new double[n];//коэффициенты в уравнениях для сплайнов
    double[] d = new double[n];//коэффициенты в уравнениях для сплайнов
    double[] b = new double[n];//коэффициенты в уравнениях для сплайнов
    double[] xc = new double[numD];//массив точек для записи координат графиков
    double[] yc = new double[numD];//массив точек для записи координат графиков
    //int[] k = new int[n - 1];
    double[] j = new double[n - 1];
    double[] A = new double[n - 1];
    double h = 1 / n;
    double[] x = new double[n - 1];
    double[] y = new double[n - 1];
    double[] dbx = new double[numD];
    double[] dby = new double[numD];
     double pi = 3.1415926;
     double a[];
     double ix[] = new double[n];
     double iy[] = new double[n];
     double A(int j) {
        double S = 0;
        int ii;
        for (int i = -n; i < n + 1; i++) {

            S = S + Function(2 * pi * (double) (i) / (2 * n + 1)) * Math.cos(2 * pi * (double) (j) * (double) (i) / (2 * n + 1));
        }
        if (j == 0) return 1 / (double) (2 * n + 1) * S;

        return 2 / (double) (2 * n + 1) * S;
    }

     double B(int j) {
        int ii;
        double S = 0;
        for (int i = -n; i < n + 1; i++) {
            ii = -n + i;
            S = S + Function(2 * pi * (double) (i) / (double) (2 * n + 1)) * Math.sin(2 * pi * (double) (j * i) / (double) (2 * n + 1));
        }
        return 2 / (double) (2 * n + 1) * S;
    }

     double Function(double x) {
        if (x < -1.5) return (double) (1);
        if (x >= -1.5 && x < 1.6) return 0.5;
        return -0.333;
    }

     double Interpolate(double x) {
        double S = a[0];
        for (int i = 1; i < n; i++) {
            S = S + a[i] * Math.cos((double) (i) * x) + b[i] * Math.sin((double) (i) * x);
        }
        return S;
    }

    public  void mainN() {
        {
            int size = 50;

            a = new double[n];
            b = new double[n];
            System.out.println(" Коэффициенты a :");
            for (int j = 0; j < n; j++) {
                a[j] = A(j);
                System.out.println("a[j] = "+a[j]); }

            System.out.println(" Коэффициенты b :");
            for (int j = 1; j < n; j++) {
                b[j] = B(j);
                System.out.println("b[j] = "+b[j]);
            }
            double x;
            System.out.println("Координаты узлов  и значения в них");//эти узлы - точки интерполяции?//а вектор - набор координат?
            for (int j = 0; j < n; j++) {
                ix[j] = x = -pi + 2 * pi / size * j;
                iy[j] =  Function(x);
            }
            System.out.println(" STOP ");
            for (int j = 0; j < n; j++) {
                x = -pi + 2 * pi / size * j;
                Interpolate(x);
            }
            System.out.println(" Error ");//типа походу выдаёт разницу между реальным и интерполированным значениями
            for (int j = 0; j < numD; j++) {
              xc[j]=  x = -pi + 2 * pi / size * j;
              yc[j]=Interpolate(xc[j]);
                //System.out.println("x = " + x + "Interpolate(x)-Function(x) = " + (Interpolate(x) - Function(x)));
            }/*
            for(int r = 0; r<numD; r++){
                xc[r]  = -pi + 2 * pi / size * numD;
                yc[r] = Interpolate(xc[r]);
            }*/
        }
    }
    public void initXXYY() {//инициализация интерполяционных точек
        xx[0] = 2;
        yy[0] = 1;
        xx[1] = 4;
        yy[1] = 0;
        xx[2] = 6;
        yy[2] = 1;
        xx[3] = 8;
        yy[3] = 4;
        // x = xx.clone();
        y = yy.clone();
        //x[4] = 9;
        //y[4] = 2;
    }// 5 2

    public void trig() {
        A[0] = 0;
        // k[0] = 0;
        double h = 1 / n;
        j[0] = -(n - 1) / 2;
        x[0] = 0;
        for (int i = 1; i < n - 1; i++) {
            x[i] += x[i - 1] + 1 / n;
        }
        for (int k = 0; k < n - 1; k++) {
            //A[0] += y[k] * Math.pow(Math.E, (-2 * Math.PI *  j * (x[j] / (double) n)));
        }
        A[0] *= (1 / n);
    }

    public void aCount() {
        //int k
    }

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


    public void coefficients() {
        int k = 0;
        //System.out.printf("\na[k]\t\tb[k]\t\tc[k]\t\td[k]\n");
        for (k = 1; k < n; k++) {
            //System.out.printf("%f\t%f\t%f\t%f\n", y[k], b[k], c[k], d[k]);
        }
    }

    public void interpBuildCubSpl() {//заполняю массивы интерполированными точками
        double start = xx[0];
        double end = xx[n - 1];
        double step = (end - start) / numD;
        int i = 0;
        for (double s = start; s <= end; s += step) {
            int k;
            for (k = 1; k < n; k++) {
                if (s >= xx[k - 1] && s <= xx[k]) {
                    break;//перескакиваем на нужное k
                }
            }
            if (i < numD) {
                yc[i] = yy[k] + b[k] * (s - xx[k]) + c[k] * Math.pow(s - xx[k], 2) + d[k] * Math.pow(s - xx[k], 3);//считаем значения функции с помощью сплайнов
                xc[i] = s;
                //System.out.printf("s = %f\t F = %f\n", s, yc[i]);
                i++;
            }
        }
    }

    public void interpolate() {
        int k = 0;
        initXXYY();
        for (k = 1; k < n; k++) {
            hh[k] = xx[k] - xx[k - 1];//считаем расстояние(только по икс) между точками интерполяции
            l[k] = (yy[k] - yy[k - 1]) / hh[k];//это из уравнения прямой, проходящей через две точки
        }
        delta[1] = -hh[2] / (2 * (hh[1] + hh[2]));//прогоночные коэффициенты
        lambda[1] = 1.5 * (l[2] - l[1]) / (hh[1] + hh[2]);//прогоночные коэффициенты
        for (k = 3; k < n; k++) {
            delta[k - 1] = -hh[k] / (2 * hh[k - 1] + 2 * hh[k] + hh[k - 1] * delta[k - 2]);//прогоночные коэффициенты
            lambda[k - 1] = (3 * l[k] - 3 * l[k - 1] - hh[k - 1] * lambda[k - 2]) /
                    (2 * hh[k - 1] + 2 * hh[k] + hh[k - 1] * delta[k - 2]);//прогоночные коэффициенты
        }
        c[0] = 0;
        c[n - 1] = 0;
        for (k = n - 1; k >= 2; k--) {
            c[k - 1] = delta[k - 1] * c[k] + lambda[k - 1];//находим коэффициенты с[k] по формулам обратной прогонки
        }
        for (k = 1; k < n; k++) {
            d[k] = (c[k] - c[k - 1]) / (3 * hh[k]);//нахождение d[k] и b[k] по специальным формулам
            b[k] = l[k] + (2 * c[k] * hh[k] + hh[k] * c[k - 1]) / 3;
        }
    }

    @Override
    public void start(Stage stage) {

        stage.setTitle("Интерполяция кубическими сплайнами, тригонометрическая интерполяция");
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


        mainN();
        XYChart.Series seriesTrig = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesTrig.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        seriesTrig.setName("Тригонометрическая интерполяция");

        //interpolate();
        // coefficients();
        // interpBuildCubSpl();
        //XYChart.Series seriesSpline = new XYChart.Series();
        // for (int i = 0; i < numD; i++) {
        //    seriesSpline.getData().add(new XYChart.Data(xc[i], yc[i]));
        //  }
        //  seriesSpline.getData().add(new XYChart.Data(xx[n - 1], yy[n - 1]));
        //  seriesSpline.setName("Интерполяция кубическими сплайнами");

        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesInt, seriesTrig);
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        stage.setScene(scene);
        stage.show();
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