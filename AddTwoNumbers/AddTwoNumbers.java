
public class Solution {

    public class ListNode {
          int val;
          ListNode next;
          public ListNode(int x) { this.val = x; }
    }

    public ListNode addTwoNumbers(ListNode m1, ListNode m2) {
        ListNode l1 = m1;
        ListNode l2 = m2;
        ListNode l3 = new ListNode(0);
        ListNode res = l3;
        while (l1 != null && l2 != null){
            int sum = 0;
            sum = l1.val + l2.val;
            
                
                l3.val += sum;
                if(l3.val >= 10){
                    l3.val-=10;
                    l3.next = new ListNode(1);
                }
                else{
                   
                    l3.next = new ListNode(0);
                }
            
            l1 = l1.next;
            l2 = l2.next;
            l3 = l3.next;
       }
        
        while (l1 != null){
            System.out.println("Get");
            int sum = 0;
            sum = l1.val;
           
                    l3.val += sum;
                    if(l3.val >= 10){
                        l3.next = new ListNode(1);
                        l3.val -=10;
                    }
                    else{
                        l3.next = new ListNode(0);
                    }
                
            
            l1 = l1.next;
            l3 = l3.next;
        }
        
        while (l2 != null){
            System.out.println("Get2");
            int sum = 0;
            sum = l2.val;
            
                    l3.val += sum;
                    if(l3.val >= 10){
                        l3.next = new ListNode(1);
                        l3.val -=10;
                    }
                    else{
                        l3.next = new ListNode(0);
                    }
                    
                
            
            l2 = l2.next;
            l3 = l3.next;
        }
        
        ListNode tmp = res;
        while(tmp.next.next != null){
            tmp = tmp.next;
        }
        if(tmp.next.val == 0){
            tmp.next = null;    
        }
        
        return res;
    }
    
}
