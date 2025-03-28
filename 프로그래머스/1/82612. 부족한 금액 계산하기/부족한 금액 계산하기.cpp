using namespace std;

long long solution(int price, int money, int count)
{
    long long llmoney = money;
    for(int i = 1; i <= count; i++) llmoney -= price * i;
    if (llmoney >= 0) return 0;
    else return -llmoney;
}