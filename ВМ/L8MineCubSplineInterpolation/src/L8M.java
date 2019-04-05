import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

public class L8M extends Application {
    int n = 4; // n - число точек, по которым интерполируем
    int numD = 100;// число точек для точного графика( для корня из икс и остальных )
    double[] x= new double[n];//точки по которым интерполируем
    double[] y= new double[n];//точки по которым интерполируем
    double[] h= new double[n];
    double[] l= new double[n];
    double[] delta= new double[n];
    double[] lambda= new double[n];
    double[] c= new double[n];//коэффициенты в уравнении для сплайнов
    double[] d= new double[n];//коэффициенты в уравнении для сплайнов
    double[] b= new double[n];//коэффициенты в уравнении для сплайнов
    double[] xc= new double[numD];//массив точек для записи координат графиков
    double[] yc= new double[numD];//массив точек для записи координат графиков



   /* void allocmatrix() {
        //allocate memory for matrixes
        x
        y = new double[n];
        h = new double[n];
        l = new double[n];
        delta = new double[n];
        lambda = new double[n];
        c = new double[n];
        d = new double[n];
        b = new double[n];
        xc = new double[numD];
        yc = new double[numD];
    }*/

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

    public void coefficients() {
        int k = 0;
        System.out.printf("\nA[k]\t\tB[k]\t\tC[k]\t\tD[k]\n");
        for (k = 1; k < n; k++) {
            System.out.printf("%f\t%f\t%f\t%f\n", y[k], b[k], c[k], d[k]);
        }
    }

    public void interpBuildCubSpl() {
        double start = x[0];
        double end = x[n-1];
        double step = (end - start) / numD;
        int i = 0;
        for (double s = start; s <= end; s += step) {
            //find k, where s in [x_k-1; x_k]
            int k;
            for (k = 1; k < n; k++) {
                if (s >= x[k - 1] && s <= x[k]) {
                    break;
                }
            }
            double F = y[k] + b[k] * (s - x[k]) + c[k] * Math.pow(s - x[k], 2) + d[k] * Math.pow(s - x[k], 3);
            yc[i] = F;
            xc[i++] = s;
            System.out.printf("s = %f\t F = %f\n", s, F);
        }

    }

    void main() {
        int k = 0;
        initXXYY();
        for (k = 1; k < n; k++) {
            h[k] = x[k] - x[k - 1];
            if (h[k] == 0) {
                System.out.printf("\nError, x[%d]=x[%d]\n", k, k - 1);
                return;
            }
            l[k] = (y[k] - y[k - 1]) / h[k];
        }
        delta[1] = -h[2] / (2 * (h[1] + h[2]));
        lambda[1] = 1.5 * (l[2] - l[1]) / (h[1] + h[2]);
        for (k = 3; k < n; k++) {
            delta[k - 1] = -h[k] / (2 * h[k - 1] + 2 * h[k] + h[k - 1] * delta[k - 2]);
            lambda[k - 1] = (3 * l[k] - 3 * l[k - 1] - h[k - 1] * lambda[k - 2]) /
                    (2 * h[k - 1] + 2 * h[k] + h[k - 1] * delta[k - 2]);
        }
        c[0] = 0;
        c[n-1] = 0;
        for (k = n-1; k >= 2; k--) {
            c[k - 1] = delta[k - 1] * c[k] + lambda[k - 1];
        }
        for (k = 1; k < n; k++) {
            d[k] = (c[k] - c[k - 1]) / (3 * h[k]);
            b[k] = l[k] + (2 * c[k] * h[k] + h[k] * c[k - 1]) / 3;
        }
        coefficients();
        interpBuildCubSpl();

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
