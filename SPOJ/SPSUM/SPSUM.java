import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;

class SPSUM {

    public static BigInteger ten = BigInteger.valueOf(10);

    public static BigInteger getAns(int d, BigInteger n) {
        if (n.compareTo(BigInteger.ZERO) <= 0) {
            return BigInteger.ZERO;
        }
        // Phase 1
        BigInteger res = n.divide(ten);
        if (n.mod(ten).compareTo(BigInteger.valueOf(d)) >= 0)
            res = res.add(BigInteger.ONE);
        // Phase 2
        String str = n.divide(ten).toString();
        int cnt = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str.charAt(i) == '0' + d) {
                cnt++;
            }
        }
        res = res.add(n.mod(ten).add(BigInteger.ONE).multiply(BigInteger.valueOf(cnt)));
        // Phase 3
        res = res.add(getAns(d, n.divide(ten).subtract(BigInteger.ONE)).multiply(ten));
        return res;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger n = new BigInteger(br.readLine());
        BigInteger res = BigInteger.ZERO;
        for (int digit = 1; digit < 10; digit++) {
            BigInteger u = getAns(digit, n);
            // System.out.println(digit + ": " + u);
            res = res.add(u.multiply(BigInteger.valueOf(digit)));
        }
        System.out.println(res);
    }
}