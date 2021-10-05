package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

/**
 * [백준] 나무 재테크
 *  출처 : https://www.acmicpc.net/problem/16235
 */
public class boj_16235 {

  private static int N,M,K;
  private static int[][] foods;
  private static int[][] foodTable;

  private static int[] dx = {-1,0,1,1,1,0,-1,-1};
  private static int[] dy = {-1,-1,-1,0,1,1,1,0};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine()," ");

    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    K = Integer.parseInt(st.nextToken());

    foodTable = new int[N][N];
    for (int i = 0; i < N; i++) {
      foodTable[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }

    foods = new int[N][N];
    for (int i = 0; i < N; i++) {
      Arrays.fill(foods[i],5);
    }

    ArrayList<Tree> trees = new ArrayList<>();
    for (int i = 0; i < M; i++) {
      st = new StringTokenizer(br.readLine()," ");
      int y = Integer.parseInt(st.nextToken())-1;
      int x = Integer.parseInt(st.nextToken())-1;
      int age = Integer.parseInt(st.nextToken());

      trees.add(new Tree(y,x,age));
    }

    for (int i = 0; i < K; i++) {
      trees = spring(trees);
      authmn(trees);
      winter();
    }
    System.out.println(trees.size());
  }

  private static ArrayList<Tree> spring(ArrayList<Tree> trees) {
    ArrayList<Tree> live = new ArrayList<>(), dead = new ArrayList<>();
    trees.sort(null);
    for (Tree tree : trees) {
      if(tree.age > foods[tree.yIdx][tree.xIdx])
        dead.add(tree);
      else {
        foods[tree.yIdx][tree.xIdx] -= tree.age;
        tree.age++;
        live.add(tree);
      }
    }
    summer(dead);
    return live;
  }

  private static void summer(final ArrayList<Tree> dead) {
    for (Tree tree : dead) {
      foods[tree.yIdx][tree.xIdx] += (tree.age/2);
    }
  }

  private static void authmn(ArrayList<Tree> trees) {
    ArrayList<Tree> newTrees = new ArrayList<>();
    for (Tree tree : trees) {
      if(tree.age % 5 != 0) continue;
      for (int i = 0; i < 8; i++) {
        int ny = tree.yIdx + dy[i];
        int nx = tree.xIdx + dx[i];
        if(nx<0||nx>=N||ny<0||ny>=N) continue;
        newTrees.add(new Tree(ny,nx,1));
      }
    }
    trees.addAll(newTrees);
  }

  private static void winter() {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        foods[i][j] += foodTable[i][j];
      }
    }
  }
  static class Tree implements Comparable<Tree>{
    private final int yIdx;
    private final int xIdx;
    private int age;

    public Tree(int yIdx, int xIdx, int age) {
      this.yIdx = yIdx;
      this.xIdx = xIdx;
      this.age = age;
    }

    @Override
    public int compareTo(Tree o) {
      return this.age - o.age;
    }
  }
}
