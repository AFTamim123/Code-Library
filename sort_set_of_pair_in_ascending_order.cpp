auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    };
set<pair<int,int>, decltype(compare)> s(compare);