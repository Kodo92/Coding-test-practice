package boj;

import java.util.*;

public class boj_7576 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int M, N;
        M = sc.nextInt();
        N = sc.nextInt();

        Queue<Pos> queue = new LinkedList<>();
        int[][] map = new int[N][M];
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                map[i][j] = sc.nextInt();
                if (map[i][j] == 1) {
                    queue.add(new Pos(i, j));
                } else if (map[i][j] == 0) {
                    count++;
                }
            }
        }

        int[] dx = {0, 0, -1, 1};
        int[] dy = {-1, 1, 0, 0};

        int answer = 0;

        while (true) {
            Queue<Pos> subQueue = new LinkedList<>();
            while (!queue.isEmpty()) {
                Pos nowPos = queue.peek();
                queue.poll();

                for (int i = 0; i < 4; i++) {
                    int newX = nowPos.getxPos() + dx[i];
                    int newY = nowPos.getyPos() + dy[i];

                    if (newX < 0 || newX >= M || newY < 0 || newY >= N) continue;
                    if (map[newY][newX] != 0) continue;
                    map[newY][newX] = 1;
                    count--;
                    subQueue.add(new Pos(newY, newX));
                }

            }
            queue = subQueue;
            if(queue.isEmpty())
                break;
            answer++;
        }

        if(count != 0) {
            System.out.println(-1);
        } else {
            System.out.println(answer);
        }

    }


    static class Pos {
        private int xPos;
        private int yPos;

        public Pos(int yPos, int xPos) {
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
