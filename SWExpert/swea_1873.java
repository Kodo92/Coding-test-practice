package SWEA;

import java.util.Scanner;

public class swea_1873 {
    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};
    private static char[] dc = {'^','v','<','>'};
    private static int H,W;

    private static void move(char[][] map, Position nowPos, final int direction) {
        int newXPos = nowPos.xPos + dx[direction];
        int newYPos = nowPos.yPos + dy[direction];

        nowPos.direction = direction;
        map[nowPos.yPos][nowPos.xPos] = dc[nowPos.direction];
        if(newYPos < 0 || newYPos >= H || newXPos < 0 || newXPos >= W)
            return;

        if(map[newYPos][newXPos] != '.')
            return;

        map[nowPos.yPos][nowPos.xPos] = '.';
        nowPos.xPos = newXPos;
        nowPos.yPos = newYPos;
        map[nowPos.yPos][nowPos.xPos] = dc[nowPos.direction];
    }

    private static int getDirection(char c) {
        if(c == 'U')
            return 0;
        else if(c == 'D')
            return 1;
        else if(c == 'L')
            return 2;
        else
            return 3;
    }

    private static void shoot(char[][] map, Position nowPos) {
        int bulletXPos = nowPos.xPos;
        int bulletYPos = nowPos.yPos;
        int dir = nowPos.direction;
        while(true) {
            bulletXPos += dx[dir];
            bulletYPos += dy[dir];

            if(bulletXPos < 0 || bulletXPos >= W || bulletYPos < 0 || bulletYPos >= H)
                break;

            if(map[bulletYPos][bulletXPos] == '#')
                return;

            if(map[bulletYPos][bulletXPos] == '*') {
                map[bulletYPos][bulletXPos] = '.';
                return;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T;
        T=sc.nextInt();

        for(int test_case = 1; test_case <= T; test_case++)
        {
            H = sc.nextInt();
            W = sc.nextInt();

            char[][] map = new char[H][W];
            Position pos = null;
            for(int i=0;i<H;i++) {
                String[] input = sc.next().split("");
                for(int j=0;j<W;j++) {
                    map[i][j] = input[j].charAt(0);
                    if(map[i][j] == '^')
                        pos = new Position(i,j,0);
                    else if(map[i][j] == 'v')
                        pos = new Position(i,j,1);
                    else if(map[i][j] == '<')
                        pos = new Position(i,j,2);
                    else if(map[i][j] == '>')
                        pos = new Position(i,j,3);

                }
            }

            int moveCount = sc.nextInt();
            String[] moving = sc.next().split("");
            for(String str : moving) {
                char c = str.charAt(0);
                if(c == 'S')
                    shoot(map,pos);
                else
                    move(map,pos,getDirection(c));
            }
            System.out.printf("#%d ",test_case);
            for(int i=0;i<H;i++) {
                for(int j=0;j<W;j++){
                    System.out.print(map[i][j]);
                }
                System.out.println();
            }
        }
    }

    static class Position {
        private int yPos;
        private int xPos;
        private int direction;

        public Position(int yPos, int xPos, int direction) {
            this.yPos = yPos;
            this.xPos = xPos;
            this.direction = direction;
        }
    }
}
