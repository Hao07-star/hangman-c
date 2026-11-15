#include <stdio.h>
#include <string.h>

int reveal_letter(const char answer[], char shown[], char guess);

int main(void)
{
    char answer[20] = "apple";
    char shown[20] = "_____";
    char guess;

    while (strcmp(answer, shown) != 0)
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

        int count = reveal_letter(answer, shown, guess);

        if (count == 0)
        {
            printf("这次没有揭开新的位置。\n");
        }
        else
        {
            printf("这次揭开了 %d 个位置。\n", count);
        }
    }

    printf("猜对了！答案是 %s。\n", shown);
    return 0;
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