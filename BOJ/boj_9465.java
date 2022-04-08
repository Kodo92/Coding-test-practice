package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * [백준 9465] 스티커
 *  출처 : https://www.acmicpc.net/problem/9465
 */
public class boj_9465 {

  private static void solution(BufferedReader br) throws IOException {
    int N = Integer.parseInt(br.readLine());

    int[][] scores = new int[2][];
    scores[0] = Arrays.stream(br.readLine().split(" "))
        .mapToInt(Integer::parseInt)
        .toArray();

    scores[1] = Arrays.stream(br.readLine().split(" "))
        .mapToInt(Integer::parseInt)
        .toArray();

    int length = N + 1;
    int[][] dp = new int[2][length];

    dp[0][1] = scores[0][0];
    dp[1][1] = scores[1][0];
    for (int i = 2; i < length ; i++) {
      for (int j = 0; j < 2; j++) {
        dp[j][i] = Math.max(dp[(j+1)%2][i-2],dp[(j+1)%2][i-1]) + scores[j][i-1];
      }
    }
    System.out.println(Math.max(dp[0][N], dp[1][N]));
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int N = Integer.parseInt(br.readLine());

    for (int i = 0; i < N; i++) {
      solution(br);
    }
  }

}
