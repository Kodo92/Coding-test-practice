package SWEA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class swea_3289 {
    private static int[] parents;

    private static int findSet(int number) {
        if(parents[number] == number)
            return number;
        return parents[number] = findSet(parents[number]);
    }

    private static void union(int a, int b) {
        parents[findSet(b)]=findSet(a);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        for(int test_case=1 ; test_case <= T ; test_case++ ) {
            sb.append("#"+test_case+" ");
            StringTokenizer st = new StringTokenizer(br.readLine()," ");
            int N = Integer.parseInt(st.nextToken());
            int M = Integer.parseInt(st.nextToken());

            // makeSet
            parents = new int[N+1];
            for(int i=1;i<=N;i++)
                parents[i] = i;

            for(int i=0;i<M;i++) {
                st = new StringTokenizer(br.readLine()," ");
                int type = Integer.parseInt(st.nextToken());
                int a = Integer.parseInt(st.nextToken());
                int b = Integer.parseInt(st.nextToken());

                switch (type) {
                    case 0:
                        union(a,b);
                        break;
                    case 1:
                        if(findSet(a) != findSet(b))
                            sb.append(0);
                        else
                            sb.append(1);
                        break;
                }
            }
            sb.append('\n');
        }
        System.out.println(sb);
    }
}
