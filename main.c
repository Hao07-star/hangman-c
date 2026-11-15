#include <stdio.h>
#include <string.h>
int guessed[26]={0};
int wrong = 0;
int reveal_letter(const char answer[], char shown[], char guess);

int main(void)
{
    char answer[20] = "apple";
    char shown[20] = "_____";
    char guess;

    while (strcmp(answer, shown) != 0 && wrong<6)
    {
        printf("当前单词：%s\n", shown);
        printf("请输入一个小写英文字母：");

        if (scanf(" %c", &guess) != 1)
        {
            return 1;
        }

        if (guess < 'a' || guess > 'z')
        {
            printf("请输入 a 到 z 之间的字母。\n");
            continue;
        }
        int index = guess-'a';
        if(guessed[index]==1)
        {printf("已经猜过了\n");
            continue;
        }
        else
        guessed[index]=1;
        int count = reveal_letter(answer, shown, guess);
        if(count == 0)
        {
            wrong ++;
            printf("猜错了，还可以猜错 %d 次。\n", 6 - wrong);
        }
        else
        {
            printf("这次揭开了 %d 个位置。\n", count);
        }
        if (count == 0)
        {
            printf("这次没有揭开新的位置。\n");
        }
        else
        {
            printf("这次揭开了 %d 个位置。\n", count);
        }
    }

    if (strcmp(answer, shown) == 0)
    {
        printf("猜对了！答案是 %s。\n", answer);
    }
    else
    {
        printf("已经猜错 6 次，答案是 %s。\n", answer);
    }
}

int reveal_letter(const char answer[], char shown[], char guess)
{
    int count = 0;

    for (int i = 0; answer[i] != '\0'; i++)
    {
        if (answer[i] == guess && shown[i] == '_')
        {
            shown[i] = guess;
            count++;
        }
    }

    return count;
}