/**
 * ITP1_11_B Dice III
 */
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] s = br.readLine().split(" ");
        String[] t = br.readLine().split(" ");
        int[] a = new int[6];
        int[] b = new int[6];

        for(int i = 0; i < s.length; i++){
            a[i] = Integer.parseInt(s[i]);
            b[i] = Integer.parseInt(t[i]);
        }

        Dice diceA = new Dice(a);
        Dice diceB = new Dice(b);
        
        while(true){
            if(diceA.equals(diceB)) break;
            diceB.turnN();
            if(diceA.equals(diceB)) break;
            diceB.turnN();
            if(diceA.equals(diceB)) break;
            diceB.turnN();
            if(diceA.equals(diceB)) break;
            diceB.turnW();
            if(diceA.equals(diceB)) break;
            diceB.turnE();  diceB.turnE();
            if(diceA.equals(diceB)) break;
            System.out.println("No");
            System.exit(0);
        }

        System.out.println("Yes");
    
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