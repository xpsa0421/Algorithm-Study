#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct Word
{
	char str[51];
	int len;
};

bool CompareWords(Word a, Word b);

int main() {
	int n;
	scanf("%d", &n);

	vector<Word> words(n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", words[i].str);
		words[i].len = strlen(words[i].str);
	}

	sort(words.begin(), words.end(), CompareWords);

	printf("%s\n", words[0].str);
	for (int i = 1; i < n; i++)
	{
		if (strcmp(words[i].str, words[i-1].str) == 0) continue;
		printf("%s\n", words[i].str);
	}

	return 0;
}

bool CompareWords(Word a, Word b)
{
	if (a.len == b.len)
	{
		return strcmp(a.str, b.str) < 0;
	}
	else
	{
		return a.len < b.len;
	}
}