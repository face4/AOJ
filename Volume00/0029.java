
/**
 * 0029 English Sentence
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String longestWord = "";
        HashMap<String, Integer> map = new HashMap<String, Integer>();

        String[] input = br.readLine().split(" ");
        for (String word : input) {
            if (map.containsKey(word)) {
                map.put(word, map.get(word) + 1);
            } else {
                map.put(word, 1);
            }

            if(longestWord.length() < word.length()){
                longestWord = word;
            }
        }

        int mode = 0;
        String maxmodeWord = "";

        for(String x : map.keySet()){
            if(map.get(x) > mode){
                mode = map.get(x);
                maxmodeWord = x;
            }
        }

        System.out.println(maxmodeWord + " " + longestWord);
    }
}