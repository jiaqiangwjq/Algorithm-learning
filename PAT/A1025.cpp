#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student
{
	char reg_number[15];
	int score;
	int loc_number;
	int final_rank;
	int local_rank;
}stu[30010];

bool cmp(Student stu_1, Student stu_2);

int N, K;

int main(void)
{
	scanf("%d", &N);

	int i = 0;
	int totalLength = 0;
	int group = 1;

	while (N--)
	{
		scanf("%d", &K);

		int length = K;
		totalLength += length;

		while (K--)
		{
			stu[i].loc_number = group;
			scanf("%s %d", stu[i].reg_number, &stu[i].score);
			++i;
		}

		++group;
		sort(stu + i - length, stu + i, cmp);

		stu[i - length].local_rank = 1;
		int r = 1;
		for (int j = i - length + 1; j < i; j++)
		{
			if (stu[j].score == stu[j-1].score)
			{
				stu[j].local_rank = stu[j - 1].local_rank;
				++r;
			}
			else
			{
				++r;
				stu[j].local_rank = r;
			}
		}
	}

	sort(stu, stu + totalLength, cmp);

	stu[0].final_rank = 1;

	for (int j = 1; j < totalLength; j++)
	{
		if (stu[j].score == stu[j - 1].score)
		{
			stu[j].final_rank = stu[j - 1].final_rank;
		}
		else
		{
			stu[j].final_rank = j + 1;
		}
	}

	printf("%d\n", totalLength);
	for (int j = 0; j < totalLength; j++)
	{
		printf("%s %d %d %d\n", stu[j].reg_number, stu[j].final_rank, stu[j].loc_number, stu[j].local_rank);
	}

	return 0;
}

bool cmp(Student stu_1, Student stu_2)
{
	if (stu_1.score != stu_2.score)
		return stu_1.score > stu_2.score;
	else
		return strcmp(stu_1.reg_number, stu_2.reg_number) < 0;
}