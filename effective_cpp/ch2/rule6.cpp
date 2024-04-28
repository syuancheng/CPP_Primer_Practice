

class HomeForSale {
public:
  HomeForSale() = default;

private:
  HomeForSale(const HomeForSale &);
  HomeForSale &operator=(const HomeForSale &);
};

int main() {
  HomeForSale h1; // default constructor
  HomeForSale h2;
  HomeForSale h3(h1); // copying constructor
  h1 = h2;            // copying assignment
}