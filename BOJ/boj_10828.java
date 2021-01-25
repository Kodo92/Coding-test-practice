import java.util.*;

public class boj_10828 {
    static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
        LinkedList stack = new LinkedList();
        StringBuilder buffer = new StringBuilder();
        int N = sc.nextInt();
        for(int i=0;i<N;i++)
        {
            String str = sc.next();
            if(str.contains("push")) {
                int number = sc.nextInt();
                stack.push(number);
            } else if (str.contains("pop")) {
                buffer.append("" + (stack.isEmpty()? -1 : stack.pop())+'\n');
            }
            else if(str.contains("size"))
                buffer.append(""+stack.size()+'\n');
            else if(str.contains("empty"))
                buffer.append(""+(stack.isEmpty() ? 1 : 0)+'\n');
            else
                buffer.append(""+(stack.isEmpty()?-1:stack.peek())+'\n');

        }
        System.out.println(buffer);
    }
}
