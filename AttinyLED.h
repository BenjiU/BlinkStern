class AttinyLED : public ILED {
private:
    uint8_t mGPIO;
    
public:
    AttinyLED(uint8_t gpio);
    void on();
    void off();
};
