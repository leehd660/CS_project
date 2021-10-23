#include <stdio.h>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
using namespace std;

class Add {
    public:
        int sum;
        int carry;
        char mResult[10001];
        int len;
        string result;
        
        void add(char a[], char b[]) {

            int b1Len = strlen(a);
            int b2Len = strlen(b);
            if (b1Len > b2Len)
            {
                int dis = b1Len-b2Len;
                len = b1Len;
                char s[10000] = "";
                for (int i = 0; i < dis; i++)
                {
                    s[i] = '0';
                }
                strcat(s,b);
                strcpy(b,s);
            }
            else if (b2Len > b1Len)
            {
                int dis = b2Len-b1Len;
                len = b2Len;
                char s[10000] = "";
                for (int i = 0; i < dis; i++)
                {
                    s[i] = '0';
                }
                strcat(s,a);
                strcpy(a,s);
            }

            // printf("%s\n", a);
            // printf("%s\n", b);
            
            for (int i = len; i > 0; i--) {
            sum = (a[i - 1] - '0') + (b[i - 1] - '0') + carry;
            if (sum > 9)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            mResult[i] = sum % 10 + '0';
            }
            if (carry == 1) {
                mResult[0] = '1';
            }
            else {
                mResult[0] = '0'; 
            }

            std::string resultT;
            string sResult(mResult);
            resultT += sResult.at(0);
            if (resultT.compare("0")==0)
            {
                sResult.erase(0,1);
            }

            result = sResult;
        }
};


int main() {
    string num1 = "-100000";
    string num2 = "0";

    int a1 = 0;
    char b1[10000] = "";
    int c1 = 0;
    int a2 = 0;
    char b2[10000] = "";
    int c2 = 0;
    string f_b = "";
    int f_a = 0;
    int f_c = 0;

    int j = 0;
    for (int i = 0; i < num1.length(); i++)
    {
        std::string test; 
        test += num1.at(i);
        // printf("%s\n",test);
        if (test.compare("-")==0)
        {
            a1 = 1;
        }
        if (test.compare(".")==0) {
            c1 = -(num1.length()-i-1);
            j--;
        }
        else if (test.compare("-")==0) {
            continue;
        }
        else {
            b1[j] = num1.at(i);
        }
        j++;
    }
    
    
    int k = 0;
    for (int i = 0; i < num2.length(); i++)
    {
        std::string test2; 
        test2 += num2.at(i);
        // printf("%s\n",test);
        if (test2.compare("-")==0)
        {
            a2 = 1;
        }
        if (test2.compare(".")==0) {
            c2 = -(num2.length()-i-1);
            k--;
        }
        else if (test2.compare("-")==0) {
            continue;
        }
        else {
            b2[k] = num2.at(i);
        }
        k++;
    }
    printf("처음 값\n");
    printf("a1: %d b1: %s c1: %d \n", a1, b1, c1 );
    printf("a2: %d b2: %s c2: %d \n", a2, b2,c2 );

    f_c = c1+c2;
    f_a = a1^a2;
    int forn1=0;
    int forn2=0;
    if (strlen(b1)%3>0){
        forn1 = 1;
    }
    if (strlen(b2)%3>0){
        forn2 = 1;
    }

    Add A;
    char init[10000] = "0";

    for (int i = 0; i < (strlen(b1)/3)+forn1; i++) {
        //b1을 3개씩 잘랐을 때, 나오는 갯수만큼 for문 돌리기
        for (int j = 0; j < (strlen(b2)/3)+forn2; j++) {
            //b2를 3개씩 잘랐을 때, 나오는 갯수만큼 for문 돌리기
            std::string partN1;
            string strB1(b1);
            int numLenTest1 = strlen(b1)-3*(i+1);
            if (numLenTest1>=0) {
                partN1 += strB1.substr(numLenTest1,3);
            }
            else {
                partN1 += strB1.substr(0,3+(numLenTest1));
            }
            std::string partN2;
            string strB2(b2);
            int numLenTest2 = strlen(b2)-3*(j+1);
            if (numLenTest2>=0) {
                partN2 += strB2.substr(numLenTest2,3);
            }
            else {
                partN2 += strB2.substr(0,3+(numLenTest2));
            }
            // printf("part1 : %s  part2 : %s \n ",partN1, partN2);
            int num1 = stoi(partN1);
            int num2 = stoi(partN2);
            printf("num1 : %d  num2 : %d \n ",num1, num2);
            int multN = num1*num2;
            printf("곱한 값 : %d \n", multN);
            string numStr(std::to_string(multN));
            printf("%s\n",numStr.c_str());
            for (int k = 0; k < 3*(i+j); k++) {
                numStr.insert(numStr.length(),"0");
            }
            printf("실제로 곱해진 수(더하면 되는 수) : %s\n", numStr.c_str());
            char addNum[10000];
            strcpy(addNum,numStr.c_str());
            A.add(init,addNum);
            string addResult;
            addResult = A.result;
            strcpy(init,addResult.c_str());
            printf("점점 더해지는 수 : %s\n", addResult.c_str());
            f_b = addResult;
        }
    }
    
    
    


    f_b.insert((f_b.length() + f_c),".");
    ////////0을 없애기
    printf("%s : 이게 부호 붙이기 전 답\n", f_b.c_str());
    if (f_a==1) {
        f_b.insert(0,"-");
    }
    printf("%s : 최종 답\n", f_b.c_str());

    return 0;
}