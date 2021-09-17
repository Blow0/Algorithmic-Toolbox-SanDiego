#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

long long PairWiseProductFast(vector<int>& num, unsigned long size)
{
    unsigned long n = size;
    unsigned long maxIndex1 = -1;
    for(unsigned long i = 0; i < n; i++)
        if((maxIndex1 == -1) || (num[i] > num[maxIndex1]))
            maxIndex1 = i;
    unsigned long maxIndex2 = -1;
    for(unsigned long i = 0; i < n; i++)
        if((maxIndex1 != i) &&(maxIndex2 == -1 || num[i] > num[maxIndex2]))
            maxIndex2 = i;
    return ((long long)num[maxIndex1] * num[maxIndex2]);
}
long long PairWiseProduct(vector<int>& num, unsigned long size)
{
    unsigned long n = size;
    unsigned long product = 0;
    for(unsigned long i = 0; i < n; i++)
        for(unsigned long j = i + 1; j < n; j++)
            if((long long)(num[i] * num[j]) > product)
                product = (long long)(num[i] * num[j]);
    return product;            
}
int main(void)
{
  /*  while(true)
    {
        unsigned long n = rand() % 100000 + 2;
        cout << n << endl;
        vector<long long> test;
        for(unsigned long i = 0; i < n; i++)
            test.push_back(rand() % 100000);
        for(unsigned long i = 0; i < n; i++)
            cout << test[i] << ' ';
        cout << endl;

        long long res1 = PairWiseProductFast(test, n);
        long long res2 = PairWiseProduct(test, n);
        if(res1 != res2)
        {
            cout << "Wrong Answer" << res1 << " " << res2 << endl;
            break;
        }
        else
        {
            cout << "Ok" << endl;
        }
    }*/
    unsigned long n;
    cin >> n;
    vector<int> num(n);
    for(unsigned long i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    cout << PairWiseProductFast(num, n) << endl;
    return 0;
}