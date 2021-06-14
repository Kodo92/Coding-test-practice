package boj;

import java.lang.reflect.Array;
import java.util.*;

public class boj_1260 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N,M,V;
        N = sc.nextInt();
        M = sc.nextInt();
        V = sc.nextInt()-1;

        ArrayList<ArrayList<Integer>> paths = new ArrayList<>();
        for(int i=0;i<N;i++)
            paths.add(new ArrayList<>());

        for(int i=0;i<M;i++) {
            int first, second;
            first = sc.nextInt() - 1;
            second = sc.nextInt() - 1;

            paths.get(first).add(second);
            paths.get(second).add(first);
        }

        for(int i=0;i<N;i++) {
            Collections.sort(paths.get(i));
        }

        DFS dfs = new DFS(paths);
        dfs.solution(V);
        System.out.println();
        BFS bfs = new BFS(paths);
        bfs.solution(V);

    }
}

class DFS {
    private ArrayList<ArrayList<Integer>> paths;

    private boolean[] isVisited;
    private ArrayList<Integer> answers;

    public DFS(ArrayList<ArrayList<Integer>> paths) {
        this.paths = paths;
        isVisited = new boolean[paths.size()];
        answers = new ArrayList<>();
    }

    private void setStartIndex(int startIndex) {
        isVisited[startIndex] = true;
    }

    private void recursion(int nowIndex) {
        answers.add(nowIndex+1);

        for(int i : paths.get(nowIndex)) {
            if(!isVisited[i]) {
                isVisited[i] = true;
                recursion(i);
            }
        }
    }

    public void solution(int startIndex){
        setStartIndex(startIndex);
        recursion(startIndex);
        for(int i : answers) {
            System.out.print(i + " ");
        }
    }
}

class BFS {
    private ArrayList<ArrayList<Integer>> paths;

    private boolean[] isVisited;
    private ArrayList<Integer> answers;

    public BFS(ArrayList<ArrayList<Integer>> paths) {
        this.paths = paths;
        isVisited = new boolean[paths.size()];
        answers = new ArrayList<>();
    }

    private void setStartIndex(int startIndex) {
        isVisited[startIndex] = true;
    }

    private void loop(int startIndex) {
        Queue<Integer> queue = new LinkedList<>();

        queue.add(startIndex);

        while(!queue.isEmpty()) {
            int nowIndex = queue.peek();
            answers.add(nowIndex+1);
            queue.poll();

            for(int i : paths.get(nowIndex)) {
                if(!isVisited[i]) {
                    isVisited[i] = true;
                    queue.add(i);
                }
            }
        }
    }

    public void solution(int startIndex) {
        setStartIndex(startIndex);
        loop(startIndex);
        for(int i : answers) {
            System.out.print(i + " ");
        }
    }
}