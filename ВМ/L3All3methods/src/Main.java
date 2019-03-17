public class Main {
    public static double a = 1, b = 2, d, x, e = 0.00001;
    int с = 0;

    public double f(double x) {
        return x * x - 2;
    }

    public double mpd() {//метод половинного деления или метод бисекций
        if (f(a) * f(b) > 0) {
            System.out.println("Условие на сходимость не выполняется");
            return 0;
        } else {
            while (Math.abs(a - b) > e) {
                x = (a + b) / 2;
                if (f(a) * f(x) < 0) {
                    b = x;
                } else a = x;
                System.out.print("Итерация номер: " + ++с + ", промежуточное значение X = ");
                System.out.printf("%2.5f", x);
                System.out.println();
            }

            return 0;
        }
    }

    public static void main(String[] args) {

        Main mn = new Main();
        mn.mpd();

    }
}
