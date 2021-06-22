package boj;

import java.util.*;

public class boj_14502 {

    private static int N,M;
    private static int[][] map;
    private static int wallCount;
    private static int totalCount;
    private static int answer;

    private static List<Position> viruses;

    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};

    private static void DFS(int level, int yPos, int xPos) {
        if(level > 3) {
            int virusCount = BFS();
            int safeAreaCount = totalCount - wallCount - virusCount;
            answer = Math.max(answer, safeAreaCount);
            return;
        }

        for(int i=yPos ; i < N; i++) {
            for(int j = xPos ; j < M;j++) {
                if(map[i][j]==0) {
                    map[i][j] = 1;
                    DFS(level+1,i,j);
                    map[i][j] = 0;
                }
            }
            xPos=0;
        }
    }

    private static int BFS() {
        int count = viruses.size();

        int[][] copyMap = new int[N][];
        for(int i=0;i<N;i++)
            copyMap[i] = map[i].clone();

        Queue<Position> queue = new LinkedList<>();
        for(Position i : viruses) {
            queue.add(i);
        }

        while(!queue.isEmpty()) {
            Position now = queue.poll();

            int nowX = now.getxPos();
            int nowY = now.getyPos();

            for(int i=0;i<4;i++) {
                int newX = nowX + dx[i];
                int newY = nowY + dy[i];

                if(newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
                if(copyMap[newY][newX] != 0) continue;
                copyMap[newY][newX] = 2;
                queue.add(new Position(newY, newX));
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        N = sc.nextInt();
        M = sc.nextInt();

        viruses = new LinkedList<>();
        map = new int[N][M];

        wallCount = 3;
        totalCount = N*M;
        answer = 0;

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                map[i][j] = sc.nextInt();
                if(map[i][j] == 2)
                    viruses.add(new Position(i,j));
                 else if (map[i][j] == 1)
                    wallCount++;
            }
        }

        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                DFS(1,i,j);
            }
        }
        System.out.println(answer);
    }

    static class Position {
        private int xPos;
        private int yPos;

        public Position(int yPos, int xPos) {
            this.xPos = xPos;
            this.yPos = yPos;
        }

        public int getxPos() {
            return xPos;
        }

        public void setxPos(int xPos) {
            this.xPos = xPos;
        }

        public int getyPos() {
            return yPos;
        }

        public void setyPos(int yPos) {
            this.yPos = yPos;
        }
    }
}

