package boj;

import java.math.BigInteger;
import java.util.Scanner;

public class boj_2407 {

  private int N,M;

  private void read() {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    M = sc.nextInt();
  }

  private void solution() {
    int count = Math.min(M, N-M);

    BigInteger up = BigInteger.ONE;
    BigInteger down = BigInteger.ONE;
    for (int i=0;i<count;i++) {
      up = up.multiply(new BigInteger(String.valueOf(N-i)));
      down = down.multiply(new BigInteger(String.valueOf(i+1)));
    }

    System.out.println(up.divide(down));
  }

  public static void main(String[] args) {
    boj_2407 sol = new boj_2407();

    sol.read();
    sol.solution();
  }
}
