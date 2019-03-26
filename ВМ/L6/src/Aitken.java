import java.lang.*;

public class Aitken {
    public static void main(String []argv) {
        double []xi = {1, 1.2, 1.4, 1.6};
        double []fi = {1, 1.0954, 1.1832, 1.2649};

        double x = 1.44;
        double f = aitken(x, xi, fi);
        System.out.println("Интерполированное значение: " + f);
    }

    public static double aitken(double x, double []xi,  double []fi) {
        int n = xi.length - 1;
        double []ft =  fi.clone();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n - i; ++j) {
                ft[j] = (x - xi[j]) / (xi[i + j + 1] - xi[j]) * ft[j + 1]
                        + (x - xi[i + j + 1]) / (xi[j] - xi[i + j + 1]) * ft[j];
                System.out.println("i = " + i + "; j = " + j + "; Интерполированное значение: " + ft[j]);
            }
        }
        return ft[0];
    }
}
