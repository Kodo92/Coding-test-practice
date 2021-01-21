import java.util.*;

public class boj_1012 {
    static Scanner sc = new Scanner(System.in);
    static int[] dy = new int[]{-1,0,1,0};
    static int[] dx = new int[]{0,1,0,-1};

    public static void main(String[] args) {
        int T = sc.nextInt();

        while(T-- != 0)
            slove();
    }

    static void slove()
    {
        int W,H,K;
        W = sc.nextInt();
        H = sc.nextInt();
        K = sc.nextInt();
        Boolean[][] map = new Boolean[H][W];
        for(int i=0;i<H;i++)
            Arrays.fill(map[i],false);
        for(int i=0;i<K;i++)
        {
            int x,y;
            x = sc.nextInt();
            y = sc.nextInt();

            map[y][x] = true;
        }

        int count = 0;
        for(int i=0;i<H;i++)
        {
            for(int j=0;j<W;j++)
            {
                if(map[i][j])
                {
                    // BFS
                    count++;
                    Queue q = new LinkedList();
                    q.add(new Pair(i,j));
                    while(!q.isEmpty())
                    {
                        Pair top = (Pair)q.element();
                        q.remove();

                        for(int k=0;k<dy.length;k++)
                        {
                            int newY = top.first + dy[k];
                            int newX = top.second + dx[k];
                            if(newY < 0 || newY >= H || newX < 0 || newX >= W)
                                continue;
                            if(!map[newY][newX])
                                continue;
                            map[newY][newX] = false;
                            q.offer(new Pair(newY,newX));
                        }
                    }
                }
            }
        }
        System.out.println(count);
    }
}

class Pair{
    int first, second;

    public Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}