#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main() {
    string num1 = "0.0000075";
    string num2 = "0.0000025";

    int a1 = 0;
    char b1[1000] = "";
    int c1 = 0;
    int a2 = 0;
    char b2[1000] = "";
    int c2 = 0;
    string f_b = "";
    int f_a = 0;

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

    if (abs(c1)>=abs(c2)){
        for (int i=0; i<(abs(c1)-abs(c2)); i++) {
            strcat(b2, "0");
        }
        c2 = c1;
    }
    else {
        //c2가 더 크면
        for (int i=0; i<(abs(c2)-abs(c1)); i++) {
            strcat(b1, "0");
        }
        c1 = c2;
    }
    printf("c랑 b에 수정 및 추가해준 값\n");
    printf("a1: %d b1: %s c1: %d \n", a1, b1, c1 );
    printf("a2: %d b2: %s c2: %d \n", a2, b2, c2 );

    //b끼리 자리 수 맞춰주기
    int b1Len = strlen(b1);
    int b2Len = strlen(b2);
    if (b1Len > b2Len)
    {
        int dis = b1Len-b2Len;
        char s[1000] = "";
        for (int i = 0; i < dis; i++)
        {
            s[i] = '0';
        }
        strcat(s,b2);
        strcpy(b2,s);
    }
    else if (b2Len>b1Len)
    {
        int dis = b2Len-b1Len;
        char s[1000] = "";
        for (int i = 0; i < dis; i++)
        {
            s[i] = '0';
        }
        strcat(s,b1);
        strcpy(b1,s);
    }
    //앞에 0 추가해서 자리수 맞춰줌
    printf("b에 0추가해서 길이 맞추기\n");
    printf("a1: %d b1: %s c1: %d \n", a1, b1, c1 );
    printf("a2: %d b2: %s c2: %d \n", a2, b2, c2 );
    

    int a = a1^a2;
    if  (a==0) {
        //음수끼리 더하거나 양수끼리 더하기
        //b끼리 더한거.
        int sum =0;
        int carry =0;
        char mResult[1001] = "";
        int len = strlen(b1);
        for (int i = len; i > 0; i--)
        {
            sum = (b1[i - 1] - '0') + (b2[i - 1] - '0') + carry;
            // printf("%d\n", sum);
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
        if (carry == 1)
        {
            mResult[0] = '1';
        }
        else
        {
            mResult[0] = '0'; 
        }

        std::string resultT;
        string sResult(mResult);
        resultT += sResult.at(0);
        if (resultT.compare("0")==0)
        {
            sResult.erase(0,1);
        }
        f_b = sResult;
    } 
    else
    {
        //b끼리 빼기
        //먼저 b1과 b2 크기 비교를 통한 부호 정하기
        int sub =0;
        int carry =0;
        char mResult[1001] = "";
        char big[1000] = "";
        char small[1000] = "";
        for (int i = 0; i <strlen(b1); i++)
        {
            if (b1[i] == b2[i])
            {
                strcpy(big,b1);
                strcpy(small,b2);
                f_a = a1;
            }
            else if (b1[i] > b2[i])
            {
                strcpy(big,b1);
                strcpy(small,b2);
                f_a = a1;
                break;
            }
            else {
                strcpy(small,b1);
                strcpy(big, b2);
                f_a = a2;
                break;
            }
        }
        //big에서 small을 빼면 됨.
        int len = strlen(big);
        for (int i=len; i>0; i--){
            sub = (big[i - 1] - '0') - (small[i - 1] - '0') + carry;
            if (sub >= 0)
            {
                mResult[i-1] = sub + '0';
                carry = 0;
            }
            else {
                sub += 10;
                carry = -1;
                mResult[i-1] = sub + '0';
            }
        }
        std::string resultT;
        string sResult(mResult);
        resultT += sResult.at(0);
        // if (resultT.compare("0")==0)
        // {
        //     sResult.erase(0,1);
        // }
        f_b = sResult;
    }

    
    
    


    f_b.insert((f_b.length() + c1),".");
    ////////0을 없애기
    printf("%s : 이게 부호 붙이기 전 답\n", f_b.c_str());
    if (a1==1 && a2==1) {
        f_b.insert(0,"-");
    }
    else if (f_a==1) {
        f_b.insert(0,"-");
    }
    printf("%s : 최종 답\n", f_b.c_str());

    return 0;
}