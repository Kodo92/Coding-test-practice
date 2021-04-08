public class pro_42862 {
    public static void main(String[] args) {
        System.out.println(solution(5,new int[] {3}, new int[] {1}));
    }

    public static int solution(int n, int[] lost, int[] reserve) {
        int[] student = new int[n];
        for(int i : lost) {
            student[i-1] -= 1;
        }
        for(int i : reserve) {
            student[i-1] += 1;
        }

        for(int i = 0; i<n ; i++) {
            if(student[i] < 1) continue;
            if(i-1 >= 0 && student[i-1] < 0) {
                student[i-1] += 1;
                student[i] -= 1;
            } else if(i+1 < n && student[i+1] < 0) {
                student[i+1] += 1;
                student[i] -= 1;
            }
        }
        int answer = 0;
        for(int i : student) {
            if(i >= 0)
                answer++;
        }
        return answer;
    }
}
