#include "DynamicProgramming.h"

DynamicProgramming::DynamicProgramming()
    :testCaseCnt(0){}
DynamicProgramming::~DynamicProgramming()
{
    N.clear();
    Nmap.clear();
}

void DynamicProgramming::print()
{
    for( vector<int>::iterator it = N.begin(); it != N.end(); it++ )
    {
        cout<<Nmap.find(*it)->second.zero<<" "<<Nmap.find(*it)->second.one<<endl;
    }
}

int DynamicProgramming::fibonacci(int num)
{
    if (num == 0)
    {
        zero += 1;
        return 0;
    }
    if (num == 1)
    {
        one += 1;
        return 1;
    }
    return fibonacci(num-1)+fibonacci(num-2);
}

void DynamicProgramming::inputT_N()
{
    cin>>testCaseCnt;
    int tmp = 0;
    for(int i=0; i<testCaseCnt; i++)
    {
        cin>>tmp;
        if( tmp > 40 )
            return;
        N.push_back(tmp);
    }
}

void DynamicProgramming::main()
{
    int ret = 0;
    inputT_N();
    for( vector<int>::iterator it = N.begin(); it != N.end(); it++ )
    {
        zero = 0;
        one = 0;
        ret = fibonacci( *it );
        ZeroByOne tmp = {zero, one};
        Nmap.insert( pair<int, ZeroByOne>( *it, tmp ));
    }
    print();
}

int main()
{
    DynamicProgramming dynamic;
    dynamic.main();
    return 0;
}
