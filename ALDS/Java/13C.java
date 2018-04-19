/**
 * ALDS1_3_C Doubly Linked List
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class Cell{
    Cell prev;
    Cell next;
    int value;

    Cell(){ // head生成用のコンストラクタ
        this.prev = this;
        this.next = this;
    }

    Cell(int val){
        value = val;
        this.prev = null;
        this.next = null;
    }
}

class Main{
    static Cell head = new Cell();

    static void insert(int value){
        Cell newone = new Cell(value);
        newone.next = head.next;
        newone.prev = head;
        newone.next.prev = newone;
        head.next = newone;
    }

    static void delete(int value){
        Cell run = head.next;
        while(run != head){
            if(run.value == value){
                run.prev.next = run.next;
                run.next.prev = run.prev;
                run.prev = null;
                run.next = null;
                return;
            }
            run = run.next;
        }
    }

    static void deleteFirst(){
        delete(head.next.value);
    }

    static void deleteLast(){
        Cell del = head.prev;
        head.prev = del.prev;
        del.prev.next = head;

        del.prev = null;
        del.next = null;
    }

    static void show(){
        Cell run = head.next;
        if(run == head){
            System.out.println();
            return;
        }
        StringBuilder sb = new StringBuilder();
        boolean format = true;
        while(run != head){
            if(format){
                sb.append(run.value);
                format = false;
            }else{
                sb.append(" " + run.value);
            }
            run = run.next;
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        for(int i = 0; i < n; i++){
            String[] input = br.readLine().split(" ");

            switch(input[0]){
                case "insert":
                    insert(Integer.parseInt(input[1]));
                    break;
                case "delete":
                    delete(Integer.parseInt(input[1]));
                    break;
                case "deleteFirst":
                    deleteFirst();
                    break;
                case "deleteLast":
                    deleteLast();
                    break;
            }
        }
        show();
    }
}