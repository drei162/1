#include <iostream>
#include <thread>
#include <chrono>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void NumberOne(){
for (int a = 1; a <=10; a++){
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
     std::cout <<"Thread 1: "<< a << std::endl;
}
}

void NumberTwo(){
    for (int b = 5; b <=50; b+=5){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout <<"Thread 2: "<< b << std::endl;
} 
}

void NumberThree(){
 for (int c = 2; c <=32; c*=2){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout <<"Thread 3: "<< c << std::endl;
}
}
int main()
{
    pid_t proc1 = fork(); 
    
    if (proc1==0){
        NumberOne(); 
        return 0; 
    }
   
   pid_t proc2 = fork(); 
    
    if (proc2==0){
        NumberTwo(); 
        return 0; 
    }
    
    pid_t proc3 = fork(); 
    
    if (proc3==0){
        NumberThree(); 
        return 0; 
    }
    
    waitpid(proc1, nullptr, 0);
    waitpid(proc2, nullptr, 0);
    waitpid(proc3, nullptr, 0);
    return 0;
}