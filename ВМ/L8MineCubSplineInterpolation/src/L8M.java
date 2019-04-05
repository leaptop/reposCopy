import javafx.application.Application;
import javafx.scene.Node;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

import java.util.ArrayList;

public class L8M extends Application {

    int n = 4; // n - число точек, по которым интерполируем
    int numD = 100;// число точек для точного графика( для корня из икс и остальных )
    double sh = 0.1; //шаг приращения икс для графиков
    double start = -5;//точка, с которой начнётся построение графиков(начальная абсцисса всех графиков)
    double sh2 = 0.9;// шаг приращения икс для точек для интерполяции
    double start2 = 1.0;// точка для интерполяции, с которой начнутся вызовы интерполирующей функции(например lagr())
    double[] xx ;//= new double[n];//массив точек для интерполяции с помощью lagr() и других
    double[] yy ;//= new double[n];//массив точек для интерполяции с помощью lagr() и других
    //double[] x ;//= new double[numD];//массив точек для записи координат графиков
    //double[] y = new double[numD];//массив точек для записи координат графиков

    //Cubic spline interpolation program
//when we have two columns of data x and y in input file:
//
//x0 y0
//x1 y1
//...
//xn yn
//
//and we want to find such function f(x)
//where f(xi) = yi
//and f(x) is cubic function on every [x_k-1, x_k] segment
//and f(x), f'(x), f''(x) are continual
//the result is four columns of cubic polinom coefficients

    double [] x, y,h,l,delta,lambda, c,d,b, xc, yc;
    int N = n-1;


    void allocmatrix(){
        //allocate memory for matrixes
        x = new double[N+1];
        y = new double[N+1];
        h = new double[N+1];
        l = new double[N+1];
        delta = new double[N+1];
        lambda = new double[N+1];
        c = new double[N+1];
        d = new double[N+1];
        b = new double[N+1];
        xc = new double[numD];
        yc = new double[numD];
    }
    public void initXXYY() {
        x[0] = 1;
        y[0] = 2;
        x[1] = 3;
        y[1] = 6;
        x[2] = 7;
        y[2] = -2;
        x[3] = 9;
        y[3] = 6;
    }

    void printresult(){
        int k=0;
        System.out.printf ("\nA[k]\tB[k]\tC[k]\tD[k]\n");
        for(k=1; k<=N; k++){
            System.out.printf ("%f\t%f\t%f\t%f\n", y[k], b[k], c[k], d[k]);
        }
    }
    void testresult(){
        double start = x[0];
        double end = x[N];
        double step = (end - start)/numD;
        int i = 0;
        for(double s = start; s<=end; s+= step){
            //find k, where s in [x_k-1; x_k]
            int k;
            for( k=1; k<=N; k++){
                if(s>=x[k-1] && s<=x[k]){
                    break;
                }
            }
            double F = y[k] + b[k]*(s-x[k]) + c[k]*Math.pow(s-x[k], 2) + d[k]*Math.pow(s-x[k], 3);
            yc[i] = F;
            xc[i++] = s;
            System.out.printf( "s = %f\t F = %f\n", s,  F);
        }

    }

    void main(){
        int k=0;
        allocmatrix();
        initXXYY();
        for(k=1; k<=N; k++){
            h[k] = x[k] - x[k-1];
            if(h[k]==0){
                System.out.printf("\nError, x[%d]=x[%d]\n", k, k-1);
                return;
            }
            l[k] = (y[k] - y[k-1])/h[k];
        }
        delta[1] = - h[2]/(2*(h[1]+h[2]));
        lambda[1] = 1.5*(l[2] - l[1])/(h[1]+h[2]);
        for(k=3; k<=N; k++){
            delta[k-1] = - h[k]/(2*h[k-1] + 2*h[k] + h[k-1]*delta[k-2]);
            lambda[k-1] = (3*l[k] - 3*l[k-1] - h[k-1]*lambda[k-2]) /
                    (2*h[k-1] + 2*h[k] + h[k-1]*delta[k-2]);
        }
        c[0] = 0;
        c[N] = 0;
        for(k=N; k>=2; k--){
            c[k-1] = delta[k-1]*c[k] + lambda[k-1];
        }
        for(k=1; k<=N; k++){
            d[k] = (c[k] - c[k-1])/(3*h[k]);
            b[k] = l[k] + (2*c[k]*h[k] + h[k]*c[k-1])/3;
        }
        printresult();
        testresult();

    }




    @Override
    public void start(Stage stage) {
        stage.setTitle("Интерполяция по формулам Лагранжа, нтерполяция кубическими сплайнами");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        // preciseBuild(x, y, start, sh, numD);// запускаю заполнение точными значениями интерполируемой ф-ции
        // XYChart.Series seriesPrecise = new XYChart.Series();
        // for (int i = 0; i < numD; i++) {seriesPrecise.getData().add(new XYChart.Data(x[i], y[i])); }
        // seriesPrecise.setName("Точный график");
        //preciseBuild(xx, yy, start2, sh2, n);//заполняю xx, yy точками, по которым потом буду интерполировать
        //interpBuildLagrange(x, y, xx, yy, start, sh, numD);
        // XYChart.Series seriesLagr = new XYChart.Series();
        //for (int i = 0; i < numD; i++) {seriesLagr.getData().add(new XYChart.Data(x[i], y[i]));}
        //seriesLagr.setName("Лагранж");
        main();

        initXXYY();
        XYChart.Series seriesInt = new XYChart.Series();
        for (int i = 0; i < n; i++) {
            seriesInt.getData().add(new XYChart.Data(x[i], y[i]));
        }
        seriesInt.setName("Точки интерполяции");

        XYChart.Series seriesSpline = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesSpline.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        seriesSpline.setName("Интерполяция кубическими сплайнами");

        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesInt, seriesSpline);
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
