package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * [백준] 2096 내려가기
 *  출처 : https://www.acmicpc.net/problem/2096
 */
public class boj_2096 {

  private int N;
  int[][] map;
  int[][] min;
  int[][] max;

  private void read() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    N = Integer.parseInt(br.readLine());
    map = new int[N][];
    min = new int[N][];
    max = new int[N][3];

    for (int i = 0; i < N; i++) {
      map[i] = Arrays.stream(br.readLine().split(" "))
          .mapToInt(Integer::parseInt)
          .toArray();
      min[i] = new int[] {Integer.MAX_VALUE,Integer.MAX_VALUE,Integer.MAX_VALUE};
    }

    min[0] = max[0] = map[0];
  }

  private void solution() {
    for (int i = 0; i < N - 1; i++) {
      for (int j = 0; j < 3; j++) {
        for (int k = -1; k < 2; k++) {
          if((j+k < 0) || (j+k >= 3)) continue;
          min[i+1][j+k] = Math.min(min[i][j] + map[i+1][j+k], min[i+1][j+k]);
          max[i+1][j+k] = Math.max(max[i][j] + map[i+1][j+k], max[i+1][j+k]);
        }
      }
    }
    int maxAnswer = 0, minAnswer = Integer.MAX_VALUE;
    for (int i = 0; i < 3; i++) {
      maxAnswer = Math.max(maxAnswer, max[N-1][i]);
      minAnswer = Math.min(minAnswer, min[N-1][i]);
    }
    System.out.println(maxAnswer + " " +minAnswer);
  }

  public static void main(String[] args) throws IOException {
    boj_2096 sol = new boj_2096();
    sol.read();
    sol.solution();
  }
}
