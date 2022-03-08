package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * [백준-9251] LCS
 *  출처 : https://www.acmicpc.net/problem/9251
 */

public class boj_9251 {

  public static void main(String[] args) throws IOException {

    // input
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    char[] str1 = br.readLine().toCharArray();
    char[] str2 = br.readLine().toCharArray();

    int[][] lcs = new int[str2.length+1][str1.length+1];

    for (int i = 1; i < str2.length + 1; i++) {
      for (int j = 1; j < str1.length + 1; j++) {
        if(str1[j-1] == str2[i-1]) {
          lcs[i][j] = lcs[i-1][j-1]+1;
        } else {
          lcs[i][j] = Math.max(lcs[i-1][j],lcs[i][j-1]);

        }
      }
    }

    System.out.println(lcs[str2.length][str1.length]);
  }

}
