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
    double[] x = new double[n];//точки по которым интерполируем
    double[] y = new double[n];//точки по которым интерполируем
    double[] h = new double[n];//расстояния между иксами (только по икс)
    double[] l = new double[n];// l[k] = (y[k] - y[k-1])/h[k]
    double[] delta = new double[n];//прогоночные коэффициенты
    double[] lambda = new double[n];//прогоночные коэффициенты
    double[] c = new double[n];//коэффициенты в уравнениях для сплайнов
    double[] d = new double[n];//коэффициенты в уравнениях для сплайнов
    double[] b = new double[n];//коэффициенты в уравнениях для сплайнов
    double[] xc = new double[numD];//массив точек для записи координат графиков
    double[] yc = new double[numD];//массив точек для записи координат графиков

    public void initXXYYT() {//инициализация интерполяционных точек
        x[0] = 1;
        y[0] = 2;
        x[1] = 3;
        y[1] = 6;
        x[2] = 5;
        y[2] = 2;
        x[3] = 7;
        y[3] = -2;
        x[4] = 9;
        y[4] = 2;
    }// 5 2

    public void initXXYY() {//инициализация интерполяционных точек
        x[0] = 2;
        y[0] = 1;
        x[1] = 4;
        y[1] = 0;
        x[2] = 6;
        y[2] = 1;
        x[3] = 8;
        y[3] = 4;
        //x[4] = 9;
        //y[4] = 2;
    }// 5 2

    public void coefficients() {
        int k = 0;
        //System.out.printf("\na[k]\t\tb[k]\t\tc[k]\t\td[k]\n");
        for (k = 1; k < n; k++) {
            //System.out.printf("%f\t%f\t%f\t%f\n", y[k], b[k], c[k], d[k]);
        }
    }

    public void interpBuildCubSpl() {//заполняю массивы интерполированными точками
        double start = x[0];
        double end = x[n - 1];
        double step = (end - start) / numD;
        int i = 0;
        for (double s = start; s <= end; s += step) {
            int k;
            for (k = 1; k < n; k++) {
                if (s >= x[k - 1] && s <= x[k]) {
                    break;//перескакиваем на нужное k
                }
            }
            if (i < numD) {
                yc[i] = y[k] + b[k] * (s - x[k]) + c[k] * Math.pow(s - x[k], 2) + d[k] * Math.pow(s - x[k], 3);//считаем значения функции с помощью сплайнов
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
            h[k] = x[k] - x[k - 1];//считаем расстояние(только по икс) между точками интерполяции
            l[k] = (y[k] - y[k - 1]) / h[k];//это из уравнения прямой, проходящей через две точки
        }
        delta[1] = -h[2] / (2 * (h[1] + h[2]));//прогоночные коэффициенты
        lambda[1] = 1.5 * (l[2] - l[1]) / (h[1] + h[2]);//прогоночные коэффициенты
        for (k = 3; k < n; k++) {
            delta[k - 1] = -h[k] / (2 * h[k - 1] + 2 * h[k] + h[k - 1] * delta[k - 2]);//прогоночные коэффициенты
            lambda[k - 1] = (3 * l[k] - 3 * l[k - 1] - h[k - 1] * lambda[k - 2]) /
                    (2 * h[k - 1] + 2 * h[k] + h[k - 1] * delta[k - 2]);//прогоночные коэффициенты
        }
        c[0] = 0;
        c[n - 1] = 0;
        for (k = n - 1; k >= 2; k--) {
            c[k - 1] = delta[k - 1] * c[k] + lambda[k - 1];//находим коэффициенты с[k] по формулам обратной прогонки
        }
        for (k = 1; k < n; k++) {
            d[k] = (c[k] - c[k - 1]) / (3 * h[k]);//нахождение d[k] и b[k] по специальным формулам
            b[k] = l[k] + (2 * c[k] * h[k] + h[k] * c[k - 1]) / 3;
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
            seriesInt.getData().add(new XYChart.Data(x[i], y[i]));
        }
        seriesInt.setName("Точки интерполяции");

        System.out.println("before mainN");
        L9.mainN(n, xc, yc);
        System.out.println("After mainN");
        XYChart.Series seriesTrig = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesInt.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        seriesTrig.setName("Тригонометрическая интерполяция");

        interpolate();
        coefficients();
        interpBuildCubSpl();
        XYChart.Series seriesSpline = new XYChart.Series();
        for (int i = 0; i < numD; i++) {
            seriesSpline.getData().add(new XYChart.Data(xc[i], yc[i]));
        }
        seriesSpline.getData().add(new XYChart.Data(x[n - 1], y[n - 1]));
        seriesSpline.setName("Интерполяция кубическими сплайнами");

        lineChart.setAnimated(false);
        lineChart.setCreateSymbols(true);

        lineChart.getData().addAll(seriesInt,seriesTrig, seriesSpline );
        Scene scene = new Scene(lineChart, 800, 600);
        scene.getStylesheets().add(getClass().getResource("Style.css").toExternalForm());
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch(args);
    }
}
