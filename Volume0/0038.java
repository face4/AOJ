/**
 * 0038 Poker Hand
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String line;

        while((line = br.readLine()) != null){
            String[] input = line.split(",");
            int[] cards = new int[5];

            // 特殊なstraight判定
            int[] special = {1,10,11,12,13};

            for(int i = 0; i < 5; i++){
                cards[i] = Integer.parseInt(input[i]);
            }

            Arrays.sort(cards);

            int tmp = 0;    // 比較対象の数字
            int same = 0;   // 前の数字と一致する回数
            boolean gtTwo = false; // 数字の一致する枚数が3枚以上かどうか
            boolean gtThree = false; // 数字の一致する枚数が4枚以上かどうか
            int count = 1;  // 今何枚連続で一致しているか

            for(int x : cards){
                if(tmp == x){
                    same++;
                    count++;
                    if(count > 2) gtTwo = true;
                    if(count > 3) gtThree = true;
                }else{
                    tmp = x;
                    count = 1;
                }
            }

            if(same == 3){
                if(gtThree){
                    System.out.println("four card");
                }else{
                    System.out.println("full house");
                }
            }else if(same == 2){
                if(gtTwo){
                    System.out.println("three card");
                }else{
                    System.out.println("two pair");
                }
            }else if(same == 1){
                System.out.println("one pair");
            }else if(same == 0){
                boolean isStraight = true;
                int run = cards[0];
                for(int i = 1; i < 5; i++){
                    if(cards[i] - run != 1){
                        isStraight = false;
                        break;
                    }
                    run = cards[i];
                }

                if(isStraight || Arrays.equals(cards, special)){
                    System.out.println("straight");
                }else{
                    System.out.println("null");
                }
            }

        } // end of while

    }
}