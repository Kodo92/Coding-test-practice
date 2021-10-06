package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class boj_2239 {
  private static final int N = 9;
  private static int[][] map;
  private static boolean[][] heightUsed, widthUsed, squareUsed;
  private static String answer;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    heightUsed = new boolean[N][N+1];
    widthUsed = new boolean[N][N+1];
    squareUsed = new boolean[N][N+1];

    map = new int[N][N];
    for (int i = 0; i < N; i++) {
      char[] input = br.readLine().toCharArray();
      for (int j = 0; j < N; j++) {
        map[i][j] = Character.getNumericValue(input[j]);
        heightUsed[i][map[i][j]] = true;
        widthUsed[j][map[i][j]] = true;
        squareUsed[getSquareIdx(i,j)][map[i][j]] = true;
      }
    }

    DFS(0,0);

    System.out.println(answer);
  }

  private static boolean DFS(final int yIdx, final int xIdx) {
    int ny = yIdx, nx = xIdx;
    while(true) {
      if(map[ny][nx] == 0) {
        break;
      }
      nx++;
      if(nx == N) {
        nx = 0;
        ny++;
        if(ny == N) {
          break;
        }
      }
    }

    if(ny >= N) {
      String result = mapToString();
      if(answer==null || answer.compareTo(result) > 0)
        answer = result;
      return true;
    }

    int squareIdx = getSquareIdx(ny,nx);
    for (int i = 1; i < 10; i++) {
      if(!heightUsed[ny][i] && !widthUsed[nx][i] && !squareUsed[squareIdx][i]) {
        heightUsed[ny][i] = true;
        widthUsed[nx][i] = true;
        squareUsed[squareIdx][i] = true;
        map[ny][nx] = i;
        if(DFS(ny,nx))
          return true;
        map[ny][nx]=0;
        heightUsed[ny][i] = false;
        widthUsed[nx][i] = false;
        squareUsed[squareIdx][i] = false;
      }
    }
    return false;
  }

  private static int getSquareIdx(final int yIdx, final int xIdx) {
    return ((yIdx/3)*3) + xIdx/3;
  }

  private static String mapToString() {
    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        sb.append(map[i][j]);
      }
      sb.append('\n');
    }
    return sb.toString();
  }
}

