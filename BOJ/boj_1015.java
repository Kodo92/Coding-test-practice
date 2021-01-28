import java.util.*;

class Node implements Comparable<Node> {
    private final int index;
    private final int value;

    public Node(int index, int value) {
        this.index = index;
        this.value = value;
    }

    public int getIndex()
    {
        return index;
    }
    @Override
    public int compareTo(Node compared) {
        if(this.value == compared.value) {
            return (this.index < compared.index) ? -1 : 1;
        }
        return (this.value < compared.value) ? -1 : 1;
    }
}

public class boj_1015 {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int N = sc.nextInt();
        ArrayList<Node> array = new ArrayList<Node>();
        for(int i=0;i<N;i++)
            array.add(new Node(i,sc.nextInt()));

        Collections.sort(array);

        int[] answer = new int[N];
        for(int i=0;i<N;i++)
            answer[array.get(i).getIndex()] = i;

        for(int a : answer)
            System.out.print(""+a+" ");
    }
}
