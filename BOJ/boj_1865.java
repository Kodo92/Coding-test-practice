package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_1865 {
    private static int N,M,W;
    private static BufferedReader br;
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int TC = Integer.parseInt(br.readLine());
        for(int test_case = 0 ; test_case < TC ; test_case++){
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            N = Integer.parseInt(st.nextToken());
            M = Integer.parseInt(st.nextToken());
            W = Integer.parseInt(st.nextToken());

            ArrayList<ArrayList<Node>> paths = new ArrayList<>();
            for(int i=0;i<N;i++)
                paths.add(new ArrayList<>());

            input(paths,M,1);
            input(paths,W,-1);
            if(bellmanFord(paths))
                sb.append("YES");
            else
                sb.append("NO");
            sb.append('\n');
        }
        System.out.println(sb);
    }

    private static boolean bellmanFord(ArrayList<ArrayList<Node>> paths) {
        int[] upper = new int[N];
        Arrays.fill(upper,10001);
        upper[0] = 0;
        boolean updated = false;
        for(int iter=0;iter<N;iter++) {
            updated = false;
            for(int here = 0; here < N ; here++) {
                for(Node n :paths.get(here)) {
                    if(upper[n.index] > upper[here]+n.cost) {
                        upper[n.index] = upper[here] + n.cost;
                        updated = true;
                    }
                }
            }
            if(!updated)
                return false;
        }
        if(updated) {
            return true;
        }
        return false;
    }

    private static void input(ArrayList<ArrayList<Node>> paths, int count, int type) throws IOException {
        for(int i=0;i<count;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            int S = Integer.parseInt(st.nextToken())-1;
            int E = Integer.parseInt(st.nextToken())-1;
            int T = Integer.parseInt(st.nextToken())*type;

            put(paths, S, E, T);
            if(type==1)
                put(paths, E, S, T);
        }
    }

    private static void put(ArrayList<ArrayList<Node>> paths, int s, int e, int t) {
        paths.get(s).add(new Node(e, t));
    }


    static class Node{
        private int index;
        private int cost;

        public Node(int index, int cost) {
            this.index = index;
            this.cost = cost;
        }
    }
}

/*
    1. paths null exception
    2. upper array init value INT.MAX_VALUE -> 10001 : overflow
    3. paths HashMap -> ArrayList
 */

