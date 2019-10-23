// saycpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<int, char> NextSequence(vector<char> str);
vector<char> ExpandSequence(vector<char> str);
vector<char> Say(int digit, int nthTerm);
void dump(vector<char>);

int main(int argc, char*argv[])
{
        int n = 10;
        if (argc > 1) {
            n = atoi(argv[1]);
        }
	vector<char> result = Say(1, n);
	cout << "Say(1," << n << ") yields " << result.size() << " digits\n";
}


void dump(vector<char> v) {
	cout << "[";
	for (auto c : v) {
		cout << c;
	}
	cout << "]\n";
}

tuple<int, char> NextSequence(vector<char> str) {
	if (str.empty())
		return make_tuple(0, '\0');
	char lastChar = str[0];
	int count = 0;
	for (auto c : str) {
		if (c == lastChar)
			++count;
		else
			break;
	}
	return make_tuple(count, lastChar);
}

vector<char> ExpandSequence(vector<char> str) {
	vector<char> cb;
	int next = 0;
	int count;
	char ch;
	tie(count, ch) = NextSequence(str);
	while (count != 0) {
		cb.push_back(('0' + count));
		cb.push_back(ch);
		next += count;
		tie(count, ch) = NextSequence(vector<char>(str.begin()+next, str.end()));
	}
	return cb;
}

vector<char> Say(int digit, int nthTerm) {
	vector<char> sequence{ ((char)('0' + digit)) };
	for (int i = 1; i < nthTerm; ++i) {
		sequence = ExpandSequence(sequence);
	}
	return sequence;
}

