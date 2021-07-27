package boj;

import java.util.Scanner;

public class boj_2615 {
    private static final int mapSize = 19;
    private static int[][] maps = new int[mapSize][mapSize];
    private static int xf[] = {0,1,1,1};
    private static int yf[] = {1,0,1,-1};

    // yFlag == 0 && xFlag == 1 -> 가로체크
    // yFlag == 1 && xFlag == 0 -> 세로체크
    // yFlag == 1 && xFlag == 1 -> 대각선 체크
    private static boolean checkStone(final int yIndex, final int xIndex, final int yFlag, final int xFlag) {
        if(yFlag > 0) {
            if(yIndex + 5 > mapSize) return false;
        }
        if(xFlag > 0) {
            if(xIndex + 5 > mapSize) return false;
        }
        if(yFlag < 0) {
            if(yIndex - 5 < 0) return false;
        }

        int pivot = maps[yIndex][xIndex];
        int count = 0;
        while(true) {
            int newY = yIndex + (count*yFlag);
            int newX = xIndex + (count*xFlag);
            if(newY < 0 || newY >= mapSize || newX < 0 || newX >= mapSize)
                break;
            if(maps[newY][newX] != pivot)
                break;
            count++;

        }
        if(count == 5) {
            int newY = yIndex - yFlag;
            int newX = xIndex - xFlag;
            if(newX >= 0 && newX < mapSize && newY >= 0 && newY < mapSize && maps[newY][newX] == pivot)
                return false;
            return true;
        }
        return false;
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        for(int i=0;i<mapSize;i++) {
            for(int j=0;j<mapSize;j++) {
                maps[i][j] = sc.nextInt();
            }
        }

        boolean isFind = false;
        for(int i=0;i<mapSize;i++) {
            for(int j=0;j<mapSize;j++) {
                if(maps[i][j] == 0) continue;
                // 가로, 세로, 대각선 체크 델타 방식을 이용
                for(int k=0;k<4;k++) {
                    if(checkStone(i,j,yf[k],xf[k])) {
                        isFind = true;
                        System.out.println(maps[i][j]);
                        System.out.println((i+1)+ " "+(j+1));
                        break;
                    }
                }
                if(isFind)
                    break;
            }
            if(isFind)
                break;
        }
        if(!isFind) {
            System.out.println(0);
        }
        sc.close();
    }
}

// 6목 체크 완료
// 승부 못가리는 경우 체크 완료
// 가로 체크 완료 - 4, 5, 6
// 세로 체크 완료 - 4, 5, 6
// 우하 체크 완료 - 4, 5, 6
// 우상 체크 완료 - 4, 5, 6
