package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * [백준] 1932 정수 삼각형
 *  출처 : https://www.acmicpc.net/problem/1932
 */

public class boj_1932 {

  public static void main(String[] args) throws IOException {

    // Input
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int N = Integer.parseInt(br.readLine());
    List<int[]> nums = new ArrayList<>();

    for (int i=0;i<N;i++) {
      nums.add(
        Arrays.stream(br.readLine().split(" "))
          .mapToInt(Integer::parseInt)
          .toArray());
    }

    // Solution
    List<int[]> dp = new ArrayList<>();
    dp.add(nums.get(0));
    for (int i=0;i<N-1;i++) {
      int[] prev = dp.get(i);
      int[] next = nums.get(i+1);
      int[] newArray = new int[nums.get(i + 1).length];
      for (int j=0;j<prev.length;j++) {
        for(int k=0;k<2;k++) {
          newArray[j+k] = Math.max((prev[j]+next[j+k]), newArray[j+k]);
        }
      }
      dp.add(newArray);
    }

    // Output
    int answer = 0;
    for (int i : dp.get(N-1)) {
      answer = Math.max(answer, i);
    }

    System.out.println(answer);

  }
}
