package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class boj_9205 {
    private static int getDistance(final int sX, final int sY, final int dX, final int dY) {
        return Math.abs(sX-dX) + Math.abs(sY-dY);
    }

    private static int getConsumption(final int distance) {
            return (int)Math.ceil((double)distance / 50.0);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        loop:
        for(int test_case = 1 ; test_case <= T; test_case++) {
            int N = Integer.parseInt(br.readLine());
            int[][] paths = new int[N + 2][2];

            for(int i=0;i<N+2;i++) {
                StringTokenizer st = new StringTokenizer(br.readLine()," ");
                paths[i][0] = Integer.parseInt(st.nextToken());
                paths[i][1] = Integer.parseInt(st.nextToken());
            }

            boolean[][] isPossible = new boolean[N+2][N+2];
            for(int i=0;i<N+2;i++) {
                for (int j=0;j<N+2;j++) {
                    if(getConsumption(getDistance(paths[i][0],paths[i][1],paths[j][0],paths[j][1]))<=20)
                        isPossible[i][j] = isPossible[j][i] = true;
                }
            }

            // floyd
            for(int k=0;k<N+2;k++) {
                for (int i = 0; i < N + 2; i++) {
                    for (int j = 0; j < N + 2; j++) {
                        if (isPossible[i][k] && isPossible[k][j])
                            isPossible[i][j] = true;
                    }
                }
            }
            if(isPossible[0][N+1])
                sb.append("happy\n");
            else
                sb.append("sad\n");
        }
        System.out.println(sb);
    }
}
