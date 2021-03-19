import java.util.*;


public class pro_42576 {
    public static void main(String[] args) {
        System.out.println(solution(new String[]{"mislav", "stanko", "mislav", "ana"}, new String[]{"stanko", "ana", "mislav"}));
    }

    public static String solution(String[] participant, String[] completion) {
/*
        //max : 106.1 ms
        HashMap<String,Integer> p = new HashMap<>();
        for(String str : participant) {
            Integer result = p.putIfAbsent(str, 1);
            if(result != null)
                p.replace(str,result+1);
        }

        for(String str : completion) {
            Integer result = p.get(str);
            if(result == null)
                return str;
            else if(result == 1) {
                p.remove(str);
            } else {
                p.replace(str,result-1);
            }
        }
        return p.keySet().iterator().next();

*/

/*
        //max : 104.42ms
        HashMap<String, Integer> p = new HashMap<>();
        for(String str : participant) p.put(str,p.getOrDefault(str,0)+1);
        for(String str : completion) p.put(str,p.get(str)-1);

        String answer = "";
        for(Map.Entry<String,Integer> i : p.entrySet()) {
            if(i.getValue() != 0) {
                answer = i.getKey();
                break;
            }
        }
        return answer;
*/

        //max=381.22ms
        Arrays.sort(participant);
        Arrays.sort(completion);

        System.out.println(Arrays.asList(participant));
        for(int i=0;i<completion.length;i++)
            if(!participant[i].equals(completion[i])) {
                return participant[i];
            }
        return participant[participant.length-1];

    }
}