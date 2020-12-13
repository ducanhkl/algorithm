import java.io.*;
import java.util.*;
import java.math.*;

public class SPSUMT {
    public static final BigInteger ten = BigInteger.valueOf(10);

    public static BigInteger get(int digit, BigInteger n) {
        if (digit == 0 && n.compareTo(ten) < 0)
            return BigInteger.ZERO;
        if (n.compareTo(BigInteger.ZERO) <= 0)
            return BigInteger.ZERO;
        BigInteger res = n.divide(ten);
        if (digit > 0 && n.mod(ten).compareTo(BigInteger.valueOf(digit)) >= 0)
            res = res.add(BigInteger.ONE);
        res = res.add(get(digit, n.divide(ten).subtract(BigInteger.ONE)).multiply(ten));
        String buff = n.divide(ten).toString();
        int cnt = 0;
        for (int i = 0; i < buff.length(); i++)
            if (buff.charAt(i) == '0' + digit)
                cnt++;
        res = res.add(n.mod(ten).add(BigInteger.ONE).multiply(BigInteger.valueOf(cnt)));
        return res;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BigInteger n = new BigInteger(br.readLine());
        BigInteger res = BigInteger.ZERO;
        for (int digit = 0; digit < 10; digit++) {
            BigInteger u = get(digit, n);
            // System.out.println(digit + ": " + u);
            res = res.add(u.multiply(BigInteger.valueOf(digit)));
        }
        System.out.println(res);
    }
}