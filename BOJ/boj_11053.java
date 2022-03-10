package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;

/**
 * [백준 11053] 가장 긴 증가하는 부분 수열 출처 : https://www.acmicpc.net/problem/11053
 */
public class boj_11053 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    int[] inputs = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

    int[] answers = new int[N];
    int pos = 0;
    answers[pos++] = inputs[0];
    for (int i = 1; i < N; i++) {
      if (answers[pos - 1] < inputs[i]) {
        answers[pos++] = inputs[i];
      } else if (answers[pos - 1] > inputs[i]) {
        int idx = upperBound(answers, pos, inputs[i]);
        answers[idx] = inputs[i];
      }
    }
    System.out.println(pos);
  }

  private static int upperBound(int[] array, int pos, int val) {
    int left = 0, right = pos, mid;
    while (left < right) {
      mid = (left + right) / 2;
      if (array[mid] < val) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return right;
  }

}

/*
4
10 20 10 20
answer : 2

 */

