import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{ 
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int num = Integer.valueOf(br.readLine());
        String[] preData = br.readLine().split(" " , num);
        int[] data = new int[num];

        for(int i = 0; i < num; i++) data[i] = Integer.parseInt(preData[i]);

        int max = data[0];

        for(int i = 1; i < num; i++){
            if(data[i] > max)   max = data[i];
        }

        int times = 0;
        int lcd = 0;

        while(true){
            times++;
            lcd = max * times;
            boolean isLCD = true;
            
            for(int i = 0; i < num; i++){
                if(lcd % data[i] != 0) isLCD = false;
            }

            if(isLCD){
                break;
            }
        }

        System.out.println(lcd);
    }
}