package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

// TODO 못풀엇음
public class boj_18442 {

  private static int P,V;
  private static long L;

  private static long minDistance;
  private static LinkedList<Integer> answerPaths;	// 경찰서 지을 마을들의 좌표

  private static long[] positions;					// 마을 좌표
  private static long[][] costs;			// 마을별로 다른 마을까지 거리 관리


  public static void main(String[] args) throws NumberFormatException, IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringBuilder sb = new StringBuilder();

    init(br);

    // DFS로 탐색한 마을의 경로
    LinkedList<Integer> path = new LinkedList<>();
    for(int i=0;i<=V-P;i++) {
      DFS(i,0,path);
    }

    sb.append(minDistance+"\n");
    for(int i : answerPaths) {
      sb.append(positions[i] +" ");
    }
    System.out.println(sb);
  }

  /**
   * 입력값들을 받아 static 변수들을 초기화하는 역할을 한다.
   * @throws IOException
   */
  private static void init(BufferedReader br) throws IOException {
    StringTokenizer st = new StringTokenizer(br.readLine()," ");
    V = Integer.parseInt(st.nextToken());
    P = Integer.parseInt(st.nextToken());
    L = Long.parseLong(st.nextToken());
    minDistance = Long.MAX_VALUE;

    positions = Arrays.stream(br.readLine().split(" ")).mapToLong(Long::parseLong).toArray();
    answerPaths = new LinkedList<>();
    costs = new long[V][];
  }

  /**
   * 재귀적으로 경찰서를 세울 마을을 완전탐색으로 탐색한다.
   * @param source	시작점
   * @param level		경찰서 개수
   * @param path		경로
   */
  private static void DFS(final int source, final int level, LinkedList<Integer> path) {
    if(level >= P) {
      long sum = getSum(path);
      if(minDistance > sum) {
        minDistance = sum;
        answerPaths = new LinkedList<>(path);
      }
      return;
    }
    for(int i=source; i<V;i++) {
      path.add(i);
      DFS(i+1,level+1,path);
      path.removeLast();
    }
  }

  private static long getSum(LinkedList<Integer> path) {
    // 경찰서가 있는 마을에서 각 마을의 거리를 저장할 지역 변수
    long[] distinces = new long[V];
    // 최소값 갱신을 위해 초기화 작업
    Arrays.fill(distinces, Long.MAX_VALUE);
    // 거리 갱신
    for(Integer pos : path) {
      // pos 마을에서 각 마을별 최단 거리를 구하지 않은 경우 pos 기준 각 마을간 거리 구한다.
      if(costs[pos] == null) {
        getDistance(pos);
      }
      // pos에서 각 마을의 거리가 존재한다면, path의 마을들 간 최소 경로를 구한다.
      setDistinceByPath(pos, distinces);
    }

    long sum = 0;
    for(long i : distinces)
      sum += i;
    return sum;
  }

  /**
   * idx 마을에서 각 마을간의 거리 구하기
   * @param idx
   */
  private static void getDistance(final int idx) {
    costs[idx] = new long[V];
    for(int i=0;i<V;i++) {
      costs[idx][i] = Math.min(Math.abs(positions[idx] - positions[i]), L- Math.abs(positions[idx] - positions[i]));
    }
  }

  private static void setDistinceByPath(final int idx, long[] distinces) {
    for(int i=0;i<V;i++) {
      distinces[i] = Math.min(distinces[i], costs[idx][i]);
    }
  }

}
