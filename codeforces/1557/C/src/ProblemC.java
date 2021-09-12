import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.stream.IntStream;

public class ProblemC {

    public BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
    public PrintWriter out = new PrintWriter(System.out);
    public String[] in;
    int n, k;
    final int MAXN = (int)1e6;
    long[] pow2 = new long[MAXN];

    final long MOD = (long) (1e9+7);

    long fast_pow(long x, long y) {
        if (y == 0)
            return 1;
        if (y == 1)
            return x;
        long res =  fast_pow(x, y/2);
        res = res * res % MOD;
        if (y % 2 == 1) {
            return  res * x % MOD;
        }
        return res;
    }

    void solve(int n, int k) {
        long dp[] = new long[k+1];
        dp[0] = 1;
        for (int i = 1; i <= k; i++) {
            if (n % 2 == 0) {
                dp[i] = (pow2[n-1]-1)*dp[i-1] + fast_pow(pow2[n], i-1);
            } else {
                dp[i] = (pow2[n-1]+1)*dp[i-1];
            }
             dp[i] %= MOD;
        }
        out.println(dp[k]);
    }

    void process() throws Exception {
        int t = Integer.parseInt(scanner.readLine());
        pow2[0] = 1;
        IntStream.range(1, MAXN-1).forEachOrdered(it -> {
            pow2[it] = (pow2[it] * 2) % MOD;
        });
        for (int i = 1; i < MAXN; i++) {
            pow2[i] = (pow2[i-1] * 2) % MOD;
        }
        while (t-- != 0) {
            in = scanner.readLine().split(" ");
            n = Integer.parseInt(in[0]);
            k = Integer.parseInt(in[1]);
            solve(n, k);
        }
        out.flush();
    }

    public static void main(String[] args) throws Exception {
        ProblemC  app = new ProblemC();
        app.process();
    }
}
