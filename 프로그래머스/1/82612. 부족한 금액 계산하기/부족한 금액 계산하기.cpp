using namespace std;

long long solution(int price, int money, int count)
{
    long long priceSum = 0;
    
    money - price*count;
    for(int i = 0; i<count; ++i){
        priceSum += price * (i+1);
    }
    
    return priceSum > money ? priceSum - money : 0;
}