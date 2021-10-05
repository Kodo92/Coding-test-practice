package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 백준 - 회전 초밥
 *  출처 : https://www.acmicpc.net/problem/15961
 *  문제 구분 : two-pointer
 */

public class boj_15961 {

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine()," ");

    int N = Integer.parseInt(st.nextToken());
    int D = Integer.parseInt(st.nextToken());
    int K = Integer.parseInt(st.nextToken());
    int C = Integer.parseInt(st.nextToken())-1;

    int[] sushis = new int[N];
    for (int i = 0; i < N; i++) {
      sushis[i] = Integer.parseInt(br.readLine())-1;
    }


    int[] useCount = new int[3_000_000];

    int count = 0;
    boolean isContain = false;
    for (int i = 0; i < K; i++) {
      if(useCount[sushis[i]] == 0) {
        count++;
        if(sushis[i] == C) {
          isContain = true;
        }
      }
      useCount[sushis[i]]++;
    }
    int answer = count;
    answer += (isContain) ? 0 : 1;

    int endIdx = K;
    for (int startIdx = 1; startIdx < N; startIdx++, endIdx = (endIdx+1)%N) {
      if(--useCount[sushis[startIdx-1]] == 0) {
        count--;
        if(sushis[startIdx-1] == C)
          isContain = false;
      }

      if(++useCount[sushis[endIdx]] == 1) {
        count++;
        if(sushis[endIdx] == C)
          isContain = true;
      }
      answer = Math.max(count + ((isContain) ? 0 : 1),answer);
      if(answer == K+1)
        break;
    }
    System.out.println(answer);
  }
}
