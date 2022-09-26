class IBlinkProgram {
protected:
    ILED**  mLEDs;
    ILED*   mCurrentLED;
    uint8_t mCurrentLEDindex;
    uint8_t mCurrentLEDmax;

protected:
    void setLEDs(ILED** leds) {
        mLEDs = leds;
    }
    
    void nextLED() {
        mCurrentLEDindex++;
        if(mCurrentLEDindex == mCurrentLEDmax) {
            mCurrentLEDindex = 0;
        }
        mCurrentLED = mLEDs[mCurrentLEDindex];
    }
    
public:
    virtual void start() = 0;
    virtual void step() = 0;
    virtual void stop() = 0;
};
