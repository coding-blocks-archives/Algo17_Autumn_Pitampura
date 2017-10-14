import java.util.*;
import java.lang.*;

class Main {
    public static void main(String args[]) {
        Main call = new Main();
        call.foo();
    }

    public void foo() {
        PriorityQueue<Book> pqb = new PriorityQueue<>();
        pqb.add(new Book());
        pqb.add(new Book());
        System.out.println(pqb.peek());

    }
}

class Book implements Comparable<Book>{
    public int id;
    public String author;
    public Book() {
        id = 0;
        author = "abc";
    }

    public Book(int i){
        id = i;
        author = "def";
    }

    @Override
    public int compareTo(final Book B){
        return id - B.id;
    }

    public String toString() {
        return (Integer.toString(id) + " " + author);
    }
}