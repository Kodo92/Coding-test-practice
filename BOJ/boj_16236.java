package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;

public class boj_16236 {

    private static int N;
    private static int[][] map;
    private static Shark shark;

    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};

    private static Node getFish() {

        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(shark.yIndex,shark.xIndex,0));
        boolean[][] isVisited = new boolean[N][N];
        isVisited[shark.yIndex][shark.xIndex] = true;
        while(!queue.isEmpty()) {
            Node now = queue.poll();

            if(map[now.yIndex][now.xIndex] < shark.getSize() && map[now.yIndex][now.xIndex] != 0)
                return now;

            for(int i=0;i<4;i++) {
                int newX = now.xIndex + dx[i];
                int newY = now.yIndex + dy[i];

                if(newX < 0 || newX >= N || newY < 0 || newY >= N) continue;
                if(isVisited[newY][newX]) continue;
                if(map[newY][newX] > shark.getSize()) continue;
                isVisited[newY][newX] = true;
                queue.add(new Node(newY,newX,now.cost+1));
            }
        }

        return null;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        map = new int[N][];
        for(int i=0;i<N;i++) {
            map[i] = Arrays.stream(br.readLine().split(" "))
                    .mapToInt(Integer::parseInt)
                    .toArray();
            for(int j=0;j<N;j++) {
                if(map[i][j] == 9) {
                    shark = new Shark(i, j);
                    map[i][j] = 0;
                }
            }
        }

        int answer = 0;
        while(true) {
            Node next = getFish();
            if(next == null)
                break;
            answer += next.cost;
            map[next.yIndex][next.xIndex] = 0;
            shark.eat();
            shark.move(next.yIndex,next.xIndex);
        }
        System.out.println(answer);
    }

    static class Node implements Comparable<Node> {
        private int yIndex;
        private int xIndex;
        private int cost;

        public Node(int yIndex, int xIndex, int cost) {
            this.yIndex = yIndex;
            this.xIndex = xIndex;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            if(this.cost == o.cost) {
                if(this.yIndex == o.yIndex)
                    return this.xIndex - o.xIndex;
                return this.yIndex - o.yIndex;
            }
            return this.cost - o.cost;
        }
    }

    static class Shark {
        private int yIndex;
        private int xIndex;
        private int nowSize;
        private int eatCount;

        public Shark(int yIndex, int xIndex) {
            this.yIndex = yIndex;
            this.xIndex = xIndex;
            this.nowSize = 2;
            this.eatCount = 0;
        }

        public void eat() {
            this.eatCount++;
            if(eatCount == this.nowSize) {
                this.nowSize++;
                this.eatCount=0;
            }
        }

        public void move(int i, int j) {
            this.yIndex = i;
            this.xIndex = j;
        }

        public int getSize() {
            return this.nowSize;
        }
    }
}
