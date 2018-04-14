/**
 * ITP1_11_D Dice IV
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        Dice[] dice = new Dice[n];

        for(int i = 0; i < n; i++){
            String[] inputs = br.readLine().split(" ");
            int[] input = new int[6];

            for(int j = 0; j < 6; j++){
                input[j] = Integer.parseInt(inputs[j]);
            }

            dice[i] = new Dice(input);
        }

        boolean result = false;
        outer:
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(dice[i].superEquals(dice[j]))    {result = true; break outer;};
            }
        }

        if(result)  System.out.println("No");
        else        System.out.println("Yes");

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

    boolean superEquals(Dice another){
        Dice tmp = another;
        while(true){
            if(this.equals(tmp)) break;
            tmp.turnN();
            if(this.equals(tmp)) break;
            tmp.turnN();
            if(this.equals(tmp)) break;
            tmp.turnN();
            if(this.equals(tmp)) break;
            tmp.turnW();
            if(this.equals(tmp)) break;
            tmp.turnE();  tmp.turnE();
            if(this.equals(tmp)) break;

            return false;
        }
        
        return true;
    }

    boolean equals(Dice another){
        Dice tmp = another;
        if(this.TOP == tmp.TOP){
            if(this.BOTTOM == tmp.BOTTOM){
                for(int i = 0; i < 4; i++){
                    if(this.checkSides(tmp)) return true;
                    tmp.turnR();
                }
            }
        }
        return false;
    }

    boolean checkSides(Dice another){
        return  this.FRONT == another.FRONT &&
                this.RIGHT == another.RIGHT &&
                this.LEFT == another.LEFT &&
                this.BACK == another.BACK;
    }

    void setTop(int top){
        if(this.FRONT == top)           this.turnN();
        else if(this.RIGHT == top)      this.turnW();
        else if(this.LEFT == top)       this.turnE();
        else if(this.BACK == top)       this.turnS();
        else if(this.BOTTOM == top)    {this.turnN(); this.turnN();}
    }

    void setFront(int front){
        if(this.RIGHT == front)         this.turnL();
        else if(this.LEFT == front)     this.turnR();
        else if(this.BACK == front)    {this.turnR(); this.turnR();}
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

    void turnL(){
        int tmp = this.FRONT;
        this.FRONT = this.RIGHT;
        this.RIGHT = this.BACK;
        this.BACK = this.LEFT;
        this.LEFT = tmp;
    }

    void turnR(){
        int tmp = this.FRONT;
        this.FRONT = this.LEFT;
        this.LEFT = this.BACK;
        this.BACK = this.RIGHT;
        this.RIGHT = tmp;
    }

}