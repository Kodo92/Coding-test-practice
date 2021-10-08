package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

/**
 * [백준] 문자열 폭발
 * 출처 : https://www.acmicpc.net/problem/9935
 * 풀이기법 : Stack
 */
public class boj_9935 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    char[] str = br.readLine().toCharArray();
    char[] bomb = br.readLine().toCharArray();

    StringBuilder answer = new StringBuilder();
    int idx = 0;
    for (int i = 0; i < str.length; i++) {
      answer.append(str[i]);
      if (answer.length() >= bomb.length) {
        boolean isCollect = true;
        for (int j = answer.length() - 1, k = bomb.length-1; j >= 0 && k >= 0; j--, k--) {
          if (answer.charAt(j) != bomb[k]) {
            isCollect = false;
            break;
          }
        }
        if (isCollect) {
          answer.delete(answer.length() - bomb.length, answer.length());
        }
      }
    }
    if (answer.length() == 0)
      System.out.println("FRULA");
    else {

      System.out.println(answer);
    }
  }
}
