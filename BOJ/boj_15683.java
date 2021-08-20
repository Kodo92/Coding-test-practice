package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class boj_15683 {
    private static int N,M;

    // CCTV들의 좌표 배열
    private static ArrayList<Node> cctvPosition;

    private static int[] dx = {0,0,-1,1};
    private static int[] dy = {-1,1,0,0};

    private static int answer;

    /**
     * Next_permutation..........
     * @param arr
     * @return
     */
    private static boolean np(int[] arr) {
        int i = 3;
        while(i>0 && arr[i-1] >= arr[i]) i--;

        if(i==0) return false;

        int j = 3;
        while(arr[i-1]>=arr[j]) j--;

        int temp = arr[i-1];
        arr[i-1] = arr[j];
        arr[j] = temp;

        int k = 3;
        while(i<k) {
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
            i++; k--;
        }
        return true;
    }

    /**
     * map에서 사각지대의 갯수를 찾는다.
     * @param map
     * @return  : 사각 지대 (map[i][j] == 0)의 갯수
     */
    private static int getCount(final int[][] map) {
        int count = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++)
                if(map[i][j] == 0)
                    count++;
        }
        return count;
    }

    /**
     * map에서 지정한 방향으로 직진하면서 장애물을 만나기 전 까지 탐색한다. 탐색한 좌표의 값은 -1로 변경해준다.
     * 함수 내부에서 Param으로 들어온 map을 copy한 뒤 탐색 작업을 진행한다.
     * @param map   : 지도
     * @param yPos  : 탐색 기준 y값
     * @param xPos  : 탐색 기준 x값
     * @param dir   : 탐색할 방향
     * @return      : map을 copy한 새로운 배열 객체
     */
    private static int[][] search(final int[][] map, final int yPos, final int xPos, final int dir) {
        // Map copy to dest
        int[][] dest = new int[N][];
        for(int i=0;i<N;i++)
            dest[i] = Arrays.copyOf(map[i],M);

        // Dir 방향으로 탐색 시작
        int newX = xPos, newY = yPos;
        while (true) {
            newX += dx[dir];
            newY += dy[dir];

            if(newX < 0 || newX >= M || newY < 0 || newY >= N) break;
            // 벽
            if(dest[newY][newX] == 6) break;
            if(dest[newY][newX] != 0) continue;
            dest[newY][newX] = -1;
        }

        return dest;
    }

    private static void simulation(int[][] map, final int index) {
        if(index == cctvPosition.size()) {
            answer = Math.min(answer,getCount(map));
            return;
        }

        Node now = cctvPosition.get(index);

        switch (now.type) {
            case 1:
                // -> 한 방향으로 이동하는 경우
                for(int i=0;i<4;i++)
                    simulation(search(map,now.yPos, now.xPos, i),index+1);
                break;
            case 2:
                // <- ->
                for(int i=0;i<2;i++) {
                    int[][] temp = search(map, now.yPos, now.xPos, (i*2));
                    temp = search(temp, now.yPos, now.xPos, (i*2)+1);
                    simulation(temp,index+1);
                }
                break;
            case 3:
                // | ->
                for(int i=0;i<4;i++) {
                    int[][] temp = search(map, now.yPos, now.xPos, i/2);
                    temp = search(temp, now.yPos, now.xPos, (i%2)+2);
                    simulation(temp,index+1);
                }
                break;
            case 4:
                // <- | ->
                // 4 방향 중 3개를 선택하기 때문에 Next_permutation을 사용했다.
                int[] arr = {0,1,1,1};
                do {
                    int[][] temp = new int[N][];
                    for(int i=0;i<N;i++)
                        temp[i] = Arrays.copyOf(map[i],M);
                    for(int i=0;i<4;i++) {
                        if(arr[i] == 1)
                            temp = search(temp, now.yPos, now.xPos, i);
                    }
                    simulation(temp,index+1);
                } while(np(arr));
                break;
            case 5:
                for(int i=0;i<4;i++)
                    map = search(map, now.yPos, now.xPos, i);
                simulation(map,index+1);
                break;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        answer = Integer.MAX_VALUE;

        int[][] map = new int[N][M];
        cctvPosition  = new ArrayList<>();
        for(int i=0;i<N;i++) {
            map[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            for(int j=0;j<M;j++) {
                if(map[i][j] != 0 && map[i][j] != 6)
                    cctvPosition.add(new Node(i,j,map[i][j]));
            }
        }

        simulation(map,0);

        System.out.println(answer);

    }

    static class Node {
        private int yPos;
        private int xPos;
        private int type;

        public Node(int yPos, int xPos, int type) {
            this.yPos = yPos;
            this.xPos = xPos;
            this.type = type;
        }
    }

}
