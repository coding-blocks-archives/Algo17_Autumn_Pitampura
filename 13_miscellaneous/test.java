import java.util.*;

class test{
    public static void testing(Object ... x){
        for(Object i : x){
            System.out.println(i);
        }
    }

    public static void main(String  args[]){
        int[] arr = new int[]{1,2,3}; 
        testing(1, 2, "baby", 2.00, arr);
    }
}