#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int subarraysWithKDistinct( vector<int> &A, int K )
    {
        return atMostK( A, K ) - atMostK( A, K - 1 );
    }
    //长度为[1,K]的子数组的个数
    int atMostK( vector<int> &A, int K )
    {
        int i = 0, res = 0;
        unordered_map<int, int> count;
        for( int j = 0; j < A.size(); ++j ) {
            // 发现新的数字
            std::cout << "j = " << j << "\n";
            if( !count[A[j]]++ ) {
                K--;
                std::cout << "=============== K = " << K << " =================\n";
                for( unordered_map<int, int>::iterator it = count.begin();
                        it != count.end();
                        it++ ) {
                    std::cout << it->first << "\t";
                }
                std::cout << "\n";
                for( unordered_map<int, int>::iterator it = count.begin();
                        it != count.end();
                        it++ ) {
                    std::cout << it->second << "\t";
                }
                std::cout << "\n";
            }
            //新数字个数达到K
            while( K < 0 ) {
                //将前窗口向后推一个
                if( !--count[A[i]] ) {//平均长度复杂度，最大线性复杂度
                    for( unordered_map<int, int>::iterator it = count.begin();
                            it != count.end();
                            it++ ) {
                    }
                    K++;
                };
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
};

int main()
{
    vector<int> A1 = {1, 2, 1, 2, 3};
    int K1 = 2;
    vector<int> A2 = {1, 2, 1, 3, 4};
    int K2 = 3;
    std::cout << " Test1:\tK = " << K1 << "\tarray: [ ";
    for( int val : A1 ) {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;
    Solution sol;
    int num1 = sol.subarraysWithKDistinct( A1, K1 );
    //    int num2 = sol.subarraysWithKDistinct( A2, K2 );
    std::cout << "num1: " << num1 << "\n";
    //   std::cout << "num2: " << num2 << "\n";


    return 0;
}
