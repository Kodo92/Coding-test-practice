package SWEA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class swea_1263 {

    private static int getMin(final int N, final int[][] map){
        int min = Integer.MAX_VALUE;
        for(int i=0;i<N;i++) {
            int sum = 0;
            for(int j=0;j<N;j++) {
                if(i==j || map[i][j] == Integer.MAX_VALUE) continue;
                sum += map[i][j];
            }
            min = Math.min(min,sum);
        }
        return min;
    }

    private static int floyd(final int N, final int[][] map) {
        // 이 문제에선 최대 비용을 요구
        // 경유 노드
        int[][] cost = new int[N][];
        for(int i=0;i<N;i++)
            cost[i] = Arrays.copyOf(map[i],N);

        for(int k=0;k<N;k++) {
            for(int i=0;i<N;i++) {
                for(int j=0;j<N;j++) {
                    if(cost[i][k]+cost[k][j] < cost[i][j])
                        cost[i][j] = cost[i][k]+cost[k][j];
                }
            }
        }
        return getMin(N,cost);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case<=T;test_case++) {
            StringTokenizer st = new StringTokenizer(br.readLine()," ");
            int N = Integer.parseInt(st.nextToken());
            int[][] map = new int[N][N];
            for(int i=0;i<N;i++) {
                for(int j=0;j<N;j++) {
                    map[i][j] = Integer.parseInt(st.nextToken());
                    if(map[i][j] == 0 && i != j)
                        map[i][j] = 1001;
                }
            }

            //floyd(N,map);
            sb.append("#"+test_case+" ").append(floyd(N,map)).append('\n');
        }
        System.out.println(sb);
    }
}
