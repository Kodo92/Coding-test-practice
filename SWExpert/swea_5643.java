package SWEA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_5643 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    int T = Integer.parseInt(br.readLine());
    for (int testCase = 1; testCase <= T; testCase++) {
      int N = Integer.parseInt(br.readLine());
      int M = Integer.parseInt(br.readLine());
      boolean[][] map = new boolean[N][N];
      for (int i = 0; i < N; i++) {
        map[i][i] = true;
      }
      for (int i = 0; i < M; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        map[Integer.parseInt(st.nextToken())-1][Integer.parseInt(st.nextToken())-1] = true;
      }

      for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
            if(map[i][k] && map[k][j])
              map[i][j] = true;
          }
        }
      }

      int answer = 0;
      loop:
      for (int i = 0; i < N; i++) {
        for (int j = 0; j < map[i].length; j++) {
          if(!map[i][j] && !map[j][i])
            continue loop;
        }
        answer++;
      }
      sb.append("#"+testCase+' ').append(answer).append('\n');
    }
    System.out.println(sb);
  }
}

