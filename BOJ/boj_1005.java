import java.util.*;

public class boj_1005 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        while(T-- != 0)
        {
            int N,K;
            N = sc.nextInt();
            K = sc.nextInt();

            ArrayList<Integer> costs = new ArrayList<Integer>(N);
            for(int i =0;i<N;i++)
                costs.add(i,sc.nextInt());

            ArrayList<ArrayList<Integer>> paths = new ArrayList<>();
            for(int i=0;i<N;i++)
                paths.add(new ArrayList<Integer>());

            int[] indegrees = new int[N];
            for(int i=0;i<K;i++)
            {
                int source, dest;
                source = sc.nextInt()-1;
                dest = sc.nextInt()-1;

                paths.get(source).add(dest);
                indegrees[dest]++;
            }

            int D = sc.nextInt()-1;
            int[] distance = new int[N];

            Queue queue = new LinkedList();
            for(int i=0;i<N;i++)
            {
                if(indegrees[i] == 0) {
                    queue.add(i);
                    distance[i]=costs.get(i);
                }
            }

            while(!queue.isEmpty())
            {
                int top = (Integer)queue.element();
                queue.remove();

                if(top == D)
                    break;

                ArrayList<Integer> ret = paths.get(top);
                for(int i=0;i<ret.size();i++)
                {
                    int now = ret.get(i);
                    if(--indegrees[now] == 0)
                        queue.add(now);
                    if(distance[now] < distance[top] + costs.get(now))
                        distance[now] = distance[top] + costs.get(now);
                }
            }
            System.out.println(distance[D]);
        }

    }
}
