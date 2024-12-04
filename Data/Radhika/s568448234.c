int main(int argc, const char * argv[]) {
    int A,B;
    scanf("%d\n",&A);
    scanf("%d\n",&B);
    
    if(A==1&&B!=1){
        printf("Alice\n");
    }
    else if(A!=1&&B==1){
        printf("Bob\n");
    }
   
    else if(A>B){
        printf("Alice\n");
    }
    else if(B>A){
        printf("Bob\n");
    }
    else {
        printf("Draw\n");
    }