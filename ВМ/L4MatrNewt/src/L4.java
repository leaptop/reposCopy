import com.sun.xml.internal.bind.v2.schemagen.xmlschema.SimpleDerivation;

import java.util.function.DoubleFunction;

public class L4 {
    private static final double DX = 0.00000001;
    public static double a = 1, b = 2, x = 2, y = 1, e = 0.0001;
    static int c = 0;
    public static double det;


    private static DoubleFunction<Double> derive(DoubleFunction<Double> f) {// здесь как-то считается производная
        return (x) -> (f.apply(x + DX) - f.apply(x)) / DX;
    }

    public static double[][] m = new double[2][2];

    public static void mCount() {//расчёт матрицы по производным и приближенным значениям икс и игрек
        m[0][0] = nm00(x, y);
        m[0][1] = nm01(x, y);
        m[1][0] = nm10(x, y);
        m[1][1] = nm11(x, y);
    }

    public static void determCount() {//расчёт определителя матрицы
        det = m[0][0] * m[1][1] - m[0][1] * m[1][0];
    }

    public static void mAlgebrDopoln() {//построение матрицы алгебр. дополнений
        double temp = m[0][0];
        m[0][0] = m[1][1];
        m[1][1] = temp;

        temp = m[0][1];
        m[0][1] = m[1][0];
        m[1][0] = temp;
    }

    public static void mTranspon() {//транспонирование матрицы
        double temp = m[1][0];
        m[1][0] = m[0][1];
        m[0][1] = temp;

        m[0][1] = -1 * m[0][1];
        m[1][0] = -1 * m[1][0];
    }

    public static void mObratn() {//построение обратной матрицы
        m[0][0] = m[0][0] * (1 / det);
        m[0][1] = m[0][1] * (1 / det);
        m[1][0] = m[1][0] * (1 / det);
        m[1][1] = m[1][1] * (1 / det);
    }

    public static void finalCount() {//расчёт икс и игрек
        x = x - (m[0][0] * f11 + m[0][1] * f22);
        y = y - (m[1][0] * f11 + m[1][1] * f22);
    }

    public static double f11 = x * x + y * y * y - 4;
    public static double f22 = x / y - 2;

    public static double nm00(double argX, double y) {//argX - отдельная переменная, т.к. лямбда по-другому не разрешает
        //f1(x) = x*x + y*y*y - 4
        DoubleFunction<Double> f1 = (x) -> (x * x + y * y * y - 4);//f11
        //f1'(x) = 2x( производная по икс)
        DoubleFunction<Double> f1Deriv = derive(f1);
        return f1Deriv.apply(argX);
    }

    public static double nm10(double argX, double y) {
        //f2(x) = x/y - 2
        DoubleFunction<Double> f2 = (x) -> (x / y - 2);//f22
        //f2'(x) = 1/y(производная по икс)
        DoubleFunction<Double> f2Deriv = derive(f2);
        return f2Deriv.apply(argX);
    }

    public static double nm01(double x, double argY) {
        //f1(x) = x*x + y*y*y - 4
        DoubleFunction<Double> f1 = (y) -> (x * x + y * y * y - 4);//f11
        //f1'(x) = 3*y*y( производная по игрек)
        DoubleFunction<Double> f1Deriv = derive(f1);
        return f1Deriv.apply(argY);
    }

    public static double nm11(double x, double argY) {
        //f2(x) = x/y - 2
        DoubleFunction<Double> f2 = (y) -> (x / y - 2);//f22
        //f2'(x) = -x/(y*y) (производная по игрек)
        DoubleFunction<Double> f2Deriv = derive(f2);
        return f2Deriv.apply(argY);
    }

    public static void main(String[] args) {

        double xt = x, yt = y;

        //System.out.println(" x = " + nm11(10, 6));

        for(int i =0; i<8; i++){
            System.out.println("№1 X = " + x + "; Y = " + y);
            mCount();
            System.out.println("№2 X = " + x + "; Y = " + y);
            determCount();
            System.out.println("№3 X = " + x + "; Y = " + y);
            mAlgebrDopoln();
            System.out.println("№4 X = " + x + "; Y = " + y);
            mTranspon();
            System.out.println("№5 X = " + x + "; Y = " + y);
            mObratn();
            System.out.println("№6 X = " + x + "; Y = " + y);
            finalCount();
            System.out.println("№7 X = " + x + "; Y = " + y);
        }

        /*do {
            mCount();
            determCount();
            mAlgebrDopoln();
            mTranspon();
            mObratn();
            finalCount();
            System.out.println("X = " + x + "; Y = " + y);
        } while (Math.abs((Math.abs(x) - Math.abs(xt))) > e && Math.abs((Math.abs(y) - Math.abs(yt))) > e);
*/
    }



     /* public static void newt() {// метод Ньютона или метод касательных

        // f(x) = x^2 -2
        DoubleFunction<Double> ff = (x) -> (x * x - 2);
        //f'(x) = 2*x
        DoubleFunction<Double> fDeriv = derive(ff);
        //f''(x) = 2
        DoubleFunction<Double> fDeriv2 = derive(fDeriv);

        if (f(x) * fDeriv2.apply(a) < 0)
            x = a;//условие сходимости выполнено для a
        else x = b;//условие сходимости выполнено для b

        while (Math.abs(f(x)) > e) {
            x = x - f(x) / fDeriv.apply(x);//в этом выражении суть метода Ньютона
            print();
        }
    }*/
}