public class L10Mine {
    static double a = 1.0;
    static double b = 2.0;

    static int Razb = 10;// число разбиений
    static int N = Razb, n = Razb / 2;
    static double h = (b - a) / N;
    static double H = (b - a) / n;
    static double e = 0.00000001;// надо до 10 в минус восьмой

    public static double f(double x) {
        return 1 / x;
    }

    public static double integrateTrapezii(double a, double b, double h) {

        double sum = 0, x = 0;
        for (int i = 0; x < b; i++) {
            x = a + h * i;
            sum += h * (f(x) + f(x + h)) / 2;
        }
        return sum;
    }

    public static double integrateSimpson(double a, double b, double h, int N) {
        // 1/3
        double sum = 1.0 / 3.0 * (f(a) + f(b));//

        // 4/3
        for (int i = 1; i < N - 1; i += 2) {
            double x = a + h * i;
            sum += 4.0 / 3.0 * f(x);
        }

        // 2/3
        for (int i = 2; i < N - 1; i += 2) {
            double x = a + h * i;
            sum += 2.0 / 3.0 * f(x);
        }

        return sum * h;
    }

    public static void main(String[] args) {
        double aa, bb, dif ;

        /*
        System.out.println("\nTrapezii: ");
        Razb = 10;// число разбиений
        N = Razb;
        n = Razb / 2;
        h = (b - a) / N;
        H = (b - a) / n;
        System.out.println("Trapezii(h) : " + integrateTrapezii(a, b, h));
        System.out.println("Trapezii(H) : " + integrateTrapezii(a, b, H));
        aa = integrateTrapezii(a, b, h);
        bb = integrateTrapezii(a, b, H);
        dif = Math.abs(Math.abs(bb) - Math.abs(aa));
        while (dif > e) {// если здесь д.б. цикл, то как его реализовать?
            //correct = aa + 1.0 / 3.0 * (aa - bb);
            dif = Math.abs(Math.abs(bb) - Math.abs(aa));
            Razb *= 10.0;
            N = Razb; //большее число разбиений
            n = Razb / 2;//меньшее число разбиений
            h = (b - a) / N;//меньший шаг
            H = (b - a) / n;//больший шаг
            aa = integrateTrapezii(a, b, h);
            bb = integrateTrapezii(a, b, H);
            System.out.println("    Correct = " + aa + ", h = " + h + "\n");
        }
        // correct = correct + 1.0 / 3.0 * (aa - bb);
        System.out.println("FinlCorrect = " + aa);
        System.out.println("Точность : " + e);
*/


         aa = integrateSimpson(a, b, h, N);
         bb = integrateSimpson(a, b, H, n);
        double correct = 0, correct2 = 0;
        System.out.println("\nSimpson: ");
        dif = dif = Math.abs(Math.abs(bb) - Math.abs(aa));
        System.out.println("Simpson(h) : " + aa);
        System.out.println("Simpson(H) : " + bb);
        while (dif > 3.0 * e) {// если здесь д.б. цикл, то как его реализовать?
            dif = Math.abs(Math.abs(bb) - Math.abs(aa));
            Razb += 10;
            N = Razb; //большее число разбиений
            n = Razb / 2;//меньшее число разбиений
            h = (b - a) / N;//меньший шаг
            H = (b - a) / n;//больший шаг
            aa = integrateSimpson(a, b, h, N);
            bb = integrateSimpson(a, b, H, n);
            System.out.println("    Correct = " + aa + ", h = " + h + "\n");
        }
        // correct = correct + 1.0 / 3.0 * (aa - bb);
        correct = aa + 1.0 / 3.0 * (aa - bb);
        System.out.println("FinlCorrect = " + correct);
        System.out.println("Точность : " + e);







    }// ln(2) = 0.6931471805599
    //Simpson при шаге 0.01 даёт погрешность десять в минус восьмой, трапеции тоже быстрые
}