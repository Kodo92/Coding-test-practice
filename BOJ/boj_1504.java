package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj_1504 {
    private static int N,E;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");

        N = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        HashMap<Integer, ArrayList<Node>> map = new HashMap<>();

        for(int i=0;i<E;i++) {
            st = new StringTokenizer(br.readLine()," ");
            int source = Integer.parseInt(st.nextToken())-1;
            int dest = Integer.parseInt(st.nextToken())-1;
            int cost = Integer.parseInt(st.nextToken());

            put(map, dest, source, cost);
            put(map, source, dest, cost);
        }
        st = new StringTokenizer(br.readLine()," ");
        int v1,v2;
        v1 = Integer.parseInt(st.nextToken())-1;
        v2 = Integer.parseInt(st.nextToken())-1;

        int source[] = {BFS(map,0,v1),BFS(map,0,v2)};
        int middle = BFS(map,v1,v2);
        int dest[] = {BFS(map,N-1,v1),BFS(map,N-1,v2)};

        long answer = Long.MAX_VALUE;
        for(int i=0;i<2;i++) {
            if(source[i]== -1) {
                answer  = -1;
                break;
            }
            for(int j=0;j<2;j++) {
                if(i==j)continue;
                if(dest[j] == -1) {
                    answer = -1;
                    break;
                }
                answer = Math.min(answer,source[i]+dest[j]);
            }
        }
        if(middle == -1)
            middle = 0;
        System.out.println(answer+middle);
    }

    private static int BFS(HashMap<Integer, ArrayList<Node>> map, int source, int dest) {
        PriorityQueue<Node> queue = new PriorityQueue<>();
        queue.add(new Node(source,0));

        int[] isVisited = new int[N];
        while(!queue.isEmpty()) {
            Node now = queue.poll();
            if(now.index == dest)
                return now.cost;

            if(!map.containsKey(now.index))continue;
            for(Node n : map.get(now.index)) {
                int newCost = now.cost + n.cost;
                if(isVisited[n.index] != 0 && isVisited[n.index] < newCost) continue;;
                isVisited[n.index] = newCost;
                queue.add(new Node(n.index,newCost));
            }
        }
        return -1;
    }

    private static void put(HashMap<Integer, ArrayList<Node>> map, int source, int dest, int cost) {
        if(!map.containsKey(dest)) {
            ArrayList<Node> node = new ArrayList<>();
            node.add(new Node(source,cost));
            map.put(dest,node);
        } else {
            map.get(dest).add(new Node(source,cost));
        }
    }

    static class Node implements Comparable<Node> {
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

/*
    [수정 기록]
        1. 1 -> v1, v2 / v1,v2 -> N 합의 최솟값을 구할때 1 -> v1 -> v1 -> N 경로 포함 : 예외처리 추가
        2. middle (v1 -> v2) 경로 없는 경우 추가
        3. index의 경로가 없는 경우 추가 : Null exception
*/