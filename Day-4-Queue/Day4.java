//importing all the libraries
import java.util.*;
import java.lang.*;
import java.io.*;

class Day4{
    static class Queue{
        static Stack<Integer> s1 = new Stack<Integer>();
        static Stack<Integer> s2 = new Stack<Integer>();

        static void enQueue(int x){
            //Move all elements from s1 to s2
            while (!s1.isEmpty()){
                s2.push(s1.pop());
                //s1.pop() returns the element we delete in s1, and it is then pushed into s2
            }

            //Pushing x into s1
            s1.push(x);

            //Push everything back to s1
            while (!s2.isEmpty()){
                s1.push(s2.pop());
                //s2.pop() returns the element we delete in s2, and it is then pushed into s1
            }
        }

        // Dequeue an item from the Queue
        static int deQueue(){
            //Checking if the queue is empty
            if(s1.isEmpty()){
                System.out.println("Q is empty");
                System.exit(0);
            }

            //peek returns the top of s1
            int x =  s1.peek();
            s1.pop();
            return x;
        }
    };

    // Driver Code
    public static void main(String[] args){
        Queue q = new Queue();
        q.enQueue(1);
        q.enQueue(2);
        q.enQueue(3);

        System.out.println(q.deQueue());
        System.out.println(q.deQueue());
        System.out.println(q.deQueue());
    }
}
