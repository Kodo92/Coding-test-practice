import java.util.*;

public class pro_68644 {
    public static void main(String[] args) {
        System.out.println(solution(new int[] {2,1,3,4,1}));
    }

    public static int[] solution(int[] numbers) {
        Set<Integer> answer = new TreeSet<>();

        for(int i=0;i<numbers.length;i++)
        {
            for(int j=i+1;j<numbers.length;j++)
                answer.add(numbers[i] + numbers[j]);
        }

        return answer.stream().mapToInt(i->i).toArray();

        // HashSet<> 보다 TreeSet<>이 더 빠름~
    }
}
