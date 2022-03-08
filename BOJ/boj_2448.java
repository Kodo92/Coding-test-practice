package boj;

import java.util.Scanner;

/**
 * [백준] 2448 별찍기 11
 *  출처 : https://www.acmicpc.net/problem/2448
 */

public class boj_2448 {

  private int N;
  private char[][] map;

  private void read() {
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    map = new char[N][(2*N)-1];
    for (char[] chars : map) {
      for (int i = 0; i < chars.length; i++) {
        chars[i] = ' ';
      }
    }
  }

  private void setStar(int yPos, int xPos) {
    map[yPos][xPos] = '*';

    map[yPos+1][xPos-1] = '*';
    map[yPos+1][xPos+1] = '*';

    map[yPos+2][xPos-2] = '*';
    map[yPos+2][xPos-1] = '*';
    map[yPos+2][xPos] = '*';
    map[yPos+2][xPos+1] = '*';
    map[yPos+2][xPos+2] = '*';
  }

  private void recursive(int yPos, int xPos, int k, int length) {
    if(k == 0) {
      setStar(yPos, xPos);
      return;
    }

    recursive(yPos,xPos, k-1,length/2);
    recursive(yPos+length,xPos - length , k-1,length/2);
    recursive(yPos+length,xPos + length, k-1,length/2);
  }

  private int getK() {
    int k = 0;
    int temp = N/3;
    while(temp/2 != 0) {
      temp /= 2;
      k++;
    }
    return k;
  }

  private void print() {

    for (char[] chars : map) {
      System.out.println(String.valueOf(chars));
    }
  }

  private void solution() {
    int k = getK();

    recursive(0,N-1,k,N/2);
    print();
  }


  public static void main(String[] args) {
    boj_2448 sol = new boj_2448();
    sol.read();
    sol.solution();
  }
}
