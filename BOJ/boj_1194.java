package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj_1194 {
  private static int N,M;
  private static char[][] map;
  private static Node start;
  private static HashSet<Node> end;

  private static void init(BufferedReader br) throws IOException {
    map = new char[N][];
    end = new HashSet<>();
    for (int i = 0; i < N; i++) {
      map[i] = br.readLine().toCharArray();
      for (int j = 0; j < M; j++) {
        if(map[i][j] == '0') {
          start = new Node(0,i,j, 0);
          map[i][j]='.';
        } else if (map[i][j] == '1') {
          end.add(new Node(0,i,j,0));
          map[i][j]='.';
        }
      }
    }
  }



  private static int BFS() {
    int[] dx = {0,0,-1,1};
    int[] dy = {-1,1,0,0};

    HashSet<Integer>[][] isVisited = new HashSet[N][M];

    Queue<Node> queue = new LinkedList<>();
    queue.add(start);

    while(!queue.isEmpty()) {
      Node now = queue.poll();

      if(end.contains(now)) {
        return now.cost;
      }

      for (int i = 0; i < 4; i++) {
        int newX = now.xIdx + dx[i];
        int newY = now.yIdx + dy[i];
        int newKey = now.key;
        if(newY<0||newY>=N||newX<0||newX>=M) continue;
        if(isVisited[newY][newX] == null) {
          isVisited[newY][newX] = new HashSet<>();
        }
        if(map[newY][newX] == '#') continue;
        if(isVisited[newY][newX].contains(now.key)) continue;
        if(map[newY][newX] != '.') {
          // Key or Door
          if(Character.isUpperCase(map[newY][newX]) && !now.hasKey(map[newY][newX])) continue;
          else if(Character.isLowerCase(map[newY][newX])) {
            if(isVisited[newY][newX].contains(now.key | (1 << (map[newY][newX] - 'a'))))
              continue;
            newKey |= (1 << (map[newY][newX] - 'a'));
          }
        }
        isVisited[newY][newX].add(newKey);
        queue.add(new Node(now.cost+1, newY,newX, newKey));
      }

    }
    return -1;
  }

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine()," ");
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    init(br);
    System.out.println(BFS());

  }

  static class Node {
    private final int cost;
    private final int yIdx;
    private final int xIdx;
    private int key;

    public Node(int cost, int yIdx, int xIdx, int key) {
      this.cost = cost;
      this.yIdx = yIdx;
      this.xIdx = xIdx;
      this.key = key;
    }

    private boolean hasKey(char doorType) {
      if((key & (1 << (doorType-'A'))) != 0)
        return true;
      return false;
    }

    @Override
    public int hashCode() {
      return Objects.hash(yIdx,xIdx);
    }

    @Override
    public boolean equals(Object obj) {
      if(this == obj)
        return true;
      if(obj == null || getClass() != obj.getClass())
        return false;

      Node compare = (Node) obj;
      return Objects.equals(yIdx,compare.yIdx) && Objects.equals(xIdx,compare.xIdx);
    }
  }
}

/*
2 7
1F.f#.0
A...#.a
: -1

2 7
1F.f..0
A.....a
: 6

4 7
1F....f
A.....a
#....##
....0..
: 11

4 7
1F....f
A.....a
#....##
....Aa0
: 9

8 14
1FD...b#....f#
AC.....#.....#
#.....##.....#
#cd....AC....a
1BD....#.....#
AC.....AC.....
#.....#.......
.............0
: 26

8 7
1FD...b
AC....a
#.....#
#cd....
1BD....
AC.....
#.....#
......0
: 19
 */