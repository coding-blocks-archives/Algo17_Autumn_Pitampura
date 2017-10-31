//time complexity : O(n) 
//space complexity: O(n)

public static void preorderwithoutRec(BTNode root){
        if(root==null)
            return;

        Stack<BTNode> s1=new Stack<>();    //since we cannot use internal stack i.e.recursion so use external stack

        s1.push(root);

        while(!s1.isEmpty()){

            BTNode temp=s1.pop();
            System.out.print(temp.data+" ");            //print the topmost elemnt in stack 
            if(temp.right!=null)
                s1.push(temp.right);                  
            if(temp.left!=null)
                s1.push(temp.left);
        }

 }