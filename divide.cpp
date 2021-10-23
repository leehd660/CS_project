#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Sub {
    public:
        int subsum=0;
        int carry=0;
        char mResult[10010] ="";
        int len=0;
        string minus ="";
        string result ="";

        void sub(char b1[], char b2[]) {
            carry=0;
            int b1Len = strlen(b1);
            int b2Len = strlen(b2);
            printf("%d 길이 측정 %d\n", b1Len, b2Len);
            if (b1Len > b2Len)
            {
                int dis = b1Len-b2Len;
                len = b1Len;
                char s[10000] = "";
                for (int i = 0; i < dis; i++)
                {
                    s[i] = '0';
                }
                strcat(s,b2);
                strcpy(b2,s);
            }
            else if (b2Len > b1Len) {   
                int dis = b2Len-b1Len;
                char s[10000] = "";
                for (int i = 0; i < dis; i++)
                {
                    s[i] = '0';
                }
                strcat(s,b1);
                strcpy(b1,s);
            }
            ////여기까지가 길이 맞춰준거

            // printf("&&&$$$$$$$$$%s\n", b1);
            // printf("&&&$$$$$$$$$%s\n", b2);

            ////크기 비교해서 바꿔주기
            for (int i = 0; i <strlen(b1); i++)
            {
                if (b1[i] == b2[i]){
                    continue;
                }
                else if (b1[i] > b2[i])
                {
                    break;
                }
                else if (b1[i] < b2[i])
                {
                    minus = "-";
                    strcpy(b1, minus.c_str());
                    break;
                }
            }

            printf("%s\n", b1);
            printf("%s\n", b2);

            len = strlen(b1);
            printf("carry >> %d\n",carry);
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
    string num1 = "1212.121212121212";
    string num2 = "98.989898";

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
        char s[10000] = "";
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
        char s[10000] = "";
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

    Sub A;
    f_a = a1^a2;
    int a = a1^a2;
    int totalLen = 0;
    string answer = "";
    char b_1[10000];
    char b_2[10000];
    strcpy(b_1,b1);
    strcpy(b_2,b2);
    while (true)
    {
        int count = 0;
        while (true)
        {
            printf("%s +++ %s\n",b_1,b_2);
            char cpyb_1[10000];
            strcpy(cpyb_1,b_1);
            A.sub(b_1,b_2);
            string resultStr;
            resultStr = A.result;
            // int resultNum = stoi(A.result);
            printf("%s ::::\n", resultStr.c_str());
            if (resultStr.compare("-")==0)
            {
                if (answer.length()==0) {
                    answer.insert(answer.length(),to_string(count));
                    answer.insert(answer.length(),".");
                    printf("gggg\n");
                }
                else {
                    answer.insert(answer.length(),to_string(count));
                }
                // int afterNum = stoi(cpyb_1);
                // string b_1_1 = to_string(afterNum);
                string b_1_1 = cpyb_1;
                strcpy(b_1,b_1_1.c_str());
                strcat(b_1,"0");
                printf("%s\n",b_1);
                printf("%d count입니다\n",count);
                break;
            }
            else if (resultStr.compare("0") ==0 ) {
                if (answer.length()==0) {
                    count++;
                    answer.insert(answer.length(),to_string(count));
                    answer.insert(answer.length(),".");
                    printf("kkkgg\n");
                }
                else {
                    count++;
                    answer.insert(answer.length(),to_string(count));
                }
                strcpy(b_1,"0");
                printf("%d count입니다\n",count);
                break;
            }
            else {
                count++;
                strcpy(b_1,resultStr.c_str());
                // continue;
            }
        }
        string str = "";
        str = b_1;
        if (answer.length() >= 33 || str.compare("0")==0) {
            break;
        }
    }

    f_b = answer;

    // f_b.insert((f_b.length() + c1),".");
    ////////0을 없애기
    printf("%s : 이게 부호 붙이기 전 답\n", f_b.c_str());
    if (f_a==1) {
        f_b.insert(0,"-");
    }
    printf("%s : 최종 답\n", f_b.c_str());

    return 0;
}