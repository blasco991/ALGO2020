int confronto_con(long long int val);

void answer(long long int risp);

long long int g, l = 1;

void ricerca(long long int n) {
    if (n == l)
        return answer(n);
    g = (n + l) / 2;
    switch (confronto_con(g)) {
        case 0:
            return answer(g);
        case -1:
            l = g + 1;
            return ricerca(n);
        case 1:
            return ricerca(g - 1);
    }

}