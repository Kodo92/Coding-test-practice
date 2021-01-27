import java.util.*;

public class boj_1015 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        ArrayList array = new ArrayList();
        ArrayList sorted = new ArrayList();
        for(int i=0;i<N;i++)
        {
            int temp = sc.nextInt();
            array.add(temp);
            sorted.add(temp);
        }

        Collections.sort(sorted);
        int[] answer = new int[N];
        int count = 0;
        for(int i=0;i<N;i++)
        {
            int compared = (int)sorted.get(i);
            for(int j=0;j<N;j++)
            {
                if((int)array.get(j) == compared) {
                    array.set(j, -1);
                    answer[j] = count;
                    count++;
                    break;
                }
            }
        }

        for(int i=0;i<N;i++)
            System.out.print(""+ answer[i]+" ");
    }
}
