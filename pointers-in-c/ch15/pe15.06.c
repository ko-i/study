// 2020-12-19 created by Akson
// pe15.6
// 我借用之前写过的代码

int isPalindrome(int x){
    if(x < 0)
    {
        return 0;
    }
    
    int digit[15] = {0};
    int count = 0;
    while(x != 0)
    {
        digit[count] = x % 10;
        x /= 10;
        count++;
    }
    
    int start = 0;
    int end = count - 1;
    while(start < end)
    {
        if(digit[start] != digit[end])
        {
            return 0;
        }
        
        start++;
        end--;
    }
    
    return 1;
}