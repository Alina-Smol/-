#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 3) {
		cout << "error";
	}
	else
	{
		char* input = argv[1];
		char* output = argv[2];
		int n, m;
		int sum = 0;
		ifstream fin;
		fin.open(input);

		fin >> m >> n;
		vector<vector<int> > v(n);
		if (fin.is_open()) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					fin >> v[i][j];
				}
			}
		}
		else { cout << "error1"; }
		for (int j = 0; j < m; j++) {
			sum = 0;
			for (int i = 0; i < n; i++) {
				sum = v[i][j];
			}
			v[m + 1][j] = sum;
		}
		int t;
		for (int g = 0; g < m - 1; g++) {
			for (int j = 0; j < m - g - 1; j++) {
				if (v[m + 1][n] > v[m + 1][n + 1]) {
					t = v[m + 1][n];
					v[m + 1][n] = v[m + 1][n + 1];
					v[m + 1][n + 1] = t;
					for (int i = 0; i < n; i++) {
						t = v[i][j];
						v[i][j] = v[i][j + 1];
						v[i][j + 1] = t;
					}
				}
				else { continue; }
			}
		}
		ofstream fout;
		fout.open(output);
		if (fin.is_open()) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					fout << v[i][j];
				}
				fout << "\n";
			}
		}
		else { cout << "error1"; }


		fout.close();

		return 0;
	}
}