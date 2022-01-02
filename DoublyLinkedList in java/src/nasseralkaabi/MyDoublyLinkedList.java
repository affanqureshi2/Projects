package nasseralkaabi;
//Problem 1
public class MyDoublyLinkedList { 
        
		//Declare header and trailer   
		Node header  = null;
		Node trailer = null;  
  
     	//Node Class
        class Node{  
        	Node next;  
        	Node previous;   
        	int newInfo;  
         
        	public Node() 
        	{
        		//For temp varaible
        	}
            public Node(int newInfo) {  
                this.newInfo = newInfo;  
            }  
        }  
      
        
        //insert() for inserting new node with newinfo in list 
        public void insert(int newInfo) {  
           
        	Node newData = new Node(newInfo);  
        	Node temp  = new Node();
            //When empty list  
            if(header == null) {  
                //header and trailer initialize to newData  
                header = trailer = newData;  
                //header's previous and trailer's next assigned null  
                header.previous  =  trailer.next = null;  
      
            }  

            else {  
                if(header.newInfo > newData.newInfo) {
                	temp.newInfo = header.newInfo;
                	header.newInfo = newData.newInfo;
                	newData.newInfo = temp.newInfo ;
                }
                //For new date trailer's next assigned to newData  
                if(trailer.newInfo > newData.newInfo) {
                	temp.newInfo = trailer.newInfo;
                	trailer.newInfo = newData.newInfo;
                	newData.newInfo = temp.newInfo ;
                }
                trailer.next = newData;  
                //newData's previous assigned to trailer  
                newData.previous = trailer;  
                //newData assigned to trailer  
                trailer = newData;  
                //trailer is last so it will become null  
                trailer.next = null;  
            }  
        }  
        //search() to search the element in the list    
        public Node search(int searchInfo) {  
            //For starting  
            Node current = header;
            if(header == null) {  
                return null;  
            }  
            while(current != null) {  
                //Search each element.  
                if(current.newInfo == searchInfo) {
                	return current;
                };  
                current = current.next;  
            }  
            return null;
        }  
        //search() to search the element in the list    
        public void delete(int deleteInfo) {  
            //For starting  
            Node current = header;
            if(header.newInfo == deleteInfo) {  
                header = current.next;  
                return;
            }  
            while(current != null) {  
                //Display each element.  
                if(current.newInfo == deleteInfo) {
                	current = current.previous;
                	current.next = current.next.next;
                	return;
                };  
                current = current.next;  
            }  
           
        }  
        //print() that prints the elements of the list    
        public void print() {  
            //For starting  
            Node current = header;  
            if(header == null) {  
                System.out.println("Empty List");  
                return;  
            }  
            System.out.println("Elements of doubly linked list: ");  
            while(current != null) {  
                //Display each element.  
                System.out.print(current.newInfo + " ");  
                current = current.next;  
            }  
        }  
        public void merge(MyDoublyLinkedList L2) {
        	//L1.trailer.next = L2.header;
        	Node cL2 = L2.header;
        	if(cL2 == null) {
        		return;
        	}
        	while (cL2 != null)
        	{
        		this.insert(cL2.newInfo);
        		cL2 = cL2.next;
        	}
        	
/*        	Node cL1 = header;
        	Node cL2 = L2.header;
        	if(header == null)
        	{	header = L2.header;
        		return;
        	}
        	if(L2.header == null)
        	{	return;
        	}
        	while(cL1 != null || cL2 != null ) {  
                //Count Divisible by countInfo.
            	if(cL1.newInfo < cL2.newInfo) {
            		trailer = cL1;
            		trailer.next = cL2;
            	}
            	else {
            		trailer = cL2;
            		trailer.next = cL1;
            	}
                 cL1 = cL1.next;
                 cL2 = cL2.next;
            }
        	
*/        }
        public Integer count(int countInfo) {  
            //For starting  
        	int count = 0;
            Node current = header;  
            if(header == null) {  
                return null;  
            }  
            while(current != null) {  
                //Count Divisible by countInfo.
            	if(current.newInfo % countInfo == 0) {
            		count= count+1;
            	}
                 current = current.next;
            }  
            return count;
        }  
      
        public static void main(String[] args) {  
      
        	MyDoublyLinkedList newList1 = new MyDoublyLinkedList();  
            //Add new Elements to the list  
        	newList1.insert(2);  
        	newList1.insert(3);  
        	newList1.insert(1);  
        	newList1.insert(5);  
        	newList1.insert(4);  
      
            //Display elements  
        	newList1.print();
            //Search element
            System.out.println(newList1.search(3));
            //Delete element
            newList1.delete(3);
            newList1.print();
            System.out.println(newList1.count(3));
            
        	MyDoublyLinkedList newList2 = new MyDoublyLinkedList();  
            //Add new Elements to the list  
        	newList2.insert(6);  
        	newList2.insert(10);  
        	newList2.insert(7);  
        	newList2.insert(9);  
        	newList2.insert(8);  
        	
        	newList2.print();
        	newList1.merge(newList2);
        	newList1.print();
        	
        }  
    }  