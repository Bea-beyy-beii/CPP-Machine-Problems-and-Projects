#include <cstdio>
using namespace std;

int main() {
    long long fare[1000000] = {};
    long long passengers, query, start, end;

    scanf("%lld %lld", &passengers, &query);

    if (passengers < 1 || passengers > 100000 || query < 1 || query > 100000) {
        return 0;
    }

    for (int i = 0; i < passengers; i++) {
        scanf("%lld", &fare[i]);

        if (fare[i] < 0 || fare[i]>1000000) {
            return 0;
        }
    }

    for (int i = 0; i < query; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%lld %lld", &start, &end);

            if (start < 1 || start > end || end < start || end > passengers) {
                return 0;
            }

            for (int k = start; k <= end; k++) {
                long long total = 0;
                printf("%lld", total += fare[k]);
            }
        }
    }
}