# Problem 4: Linked List Recursion Tracing

## Question a:
  Some pseudocode to track the function calls:

    llrec( 1->2->3->4 , 5->6 )
    return 1->...
        llrec( 5->6 , 2->3->4 )
        return 5->...
            llrec( 2->3->4, 6)
            return 2->...
                llrec( 6 , 3->4 )
                return 6->...
                    llrec( 3->4 , nullptr )
                    return 3->4
  
  As we can see, the sequence of return statements gives **1->5->2->6->3->4**

___
## Question b:

  Same thing, using pseudocode to track the function calls:

    llrec( nullptr , 2 )
    return in2 = 2
  
  As we can see, this returns the linked list of in2, just one node with value 2.