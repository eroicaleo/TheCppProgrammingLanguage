#include <vector>

using namespace std;

class Tic_tac_toe {
public:
	enum State {empty, nought, cross};
private:
	vector<State> pos {vector<State>(9)};
};

int main() {
	Tic_tac_toe t1;
	Tic_tac_toe t2(t1);
	t1 = t2;
	return 0;
}
