package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_1520 {
    private static int M,N;
    private static int[][] map;
    private static long[][] dp;

    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};

    private static void init() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        map = new int[M][N];
        dp = new long[M][N];
        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine()," ");
            for(int j=0;j<N;j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }
    }

    private static long dfs(final int yIndex, final int xIndex) {
        if(yIndex == M-1 && xIndex == N-1) {
            return 1;
        }

        if(dp[yIndex][xIndex] == -1) {
            dp[yIndex][xIndex] = 0;
            for(int i=0;i<4;i++) {
                int newX = xIndex + dx[i];
                int newY = yIndex + dy[i];
                if(newX < 0 || newX >= N || newY < 0 || newY >= M) continue;
                if(map[yIndex][xIndex] <= map[newY][newX]) continue;

                dp[yIndex][xIndex] += dfs(newY,newX);
            }
        }
        return dp[yIndex][xIndex];
    }

    public static void main(String[] args) throws IOException {

        init();
        dfs(0,0);
        System.out.println(dp[0][0]);
    }
}
