

class ConstRef {
public:
    ConstRef(int i);
private:
    int i;
    const int ci;
    int &ri;
};

ConstRef::ConstRef(int ii) {
    i = ii;
    ci = ii;
    ri = i;
}