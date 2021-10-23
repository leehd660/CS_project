#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Sub {
    public:
        int subsum=0;
        int carry=0;
        char mResult[1001];
        int len;
        string minus;
        string result;

        void sub(char b1[], char b2[]) {
            int b1Len = strlen(b1);
            int b2Len = strlen(b2);
            if (b1Len > b2Len)
            {
                int dis = b1Len-b2Len;
                len = b1Len;
                char s[1000] = "";
                for (int i = 0; i < dis; i++)
                {
                    s[i] = '0';
                }
                strcat(s,b2);
                strcpy(b2,s);
            }
            else if (b2Len > b1Len) {   
                int dis = b2Len-b1Len;
                char s[1000] = "";
                for (int i = 0; i < dis; i++)
                {
                    s[i] = '0';
                }
                strcat(s,b1);
                strcpy(b1,s);
            }
            ////여기까지가 길이 맞춰준거

            ////크기 비교해서 바꿔주기
            for (int i = 0; i <strlen(b1); i++)
            {
                if (b1[i] > b2[i])
                {
                    break;
                }
                else if (b1[i] < b2[i])
                {
                    minus = "-";
                    strcpy(b1, minus.c_str());
                    break;
                }
                else{
                    continue;
                }
            }

            printf("%s\n", b1);
            printf("%s\n", b2);

            len = strlen(b1);
            for (int i=len; i>0; i--){
                subsum = (b1[i - 1] - '0') - (b2[i - 1] - '0') + carry;
                if (subsum >= 0)
                {
                    mResult[i-1] = subsum + '0';
                    carry = 0;
                }
                else {
                    subsum += 10;
                    carry = -1;
                    mResult[i-1] = subsum + '0';
                }
            }
            string check_b1 = "";
            string check_b2 = "";
            check_b1 = b1;
            check_b2 = b2;
            
            if (check_b1.compare("-") == 0) {
                result = "-";
            }
            else if (check_b1.compare(check_b2) == 0) {
                result = "0";
            }
            else {
                std::string resultT;
                string sResult(mResult);
                resultT += sResult.at(0);
                result = sResult;
            }
        }
};

int main() {

    char a[1000] = "090";
    char b[1000] = "010";

    Sub A;
    A.sub(a, b);
    string result;
    result = A.result;

    printf("%s\n", result.c_str());

    return 0;
}