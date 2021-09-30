package boj;

import java.io.*;
import java.util.*;

public class boj_11779 {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    int N = Integer.parseInt(br.readLine());
    int M = Integer.parseInt(br.readLine());

    ArrayList<Node>[] paths = new ArrayList[N];
    for (int i = 0; i < N; i++) {
      paths[i] = new ArrayList<>();
    }

    for (int i = 0; i < M; i++) {
      StringTokenizer st = new StringTokenizer(br.readLine(), " ");
      int source = Integer.parseInt(st.nextToken()) - 1;
      int dest = Integer.parseInt(st.nextToken()) - 1;
      int cost = Integer.parseInt(st.nextToken());
      paths[source].add(new Node(cost, dest, null));
    }
    StringTokenizer st = new StringTokenizer(br.readLine(), " ");
    int source = Integer.parseInt(st.nextToken()) - 1;
    int dest = Integer.parseInt(st.nextToken()) - 1;

    Node result = dijkstra(N, source, dest, paths);
    sb.append(result.cost).append('\n');
    sb.append(result.paths.size()).append('\n');
    result.paths.forEach(i -> sb.append(i+1).append(' '));
    System.out.println(sb);
  }

  private static Node dijkstra(final int N, final int source, final int dest, final ArrayList<Node>[] paths) {
    long[] costs = new long[N];
    Arrays.fill(costs, 1_000_000_000_1L);

    costs[source] = 0;

    PriorityQueue<Node> queue = new PriorityQueue<>();
    queue.add(new Node(0, source, new LinkedList<>()).addPath(source));

    while(!queue.isEmpty()) {
      Node now = queue.poll();

      if(now.idx == dest) {
        return now;
      }

      for (Node next : paths[now.idx]) {
        long newCost = now.cost + next.cost;
        if(costs[next.idx] <= newCost) continue;
        Node newNode = new Node(newCost,next.idx,now.paths).addPath(next.idx);
        costs[next.idx] = newCost;
        queue.add(newNode);
      }
    }
    return null;
  }

  static class Node implements Comparable<Node>{
    private final long cost;
    private final int idx;
    private List<Integer> paths;

    public Node(long cost, int idx, List<Integer> paths) {
      this.cost = cost;
      this.idx = idx;
      if (paths != null) {
        this.paths = new LinkedList<>(paths);
      } else {
        this.paths = paths;
      }
    }

    public Node addPath(final int idx) {
      if(paths == null)
        paths = new LinkedList<>();
      paths.add(idx);
      return this;
    }

    @Override
    public int compareTo(Node o) {
      return (this.cost > o.cost) ? 1 : (this.cost == o.cost) ? 0 : -1;
    }
  }
}