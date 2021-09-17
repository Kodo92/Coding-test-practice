package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj_17472 {
    private static int N,M;

    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};

    private static List<Node>[] cost;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int[][] map = new int[N][M];
        for(int i=0;i<N;i++) {
            st = new StringTokenizer(br.readLine()," ");
            for(int j=0;j<M;j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                if(map[i][j] != 0)
                    map[i][j] = -1;
            }
        }
        // find island
        ArrayList<int[]> islandPos = new ArrayList<>(6);
        int islandCount = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(map[i][j] == -1) {
                    islandCount++;
                    searchIsland(map,i,j,islandCount);
                    islandPos.add(new int[] {i,j});
                }
            }
        }

        // find cost
        cost = new List[islandCount];
        for(int i=0;i<islandCount;i++)
            cost[i] = new LinkedList<>();

        for (int i = 0; i < islandPos.size(); i++) {
            searchPath(map,islandPos,i);
        }

        // Prim
        System.out.println(prim(islandCount));
    }

    private static void searchIsland(int[][] map, final int yPos, final int xPos, final int marker) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{yPos,xPos});
        map[yPos][xPos] = marker;

        while(!queue.isEmpty()) {
            int[] now = queue.poll();

            for(int i=0;i<4;i++) {
                int newY = now[0] + dy[i];
                int newX = now[1] + dx[i];
                if(newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
                if(map[newY][newX] != -1) continue;
                map[newY][newX] = marker;
                queue.add(new int[]{newY,newX});
            }
        }
    }

    private static void searchPath(final int[][] map, final ArrayList<int[]> islandPos, final int islandIdx) {
        boolean[][] isVisited = new boolean[N][M];
        Queue<int[]> queue = new LinkedList<>();
        int[] startNode = islandPos.get(islandIdx);
        queue.add(new int[] {startNode[0],startNode[1]});
        isVisited[startNode[0]][startNode[1]] = true;
        while(!queue.isEmpty()) {
            int[] now = queue.poll();

            for(int i=0;i<4;i++) {
                int newY = now[0]+dy[i];
                int newX = now[1]+dx[i];
                if(newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
                if(isVisited[newY][newX]) continue;;
                if(map[newY][newX] == islandIdx+1) {
                    isVisited[newY][newX] = true;
                   queue.add(new int[]{newY,newX});
                } else {
                    // [0] : dest / [1] : cost
                    int[] result = goSearch(map,now[0],now[1],i);
                    if(result[0] != -1) {
                        cost[islandIdx].add(new Node(result[0],result[1]));
                        cost[result[0]].add(new Node(islandIdx,result[1]));
                    }
                }

            }
        }

    }

    private static int[] goSearch(final int[][] map, final int yPos, final int xPos, final int dir) {
        int newY = yPos;
        int newX = xPos;
        int cost = -1;
        while(true) {
            cost++;
            newY += dy[dir];
            newX += dx[dir];
            if(newX < 0 || newX >= M || newY < 0 || newY >= N) break;
            if(map[newY][newX] != 0) {
                if(cost < 2) break;
                return new int[] {map[newY][newX]-1, cost};
            }
        }
        return new int[] {-1,0};
    }

    private static int prim(final int islandCount){
        int answer = 0;
        boolean[] isSelected = new boolean[islandCount];

        PriorityQueue<Node> queue = new PriorityQueue<>();
        for (Node node : cost[0]) {
            queue.add(node);
        }
        isSelected[0] = true;

        int findCount = islandCount-1;
        while(!queue.isEmpty()) {
            Node now = queue.poll();
            if(isSelected[now.idx]) continue;
            isSelected[now.idx] = true;
            answer += now.cost;
            findCount--;

            if(findCount == 0)
                break;

            for (Node node : cost[now.idx]) {
                if(isSelected[node.idx]) continue;
                queue.add(node);
            }
        }
        if(findCount == 0)
            return answer;
        else
            return -1;
    }

    static class Node implements Comparable<Node>{
        private final int idx;
        private final int cost;

        public Node(int idx, int cost) {
            this.idx = idx;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost - o.cost;
        }
    }
}
