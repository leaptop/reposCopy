

public class L10Mine {
    static double a = 2;
    static double b = 3;
    static int Razb = 1000000;// число разбиений
    static int N = Razb, n = Razb / 2;
    static double h = (b - a) / N;
    static double H = (b - a) / n;
    static double e = 0.0000001;

    public static double f(double x) {
        return 2 * x;
    }

    public static double integrateTrapezii(double a, double b, double h) {

        double sum = 0, x = 0;
        for (int i = 0; x < b; i++) {
            x = a + h * i;
            sum += h * (f(x) + f(x + h)) / 2;
        }
        return sum;
    }

    public static double integrateSimpson(double a, double b) {

        // 1/3 terms
        double sum = 1.0 / 3.0 * (f(a) + f(b));//

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

    public static void main(String[] args) {

        System.out.println("Trapezii(h) : " + integrateTrapezii(a, b, h));
        System.out.println("Trapezii(H) : " + integrateTrapezii(a, b, H));
        double aa = integrateTrapezii(a, b, h);
        double bb = integrateTrapezii(a, b, H);
        double correct;
        if (Math.abs(bb - aa) > 3.0 * e) {// если здесь д.б. цикл, то как его реализовать?
            correct = aa + 1.0/3.0 * (aa-bb);
            System.out.println("Correct = "+ correct);
        }else System.out.println("aa = "+ aa);

        while(Math.abs(aa - bb) > 3.0 * e){
            aa = aa + 1.0/3.0 * Math.abs(aa-bb);
            System.out.println("bb = "+bb);
        }
    }

}