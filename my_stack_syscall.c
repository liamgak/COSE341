#include<linux/syscalls.h>
#include<linux/kernel.h>
#include<linux/linkage.h>

int stack[100]={0,};
int stack_instructor=0; //getLength()

SYSCALL_DEFINE1(oslab_push, int, a){
        /* push param a in the stack(global variable)
            param a: a numeric value which will be pushed 
        */
        int i = 0; // variable 1 for iterating
        int j = 0; // variable 2 for iterating

        // check a input is already in a stack. If it is true, return.
        for(i=0; i<stack_instructor; i++){
                if(stack[i]==a){
                        printk("[System call] oslab_push(): %d is already in stack\n",a);
                        return;
                }
        }

        if(i==stack_instructor){
                stack[stack_instructor++]=a;
                printk("[System call] oslab_push(): Push %d\n", a);
                printk("Stack Top ----------\n");
                for(j=0; j<stack_instructor; j++){
                        printk("%d\n", stack[stack_instructor-1-j]); // print the element in stack to system-call log.
                }
                printk("Stack Bottom -------\n");
        }

}
SYSCALL_DEFINE0(oslab_pop){
        /* pop the element which is located in the top of stack.
           return : the top element of the stack if it exists.
        */

        int poped_value; // return value(the top element of the stack)
        int j=0; // variable 1 for iterating

        if(stack_instructor>0){   // if the stack has at least one elements, then
                poped_value=stack[(stack_instructor--)-1];	// a variable storing the top element of a stack
                printk("[System call] oslab_pop(): Pop %d\n", poped_value);
                printk("Stack Top ----------\n");
                for(j=0; j<stack_instructor; j++){
                        printk("%d\n", stack[stack_instructor-1-j]); // print reversely all elements to system-call log
                }
                printk("Stack Bottom -------\n");

                return poped_value;
        }
        else{  // if there is no element in the stack , then return the negative number.
                printk("[System_call] oslab_pop(): no element in stack\n");
                return -2;
        }
}
