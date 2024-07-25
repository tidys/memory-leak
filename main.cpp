
#include <iostream>
#define CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <certreqd.h>
#ifdef _DEBUG 
#define new  new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif
using namespace std;
void doMallocLeak(int num){
    void* ptr = malloc(sizeof(char) * num);
    //free(ptr);
}

int* doNewLeak(){
    return  new int;
}
int main(_In_ int argc, _In_reads_(argc) _Pre_z_ char** argv, _In_z_ char** envp){
    _CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG));
    doMallocLeak(1000);
    int* p1= doNewLeak();
    delete p1;

    //int num = _CrtDumpMemoryLeaks();
    //_CrtSetBreakAlloc(107);
    return 0;
}