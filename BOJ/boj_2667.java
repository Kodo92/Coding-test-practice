package boj;

import java.util.*;

public class boj_2667 {
    private static int dx[] = {0,0,-1,1};
    private static int dy[] = {-1,1,0,0};

    private static int BFS(char[][] map, int yPos, int xPos) {
        Queue<Pos> queue = new LinkedList<>();
        queue.add(new Pos(xPos,yPos));
        map[yPos][xPos] = '0';
        int count = 0;
        while(!queue.isEmpty()) {
            Pos now = queue.peek();
            queue.poll();
            count++;

            for(int i=0;i<4;i++) {
                int newX = now.getX() + dx[i];
                int newY = now.getY() + dy[i];
                if(newX < 0 || newX >= map.length || newY < 0 || newY >= map.length)
                    continue;
                if(map[newY][newX] == '0') continue;
                map[newY][newX] = '0';
                queue.add(new Pos(newX,newY));
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();

        char[][] map = new char[N][N];
        for(int i=0;i<N;i++) {
            String str = sc.next();
            for(int j=0;j<N;j++)
                map[i][j] = str.charAt(j);
        }

        ArrayList<Integer> answer = new ArrayList<>();


        for(int i=0;i<N;i++) {
            for(int j=0;j<N;j++) {
                if(map[i][j] == '1') {
                    answer.add(BFS(map,i,j));
                }
            }
        }
        Collections.sort(answer);
        System.out.println(answer.size());
        answer.forEach(System.out::println);
    }

}

class Pos {
    private int x;
    private int y;

    public int getX() {
        return x;
    }

    public Pos(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
}