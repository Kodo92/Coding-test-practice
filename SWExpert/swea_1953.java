package SWEA;

import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class swea_1953 {

  private static int N, M, R, C, L;
  private static int[][] map;
  private static final int NULL_DIRECTION = -1;

  private static final int[] dx = {0,0,-1,1};
  private static final int[] dy = {-1,1,0,0};

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    final int T = Integer.parseInt(br.readLine());
    for (int testCase = 1; testCase <= T; testCase++) {
      init(br);
      bw.write("#"+testCase+" "+BFS()+"\n");
    }
    bw.close();
  }

  private static void init(BufferedReader br) throws IOException {
    // N : 세로, M : 가로, R : 시작Y, C : 시작X, L : 시간
    StringTokenizer st = new StringTokenizer(br.readLine()," ");
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());
    R = Integer.parseInt(st.nextToken());
    C = Integer.parseInt(st.nextToken());
    L = Integer.parseInt(st.nextToken());
    map = new int[N][];
    for (int i = 0; i < N; i++) {
      map[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    }
  }

  private static ArrayList<Integer> getNextDirection(final int nowDirection, final int pipeType) {
    ArrayList<Integer> nextDir = new ArrayList<>();
    switch (pipeType) {
      // 4방향 파이프라인
      case 1:
        for (int i = 0; i < 4; i++) {
          nextDir.add(i);
        }
        break;
      case 2:
        if(nowDirection == NULL_DIRECTION) {
          nextDir.add(0);
          nextDir.add(1);
        } else if (nowDirection == 0) {
          nextDir.add(0);
        } else if (nowDirection == 1) {
          nextDir.add(1);
        }
        break;
      case 3:
        if(nowDirection == NULL_DIRECTION) {
          nextDir.add(2);
          nextDir.add(3);
        } else if (nowDirection == 2) {
          nextDir.add(2);
        } else if (nowDirection == 3) {
          nextDir.add(3);
        }
        break;
      case 4:
        if(nowDirection == NULL_DIRECTION) {
          nextDir.add(0);
          nextDir.add(3);
        } else if (nowDirection == 1) {
          nextDir.add(3);
        } else if (nowDirection == 2) {
          nextDir.add(0);
        }
        break;
      case 5:
        if(nowDirection == NULL_DIRECTION) {
          nextDir.add(1);
          nextDir.add(3);
        } else if (nowDirection == 2) {
          nextDir.add(1);
        } else if (nowDirection == 0) {
          nextDir.add(3);
        }
        break;
      case 6:
        if(nowDirection == NULL_DIRECTION) {
          nextDir.add(1);
          nextDir.add(2);
        } else if (nowDirection == 0) {
          nextDir.add(2);
        } else if (nowDirection == 3) {
          nextDir.add(1);
        }
        break;
      case 7:
        if(nowDirection == NULL_DIRECTION) {
          nextDir.add(0);
          nextDir.add(2);
        } else if (nowDirection == 1) {
          nextDir.add(2);
        } else if (nowDirection == 3) {
          nextDir.add(0);
        }
        break;
      default:
        break;
    }
    return nextDir;
  }

  private static int BFS() {
    boolean[][] isVisited = new boolean[N][M];
    PriorityQueue<Node> queue = new PriorityQueue<>();
    isVisited[R][C] = true;
    queue.add(new Node(1,R,C,NULL_DIRECTION));

    int answer = 0;
    while(!queue.isEmpty()) {
      Node now = queue.poll();

      if(now.cost > L)
        break;

      answer++;
      ArrayList<Integer> nextDirection = getNextDirection(now.dir, map[now.yIdx][now.xIdx]);
      for (Integer i : nextDirection) {
        int newX = now.xIdx + dx[i];
        int newY = now.yIdx + dy[i];
        if(!possibleRange(newY,newX)) continue;
        if(map[newY][newX] == 0) continue;
        if(isVisited[newY][newX]) continue;
        // 이동 방향 파이프로 갈 수 있는지 판단
        if(getNextDirection(i,map[newY][newX]).isEmpty()) continue;
        isVisited[newY][newX] = true;
        queue.add(new Node(now.cost+1,newY,newX,i));
      }
    }
    return answer;
  }

  private static boolean possibleRange(final int yIdx, final int xIdx) {
    return !(yIdx<0 || yIdx>=N || xIdx<0||xIdx>=M);
  }

  static class Node implements Comparable<Node> {
    private final int cost;
    private final int yIdx;
    private final int xIdx;
    private final int dir;

    public Node(int cost, int yIdx, int xIdx, int dir) {
      this.cost = cost;
      this.yIdx = yIdx;
      this.xIdx = xIdx;
      this.dir = dir;
    }

    @Override
    public int compareTo(Node o) {
      return this.cost - o.cost;
    }
  }
}
