/**
 * ITP1_11_A Dice I
 */
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        int[] a = new int[6];

        for(int i = 0; i < s.length; i++){
            a[i] = Integer.parseInt(s[i]);    
        }

        Dice dice = new Dice(a);

        String order = br.readLine();

        for(int i = 0; i < order.length(); i++){
            char c = order.charAt(i);
            switch(c){
                case 'S':
                    dice.turnS();
                    break;
                case 'N':
                    dice.turnN();
                    break;
                case 'W':
                    dice.turnW();
                    break;
                case 'E':
                    dice.turnE();
                    break;
            }
        }

        System.out.println(dice.TOP);
    }
}

class Dice{
    int TOP,BOTTOM,LEFT,RIGHT,FRONT,BACK;

    Dice(int[] a){
        this.TOP = a[0];
        this.FRONT = a[1];
        this.RIGHT = a[2];
        this.LEFT = a[3];
        this.BACK = a[4];
        this.BOTTOM = a[5];
    }

    void turnS(){
        int tmp = this.TOP;
        this.TOP = this.BACK;
        this.BACK = this.BOTTOM;
        this.BOTTOM = this.FRONT;
        this.FRONT = tmp;
    }

    void turnN(){
        int tmp = this.TOP;
        this.TOP = this.FRONT;
        this.FRONT = this.BOTTOM;
        this.BOTTOM = this.BACK;
        this.BACK = tmp;
    }

    void turnW(){
        int tmp = this.TOP;
        this.TOP = this.RIGHT;
        this.RIGHT = this.BOTTOM;
        this.BOTTOM = this.LEFT;
        this.LEFT = tmp;
    }

    void turnE(){
        int tmp = this.TOP;
        this.TOP = this.LEFT;
        this.LEFT = this.BOTTOM;
        this.BOTTOM = this.RIGHT;
        this.RIGHT = tmp;
    }

}