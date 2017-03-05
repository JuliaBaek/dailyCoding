#ifndef __DYNAMIC_PROGRAMMING_H__
#define __DYNAMIC_PROGRAMMING_H__

#include <iostream>
#include <map>
#include <vector>

using namespace std;
struct ZeroByOne
{
    int zero;
    int one;
};
class DynamicProgramming
{
    public:
        DynamicProgramming();
        ~DynamicProgramming();
        void main();

    private:
        void inputT_N();
        int fibonacci(int num);
        void print();

        int testCaseCnt;
        int zero;
        int one;
        vector<int> N;
        map<int, ZeroByOne> Nmap;
};

#endif
