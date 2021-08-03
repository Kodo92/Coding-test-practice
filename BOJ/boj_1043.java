package boj;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class boj_1043 {
    private static int N,M;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        HashSet<Integer> duplicated = new HashSet<>();
        Queue<Integer> truePeople = new LinkedList<>();
        st = new StringTokenizer(br.readLine()," ");
        int truePeopleCount = Integer.parseInt(st.nextToken());
        for(int i=0;i<truePeopleCount;i++) {
            int personNumber =Integer.parseInt(st.nextToken())-1;
            truePeople.add(personNumber);
            duplicated.add(personNumber);
        }

        List<List<Integer>> memberParty = new ArrayList<>();
        List<List<Integer>> attendees = new ArrayList<>();
        for(int i=0;i<N;i++) {
            memberParty.add(new ArrayList<>());
        }
        for(int i=0;i<M;i++) {
            st = new StringTokenizer(br.readLine()," ");
            List<Integer> nowParty = new ArrayList<>();
            attendees.add(nowParty);
            int count = Integer.parseInt(st.nextToken());
            for(int j=0;j<count;j++) {
                int person = Integer.parseInt(st.nextToken()) - 1;
                memberParty.get(person).add(i);
                nowParty.add(person);
            }
        }

        boolean[] isChecked = new boolean[N];
        boolean[] isVisited = new boolean[M];
        while(!truePeople.isEmpty()) {
            int i = truePeople.poll();
            if(isChecked[i])
                continue;
            isChecked[i] = true;
            for(Integer party : memberParty.get(i)) {
                if(isVisited[party]) continue;
                isVisited[party] = true;
                for(Integer member : attendees.get(party)) {
                    if(!duplicated.contains(member)) {
                        duplicated.add(member);
                        truePeople.add(member);
                    }
                }
            }
        }

        int answer = 0;
        for(int i=0;i<M;i++){
            if(!isVisited[i])
                answer++;
        }
        System.out.println(answer);

    }
}
