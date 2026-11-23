class ProductOfNumbers {
public:
    int N;
    vector<int> products;

    ProductOfNumbers() {
        N = 0;
    }
    
    void add(int num) {
        if (num == 0) {
            N = 0;
            products.clear();
            return;
        } 

        if (N == 0) {
            products.push_back(num);
        }
        else {
            products.push_back(products[N-1] * num);
        }
        
        N++;
    }
    
    int getProduct(int k) {
        if (k > N) return 0;

        if (N-k-1 >= 0) return products[N-1] / products[N-k-1];

        return products[N-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
