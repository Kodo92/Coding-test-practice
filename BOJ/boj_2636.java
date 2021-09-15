package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class boj_2636 {
    private static int R,C;

    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};

    private static void BFS(int[][] map, boolean[][] isVisited, final int yIndex, final int xIndex) {

        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{yIndex,xIndex});

        while(!queue.isEmpty()) {
            int[] now = queue.poll();

            for(int i=0;i<4;i++) {
                int newY = now[0] + dy[i];
                int newX = now[1] + dx[i];

                if(newX < 0 || newX >= C || newY < 0 || newY >= R) continue;
                if(isVisited[newY][newX]) continue;
                isVisited[newY][newX]=true;
                if(map[newY][newX] != 0)
                    map[newY][newX] = -1;
                else
                    queue.add(new int[]{newY,newX});
            }
        }
    }

    private static void find(int[][] map) {
        boolean[][] isVisited = new boolean[R][C];
        BFS(map,isVisited,0,0);
    }

    private static int melt(int[][] map) {
        int count = 0;
        for(int i=0;i<R;i++) {
            for(int j=0;j<C;j++) {
                if(map[i][j] == -1)
                    map[i][j]=0;
                if(map[i][j] > 0)
                    count++;
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
        int count = melt(map);
        while(true) {
            answer++;
            find(map);
            int temp = melt(map);
            if(temp == 0)
                break;
            count = temp;
        }
        System.out.println(answer+1);
        System.out.println(count);
    }
}

