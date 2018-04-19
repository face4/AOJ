/**
 * ALDS1_3_B Queue
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Tuple{
    String name;
    int time;
    Tuple(String name, int time){
        this.name = name;
        this.time = time;
    }
}

class myQueue{
    int size = 100000;
    Tuple[] data;
    int head;
    int tail;

    myQueue(){
        data = new Tuple[size];
        head = 0;
        tail = 0;
    }

    void enqueue(String n, int t){
        if(isFull()){
            System.err.println("queue is full");
            return;
        }
        data[tail] = new Tuple(n,t);
        tail = (tail + 1) % size;
    }

    Tuple dequeue(){
        if(isEmpty()){
            System.err.println("queue is empty");
            return null;
        }
        Tuple answer = data[head];
        head = (head + 1) % size;
        return answer;
    }
    
    boolean isFull(){
        return head == (tail + 1) % size;
    }

    boolean isEmpty(){
        return head == tail;
    }
}
class Main{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int q = Integer.parseInt(input[1]);
        
        myQueue mq = new myQueue();
        for(int i = 0; i < n; i++){
            String[] line = br.readLine().split(" ");
            mq.enqueue(line[0], Integer.parseInt(line[1]));
        }

        int now = 0;
        while(!mq.isEmpty()){
            Tuple process = mq.dequeue();
            if(process.time <= q){
                now += process.time;
                System.out.println(process.name + " " + now);
            }else{
                now += q;
                mq.enqueue(process.name, process.time - q);
            }
        }
    }
}