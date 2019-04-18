#include<unistd.h>
#define my_stack_push 335
#define my_stack_pop 336

int main(){
        int i; // a variable for iterating
        int r; // a variable storing popped value

        // push three values by calling the added system_call oslab_push
        for(i=0 ; i<3; i++){
                syscall(my_stack_push, i+1);
                printf("Push: %d\n", i+1);
        }
        // pop three values by calling the added system_call oslab_pop.
        for(i=0; i<3; i++){
                r = syscall(my_stack_pop);
                if(r>0){
                        printf("Pop: %d\n", r);
                }
                else{
                        printf("Pop: Error");
                }
        }
        return 0;
}
