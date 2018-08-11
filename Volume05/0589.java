
/**
 * 0589 Production
 */

import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Arrays;
import java.util.Comparator;

class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        HashMap<String, Integer> map = new HashMap<String, Integer>();

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            String[] input = br.readLine().split(" ");
            if(map.containsKey(input[0])){
                map.put(input[0], Integer.parseInt(input[1]) + map.get(input[0]));
            }else{
                map.put(input[0], Integer.parseInt(input[1]));
            }
        }

        Object[] products = map.keySet().toArray();

        Arrays.sort(products, new Comparator<Object>(){
            public int compare(Object o1, Object o2){
                String s1 = o1.toString();
                String s2 = o2.toString();

                if(s1.length() == s2.length()){
                    return s1.compareTo(s2);
                }else{
                    return s1.length() - s2.length();
                }
            }
        });

        for(Object obj : products){
            String s = obj.toString();
            System.out.println(s + " " + map.get(s));
        }

    }
}