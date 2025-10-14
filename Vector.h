class Vector{
    private:
        int capacity;
        int curr=0;
        int *arr;
    public:
        Vector(const int =100);
        ~Vector();
        void pb(const int );
        friend int& operator[](const int );
};