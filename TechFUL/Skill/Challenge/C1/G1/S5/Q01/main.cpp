#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<string> etar = { "push-ups", "sit-ups", "squats", "walking", "radio-calisthenics" };
const vector<double> mets = { 8.0, 8.0, 5.0, 3.3, 4.0 };

int main() {
    string exer;
    double time, weight;
    cin >> exer >> time >> weight;
    int res = 0;
    for (int i=0; i<(int)(etar.size()); ++i) if (exer == etar[i]) res = (int)(time*weight*mets[i]*1.05);
    cout << res << endl;
    return 0;
}
