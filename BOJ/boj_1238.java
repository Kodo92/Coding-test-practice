package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj_1238 {
    private static int N,M,X;

    private static void BFS(int[] costs, ArrayList<ArrayList<Node>> paths) {
        Queue<Node> queue = new PriorityQueue<>();
        for(Node n : paths.get(X)) {
            queue.add(n);
        }

        int count = N-1;
        costs[X] = 0;
        while(!queue.isEmpty()) {
            if(count < 0)
                break;
            Node now = queue.poll();
            if(costs[now.index] == -1) {
                costs[now.index] = now.cost;
                count--;
            }

            for(Node n : paths.get(now.index)) {
                int newCost = now.cost + n.cost;
                if(costs[n.index] != -1 && costs[n.index] < newCost) continue;
                queue.add(new Node(n.index,newCost));
            }


        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        X = Integer.parseInt(st.nextToken())-1;

        ArrayList<ArrayList<Node>> paths = new ArrayList<>();
        ArrayList<ArrayList<Node>> reversePaths = new ArrayList<>();
        for(int i=0;i<N;i++) {
            paths.add(new ArrayList<>());
            reversePaths.add(new ArrayList<>());
        }

        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine()," ");
            int source = Integer.parseInt(st.nextToken())-1;
            int dest = Integer.parseInt(st.nextToken())-1;
            int cost = Integer.parseInt(st.nextToken());
            paths.get(source).add(new Node(dest,cost));
            reversePaths.get(dest).add(new Node(source,cost));
        }
        int[] reverseCosts = new int[N];
        Arrays.fill(reverseCosts,-1);
        BFS(reverseCosts,reversePaths);
        int[] costs = new int[N];
        Arrays.fill(costs,-1);
        BFS(costs,paths);

        int maxValue = 0;
        for(int i=0;i<N;i++) {
            int sum = costs[i]+reverseCosts[i];
            if(maxValue < sum) {
                maxValue = sum;
            }
        }
        System.out.println(maxValue);
    }

    static class Node implements Comparable<Node>{
        private int index;
        private int cost;

        public Node(int index, int cost) {
            this.index = index;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return cost - o.cost;
        }
    }
}
