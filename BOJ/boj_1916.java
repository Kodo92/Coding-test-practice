package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class boj_1916 {
    private static int N,M;
    private static ArrayList<LinkedList<Node>> paths;

    public static int BFS(final int source, final int dest) {
        int[] isVisited = new int[N];
        for (int i = 0; i < isVisited.length; i++) {
            isVisited[i] = Integer.MAX_VALUE;
        }
        isVisited[source] = 0;

        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(source,0));

        while(!queue.isEmpty()) {
            Node now = queue.poll();

            if(now.index == dest)
                return now.cost;

            for (Node node : paths.get(now.getIndex())) {
                int newCost = now.getCost() + node.getCost();
                if(isVisited[node.index] <= newCost) continue;
                queue.add(new Node(node.index, newCost));
                isVisited[node.index] = newCost;
            }
        }
        return -1;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());

        paths = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            paths.add(new LinkedList<>());
        }

        for(int i=0;i<M;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine()," ");
            int source = Integer.parseInt(st.nextToken())-1;
            int dest = Integer.parseInt(st.nextToken())-1;
            int cost = Integer.parseInt(st.nextToken());

            paths.get(source).add(new Node(dest,cost));
        }

        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        System.out.println(BFS(Integer.parseInt(st.nextToken())-1,Integer.parseInt(st.nextToken())-1));
    }

    static class Node implements Comparable<Node>{
        private final int index;
        private final int cost;

        public Node(int index, int cost) {
            this.index = index;
            this.cost = cost;
        }

        public int getIndex() {
            return index;
        }

        public int getCost() {
            return cost;
        }

        @Override
        public int compareTo(Node o) {
            return cost - o.cost;
        }
    }
}
