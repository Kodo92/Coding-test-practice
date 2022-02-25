package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

/**
 * [백준] 1629 곱셈
 *  출처 : https://www.acmicpc.net/problem/1629
 */
public class boj_1629 {

  private int[] inputs;

  private void read() throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    inputs = Arrays.stream(br.readLine().split(" "))
      .mapToInt(Integer::parseInt)
      .toArray();
  }

  private long solution(int a, int b, int c) {
    if(b == 1)
      return a%c;
    else if(b % 2 == 0) {
      // b가 짝수인 경우
      // 2*2*2*2 == 4 * 4
      long retval = solution(a,b/2,c);
      return (retval*retval)%c;
    } else {
      long retval  = solution(a,b-1,c);
      return (retval*a)%c;
    }
  }

  public static void main(String[] args) throws IOException {
    boj_1629 solution = new boj_1629();
    solution.read();
    System.out.println(solution.solution(solution.inputs[0], solution.inputs[1], solution.inputs[2]));
  }

}
