package boj;

import java.util.*;

public class boj_11724 {
    private static ArrayList<ArrayList<Integer>> paths;
    private static ArrayList<Boolean> isUsed;
    private static int answer;
    private static void BFS(int startIndex) {
        answer++;
        isUsed.set(startIndex,true);

        Queue<Integer> queue = new LinkedList<>();
        queue.add(startIndex);

        while(!queue.isEmpty()) {
            int now = queue.poll();

            for(int i : paths.get(now)) {
                if(isUsed.get(i).equals(true))
                    continue;
                isUsed.set(i,true);
                queue.add(i);
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N,M;
        N = sc.nextInt();
        M = sc.nextInt();

        paths = new ArrayList<>();
        isUsed = new ArrayList<>();
        for(int i=0;i<N;i++) {
            paths.add(new ArrayList<>());
            isUsed.add(false);
        }

        for(int i=0;i<M;i++) {
            int u,v;
            u = sc.nextInt() -1;
            v = sc.nextInt() -1;

            paths.get(u).add(v);
            paths.get(v).add(u);
        }

        for(int i=0;i<N;i++) {
            if(isUsed.get(i).equals(false))
                BFS(i);
        }

        System.out.println(answer);
    }
}
