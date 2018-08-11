/**
 * 0593 Vote
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String[] input = br.readLine().split(" ");
        int N = Integer.parseInt(input[0]);
        int M = Integer.parseInt(input[1]);
        int[] A = new int[N+1];
        int[] votes = new int[N+1];

        for(int i = 1; i <= N; i++){
            A[i] = Integer.parseInt(br.readLine());
        }

        for(int i = 0; i < M; i++){
            int B = Integer.parseInt(br.readLine());
            for(int j = 1; j <= N; j++){
                if(A[j] <= B){
                    votes[j]++;
                    break;
                }
            }
        }

        int maxIndex = -1;
        int maxVotes = Integer.MIN_VALUE;
        for(int i = 1; i <= N; i++){
            if(maxVotes < votes[i]){
                maxVotes = votes[i];
                maxIndex = i;
            }
        }
        System.out.println(maxIndex);
    }
}