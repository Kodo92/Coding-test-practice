package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class boj_1197 {
    private static int V,E;


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());

        UnionFind.init(V);
        Node[] paths = new Node[E];
        for(int i=0;i<E;i++) {
            st = new StringTokenizer(br.readLine()," ");
            paths[i] = new Node(Integer.parseInt(st.nextToken())-1,
                    Integer.parseInt(st.nextToken())-1,
                    Integer.parseInt(st.nextToken()));
        }
        Arrays.sort(paths);

        int edgeCount = 0;
        int sum = 0;
        for (Node path : paths) {
            if(edgeCount == V-1)
                break;
            if(UnionFind.unionSet(path.sIdx,path.dInx)) {
                edgeCount++;
                sum += path.cost;
            }
        }
        System.out.println(sum);
    }

    static class Node implements Comparable<Node>{
        private final int sIdx;
        private final int dInx;
        private final int cost;

        public Node(int sIdx, int dInx, int cost) {
            this.sIdx = sIdx;
            this.dInx = dInx;
            this.cost = cost;
        }

        @Override
        public int compareTo(Node o) {
            return this.cost-o.cost;
        }
    }

    static class UnionFind {
        private static int[] parents;
        public static void init(int size) {
            parents = new int[V];
            for(int i=1;i<V;i++)
                parents[i] = i;
        }

        public static int findSet(final int idx) {
            if(parents[idx] == idx)
                return idx;
            return parents[idx] = findSet(parents[idx]);
        }

        public static boolean unionSet(final int aIdx, final int bIdx) {
            int aParent = findSet(aIdx);
            int bParent = findSet(bIdx);

            if(aParent == bParent)
                return false;

            parents[bParent] = aParent;
            return true;
        }
    }
}
