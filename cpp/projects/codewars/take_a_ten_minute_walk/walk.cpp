#include<vector>

const int MAX = 10;

struct State {
    int idx = 0;
    int n = 0, s = 0, e = 0, w = 0;
};

void make_step(std::vector<char> walk, State &walked)
{
    if (walked.idx == MAX) walked.idx = MAX + 1;

    switch (walk[walked.idx++]) {
    case 'n': (walked.s > 0)? walked.s--: walked.n++; break;
    case 's': (walked.n > 0)? walked.n--: walked.s++; break;
    case 'e': (walked.w > 0)? walked.w--: walked.e++; break;
    case 'w': (walked.e > 0)? walked.e--: walked.w++; break;
    }
}

bool isValidWalk(std::vector<char> walk) {
    State s;
    while (s.idx < (int)walk.size()) {
        make_step(walk, s);
    }
    return (s.idx == MAX && s.n == 0 && s.s == 0 && s.e == 0 && s.w == 0)? true: false;
}

int main()
{
    assert(isValidWalk({'n'}) == false);
    assert(isValidWalk({'n','s','n','s','n','s','n','s','n','s'}) == true);
    assert(isValidWalk({'n','s'}) == false);
    assert(isValidWalk({'n','s','n','s','n','s','n','s','n','s','n','s'}) == false);
    assert(isValidWalk({'e','w','e','w','n','s','n','s','e','w'}) == true);
    assert(isValidWalk({'n','s','e','w','n','s','e','w','n','s','e','w','n','s','e','w'}) == false);
    assert(isValidWalk({'n','s','e','w','n','s','e','w','n','s'}) == true);
    assert(isValidWalk({'s','e','w','n','n','s','e','w','n','s'}) == true);
    assert(isValidWalk({'n','s','n','s','n','s','n','s','n','n'}) == false);
    assert(isValidWalk({'e','e','e','w','n','s','n','s','e','w'}) == false);
};
