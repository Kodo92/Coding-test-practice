package SWEA;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class swea_7227 {
    private static long answer=Long.MAX_VALUE;

    static class Position {
        private long xPos;
        private long yPos;

        public Position(long xPos, long yPos) {
            this.xPos = xPos;
            this.yPos = yPos;
        }
    }

    public static void DFS(final Position[] worms, boolean[] isVisited, int remainCount, int nowIndex) {
        if(remainCount == 0) {
            long xVec = 0;
            long yVec = 0;
            for(int i=0;i<worms.length;i++) {
                if(isVisited[i]) {
                    xVec += worms[i].xPos;
                    yVec += worms[i].yPos;
                } else {
                    xVec -= worms[i].xPos;
                    yVec -= worms[i].yPos;
                }
            }

            answer = Long.min(answer,xVec*xVec+yVec*yVec);
            return;
        }

        for(int i=nowIndex;i<isVisited.length;i++) {
            if(isVisited[i]) continue;
            isVisited[i] = true;
            DFS(worms,isVisited,remainCount-1,i+1);
            isVisited[i] = false;
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T;
        T=Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {
            answer = Long.MAX_VALUE;
            int N = Integer.parseInt(br.readLine());
            Position[] worms = new Position[N];
            for(int i=0;i<N;i++) {
                String[] inputs = br.readLine().split(" ");
                worms[i] = new Position(Integer.parseInt(inputs[0]),Integer.parseInt(inputs[1]));
            }

            DFS(worms,new boolean[N],N/2,0);

            System.out.println("#"+test_case+" "+answer);
        }
    }
}
