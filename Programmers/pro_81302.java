package programmers;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class pro_81302 {

    public static void main(String[] args) {
        pro_81302 sol = new pro_81302();
        //sol.solution(new String[][]{ {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        //        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} });
        sol.solution(new String[][]{{"OOOOO", "OPXPO", "OXPOO", "OPXPO", "OOOOO"}});
    }

    private int[] dx = {0,0,-1,1};
    private int[] dy = {-1,1,0,0};

    private boolean checkPartition(final String[] map, final int[] source, final int[] dest) {
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{0,source[0],source[1]});

        boolean[][] isVisited = new boolean[5][5];
        isVisited[source[0]][source[1]] = true;
        while(!queue.isEmpty()) {
            int[] now = queue.poll();

            if(now[0] > 2)
                continue;
            if(now[1] == dest[0] && now[2] == dest[1])
                return false;
            for(int i=0;i<4;i++) {
                int newYPos = now[1] + dy[i];
                int newXPos = now[2] + dx[i];

                if(newYPos < 0 || newYPos >= 5 || newXPos < 0 || newXPos >= 5) continue;
                if(map[newYPos].charAt(newXPos) == 'X') continue;
                if(isVisited[newYPos][newXPos]) continue;
                isVisited[newYPos][newXPos] = true;
                queue.add(new int[]{now[0]+1,newYPos,newXPos});
            }
        }
        return true;
    }

    private int getManhattanDistance(final int[] source, final int[] dest) {
        return Math.abs(source[0] - dest[0]) + Math.abs(source[1] - dest[1]);
    }

    private boolean isViolation(final String[] map, final int[] source, final int[] dest) {
        int distance = getManhattanDistance(source,dest);
        if(distance == 2 && !checkPartition(map, source,dest))
            return true;
        else if(distance == 1)
            return true;
        else
            return false;
    }

    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        int index = 0;
        for(String[] strArray : places) {
            boolean isFind = false;
            ArrayList<int[]> position = new ArrayList<>();
            for(int i=0;i<5;i++) {
                for(int j=0;j<5;j++) {
                    if(strArray[i].charAt(j) == 'P')
                        position.add(new int[]{i,j});
                }
            }

            for(int i=0;i<position.size();i++) {
                if(isFind)
                    break;
                for(int j=i+1;j<position.size();j++)
                    if(isViolation(strArray,position.get(i),position.get(j))) {
                        isFind = true;
                        break;
                    }

            }

            if(isFind)
                answer[index] = 0;
            else
                answer[index] = 1;
            index++;
        }
        return answer;
    }
}