
class Funds {

    float balance;
    int credits;

    public:

        Funds();

        float getBalance();
        int getCredits();

        bool deductCredits(int);
        void addCredits(int);


};