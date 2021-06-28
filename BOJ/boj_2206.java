package boj;

import java.util.PriorityQueue;
import java.util.Scanner;

public class boj_2206 {

    private static int N,M;
    private static int[][] map;
    private static int answer = -1;

    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};

    private static int BFS() {
        int[][][] visited = new int[N][M][2];

        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(1,0,0,0));
        visited[0][0][0] = 1;

        while(!queue.isEmpty()) {
            Node now = queue.poll();

            int nowCost = now.cost;
            int nowXPos = now.xPos;
            int nowYPos = now.yPos;
            int nowDestory = now.destoryed;

            if(nowXPos + 1 == M && nowYPos + 1 == N) {
                return visited[nowYPos][nowXPos][nowDestory];
            }

            for(int i=0;i<4;i++) {
                int newYPos = nowYPos + dy[i];
                int newXPos = nowXPos + dx[i];
                int newCost = nowCost + 1;
                int newDestory = nowDestory;

                if(newXPos < 0 || newXPos >= M || newYPos < 0 || newYPos >= N) continue;
                if(map[newYPos][newXPos] == 1 && nowDestory == 0) {
                    if(visited[newYPos][newXPos][nowDestory] == 0) {
                        newDestory = 1;
                        visited[newYPos][newXPos][newDestory] = newCost;
                        queue.add(new Node(newCost,newYPos,newXPos,newDestory));
                    }
                } else if (map[newYPos][newXPos] == 0) {
                    if(visited[newYPos][newXPos][nowDestory] == 0) {
                        visited[newYPos][newXPos][newDestory] = newCost;
                        queue.add(new Node(newCost,newYPos,newXPos,newDestory));
                    }
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();
        map = new int[N][M];
        for(int i=0;i<N;i++) {
            String str = sc.next();
            for(int j=0;j<M;j++) {
                map[i][j] = Character.getNumericValue(str.charAt(j));
            }
        }

        answer = BFS();
        System.out.println(answer);

    }

    private static class Node implements Comparable<Node>{
        int cost;
        int xPos;
        int yPos;
        int destoryed;

        public Node(int cost, int yPos, int xPos, int destroyed) {
            this.cost = cost;
            this.xPos = xPos;
            this.yPos = yPos;
            this.destoryed = destroyed;
        }

        @Override
        public int compareTo(Node o) {
            if(this.cost == o.cost)
                return (this.destoryed == 0) ? -1 : 1;
            return this.cost > o.cost ? 1 : -1;
        }
    }
}
