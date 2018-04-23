/**
 * 0124-League Match Score Sheet
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

import java.util.Arrays;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean control = false;
        int num;

        while((num = Integer.valueOf(br.readLine())) != 0){
            
            if(control) System.out.println();

            Table[] table = new Table[num];

            for(int i = 0; i < num; i++){
                String[] input = br.readLine().split(" " , 4);
                
                String country = input[0];
                int score = Integer.valueOf(input[1]) * 3 + Integer.valueOf(input[3]);

                table[i] = new Table(country , score);
            }

            Arrays.sort(table);

            for(Table a : table){
                System.out.println(a);
            }

            control = true;
        }

    }
}

class Table implements Comparable{
        String country;
        int score;
        Table(String c , int s){
            this.country = c;
            this.score = s;
        }

        public String toString(){
            return this.country + "," + this.score;
        }

        public int compareTo(Object object){
            Table comp = (Table)object;
            if(this.score < comp.score) return 1;
            else if(this.score > comp.score) return -1;
            else return 0;
        }

}