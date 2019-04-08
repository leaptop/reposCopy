import java.util.Scanner;


public class L9 {

    static double pi = 3.1415926;
    static int n, numD = 100;
    static double a[], b[];
    static double xc[] = new double[numD];
    static double yc[] = new double[numD];

    static double A(int j) {
        double S = 0;
        int ii;
        for (int i = -n; i < n + 1; i++) {

            S = S + Function(2 * pi * (double) (i) / (2 * n + 1)) * Math.cos(2 * pi * (double) (j) * (double) (i) / (2 * n + 1));
        }
        if (j == 0) return 1 / (double) (2 * n + 1) * S;

        return 2 / (double) (2 * n + 1) * S;
    }

    static double B(int j) {
        int ii;
        double S = 0;
        for (int i = -n; i < n + 1; i++) {
            ii = -n + i;
            S = S + Function(2 * pi * (double) (i) / (double) (2 * n + 1)) * Math.sin(2 * pi * (double) (j * i) / (double) (2 * n + 1));
        }
        return 2 / (double) (2 * n + 1) * S;
    }

    static double Function(double x) {
        if (x < -1.5) return (double) (1);
        if (x >= -1.5 && x < 1.6) return 0.5;
        return -0.333;
    }

    static double Interpolate(double x) {
        double S = a[0];
        for (int i = 1; i < n; i++) {
            S = S + a[i] * Math.cos((double) (i) * x) + b[i] * Math.sin((double) (i) * x);
        }
        return S;
    }

    public static void mainN(int n, double xc[], double yc[]) {
        {
             n = n;
            Scanner in = new Scanner(System.in);

            double size = 4;

           // System.out.println(" Size of result vector? ");
            //size = in.nextDouble();


//double* xj=new double[N];
            // cout <<n<<endl;
            a = new double[n];
            b = new double[n];
        /*
        ofstream oo;
        oo.open("result.txt");
        oo<< size<<" "<<endl;
        cout<<size<<endl;
*/
            System.out.println(" Коэффициенты a :");
            for (int j = 0; j < n; j++) {
                a[j] = A(j);
                //oo<<a[j]<<endl;
                System.out.println("a[j] = "+a[j]);

            }

            System.out.println(" Коэффициенты b :");
            for (int j = 1; j < n; j++) {
                b[j] = B(j);
                //oo<<b[j]<<endl;
                System.out.println("b[j] = "+b[j]);
            }
            double x;
            System.out.println("Координаты узлов  и значения в них");
            for (int j = 0; j < size; j++) {
              xc[j] = x = -pi + 2 * pi / size * j;
                //oo<<x<<"\t"<<Function(x)<<endl;
              yc[j] =  Function(x);
            }
            System.out.println(" STOP ");
            for (int j = 0; j < size; j++) {
                x = -pi + 2 * pi / size * j;
                // oo<<x<<"\t"<<Interpolate(x)<<endl;
                Interpolate(x);
            }
            System.out.println(" Error ");
            for (int j = 0; j < 400; j++) {
                x = -pi + 2 * pi / size * j;
                //oo<<x<<"\t"<<Interpolate(x)-Function(x)<<endl;
                System.out.println("x = " + x + "Interpolate(x)-Function(x) = " + (Interpolate(x) - Function(x)));
            }
        }
    }
}