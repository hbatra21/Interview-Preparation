class ProductOfNumbers {
vector<int> res = {1};
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num) res.push_back(res[res.size()-1]*num);
        else res = {1};        
    }
    
    int getProduct(int k) {
        int n = res.size();
        if(k >= n) return 0;
        else return res[n-1]/res[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
