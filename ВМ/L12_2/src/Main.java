import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.chart.LineChart;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.stage.Stage;

public class Main extends Application {
    double a[], b[], x[], y[], sums[][], xc[], yc[];
    int N = 4, K = 2, numD = 50;


    @Override
    public void start(Stage primaryStage) throws Exception {
        mainF();

        xc = new double[numD];
        yc = new double[numD];

        primaryStage.setTitle("Метод Наименьших квадратов");
        final NumberAxis xAxis = new NumberAxis();
        final NumberAxis yAxis = new NumberAxis();
        xAxis.setLabel("X");
        yAxis.setLabel("Y");
        final LineChart<Number, Number> lineChart = new LineChart<Number, Number>(xAxis, yAxis);
        lineChart.setCreateSymbols(false);//убирает кружочки из узлов

        XYChart.Series seriesInt = new XYChart.Series();
        for (int i = 0; i < N; i++) {
            seriesInt.getData().add(new XYChart.Data(x[i], y[i]));
        }
        seriesInt.setName("Точки аппроксимации");

        XYChart.Series seriesApproxim = new XYChart.Series();
        double start = -5, finish = 5;
        double h = Math.abs(start - finish) / numD;
        for (int i = 0; i < numD; i++) {
            xc[i] = start + i * h;
            yc[i] = a[0] + a[1] * xc[i] + a[2] * Math.pow(xc[i], 2);
            seriesApproxim.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        // seriesApproxim.getData().add(new XYChart.Data(xc[n - 1], yc[n - 1]));
        seriesApproxim.setName("Аппроксимация");

        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesInt, seriesApproxim);
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        primaryStage.setScene(scene);
        primaryStage.show();
    }


    //N - number of data points
//K - polinom power
//K<=N
    void allocmatrix() {
        //allocate memory for matrixes
        int i, j, k;
        a = new double[K + 1];
        b = new double[K + 1];
        x = new double[N];
        y = new double[N];
        sums = new double[K + 1][K + 1];
        for (i = 0; i < K + 1; i++) {
            a[i] = 0;
            b[i] = 0;
            for (j = 0; j < K + 1; j++) {
                sums[i][j] = 0;
            }
        }
        for (k = 0; k < N; k++) {
            x[k] = 0;
            y[k] = 0;
        }
    }

    void readmatrix() {
        int i = 0, j = 0, k = 0;
        {
            x[0] = 1;
            y[0] = 1;
            x[1] = 2;
            y[1] = 4;
            x[2] = 3;
            y[2] = 9;
            x[3] = 4;
            y[3] = 16;
        }
        //init square sums matrix
        for (i = 0; i < K + 1; i++) {
            for (j = 0; j < K + 1; j++) {
                sums[i][j] = 0;
                for (k = 0; k < N; k++) {
                    sums[i][j] += Math.pow(x[k], i + j);
                }
            }
        }
        //init free coefficients column
        for (i = 0; i < K + 1; i++) {
            for (k = 0; k < N; k++) {
                b[i] += Math.pow(x[k], i) * y[k];
            }
        }
    }

    void printresult() {
        //print polynom parameters
        int i = 0;
        System.out.println();
        for (i = 0; i < K + 1; i++) {
            System.out.printf("a[%d] = %f\n", i, a[i]);
        }
    }

    void diagonal() {
        int i, j, k;
        double temp = 0;
        for (i = 0; i < K + 1; i++) {
            if (sums[i][i] == 0) {
                for (j = 0; j < K + 1; j++) {
                    if (j == i) continue;
                    if (sums[j][i] != 0 && sums[i][j] != 0) {
                        for (k = 0; k < K + 1; k++) {
                            temp = sums[j][k];
                            sums[j][k] = sums[i][k];
                            sums[i][k] = temp;
                        }
                        temp = b[j];
                        b[j] = b[i];
                        b[i] = temp;
                        break;
                    }
                }
            }
        }
    }

    void mainF() {
        int i = 0, j = 0, k = 0;
        allocmatrix();
        readmatrix();
        //check if there are 0 on main diagonal and exchange rows in that case
        diagonal();
        //process rows
        for (k = 0; k < K + 1; k++) {
            for (i = k + 1; i < K + 1; i++) {
                if (sums[k][k] == 0) {
                    System.out.printf("\nSolution is not exist.\n");
                    return;
                }
                double M = sums[i][k] / sums[k][k];
                for (j = k; j < K + 1; j++) {
                    sums[i][j] -= M * sums[k][j];
                }
                b[i] -= M * b[k];
            }
        }
        for (i = (K + 1) - 1; i >= 0; i--) {
            double s = 0;
            for (j = i; j < K + 1; j++) {
                s = s + sums[i][j] * a[j];
            }
            a[i] = (b[i] - s) / sums[i][i];
        }
        printresult();
    }

    public static void main(String[] args) {
        launch(args);
    }
}