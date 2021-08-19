package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_3109 {
    private static int R, C;
    private static int[] dy = {-1, 0, 1};
    private static char[][] map;
    private static boolean[][] isImpossible;

    private static boolean DFS(final int yPos, final int xPos) {
        if (xPos - 1 < 0)
            return true;

        for (int i = 0; i < 3; i++) {
            int newYPos = yPos + dy[i];
            int newXPos = xPos - 1;
            if (newYPos < 0 || newYPos >= R || newXPos < 0) continue;
            if (isImpossible[newYPos][newXPos]) continue;

            isImpossible[newYPos][newXPos] = true;
            if (DFS(newYPos, newXPos))
                return true;
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        map = new char[R][];
        isImpossible = new boolean[R][C];

        for (int i = 0; i < R; i++) {
            map[i] = br.readLine().toCharArray();
            for(int j=0;j<C;j++) {
                if(map[i][j] != '.')
                    isImpossible[i][j] = true;
            }
        }


        int answer = 0;
        for (int i = 0; i < R; i++) {
            if (DFS(i, C-1)) {
                answer++;
            }
        }
        System.out.println(answer);
    }
}

