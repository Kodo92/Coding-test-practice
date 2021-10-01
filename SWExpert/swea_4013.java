package SWEA;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea_4013 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    int T = Integer.parseInt(br.readLine());
    for (int testCase = 1; testCase <= T; testCase++) {
      int K = Integer.parseInt(br.readLine());
      Gear[] gears = new Gear[4];
      for (int i = 0; i < 4; i++) {
        gears[i] = new Gear(Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray());
      }

      for (int i = 0; i < K; i++) {
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        final int gearIdx = Integer.parseInt(st.nextToken())-1;
        final int dir = Integer.parseInt(st.nextToken());
        spin(gears, gearIdx, dir);
      }
      bw.write("#"+testCase+" "+getScore(gears)+"\n");
    }
    bw.close();
  }

  private static void spin(Gear[] gears, final int startIdx, final int dir) {
    int[] isSpin = new int[4];
    int left = startIdx, right = startIdx;
    int pivot = startIdx;
    isSpin[startIdx] = dir;
    // left
    while ((left-=1) >= 0) {
        if(gears[left].isSpin(false,gears[pivot].getLeftMagnetism()))
          isSpin[left] = (isSpin[pivot] == 1 ? -1 : 1);
        else
          break;
        pivot = left;
    }

    pivot = startIdx;
    // right
    while ((right+=1) < 4) {
      if(gears[right].isSpin(true,gears[pivot].getRightMagnetism()))
        isSpin[right] = (isSpin[pivot] == 1 ? -1 : 1);
      else
        break;
      pivot = right;
    }

    for (int i = 0; i < 4; i++) {
      if(isSpin[i] != 0)
        gears[i].spin(isSpin[i]);
    }
  }

  private static int getScore(final Gear[] gears) {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      sum += (gears[i].getScore() << i);
    }
    return sum;
  }

  static class Gear {
    private int scoreIdx = 0;
    private int leftIdx = 6;
    private int rightIdx = 2;
    private final int[] magnetisms;

    public Gear(int[] numbers) {
      this.magnetisms = numbers;
    }

    // Gear가 왼쪽인 경우
    public boolean isSpin(final boolean isLeft, final int magnetism) {
      int pivot;
      if(isLeft) {
        pivot = leftIdx;
      } else {
        pivot = rightIdx;
      }
      if(magnetism != magnetisms[pivot])
        return true;
      return false;
    }

    public int getLeftMagnetism() {
      return magnetisms[leftIdx];
    }

    public int getRightMagnetism() {
      return magnetisms[rightIdx];
    }

    public int getScore() {
      return magnetisms[scoreIdx];
    }

    // 1 : 시계 && -1 : 반시계
    public void spin(final int dir) {
      if(dir == -1) {
        scoreIdx = (scoreIdx+1)%8;
        leftIdx = (leftIdx+1)%8;
        rightIdx = (rightIdx+1)%8;
      } else {
        scoreIdx -= 1;
        scoreIdx += (scoreIdx < 0) ? 8 : 0;
        leftIdx -= 1;
        leftIdx += (leftIdx < 0) ? 8 : 0;
        rightIdx -= 1;
        rightIdx += (rightIdx < 0) ? 8 : 0;
      }
    }
  }
}
