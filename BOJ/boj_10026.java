package boj;

import java.util.*;

public class boj_10026 {
    private static int N;
    private static char[][] map;

    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};

    private static void BFS(boolean[][] visited, final int yPos, final int xPos, final char c) {
        visited[yPos][xPos] = true;

        Queue<Node> queue = new LinkedList<>();
        queue.add(new Node(yPos, xPos));

        while(!queue.isEmpty()) {
            Node now = queue.poll();

            int nowX = now.getxPos();
            int nowY = now.getyPos();

            for(int i=0;i<4;i++) {
                int newX = nowX + dx[i];
                int newY = nowY + dy[i];

                if(newX < 0 || newX >= N || newY < 0 || newY >= N) continue;
                if(visited[newY][newX]) continue;
                if(map[newY][newX] != c) continue;

                visited[newY][newX] = true;
                queue.add(new Node(newY,newX));
            }
        }
    }

    private static int Calculate() {
        int count = 0;

        boolean[][] visited = new boolean[N][N];

        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(visited[i][j]) continue;
                BFS(visited,i,j,map[i][j]);
                count++;
            }
        }

        return count;
    }

    private static void colorRtoG() {
        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(map[i][j] == 'R')
                    map[i][j] = 'G';
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();

        map = new char[N][N];
        for(int i=0;i<N;i++) {
            String str = sc.next();
            for(int j=0;j<N;j++) {
                map[i][j] = str.charAt(j);
            }
        }

        int nonWeakCount = Calculate();
        colorRtoG();
        int weakCount = Calculate();

        System.out.println(nonWeakCount + " " + weakCount);

    }

    private static class Node {
        private int yPos;
        private int xPos;

        public Node(int yPos, int xPos) {
            this.yPos = yPos;
            this.xPos = xPos;
        }

        public int getyPos() {
            return yPos;
        }

        public void setyPos(int yPos) {
            this.yPos = yPos;
        }

        public int getxPos() {
            return xPos;
        }

        public void setxPos(int xPos) {
            this.xPos = xPos;
        }
    }
}
