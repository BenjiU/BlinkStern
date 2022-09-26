class AttinyLED : public ILED {
private:
    int mGPIO;
    
public:
    AttinyLED(int gpio);
    void on();
    void off();
};
