package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_2638 {
    private static int R,C;

    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};

    private static void BFS(int[][] map, final int yIndex, final int xIndex) {
        boolean[][] isVisited = new boolean[R][C];

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{yIndex,xIndex});

        while(!queue.isEmpty()) {
            int[] now = queue.poll();

            for(int i=0;i<4;i++) {
                int newY = now[0] + dy[i];
                int newX = now[1] + dx[i];

                if(newX < 0 || newX >= C || newY < 0 || newY >= R) continue;
                if(map[newY][newX] != 0)
                    map[newY][newX]++;
                if(isVisited[newY][newX]) continue;
                isVisited[newY][newX]=true;
                if(map[newY][newX]==0)
                    queue.add(new int[]{newY,newX});

            }
        }
    }

    private static int melt(int[][] map) {
        int count = 0;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                if(map[i][j] > 0) {
                    if(map[i][j] > 2)
                        map[i][j] = 0;
                    else {
                        map[i][j] = 1;
                        count++;
                    }
                }
            }
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine()," ");
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());

        int[][] map = new int[R][];
        for(int i=0;i<R;i++)
            map[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        int answer = 0;
        while(true) {
            answer++;
            BFS(map,0,0);
            if(melt(map)==0)
                break;
        }
        System.out.println(answer);
    }
}
