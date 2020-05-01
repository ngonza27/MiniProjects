/**
 *
 * @author Nicolas Gonzalez Vallejo
 */
public class Nreinas {
    int[] x;
    public Nreinas(int N) {
        x = new int[N];
    }

    public boolean posicion(int r, int c) {
        for (int i = 0; i < r; i++) {
            if (x[i] == c || (i - r) == (x[i] - c) ||(i - r) == (c - x[i])){
                return false;
            }
        }
        return true;
    }

    public void imprimirReinas(int[] x) {
        int N = x.length;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (x[i] == j) {
                    System.out.print("Q ");
                } else {
                    System.out.print("* ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }

    public void reinas(int r, int n) {
        for (int c = 0; c < n; c++) {
            if (posicion(r, c)) {
                x[r] = c;
                if (r == n - 1) {
                    imprimirReinas(x);
                } else {
                    reinas(r + 1, n);
                }
            }
        }
    }

    public void reinasAux() {
        reinas(0, x.length);
    }

    public static void main(String args[]) {
        Nreinas Q = new Nreinas(5);
        Q.reinasAux();
    }
}
