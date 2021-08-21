import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.ArrayDeque;
import java.util.Arrays;

public class ProblemE {

    public BufferedReader scanner = new BufferedReader(new InputStreamReader(System.in));
    public PrintWriter out = new PrintWriter(System.out);
    public int n, m;
    public int[] p;
    public String[] in;

    void solve() {
        int[] cnt = new int[n];
        Arrays.fill(cnt, n);
        for (int i = 0; i < n; i++) {
            int d = ((i + n) - (p[i] - 1)) % n;
            // pos is shift to true postion
            cnt[d] --;
        }
        ArrayDeque<Integer> ans = new ArrayDeque<Integer>();
        for (int i = 0; i < n; i++) {
            if (cnt[i] + 1 <= m) {
                ans.push(i);
            } else {
                 if (cnt[i] <= 2*m) {
                     if (valid(i, p)) {
                         ans.add(i);
                     }
                 }
            }
        }
        out.print(ans.size());
        for (int a: ans) {
             out.print(" " + a);
        }
        out.println();
    }

    public boolean valid(int k, int[] a) {
        boolean[] visited = new boolean[n];
        int count = 0;
        for (int i = 0; i < n; i++) {
             if (visited[i]) {
                 continue;
             }
             visited[i] = true;
             int num = 1;
             for (int j = swap(a[i], k); j != i; j = swap(a[j], k), num ++) {
                 visited[j] = true;
             }
             count += num -1;
        }
        return  count <= m;
    }

    public int  swap(int val, int k) {
         return ((val - 1) + k) % n;
    }

    public void process() throws Exception {
        int t;
        t = Integer.parseInt(scanner.readLine());
        while (t-- != 0) {
            in = scanner.readLine().split(" ");
            n = Integer.parseInt(in[0]);
            m = Integer.parseInt(in[1]);
            in = scanner.readLine().split(" ");
            p = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = Integer.parseInt(in[i]);
            }
            solve();
        }
        out.flush();
    }

    public static void main(String[] args) throws Exception {
        ProblemE app = new ProblemE();
        app.process();
    }
}
