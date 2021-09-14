package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.OptionalInt;

public class boj_1149 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[][] cost = new int[N][];
        for(int i=0;i<N;i++)
            cost[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int[][] dp = new int[N][3];
        dp[0][0] = cost[0][0];
        dp[0][1] = cost[0][1];
        dp[0][2] = cost[0][2];

        for(int i=1;i<N;i++) {
            for(int j=0;j<3;j++) {
                dp[i][j] = Integer.MAX_VALUE;
                for(int k=0;k<3;k++) {
                    if(j==k) continue;
                    dp[i][j] = Math.min(dp[i][j],dp[i-1][k]+cost[i][j]);
                }
            }
        }

        OptionalInt min = Arrays.stream(dp[N-1]).min();
        System.out.println(min.getAsInt());
    }
}
