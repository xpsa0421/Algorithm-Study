#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Applicant
{
	int idx = 0;
	int doc = 0;
	int itv = 0;
	Applicant() {};
	Applicant(int idx, int doc, int itv) : idx(idx), doc(doc), itv(itv) {};
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int num_cases;
	cin >> num_cases;

	while (num_cases--)
	{
		int num_applicants;
		cin >> num_applicants;

		vector<Applicant> applicants;

		for (int i = 0; i < num_applicants; i++)
		{
			int doc, itv;
			cin >> doc >> itv;
			applicants.push_back(Applicant(i, doc, itv));
		}
		sort(applicants.begin(), applicants.end(), [](const Applicant& a, const Applicant& b)
			{
				return a.doc < b.doc;
			}
		);

		int hired = 0;
		int min_itv_rank = num_applicants + 1;
		for (auto& a : applicants)
		{
			if (a.itv < min_itv_rank)
			{
				hired++;
				min_itv_rank = min(min_itv_rank, a.itv);
			}
		}

		cout << hired << "\n";
	}
}