

public class L10Mine   {


    public static double f(double x) {
        return Math.exp(- x * x / 2) / Math.sqrt(2 * Math.PI);
    }

    public static double integrate(double a, double b) {
        int N = 10000;                    // точность
        double h = (b - a) / (N - 1);     // шаг

        // 1/3 terms
        double sum = 1.0 / 3.0 * (f(a) + f(b));

        // 4/3 terms
        for (int i = 1; i < N - 1; i += 2) {
            double x = a + h * i;
            sum += 4.0 / 3.0 * f(x);
        }

        // 2/3 terms
        for (int i = 2; i < N - 1; i += 2) {
            double x = a + h * i;
            sum += 2.0 / 3.0 * f(x);
        }

        return sum * h;
    }
static double a = -3;
static double b = 3;

    // sample client program
    public static void main(String[] args) {


        System.out.println(integrate(a, b));
    }

}